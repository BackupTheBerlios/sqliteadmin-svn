/***************************************************************************
 *   Copyright (C) 2006 by Leonardo Mateo   *
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

#include <QFileDialog>
#include <QMessageBox>
#include <QListWidget>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMenu>
#include <QScrollBar>
#include <QFile>
#include "AdminWindow.h"
#include "ConnectionCore.h"
#include "EditTableDialog.h"
#include "SQLiteFieldModel.h"
		
		
AdminWindow::AdminWindow(QWidget *parent, Qt::WFlags flags) : QMainWindow(parent, flags)
{
	setupUi(this);
	mainSplitter->setStretchFactor(1,1);
	rightSplitter->setStretchFactor(1,1);
	cCore = new ConnectionCore(this);
	tableDialog = new EditTableDialog(this);
// 	tablesList->setContextMenuPolicy(Qt::CustomContextMenu);
	connectWidgets();
	
	tablesList->menu()->addAction(actionDrop_Table);
	tablesList->menu()->addAction(actionEdit_Ta_ble);
	
	actionSa_ve_SQL_File->setEnabled(FALSE);
	actionDrop_Table->setEnabled(FALSE);
	actionEdit_Ta_ble->setEnabled(FALSE);
}

void AdminWindow::connectWidgets()
{
	connect( action_Open, SIGNAL(triggered()), this, SLOT(dbFileOpen()) );
	connect( action_Quit, SIGNAL(triggered()), this, SLOT(close()) );
	connect( actionC_lose, SIGNAL(triggered()), this, SLOT(closeDatabase()) );
	connect( actionOpen_SQL_File, SIGNAL(triggered()), this, SLOT(sqlFileOpen()) );
	connect( actionSa_ve_SQL_File, SIGNAL(triggered()), this, SLOT(sqlFileSave()) );
	connect( actionDrop_Table, SIGNAL(triggered()), this, SLOT(dropTableRequest()) );
	connect( actionEdit_Ta_ble, SIGNAL(triggered()), this, SLOT(showTableDialog()) );
	
	connect( this, SIGNAL(sqlFileSelected(const QString &)), this, SLOT(openSqlFileNotification(const QString &)) );
	connect( this, SIGNAL(dbFileSelected(const QString&)), cCore, SLOT(addConnection( const QString& )) );
	connect( this, SIGNAL(dropTable(const QString&)), cCore, SLOT(dropTable(const QString&)) );
	
	connect( cCore, SIGNAL(databaseOpened( const QSqlError& )), this, SLOT(openDatabaseNotification( const QSqlError& )) );
	connect( cCore, SIGNAL(databaseError(const QSqlError &)), this, SLOT(sqlError(const QSqlError&)) );
	connect( cCore, SIGNAL(executedQuery( QSqlQueryModel* )), this, SLOT(queryResults( QSqlQueryModel* )) );
	
	connect( tablesList, SIGNAL(itemActivated(QListWidgetItem *)), this, SLOT(showTable( QListWidgetItem* )) );
	connect( tablesList, SIGNAL(itemActivated(QListWidgetItem *)), this, SLOT(showFields( QListWidgetItem* )) );
	connect( tablesList, SIGNAL(itemSelectionChanged()), this, SLOT(updateActionStatus()) );
//  	connect( tablesList, SIGNAL(dropTable(const QString&)), this, SLOT(dropTableRequest(const QString &)) );
	
// 	connect( sqlTextEdit, SIGNAL(textChanged()), this, SLOT(updateSqlButtons()) );
	connect( sqlTextEdit, SIGNAL(textChanged()), this, SLOT(updateActionStatus()) );
	
	connect( historyList, SIGNAL(itemSelectionChanged()), this, SLOT(updateHistoryButtons()) );
	connect( historyList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(historyItemSelected(QListWidgetItem*)) );
	
	connect( runSqlButton, SIGNAL(clicked()), this, SLOT(runQuery()) );
	connect( tableDialog, SIGNAL(sqliteFields(const QHash<int, SqliteField>)), this, SLOT(editTable(const QHash<int, SqliteField>)) );
	
// 	connect( saveSqlButton, SIGNAL(clicked()), this, SLOT(sqlFileSave()) );
}


void AdminWindow::dbFileOpen()
{
	QString databaseFile;
	
	databaseFile = QFileDialog::getOpenFileName(this, tr("Select Database File"), ".", tr("Database Files (*.db)"));
	if (!databaseFile.isNull())
		emit dbFileSelected(databaseFile);
}

void AdminWindow::sqlFileOpen()
{
	QString sqlFile;
	
	sqlFile = QFileDialog::getOpenFileName(this, tr("Select SQL File"), ".", tr("SQL Files (*.sql)"));
	if (!sqlFile.isNull())
		emit sqlFileSelected(sqlFile);
}

void AdminWindow::sqlFileSave()
{
	QString sqlFile;
	
	if (sqlTextEdit->documentTitle().isEmpty())
		sqlFile = QFileDialog::getSaveFileName(this, tr("Select SQL File Name"), ".", tr("SQL Files (*.sql)"));
	else
		sqlFile = sqlTextEdit->documentTitle();
	
	if (!sqlFile.isNull() && !sqlFile.isEmpty())
	{
		QFile fileToSave(sqlFile);
		if (fileToSave.open(QIODevice::WriteOnly))
		{
			fileToSave.write(sqlTextEdit->toPlainText().toAscii());
			fileToSave.flush();
			fileToSave.close();
			sqlTextEdit->setDocumentTitle(sqlFile);
		}
	}
}


void AdminWindow::openSqlFileNotification(const QString &fileName)
{
	QFile sqlFile (fileName);
	if (sqlFile.open(QIODevice::ReadOnly))
	{
		sqlTextEdit->setText(QString(sqlFile.readAll()));
		sqlTextEdit->setDocumentTitle(fileName);
	}
	else
	{
		QMessageBox::critical(this, tr("Open Error"), tr("There was a problem openning SQL File"), QMessageBox::Ok, QMessageBox::Ok);
	}
}

void AdminWindow::openDatabaseNotification( const QSqlError &error)
{
	if (error.type() != QSqlError::NoError)
	{
		QMessageBox::critical(this, tr("Open Error"), tr("There was a problem openning database.\n The reported error was: ") + error.databaseText(), QMessageBox::Ok, QMessageBox::Ok);
	}
	else
	{
		updateTablesList();
		databaseLabel->setText(cCore->currentDatabase().databaseName());
	}
}

void AdminWindow::updateTablesList()
{
		QStringList tables = cCore->currentDatabase().tables();
		tablesList->clear();
		for (int i = 0; i < tables.count(); i++)
			QListWidgetItem *item = new QListWidgetItem(tables.at(i), tablesList);
}

void AdminWindow::closeDatabase()
{
	cCore->removeConnection( cCore->currentDatabase().databaseName());
}

void AdminWindow::showFields(QListWidgetItem *selectedItem)
{
	 QSqlRecord rec = cCore->currentDatabase().record(selectedItem->text());
	 SQLiteFieldModel *model = new SQLiteFieldModel((QTableView*)fieldsTableView);
	
	 model->insertRows(0, rec.count());
	 
	
	 for (int i = 0; i < rec.count(); ++i) {
		  QSqlField fld = rec.field(i);
		  model->setData(model->index(i, 0), fld.name());
// 		  model->setData(model->index(i, 1), fld.typeID() == -1
// 					 ? QString(QVariant::typeToName(fld.type()))
// 					 : QString("%1 (%2)").arg(QVariant::typeToName(fld.type())).arg(fld.typeID()));
		  model->setData(model->index(i, 1), getTypeName(fld));
		  model->setData(model->index(i, 2), fld.length());
		  model->setData(model->index(i, 3), fld.precision());
		  model->setData(model->index(i, 4), fld.requiredStatus() == -1 ? QVariant("?")
					 : QVariant(bool(fld.requiredStatus())));
		  model->setData(model->index(i, 5), fld.isAutoValue());
		  model->setData(model->index(i, 6), fld.defaultValue());
	 }
	 
    int height = fieldsTableView->fontMetrics().height();
    fieldsTableView->verticalHeader()->setDefaultSectionSize(height); 
	 
	 fieldsTableView->setModel(model);
    fieldsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

QString AdminWindow::getTypeName(QSqlField fld)
{
	if (QString(QVariant::typeToName(fld.type())) == QString("QString"))
		return QString("Text");
	else if(QString(QVariant::typeToName(fld.type())) == QString("int"))
		return QString("Integer");
	else if(QString(QVariant::typeToName(fld.type())) == QString("double"))
		return QString("Real");
	else
		return tr(QVariant::typeToName(fld.type()));
}

void AdminWindow::showTable( QListWidgetItem *selectedItem ) 
{
	QSqlTableModel *model = new QSqlTableModel(resultTableView, cCore->currentDatabase());
	model->setEditStrategy(QSqlTableModel::OnRowChange);
	model->setTable(selectedItem->text());
	model->select();
	 if (model->lastError().type() != QSqlError::NoError)
       QMessageBox::critical(this, tr("Show Table Error"), tr("There was a problem showing table.\n The reported error was: ") + model->lastError().databaseText(), QMessageBox::Ok, QMessageBox::Ok);
    resultTableView->setModel(model);
}

void AdminWindow::updateSqlButtons()
{
	saveSqlButton->setEnabled(!sqlTextEdit->toPlainText().isEmpty());
	clearSqlButton->setEnabled(!sqlTextEdit->toPlainText().isEmpty());
	runSqlButton->setEnabled(!sqlTextEdit->toPlainText().isEmpty() && cCore->currentDatabase().isOpen());
}

void AdminWindow::updateHistoryButtons()
{
	saveHistoryButton->setEnabled(historyList->count() > 0);
	clearHistoryButton->setEnabled(historyList->count() > 0);
}

void AdminWindow::runQuery()
{
	if (sqlTextEdit->textCursor().hasSelection())
		cCore->executeQuery(sqlTextEdit->textCursor().selectedText());
	else
		cCore->executeQuery(sqlTextEdit->toPlainText());
	updateTablesList();
}


void AdminWindow::queryResults( QSqlQueryModel *model)
{
	if (model->lastError().type() != QSqlError::NoError)
	{
		QMessageBox::critical(this, tr("Show Table Error"), tr("There was a problem showing table.\n The reported error was: %1").arg(model->lastError().databaseText()), QMessageBox::Ok, QMessageBox::Ok);
	}
	else
	{
		resultTableView->setModel(model);
		historyList->insertItem(historyList->count() + 1, model->query().lastQuery());
	}
}

void AdminWindow::dropTableRequest( /*const QString &tableName*/ )
{
	if (QMessageBox::question(this, tr("Drop Table"), tr("Are you sure you want to DROP table %1").arg(tablesList->currentItem()->text()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Ok)
	{
		emit dropTable(tablesList->currentItem()->text()/*tableName*/);
		updateTablesList();
	}
}

void AdminWindow::sqlError(const QSqlError &error)
{
	QMessageBox::critical(this, tr("SQL Error"), tr("An error has occurred.\n The reported error was: ") + error.databaseText(), QMessageBox::Ok, QMessageBox::Ok);
}

void AdminWindow::historyItemSelected(QListWidgetItem *item)
{
	sqlTextEdit->append(item->text());
	centalTabWidget->setCurrentIndex(0);
}

void AdminWindow::updateActionStatus()
{
	actionDrop_Table->setEnabled(tablesList->currentItem() != 0);
	actionEdit_Ta_ble->setEnabled(tablesList->currentItem() != 0);
	actionSa_ve_SQL_File->setEnabled(!sqlTextEdit->toPlainText().isEmpty());
}

void AdminWindow::showTableDialog()
{
	showFields(tablesList->currentItem());
	tableDialog->setTableName(tablesList->currentItem()->text());
	tableDialog->setTableModel((SQLiteFieldModel*)fieldsTableView->model());
	tableDialog->show();
}

void AdminWindow::editTable(const QHash<int, SqliteField> fields)
{
// 	qWarning("editTable");
	foreach(SqliteField field, fields)
	{
		switch(field.status)
		{
			case STATUS_MODIFIED:
				qWarning(field.fieldName.toAscii() + " is modified");
				break;
				
			case STATUS_ADDED:
// 				qWarning(field.fieldName.toAscii() + " is added");
				cCore->addTableField(tablesList->currentItem()->text(), &field);
				break;
		}
	}
}