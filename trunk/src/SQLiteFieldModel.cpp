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
#include "SQLiteFieldModel.h"
		
SQLiteFieldModel::SQLiteFieldModel(QObject *parent) : QStandardItemModel(parent)
{
	this->insertColumns(0, 7);
	
	this->setHeaderData(0, Qt::Horizontal, tr("FieldName"));
	this->setHeaderData(1, Qt::Horizontal, tr("Type"));
	this->setHeaderData(2, Qt::Horizontal, tr("Length"));
	this->setHeaderData(3, Qt::Horizontal, tr("Precision"));
	this->setHeaderData(4, Qt::Horizontal, tr("Required"));
	this->setHeaderData(5, Qt::Horizontal, tr("AutoValue"));
	this->setHeaderData(6, Qt::Horizontal, tr("DefaultValue"));
	
}

QString SQLiteFieldModel::columnTitle(int col) const
{
	return horizontalHeaderItem(col)->text();
}
