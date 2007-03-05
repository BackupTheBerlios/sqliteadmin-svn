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
#include <QMenu>
#include <QContextMenuEvent>
#include <QSignalMapper>
#include <QPoint>
#include "TableListWidget.h"

TableListWidget::TableListWidget(QWidget *parent = 0) : QListWidget(parent)
{
	popupMenu = new QMenu(this);
// 	connect( popupMenu->addAction(tr("&Edit Table Schema")), SIGNAL(triggered()), this, SLOT(editActionTriggered()) );
// 	connect( popupMenu->addAction(tr("&Show Table SQL")), SIGNAL(triggered()), this, SLOT(showActionTriggered()) );
// 	connect( popupMenu->addAction(tr("&Copy Table Schema")), SIGNAL(triggered()), this, SLOT(tableCopyActionTriggered()) );
// 	popupMenu->addSeparator();
// 	connect( popupMenu->addAction(tr("&Drop Table")), SIGNAL(triggered()), this, SLOT(dropActionTriggered()) );
}

void TableListWidget::contextMenuEvent( QContextMenuEvent *event)
{
	if (this->itemAt(event->pos()))
		popupMenu->exec(event->globalPos());

}

QMenu* TableListWidget::menu()
{
	return popupMenu;
}

void TableListWidget::editActionTriggered()
{
	emit editTable( this->currentItem()->text());
}

void TableListWidget::showActionTriggered()
{
	emit showTableSchema( this->currentItem()->text());
}

void TableListWidget::dropActionTriggered()
{
	emit dropTable( this->currentItem()->text());
}

void TableListWidget::tableCopyActionTriggered()
{
	emit copyTable( this->currentItem()->text());
}