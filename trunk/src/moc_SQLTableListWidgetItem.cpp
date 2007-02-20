/****************************************************************************
** Meta object code from reading C++ file 'SQLTableListWidgetItem.h'
**
** Created: Sun Feb 18 03:12:52 2007
**      by: The Qt Meta Object Compiler version 59 (Qt 4.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SQLTableListWidgetItem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SQLTableListWidgetItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_SQLTableListWidgetItem[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SQLTableListWidgetItem[] = {
    "SQLTableListWidgetItem\0\0editTable(QString)\0"
    "editActionTriggered()\0"
};

const QMetaObject SQLTableListWidgetItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SQLTableListWidgetItem,
      qt_meta_data_SQLTableListWidgetItem, 0 }
};

const QMetaObject *SQLTableListWidgetItem::metaObject() const
{
    return &staticMetaObject;
}

void *SQLTableListWidgetItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SQLTableListWidgetItem))
	return static_cast<void*>(const_cast<SQLTableListWidgetItem*>(this));
    if (!strcmp(_clname, "QListWidgetItem"))
	return static_cast<QListWidgetItem*>(const_cast<SQLTableListWidgetItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int SQLTableListWidgetItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: editTable((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: editActionTriggered(); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SQLTableListWidgetItem::editTable(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
