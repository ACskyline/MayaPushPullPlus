/****************************************************************************
** Meta object code from reading C++ file 'gui2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gui2_t {
    QByteArrayData data[33];
    char stringdata[407];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui2_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui2_t qt_meta_stringdata_gui2 = {
    {
QT_MOC_LITERAL(0, 0, 4), // "gui2"
QT_MOC_LITERAL(1, 5, 11), // "selectJoint"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 6), // "Joint*"
QT_MOC_LITERAL(4, 25, 1), // "j"
QT_MOC_LITERAL(5, 27, 4), // "rotX"
QT_MOC_LITERAL(6, 32, 4), // "rotY"
QT_MOC_LITERAL(7, 37, 4), // "rotZ"
QT_MOC_LITERAL(8, 42, 4), // "skin"
QT_MOC_LITERAL(9, 47, 8), // "changeJX"
QT_MOC_LITERAL(10, 56, 1), // "x"
QT_MOC_LITERAL(11, 58, 8), // "changeJY"
QT_MOC_LITERAL(12, 67, 1), // "Y"
QT_MOC_LITERAL(13, 69, 8), // "changeJZ"
QT_MOC_LITERAL(14, 78, 1), // "Z"
QT_MOC_LITERAL(15, 80, 18), // "slot_setClickJoint"
QT_MOC_LITERAL(16, 99, 15), // "slot_updateTree"
QT_MOC_LITERAL(17, 115, 8), // "Skeleton"
QT_MOC_LITERAL(18, 124, 1), // "s"
QT_MOC_LITERAL(19, 126, 18), // "slot_setSkinButton"
QT_MOC_LITERAL(20, 145, 8), // "_skinned"
QT_MOC_LITERAL(21, 154, 33), // "on_skeletonTreeWidget_itemCli..."
QT_MOC_LITERAL(22, 188, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(23, 205, 4), // "item"
QT_MOC_LITERAL(24, 210, 6), // "column"
QT_MOC_LITERAL(25, 217, 21), // "on_rotXButton_clicked"
QT_MOC_LITERAL(26, 239, 21), // "on_rotYButton_clicked"
QT_MOC_LITERAL(27, 261, 21), // "on_rotZButton_clicked"
QT_MOC_LITERAL(28, 283, 25), // "on_skinningButton_clicked"
QT_MOC_LITERAL(29, 309, 30), // "on_xDoubleSpinBox_valueChanged"
QT_MOC_LITERAL(30, 340, 4), // "arg1"
QT_MOC_LITERAL(31, 345, 30), // "on_yDoubleSpinBox_valueChanged"
QT_MOC_LITERAL(32, 376, 30) // "on_zDoubleSpinBox_valueChanged"

    },
    "gui2\0selectJoint\0\0Joint*\0j\0rotX\0rotY\0"
    "rotZ\0skin\0changeJX\0x\0changeJY\0Y\0"
    "changeJZ\0Z\0slot_setClickJoint\0"
    "slot_updateTree\0Skeleton\0s\0"
    "slot_setSkinButton\0_skinned\0"
    "on_skeletonTreeWidget_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_rotXButton_clicked\0on_rotYButton_clicked\0"
    "on_rotZButton_clicked\0on_skinningButton_clicked\0"
    "on_xDoubleSpinBox_valueChanged\0arg1\0"
    "on_yDoubleSpinBox_valueChanged\0"
    "on_zDoubleSpinBox_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       5,    0,  112,    2, 0x06 /* Public */,
       6,    0,  113,    2, 0x06 /* Public */,
       7,    0,  114,    2, 0x06 /* Public */,
       8,    0,  115,    2, 0x06 /* Public */,
       9,    1,  116,    2, 0x06 /* Public */,
      11,    1,  119,    2, 0x06 /* Public */,
      13,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  125,    2, 0x0a /* Public */,
      16,    1,  128,    2, 0x0a /* Public */,
      19,    1,  131,    2, 0x0a /* Public */,
      21,    2,  134,    2, 0x08 /* Private */,
      25,    0,  139,    2, 0x08 /* Private */,
      26,    0,  140,    2, 0x08 /* Private */,
      27,    0,  141,    2, 0x08 /* Private */,
      28,    0,  142,    2, 0x08 /* Private */,
      29,    1,  143,    2, 0x08 /* Private */,
      31,    1,  146,    2, 0x08 /* Private */,
      32,    1,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, 0x80000000 | 22, QMetaType::Int,   23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Double,   30,

       0        // eod
};

void gui2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gui2 *_t = static_cast<gui2 *>(_o);
        switch (_id) {
        case 0: _t->selectJoint((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 1: _t->rotX(); break;
        case 2: _t->rotY(); break;
        case 3: _t->rotZ(); break;
        case 4: _t->skin(); break;
        case 5: _t->changeJX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->changeJY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->changeJZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->slot_setClickJoint((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 9: _t->slot_updateTree((*reinterpret_cast< const Skeleton(*)>(_a[1]))); break;
        case 10: _t->slot_setSkinButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_skeletonTreeWidget_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->on_rotXButton_clicked(); break;
        case 13: _t->on_rotYButton_clicked(); break;
        case 14: _t->on_rotZButton_clicked(); break;
        case 15: _t->on_skinningButton_clicked(); break;
        case 16: _t->on_xDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->on_yDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->on_zDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gui2::*_t)(Joint * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui2::selectJoint)) {
                *result = 0;
            }
        }
        {
            typedef void (gui2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui2::rotX)) {
                *result = 1;
            }
        }
        {
            typedef void (gui2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui2::rotY)) {
                *result = 2;
            }
        }
        {
            typedef void (gui2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui2::rotZ)) {
                *result = 3;
            }
        }
        {
            typedef void (gui2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui2::skin)) {
                *result = 4;
            }
        }
        {
            typedef void (gui2::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui2::changeJX)) {
                *result = 5;
            }
        }
        {
            typedef void (gui2::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui2::changeJY)) {
                *result = 6;
            }
        }
        {
            typedef void (gui2::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui2::changeJZ)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject gui2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gui2.data,
      qt_meta_data_gui2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gui2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gui2.stringdata))
        return static_cast<void*>(const_cast< gui2*>(this));
    return QWidget::qt_metacast(_clname);
}

int gui2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void gui2::selectJoint(Joint * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gui2::rotX()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void gui2::rotY()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void gui2::rotZ()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void gui2::skin()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void gui2::changeJX(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void gui2::changeJY(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void gui2::changeJZ(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
