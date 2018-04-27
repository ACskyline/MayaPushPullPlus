/****************************************************************************
** Meta object code from reading C++ file 'gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gui_t {
    QByteArrayData data[62];
    char stringdata[836];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui_t qt_meta_stringdata_gui = {
    {
QT_MOC_LITERAL(0, 0, 3), // "gui"
QT_MOC_LITERAL(1, 4, 10), // "selectFace"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 5), // "Face*"
QT_MOC_LITERAL(4, 22, 4), // "item"
QT_MOC_LITERAL(5, 27, 14), // "selectHalfEdge"
QT_MOC_LITERAL(6, 42, 9), // "HalfEdge*"
QT_MOC_LITERAL(7, 52, 12), // "selectVertex"
QT_MOC_LITERAL(8, 65, 7), // "Vertex*"
QT_MOC_LITERAL(9, 73, 9), // "splitEdge"
QT_MOC_LITERAL(10, 83, 15), // "triangulateFace"
QT_MOC_LITERAL(11, 99, 9), // "subdivide"
QT_MOC_LITERAL(12, 109, 7), // "extrude"
QT_MOC_LITERAL(13, 117, 9), // "bevelEdge"
QT_MOC_LITERAL(14, 127, 8), // "changeFR"
QT_MOC_LITERAL(15, 136, 1), // "r"
QT_MOC_LITERAL(16, 138, 8), // "changeFG"
QT_MOC_LITERAL(17, 147, 1), // "g"
QT_MOC_LITERAL(18, 149, 8), // "changeFB"
QT_MOC_LITERAL(19, 158, 1), // "b"
QT_MOC_LITERAL(20, 160, 8), // "changeVX"
QT_MOC_LITERAL(21, 169, 1), // "x"
QT_MOC_LITERAL(22, 171, 8), // "changeVY"
QT_MOC_LITERAL(23, 180, 1), // "y"
QT_MOC_LITERAL(24, 182, 8), // "changeVZ"
QT_MOC_LITERAL(25, 191, 1), // "z"
QT_MOC_LITERAL(26, 193, 10), // "pushPullPP"
QT_MOC_LITERAL(27, 204, 9), // "glm::vec3"
QT_MOC_LITERAL(28, 214, 1), // "d"
QT_MOC_LITERAL(29, 216, 5), // "theta"
QT_MOC_LITERAL(30, 222, 1), // "p"
QT_MOC_LITERAL(31, 224, 1), // "n"
QT_MOC_LITERAL(32, 226, 23), // "on_faceList_itemClicked"
QT_MOC_LITERAL(33, 250, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(34, 267, 27), // "on_halfEdgeList_itemClicked"
QT_MOC_LITERAL(35, 295, 25), // "on_vertexList_itemClicked"
QT_MOC_LITERAL(36, 321, 26), // "on_splitEdgeButton_clicked"
QT_MOC_LITERAL(37, 348, 32), // "on_triangulateFaceButton_clicked"
QT_MOC_LITERAL(38, 381, 26), // "on_subdivideButton_clicked"
QT_MOC_LITERAL(39, 408, 24), // "on_extrudeButton_clicked"
QT_MOC_LITERAL(40, 433, 26), // "on_bevelEdgeButton_clicked"
QT_MOC_LITERAL(41, 460, 30), // "on_rDoubleSpinBox_valueChanged"
QT_MOC_LITERAL(42, 491, 4), // "arg1"
QT_MOC_LITERAL(43, 496, 30), // "on_gDoubleSpinBox_valueChanged"
QT_MOC_LITERAL(44, 527, 30), // "on_bDoubleSpinBox_valueChanged"
QT_MOC_LITERAL(45, 558, 30), // "on_xDoubleSpinBox_valueChanged"
QT_MOC_LITERAL(46, 589, 30), // "on_yDoubleSpinBox_valueChanged"
QT_MOC_LITERAL(47, 620, 30), // "on_zDoubleSpinBox_valueChanged"
QT_MOC_LITERAL(48, 651, 27), // "on_pushPullPPButton_clicked"
QT_MOC_LITERAL(49, 679, 17), // "slot_setClickFace"
QT_MOC_LITERAL(50, 697, 1), // "f"
QT_MOC_LITERAL(51, 699, 21), // "slot_setClickHalfEdge"
QT_MOC_LITERAL(52, 721, 1), // "h"
QT_MOC_LITERAL(53, 723, 19), // "slot_setClickVertex"
QT_MOC_LITERAL(54, 743, 1), // "v"
QT_MOC_LITERAL(55, 745, 15), // "slot_updateList"
QT_MOC_LITERAL(56, 761, 21), // "std::vector<Vertex*>&"
QT_MOC_LITERAL(57, 783, 2), // "vV"
QT_MOC_LITERAL(58, 786, 23), // "std::vector<HalfEdge*>&"
QT_MOC_LITERAL(59, 810, 2), // "hV"
QT_MOC_LITERAL(60, 813, 19), // "std::vector<Face*>&"
QT_MOC_LITERAL(61, 833, 2) // "fV"

    },
    "gui\0selectFace\0\0Face*\0item\0selectHalfEdge\0"
    "HalfEdge*\0selectVertex\0Vertex*\0splitEdge\0"
    "triangulateFace\0subdivide\0extrude\0"
    "bevelEdge\0changeFR\0r\0changeFG\0g\0"
    "changeFB\0b\0changeVX\0x\0changeVY\0y\0"
    "changeVZ\0z\0pushPullPP\0glm::vec3\0d\0"
    "theta\0p\0n\0on_faceList_itemClicked\0"
    "QListWidgetItem*\0on_halfEdgeList_itemClicked\0"
    "on_vertexList_itemClicked\0"
    "on_splitEdgeButton_clicked\0"
    "on_triangulateFaceButton_clicked\0"
    "on_subdivideButton_clicked\0"
    "on_extrudeButton_clicked\0"
    "on_bevelEdgeButton_clicked\0"
    "on_rDoubleSpinBox_valueChanged\0arg1\0"
    "on_gDoubleSpinBox_valueChanged\0"
    "on_bDoubleSpinBox_valueChanged\0"
    "on_xDoubleSpinBox_valueChanged\0"
    "on_yDoubleSpinBox_valueChanged\0"
    "on_zDoubleSpinBox_valueChanged\0"
    "on_pushPullPPButton_clicked\0"
    "slot_setClickFace\0f\0slot_setClickHalfEdge\0"
    "h\0slot_setClickVertex\0v\0slot_updateList\0"
    "std::vector<Vertex*>&\0vV\0"
    "std::vector<HalfEdge*>&\0hV\0"
    "std::vector<Face*>&\0fV"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  184,    2, 0x06 /* Public */,
       5,    1,  187,    2, 0x06 /* Public */,
       7,    1,  190,    2, 0x06 /* Public */,
       9,    0,  193,    2, 0x06 /* Public */,
      10,    0,  194,    2, 0x06 /* Public */,
      11,    0,  195,    2, 0x06 /* Public */,
      12,    0,  196,    2, 0x06 /* Public */,
      13,    0,  197,    2, 0x06 /* Public */,
      14,    1,  198,    2, 0x06 /* Public */,
      16,    1,  201,    2, 0x06 /* Public */,
      18,    1,  204,    2, 0x06 /* Public */,
      20,    1,  207,    2, 0x06 /* Public */,
      22,    1,  210,    2, 0x06 /* Public */,
      24,    1,  213,    2, 0x06 /* Public */,
      26,    4,  216,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      32,    1,  225,    2, 0x08 /* Private */,
      34,    1,  228,    2, 0x08 /* Private */,
      35,    1,  231,    2, 0x08 /* Private */,
      36,    0,  234,    2, 0x08 /* Private */,
      37,    0,  235,    2, 0x08 /* Private */,
      38,    0,  236,    2, 0x08 /* Private */,
      39,    0,  237,    2, 0x08 /* Private */,
      40,    0,  238,    2, 0x08 /* Private */,
      41,    1,  239,    2, 0x08 /* Private */,
      43,    1,  242,    2, 0x08 /* Private */,
      44,    1,  245,    2, 0x08 /* Private */,
      45,    1,  248,    2, 0x08 /* Private */,
      46,    1,  251,    2, 0x08 /* Private */,
      47,    1,  254,    2, 0x08 /* Private */,
      48,    0,  257,    2, 0x08 /* Private */,
      49,    1,  258,    2, 0x0a /* Public */,
      51,    1,  261,    2, 0x0a /* Public */,
      53,    1,  264,    2, 0x0a /* Public */,
      55,    3,  267,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Double,   25,
    QMetaType::Void, 0x80000000 | 27, QMetaType::Float, 0x80000000 | 27, 0x80000000 | 27,   28,   29,   30,   31,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 33,    4,
    QMetaType::Void, 0x80000000 | 33,    4,
    QMetaType::Void, 0x80000000 | 33,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   42,
    QMetaType::Void, QMetaType::Double,   42,
    QMetaType::Void, QMetaType::Double,   42,
    QMetaType::Void, QMetaType::Double,   42,
    QMetaType::Void, QMetaType::Double,   42,
    QMetaType::Void, QMetaType::Double,   42,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   50,
    QMetaType::Void, 0x80000000 | 6,   52,
    QMetaType::Void, 0x80000000 | 8,   54,
    QMetaType::Void, 0x80000000 | 56, 0x80000000 | 58, 0x80000000 | 60,   57,   59,   61,

       0        // eod
};

