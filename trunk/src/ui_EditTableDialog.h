/********************************************************************************
** Form generated from reading ui file 'EditTableDialog.ui'
**
** Created: Sat May 5 19:16:01 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef EDITTABLEDIALOG_H
#define EDITTABLEDIALOG_H

#include "FieldTableWidget.h"
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

class Ui_EditTableDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QLineEdit *tableNameLineEdit;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QLabel *label_2;
    QSpacerItem *spacerItem;
    QPushButton *addFieldButton;
    QPushButton *removeFieldButton;
    FieldTableWidget *fieldsTableView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditTableDialog)
    {
    EditTableDialog->setObjectName(QString::fromUtf8("EditTableDialog"));
    EditTableDialog->setWindowModality(Qt::WindowModal);
    gridLayout = new QGridLayout(EditTableDialog);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(EditTableDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    vboxLayout->addWidget(label);

    tableNameLineEdit = new QLineEdit(groupBox);
    tableNameLineEdit->setObjectName(QString::fromUtf8("tableNameLineEdit"));

    vboxLayout->addWidget(tableNameLineEdit);


    gridLayout1->addLayout(vboxLayout, 0, 0, 1, 1);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    hboxLayout->addWidget(label_2);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    addFieldButton = new QPushButton(groupBox);
    addFieldButton->setObjectName(QString::fromUtf8("addFieldButton"));
    addFieldButton->setIcon(QIcon(QString::fromUtf8(":/icons/icons/edit_add.png")));

    hboxLayout->addWidget(addFieldButton);

    removeFieldButton = new QPushButton(groupBox);
    removeFieldButton->setObjectName(QString::fromUtf8("removeFieldButton"));
    removeFieldButton->setEnabled(false);
    removeFieldButton->setIcon(QIcon(QString::fromUtf8(":/icons/icons/editdelete.png")));

    hboxLayout->addWidget(removeFieldButton);


    vboxLayout1->addLayout(hboxLayout);


    gridLayout1->addLayout(vboxLayout1, 1, 0, 1, 1);

    fieldsTableView = new FieldTableWidget(groupBox);
    fieldsTableView->setObjectName(QString::fromUtf8("fieldsTableView"));
    fieldsTableView->setDragEnabled(false);
    fieldsTableView->setDragDropOverwriteMode(false);
    fieldsTableView->setDragDropMode(QAbstractItemView::DragDrop);
    fieldsTableView->setAlternatingRowColors(true);
    fieldsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    gridLayout1->addWidget(fieldsTableView, 2, 0, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    buttonBox = new QDialogButtonBox(EditTableDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

    label->setBuddy(tableNameLineEdit);
    label_2->setBuddy(fieldsTableView);

    retranslateUi(EditTableDialog);

    QSize size(757, 406);
    size = size.expandedTo(EditTableDialog->minimumSizeHint());
    EditTableDialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), EditTableDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), EditTableDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(EditTableDialog);
    } // setupUi

    void retranslateUi(QDialog *EditTableDialog)
    {
    EditTableDialog->setWindowTitle(QApplication::translate("EditTableDialog", "Table Edit", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("EditTableDialog", "Table", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("EditTableDialog", "&Name", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("EditTableDialog", "&Fields", 0, QApplication::UnicodeUTF8));
    addFieldButton->setText(QApplication::translate("EditTableDialog", "&Add Field", 0, QApplication::UnicodeUTF8));
    removeFieldButton->setText(QApplication::translate("EditTableDialog", "&Remove Field", 0, QApplication::UnicodeUTF8));
    if (fieldsTableView->columnCount() < 7)
        fieldsTableView->setColumnCount(7);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("EditTableDialog", "Name", 0, QApplication::UnicodeUTF8));
    fieldsTableView->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("EditTableDialog", "Type", 0, QApplication::UnicodeUTF8));
    fieldsTableView->setHorizontalHeaderItem(1, __colItem1);

    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    __colItem2->setText(QApplication::translate("EditTableDialog", "Length", 0, QApplication::UnicodeUTF8));
    fieldsTableView->setHorizontalHeaderItem(2, __colItem2);

    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    __colItem3->setText(QApplication::translate("EditTableDialog", "Precision", 0, QApplication::UnicodeUTF8));
    fieldsTableView->setHorizontalHeaderItem(3, __colItem3);

    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    __colItem4->setText(QApplication::translate("EditTableDialog", "Required", 0, QApplication::UnicodeUTF8));
    fieldsTableView->setHorizontalHeaderItem(4, __colItem4);

    QTableWidgetItem *__colItem5 = new QTableWidgetItem();
    __colItem5->setText(QApplication::translate("EditTableDialog", "Auto", 0, QApplication::UnicodeUTF8));
    fieldsTableView->setHorizontalHeaderItem(5, __colItem5);

    QTableWidgetItem *__colItem6 = new QTableWidgetItem();
    __colItem6->setText(QApplication::translate("EditTableDialog", "Default Value", 0, QApplication::UnicodeUTF8));
    fieldsTableView->setHorizontalHeaderItem(6, __colItem6);
    Q_UNUSED(EditTableDialog);
    } // retranslateUi

};

namespace Ui {
    class EditTableDialog: public Ui_EditTableDialog {};
} // namespace Ui

#endif // EDITTABLEDIALOG_H
