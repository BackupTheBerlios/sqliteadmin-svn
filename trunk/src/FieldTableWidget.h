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
#ifndef FIELDTABLEWIDGET_H
#define FIELDTABLEWIDGET_H
		
#define NAME_COL 0
#define TYPE_COL 1
#define LENGTH_COL 2
#define PRECISION_COL 3
#define REQUIRED_COL 4
#define AUTO_COL 5
#define DEFAULT_COL 6
		
#include <QTableWidget>
		
class FieldTableWidget : public QTableWidget
{
	Q_OBJECT
	public:
		FieldTableWidget(QWidget *parent = 0);
		void addFieldRow();
		
	private slots:
		void itemEdit(QTableWidgetItem*);
		void cellActivate(QTableWidgetItem*);
		
	signals:
		void itemChanged(int, int, const QString&);
};
#endif