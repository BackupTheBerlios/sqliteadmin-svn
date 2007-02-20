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
	if (db.lastError().type() != QSqlError::NoError)
		emit droppedTable(tableName);
	else
		emit databaseError(db.lastError());
}