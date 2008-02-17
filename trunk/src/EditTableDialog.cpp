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

#include <QToolBar>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QCloseEvent>
#include "EditTableDialog.h"
#include "SQLiteFieldModel.h"


EditTableDialog::EditTableDialog( QWidget *parent, Qt::WindowFlags f ) : QDialog ( parent, f )
{
	setupUi( this );
// 	fieldsTableView->setDragEnabled(TRUE);
	connectWidgets();
}

void EditTableDialog::connectWidgets()
{
	connect( fieldsTableView, SIGNAL(itemSelectionChanged()), this, SLOT(updateButtonStatus()) );
	connect( addFieldButton, SIGNAL(clicked()), this, SLOT(addTableField()) );
	connect( fieldsTableView, SIGNAL(itemChanged(int, int, const QString&)), this, SLOT(notifyItemChanged(int, int, const QString&)) );
	connect( this, SIGNAL(finished(int)), this, SLOT(close(int)) );
}

void EditTableDialog::updateButtonStatus()
{
	addFieldButton->setEnabled ( !tableNameLineEdit->text().isEmpty() );
	removeFieldButton->setEnabled ( fieldsTableView->currentIndex().isValid() );
}

void EditTableDialog::setTableName ( const QString &tableName )
{
	tableNameLineEdit->setText ( tableName );
}

void EditTableDialog::setTableModel ( SQLiteFieldModel *model )
{
	fieldsTableView->setEditTriggers ( QAbstractItemView::DoubleClicked | QAbstractItemView::AnyKeyPressed );
	fieldsTableView->setRowCount(0);
	fields.clear();
	for ( int i = 0; i < model->rowCount(); i++ )
	{
		SqliteField fieldStruct;
		
		fieldsTableView->insertRow(i);
		
		fieldStruct.fieldName = model->item( i,0 )->text();
		QTableWidgetItem *fieldData = new QTableWidgetItem(fieldStruct.fieldName);
		fieldsTableView->setItem(i, 0, fieldData);
		
		fieldStruct.fieldType = model->item( i,1 )->text();
		fieldData = new QTableWidgetItem(fieldStruct.fieldType);
		fieldsTableView->setItem(i, 1, fieldData);
		
		fieldStruct.fieldLength = model->item( i,2 )->text().toInt();
		fieldData = new QTableWidgetItem(model->item( i,2 )->text());
		fieldsTableView->setItem(i, 2, fieldData);
		
		fieldStruct.fieldPrecision = model->item( i,3 )->text().toInt();
		fieldData = new QTableWidgetItem(model->item( i,3 )->text());
		fieldsTableView->setItem(i, 3, fieldData);
		
		fieldStruct.fieldRequired = QVariant( model->item( i,4 )->text() ).toBool();
		fieldData = new QTableWidgetItem(model->item( i,4 )->text());
		fieldsTableView->setItem(i, 4, fieldData);
		
		fieldStruct.fieldAuto = QVariant( model->item( i,5 )->text() ).toBool();
		fieldData = new QTableWidgetItem(model->item( i,5 )->text());
		fieldsTableView->setItem(i, 5, fieldData);
		
		fieldStruct.fieldDefaultValue = QVariant( model->item( i,6 )->text() );
		fieldData = new QTableWidgetItem(model->item( i,6 )->text());
		fieldsTableView->setItem(i, 6, fieldData);
		
		fieldStruct.status = STATUS_UNMODIFIED;
		fieldStruct.index = i;
		fields[i] = fieldStruct;
	}
}

FieldTableWidget* EditTableDialog::fieldTable()
{
	return fieldsTableView;
}

void EditTableDialog::addTableField()
{
	SqliteField fieldStruct;
	fieldStruct.status = STATUS_ADDED;
	fieldStruct.index = fieldsTableView->rowCount();
	fields[fieldsTableView->rowCount()] = fieldStruct;
	
// 	fieldsTableView->insertRow(fieldsTableView->rowCount());
	fieldsTableView->addFieldRow();
}

void EditTableDialog::notifyItemChanged(int row, int col, const QString &text)
{
	if (fields[row].status == STATUS_ADDED || (!fields[row].fieldName.isEmpty() && !text.isEmpty() && text != fields[row].fieldName))
	{
		switch(col)
		{
			case NAME_COL:
				fields[row].fieldName =  text;
				break;
				
			case TYPE_COL:
				fields[row].fieldType =  text;
				break;
				
			case LENGTH_COL:
				fields[row].fieldLength =  text.toInt();
				break;
				
			case PRECISION_COL:
				fields[row].fieldPrecision =  text.toInt();
				break;
				
			case REQUIRED_COL:
				fields[row].fieldRequired =  QVariant(text).toBool();
				break;
				
			case AUTO_COL:
				fields[row].fieldAuto =  QVariant(text).toBool();
				break;
						
			case DEFAULT_COL:
				fields[row].fieldDefaultValue =  QVariant(text);
				break;
				
			default:
				return;
		}
		
		switch(fields[row].status)
		{
			case STATUS_UNMODIFIED:
				fields[row].status = STATUS_MODIFIED;
				break;
		}
	}
}

void EditTableDialog::closeEvent(QCloseEvent *evt)
{
	qWarning("Close");
	evt->accept();
}

void EditTableDialog::close(int result)
{
	if (result == QDialog::Accepted)
		emit sqliteFields(fields);
}