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

#ifndef EDIT_TABLEDIALOG_H
#define EDIT_TABLEDIALOG_H
		
#include <QDialog>
#include <QHash>
#include "ui_EditTableDialog.h"
#include "SQLiteDefs.h"
		
class QStandardItemModel;
class FieldTableWidget;
class SQLiteFieldModel;


class EditTableDialog : public QDialog, public Ui::EditTableDialog
{
	Q_OBJECT
	public:
		EditTableDialog(QWidget *parent = 0, Qt::WindowFlags f = 0 );
		void setTableName(const QString &);
		FieldTableWidget* fieldTable();
		
	protected:
		void closeEvent(QCloseEvent*);
		
	public slots:
		void setTableModel(SQLiteFieldModel *);
		
	protected slots:
		void connectWidgets();
		void updateButtonStatus();
		void addTableField();
		void notifyItemChanged(int, int, const QString&);

	private slots:
		void close(int);
		
	signals:
		void sqliteFields(const QHash<int, SqliteField>);
		
	private:
		QHash<int, SqliteField> fields;
		bool modified;
};
#endif