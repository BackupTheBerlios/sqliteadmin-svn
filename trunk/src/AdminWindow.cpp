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
		
AdminWindow::AdminWindow(QWidget *parent, Qt::WFlags flags) : QMainWindow(parent, flags)
{
	setupUi(this);
	mainSplitter->setStretchFactor(1,1);
	rightSplitter->setStretchFactor(1,1);
	cCore = new ConnectionCore(this);
// 	tablesList->setContextMenuPolicy(Qt::CustomContextMenu);
	connectWidgets();
}

void AdminWindow::connectWidgets()
{
	connect( action_Open, SIGNAL(triggered()), this, SLOT(dbFileOpen()) );
	connect( action_Quit, SIGNAL(triggered()), this, SLOT(close()) );
	connect( actionC_lose, SIGNAL(triggered()), this, SLOT(closeDatabase()) );
	connect( actionOpen_SQL_File, SIGNAL(triggered()), this, SLOT(sqlFileOpen()) );

	connect( this, SIGNAL(sqlFileSelected(const QString &)), this, SLOT(openSqlFileNotification(const QString &)) );
	connect( this, SIGNAL(dbFileSelected(const QString&)), cCore, SLOT(addConnection( const QString& )) );
	connect( this, SIGNAL(dropTable(const QString&)), cCore, SLOT(dropTable(const QString&)) );
	
	connect( cCore, SIGNAL(databaseOpened( const QSqlError& )), this, SLOT(openDatabaseNotification( const QSqlError& )) );
	connect( cCore, SIGNAL(databaseError(const QSqlError &)), this, SLOT(sqlError(const QSqlError&)) );
	
	connect( tablesList, SIGNAL(itemActivated(QListWidgetItem *)), this, SLOT(showTable( QListWidgetItem* )) );
	connect( tablesList, SIGNAL(itemActivated(QListWidgetItem *)), this, SLOT(showFields( QListWidgetItem* )) );
 	connect( tablesList, SIGNAL(dropTable(const QString&)), this, SLOT(dropTableRequest(const QString &)) );
	
	connect( sqlTextEdit, SIGNAL(textChanged()), this, SLOT(updateSqlButtons()) );
	
	connect( historyList, SIGNAL(itemSelectionChanged()), this, SLOT(updateHistoryButtons()) );
	connect( historyList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(historyItemSelected(QListWidgetItem*)) );
	
	connect( runSqlButton, SIGNAL(clicked()), this, SLOT(runQuery()) );
	connect( saveSqlButton, SIGNAL(clicked()), this, SLOT(sqlFileSave()) );
// 	connect( cCore, SIGNAL(executedQuery( QSqlQuery* )), this, SLOT(queryResults( QSqlQuery* )) );
	connect( cCore, SIGNAL(executedQuery( QSqlQueryModel* )), this, SLOT(queryResults( QSqlQueryModel* )) );
	
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
	 QStandardItemModel *model = new QStandardItemModel(fieldsTableView);
	
	 model->insertRows(0, rec.count());
	 model->insertColumns(0, 7);
	
	 model->setHeaderData(0, Qt::Horizontal, "Fieldname");
	 model->setHeaderData(1, Qt::Horizontal, "Type");
	 model->setHeaderData(2, Qt::Horizontal, "Length");
	 model->setHeaderData(3, Qt::Horizontal, "Precision");
	 model->setHeaderData(4, Qt::Horizontal, "Required");
	 model->setHeaderData(5, Qt::Horizontal, "AutoValue");
	 model->setHeaderData(6, Qt::Horizontal, "DefaultValue");
	
	
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
	 
    int height = fieldsTableView->fontMetrics().height();
    fieldsTableView->verticalHeader()->setDefaultSectionSize(height); 
	 
	 fieldsTableView->setModel(model);
    fieldsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

void AdminWindow::dropTableRequest( const QString &tableName )
{
	if (QMessageBox::question(this, tr("Drop Table"), tr("Are you sure you want to DROP table %1").arg(tableName), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Ok)
	{
		emit dropTable(tableName);
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