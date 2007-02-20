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

#ifndef TABLELISTWIDGET_H
#define TABLELISTWIDGET_H

#include <QListWidget>

class QMenu;

class TableListWidget : public QListWidget
{
	Q_OBJECT
	public:
		TableListWidget(QWidget *);
		void contextMenuEvent(QContextMenuEvent *);
		QMenu* menu();
	
	public slots:
	void editActionTriggered();
	void showActionTriggered();
	void dropActionTriggered();
	void tableCopyActionTriggered();
		
	signals:
		void editTable(const QString &);
		void showTableSchema(const QString &);
		void dropTable(const QString &);
		void copyTable(const QString&);
		
	private:
		QMenu *popupMenu;
};
#endif