void gui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gui *_t = static_cast<gui *>(_o);
        switch (_id) {
        case 0: _t->selectFace((*reinterpret_cast< Face*(*)>(_a[1]))); break;
        case 1: _t->selectHalfEdge((*reinterpret_cast< HalfEdge*(*)>(_a[1]))); break;
        case 2: _t->selectVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 3: _t->splitEdge(); break;
        case 4: _t->triangulateFace(); break;
        case 5: _t->subdivide(); break;
        case 6: _t->extrude(); break;
        case 7: _t->bevelEdge(); break;
        case 8: _t->changeFR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->changeFG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->changeFB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->changeVX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->changeVY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->changeVZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->pushPullPP((*reinterpret_cast< glm::vec3(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< glm::vec3(*)>(_a[3])),(*reinterpret_cast< glm::vec3(*)>(_a[4]))); break;
        case 15: _t->on_faceList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 16: _t->on_halfEdgeList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 17: _t->on_vertexList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 18: _t->on_splitEdgeButton_clicked(); break;
        case 19: _t->on_triangulateFaceButton_clicked(); break;
        case 20: _t->on_subdivideButton_clicked(); break;
        case 21: _t->on_extrudeButton_clicked(); break;
        case 22: _t->on_bevelEdgeButton_clicked(); break;
        case 23: _t->on_rDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->on_gDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->on_bDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->on_xDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->on_yDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->on_zDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->on_pushPullPPButton_clicked(); break;
        case 30: _t->slot_setClickFace((*reinterpret_cast< Face*(*)>(_a[1]))); break;
        case 31: _t->slot_setClickHalfEdge((*reinterpret_cast< HalfEdge*(*)>(_a[1]))); break;
        case 32: _t->slot_setClickVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 33: _t->slot_updateList((*reinterpret_cast< std::vector<Vertex*>(*)>(_a[1])),(*reinterpret_cast< std::vector<HalfEdge*>(*)>(_a[2])),(*reinterpret_cast< std::vector<Face*>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gui::*_t)(Face * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::selectFace)) {
                *result = 0;
            }
        }
        {
            typedef void (gui::*_t)(HalfEdge * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::selectHalfEdge)) {
                *result = 1;
            }
        }
        {
            typedef void (gui::*_t)(Vertex * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::selectVertex)) {
                *result = 2;
            }
        }
        {
            typedef void (gui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::splitEdge)) {
                *result = 3;
            }
        }
        {
            typedef void (gui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::triangulateFace)) {
                *result = 4;
            }
        }
        {
            typedef void (gui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::subdivide)) {
                *result = 5;
            }
        }
        {
            typedef void (gui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::extrude)) {
                *result = 6;
            }
        }
        {
            typedef void (gui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::bevelEdge)) {
                *result = 7;
            }
        }
        {
            typedef void (gui::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::changeFR)) {
                *result = 8;
            }
        }
        {
            typedef void (gui::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::changeFG)) {
                *result = 9;
            }
        }
        {
            typedef void (gui::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::changeFB)) {
                *result = 10;
            }
        }
        {
            typedef void (gui::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::changeVX)) {
                *result = 11;
            }
        }
        {
            typedef void (gui::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::changeVY)) {
                *result = 12;
            }
        }
        {
            typedef void (gui::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::changeVZ)) {
                *result = 13;
            }
        }
        {
            typedef void (gui::*_t)(glm::vec3 , float , glm::vec3 , glm::vec3 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gui::pushPullPP)) {
                *result = 14;
            }
        }
    }
}

const QMetaObject gui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gui.data,
      qt_meta_data_gui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gui.stringdata))
        return static_cast<void*>(const_cast< gui*>(this));
    return QWidget::qt_metacast(_clname);
}

int gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void gui::selectFace(Face * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gui::selectHalfEdge(HalfEdge * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void gui::selectVertex(Vertex * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void gui::splitEdge()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void gui::triangulateFace()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void gui::subdivide()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void gui::extrude()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void gui::bevelEdge()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void gui::changeFR(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void gui::changeFG(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void gui::changeFB(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void gui::changeVX(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void gui::changeVY(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void gui::changeVZ(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void gui::pushPullPP(glm::vec3 _t1, float _t2, glm::vec3 _t3, glm::vec3 _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_END_MOC_NAMESPACE
