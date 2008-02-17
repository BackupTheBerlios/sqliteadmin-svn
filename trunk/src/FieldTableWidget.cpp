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
#include <QMouseEvent>
#include <QComboBox>
#include "TypeComboBox.h"
#include "FieldTableWidget.h"
#include "SQLiteDefs.h"

FieldTableWidget::FieldTableWidget(QWidget *parent) : QTableWidget(parent)
{
	setHorizontalHeaderItem(NAME_COL,new QTableWidgetItem(tr("Name")));
	setHorizontalHeaderItem(TYPE_COL,new QTableWidgetItem(tr("Type")));
	setHorizontalHeaderItem(LENGTH_COL,new QTableWidgetItem(tr("Length")));
	setHorizontalHeaderItem(PRECISION_COL,new QTableWidgetItem(tr("Precision")));
	setHorizontalHeaderItem(REQUIRED_COL,new QTableWidgetItem(tr("Required")));
	setHorizontalHeaderItem(AUTO_COL,new QTableWidgetItem(tr("Auto")));
	setHorizontalHeaderItem(DEFAULT_COL,new QTableWidgetItem(tr("Default Value")));
	connect( this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(itemEdit(QTableWidgetItem*)) );
	connect( this, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(cellActivate(QTableWidgetItem*)) );
}

void FieldTableWidget::addFieldRow()
{
	TypeComboBox *typeCombo = new TypeComboBox(this);
	QComboBox *autoCombo = new QComboBox(this);
	QComboBox *requiredCombo = new QComboBox(this);
	
	autoCombo->insertItem(0, tr("true"));
	autoCombo->insertItem(1, tr("false"));
	
	requiredCombo->insertItem(0, tr("true"));
	requiredCombo->insertItem(1, tr("false"));
	
	insertRow(rowCount());
	
	setCellWidget(rowCount() - 1, TYPE_COL, typeCombo);
	setCellWidget(rowCount() - 1, AUTO_COL, autoCombo);
	setCellWidget(rowCount() - 1, REQUIRED_COL, requiredCombo);
}

void FieldTableWidget::itemEdit(QTableWidgetItem *item)
{
	emit itemChanged(item->row(), item->column(), item->text());
}

void FieldTableWidget::cellActivate(QTableWidgetItem *item)
{
	switch(item->column())
	{
		case TYPE_COL:
			TypeComboBox *typeCombo = new TypeComboBox(this);
			setCellWidget(item->row(), item->column(), typeCombo);
			typeCombo->setCurrentIndex(typeCombo->findText(item->text()));
			break;
			
		case AUTO_COL:
		case REQUIRED_COL:
			QComboBox *boolCombo = new QComboBox(this);
			boolCombo->insertItem(0, tr("true"));
			boolCombo->insertItem(1, tr("false"));
			setCellWidget(item->row(), item->column(), boolCombo);
			boolCombo->setCurrentIndex(boolCombo->findText(item->text()));
			break;
			
		default:
			qWarning("Column: " + QString::number(item->column()).toAscii());
	}
}