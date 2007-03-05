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
#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_MainWindow.h"
#include <QtSql>
		
class ConnectionCore;
		
		
class AdminWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
	public:
		AdminWindow(QWidget *parent = 0, Qt::WFlags = 0);
	
	public slots:
		void openDatabaseNotification(const QSqlError &);
		void openSqlFileNotification(const QString &);
		void updateSqlButtons();
		void updateHistoryButtons();
		void queryResults(QSqlQueryModel*);
		
 	protected slots:
 		void dbFileOpen();
		void sqlFileOpen();
		void sqlFileSave();
		void sqlError(const QSqlError&);
		void showTable(QListWidgetItem *);
		void showFields( QListWidgetItem *);
		void runQuery();
		void closeDatabase();
		void dropTableRequest();
		void historyItemSelected(QListWidgetItem *);
		void updateActionStatus();

		
	signals:
		void dbFileSelected(const QString&);
		void sqlFileSelected(const QString&);
		void tableModel(const QSqlTableModel&);
		void editTable(const QString &);
		void showTableSchema(const QString &);
		void dropTable(const QString &);
		
	protected:
		ConnectionCore *cCore;
		
	private:
		void connectWidgets();
		void updateTablesList();
};

#endif