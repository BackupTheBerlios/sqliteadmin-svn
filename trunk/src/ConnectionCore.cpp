/***************************************************************************
 *   Copyright (C) 2007 by Leonardo Mateo   *
 *   lmateo@3wdg.org   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <QStandardItemModel>
#include <QAbstractItemView>
#include "ConnectionCore.h"
	
ConnectionCore::ConnectionCore(QObject *parent, const QString &driver) : QObject(parent)
{
	dbCount = 0;
	db = QSqlDatabase::addDatabase(driver, QString("Core%1").arg(++dbCount));
// 	query = new QSqlQuery(db);
	queryModel = 0;
}

ConnectionCore::~ConnectionCore()
{
// 	delete query;
	delete queryModel;
}

void ConnectionCore::addConnection(const QString &dbName)
{
    QSqlError err;
    
	 if (db.isOpen())
		 this->removeConnection(db.databaseName());
	
	 db.setDatabaseName(dbName);
	 if (!db.open()) {
		  err = db.lastError();
		  db = QSqlDatabase();
		  QSqlDatabase::removeDatabase(QString("Core%1").arg(dbCount));
	 }
	 emit  databaseOpened(err);
}

void ConnectionCore::removeConnection( const QString &dbName)
{
	db.close();
	db.removeDatabase(dbName);
	emit databaseClosed();
}

QSqlDatabase ConnectionCore::currentDatabase()
{
	return db;
}

QSqlRecord ConnectionCore::getTableFields( const QString &tableName)
{
	emit tableFields(db.record(tableName));
	return db.record(tableName);
}


void ConnectionCore::executeQuery( const QString &sqlQuery)
{
	QSqlQuery query(db);
	query.exec(sqlQuery);
	emit executedQuery( &query );
	
	if (db.lastError().type() != QSqlError::NoError)
	{
		emit databaseError(db.lastError());
		return;
	}
	
	if (this->queryModel)
		delete queryModel;
	
	queryModel = new QSqlQueryModel(this);
	queryModel->setQuery(query);

	emit executedQuery( queryModel );
}


void ConnectionCore::dropTable(const QString &tableName)
{
	executeQuery(QString("DROP TABLE %1").arg(tableName));
	emit droppedTable(tableName);
}

void ConnectionCore::buildTableModel( const QString &tableName, QAbstractItemView *parentWidget)
{
	QSqlRecord rec = currentDatabase().record(tableName);
	QStandardItemModel *model = new QStandardItemModel((QObject*)parentWidget);
	
	model->insertRows(0, rec.count());
	model->insertColumns(0, 7);
	
	model->setHeaderData(0, Qt::Horizontal, tr("Fieldname"));
	model->setHeaderData(1, Qt::Horizontal, tr("Type"));
	model->setHeaderData(2, Qt::Horizontal, tr("Length"));
	model->setHeaderData(3, Qt::Horizontal, tr("Precision"));
	model->setHeaderData(4, Qt::Horizontal, tr("Not NULL"));
	model->setHeaderData(5, Qt::Horizontal, tr("AutoValue"));
	model->setHeaderData(6, Qt::Horizontal, tr("DefaultValue"));
		
	for (int i = 0; i < rec.count(); ++i) {
		QSqlField fld = rec.field(i);
		model->setData(model->index(i, 0), fld.name());
		model->setData(model->index(i, 1), fld.typeID() == -1
				 ? QString(QVariant::typeToName(fld.type()))
				 : QString("%1 (%2)").arg(QVariant::typeToName(fld.type())).arg(fld.typeID()));
		model->setData(model->index(i, 2), fld.length());
		model->setData(model->index(i, 3), fld.precision());
		model->setData(model->index(i, 4), fld.requiredStatus() == -1 ? QVariant("?")
			 : QVariant(bool(fld.requiredStatus())));
		model->setData(model->index(i, 5), fld.isAutoValue());
		model->setData(model->index(i, 6), fld.defaultValue());
	}
}

void ConnectionCore::addTableField(const QString &tableName, SqliteField *field)
{
	QString notNull = (field->fieldRequired) ? "NOT NULL" : "";
	QString autoIncrement = (field->fieldAuto) ? "PRIMARY KEY AUTOINCREMENT" : "";
	
	QString query = QString("ALTER TABLE %1 ADD %2 %3 %4 %5").arg(tableName).arg(field->fieldName).arg(field->fieldType).arg(notNull).arg(autoIncrement);
	qWarning(query.toAscii());
// 	executeQuery(query);
}