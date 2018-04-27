/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[57];
    char stringdata[595];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 12), // "setClickFace"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "Face*"
QT_MOC_LITERAL(4, 25, 1), // "f"
QT_MOC_LITERAL(5, 27, 16), // "setClickHalfEdge"
QT_MOC_LITERAL(6, 44, 9), // "HalfEdge*"
QT_MOC_LITERAL(7, 54, 1), // "h"
QT_MOC_LITERAL(8, 56, 14), // "setClickVertex"
QT_MOC_LITERAL(9, 71, 7), // "Vertex*"
QT_MOC_LITERAL(10, 79, 1), // "v"
QT_MOC_LITERAL(11, 81, 13), // "setClickJoint"
QT_MOC_LITERAL(12, 95, 6), // "Joint*"
QT_MOC_LITERAL(13, 102, 1), // "j"
QT_MOC_LITERAL(14, 104, 13), // "setSkinButton"
QT_MOC_LITERAL(15, 118, 8), // "_skinned"
QT_MOC_LITERAL(16, 127, 10), // "updateList"
QT_MOC_LITERAL(17, 138, 21), // "std::vector<Vertex*>&"
QT_MOC_LITERAL(18, 160, 2), // "vV"
QT_MOC_LITERAL(19, 163, 23), // "std::vector<HalfEdge*>&"
QT_MOC_LITERAL(20, 187, 2), // "hV"
QT_MOC_LITERAL(21, 190, 19), // "std::vector<Face*>&"
QT_MOC_LITERAL(22, 210, 2), // "fV"
QT_MOC_LITERAL(23, 213, 19), // "slot_setCurrentFace"
QT_MOC_LITERAL(24, 233, 23), // "slot_setCurrentHalfEdge"
QT_MOC_LITERAL(25, 257, 21), // "slot_setCurrentVertex"
QT_MOC_LITERAL(26, 279, 14), // "slot_spiltEdge"
QT_MOC_LITERAL(27, 294, 20), // "slot_triangulateFace"
QT_MOC_LITERAL(28, 315, 14), // "slot_subdivide"
QT_MOC_LITERAL(29, 330, 12), // "slot_extrude"
QT_MOC_LITERAL(30, 343, 14), // "slot_bevelEdge"
QT_MOC_LITERAL(31, 358, 13), // "slot_changeFR"
QT_MOC_LITERAL(32, 372, 1), // "r"
QT_MOC_LITERAL(33, 374, 13), // "slot_changeFG"
QT_MOC_LITERAL(34, 388, 1), // "g"
QT_MOC_LITERAL(35, 390, 13), // "slot_changeFB"
QT_MOC_LITERAL(36, 404, 1), // "b"
QT_MOC_LITERAL(37, 406, 13), // "slot_changeVX"
QT_MOC_LITERAL(38, 420, 1), // "x"
QT_MOC_LITERAL(39, 422, 13), // "slot_changeVY"
QT_MOC_LITERAL(40, 436, 1), // "y"
QT_MOC_LITERAL(41, 438, 13), // "slot_changeVZ"
QT_MOC_LITERAL(42, 452, 1), // "z"
QT_MOC_LITERAL(43, 454, 15), // "slot_pushPullPP"
QT_MOC_LITERAL(44, 470, 9), // "glm::vec3"
QT_MOC_LITERAL(45, 480, 1), // "d"
QT_MOC_LITERAL(46, 482, 5), // "theta"
QT_MOC_LITERAL(47, 488, 1), // "p"
QT_MOC_LITERAL(48, 490, 1), // "n"
QT_MOC_LITERAL(49, 492, 20), // "slot_setCurrentJoint"
QT_MOC_LITERAL(50, 513, 9), // "slot_rotX"
QT_MOC_LITERAL(51, 523, 9), // "slot_rotY"
QT_MOC_LITERAL(52, 533, 9), // "slot_rotZ"
QT_MOC_LITERAL(53, 543, 9), // "slot_skin"
QT_MOC_LITERAL(54, 553, 13), // "slot_changeJX"
QT_MOC_LITERAL(55, 567, 13), // "slot_changeJY"
QT_MOC_LITERAL(56, 581, 13) // "slot_changeJZ"

    },
    "MyGL\0setClickFace\0\0Face*\0f\0setClickHalfEdge\0"
    "HalfEdge*\0h\0setClickVertex\0Vertex*\0v\0"
    "setClickJoint\0Joint*\0j\0setSkinButton\0"
    "_skinned\0updateList\0std::vector<Vertex*>&\0"
    "vV\0std::vector<HalfEdge*>&\0hV\0"
    "std::vector<Face*>&\0fV\0slot_setCurrentFace\0"
    "slot_setCurrentHalfEdge\0slot_setCurrentVertex\0"
    "slot_spiltEdge\0slot_triangulateFace\0"
    "slot_subdivide\0slot_extrude\0slot_bevelEdge\0"
    "slot_changeFR\0r\0slot_changeFG\0g\0"
    "slot_changeFB\0b\0slot_changeVX\0x\0"
    "slot_changeVY\0y\0slot_changeVZ\0z\0"
    "slot_pushPullPP\0glm::vec3\0d\0theta\0p\0"
    "n\0slot_setCurrentJoint\0slot_rotX\0"
    "slot_rotY\0slot_rotZ\0slot_skin\0"
    "slot_changeJX\0slot_changeJY\0slot_changeJZ"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  159,    2, 0x06 /* Public */,
       5,    1,  162,    2, 0x06 /* Public */,
       8,    1,  165,    2, 0x06 /* Public */,
      11,    1,  168,    2, 0x06 /* Public */,
      14,    1,  171,    2, 0x06 /* Public */,
      16,    3,  174,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  181,    2, 0x0a /* Public */,
      24,    1,  184,    2, 0x0a /* Public */,
      25,    1,  187,    2, 0x0a /* Public */,
      26,    0,  190,    2, 0x0a /* Public */,
      27,    0,  191,    2, 0x0a /* Public */,
      28,    0,  192,    2, 0x0a /* Public */,
      29,    0,  193,    2, 0x0a /* Public */,
      30,    0,  194,    2, 0x0a /* Public */,
      31,    1,  195,    2, 0x0a /* Public */,
      33,    1,  198,    2, 0x0a /* Public */,
      35,    1,  201,    2, 0x0a /* Public */,
      37,    1,  204,    2, 0x0a /* Public */,
      39,    1,  207,    2, 0x0a /* Public */,
      41,    1,  210,    2, 0x0a /* Public */,
      43,    4,  213,    2, 0x0a /* Public */,
      49,    1,  222,    2, 0x0a /* Public */,
      50,    0,  225,    2, 0x0a /* Public */,
      51,    0,  226,    2, 0x0a /* Public */,
      52,    0,  227,    2, 0x0a /* Public */,
      53,    0,  228,    2, 0x0a /* Public */,
      54,    1,  229,    2, 0x0a /* Public */,
      55,    1,  232,    2, 0x0a /* Public */,
      56,    1,  235,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 19, 0x80000000 | 21,   18,   20,   22,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::Void, QMetaType::Double,   34,
    QMetaType::Void, QMetaType::Double,   36,
    QMetaType::Void, QMetaType::Double,   38,
    QMetaType::Void, QMetaType::Double,   40,
    QMetaType::Void, QMetaType::Double,   42,
    QMetaType::Void, 0x80000000 | 44, QMetaType::Float, 0x80000000 | 44, 0x80000000 | 44,   45,   46,   47,   48,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   38,
    QMetaType::Void, QMetaType::Double,   40,
    QMetaType::Void, QMetaType::Double,   42,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        switch (_id) {
        case 0: _t->setClickFace((*reinterpret_cast< Face*(*)>(_a[1]))); break;
        case 1: _t->setClickHalfEdge((*reinterpret_cast< HalfEdge*(*)>(_a[1]))); break;
        case 2: _t->setClickVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 3: _t->setClickJoint((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 4: _t->setSkinButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->updateList((*reinterpret_cast< std::vector<Vertex*>(*)>(_a[1])),(*reinterpret_cast< std::vector<HalfEdge*>(*)>(_a[2])),(*reinterpret_cast< std::vector<Face*>(*)>(_a[3]))); break;
        case 6: _t->slot_setCurrentFace((*reinterpret_cast< Face*(*)>(_a[1]))); break;
        case 7: _t->slot_setCurrentHalfEdge((*reinterpret_cast< HalfEdge*(*)>(_a[1]))); break;
        case 8: _t->slot_setCurrentVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 9: _t->slot_spiltEdge(); break;
        case 10: _t->slot_triangulateFace(); break;
        case 11: _t->slot_subdivide(); break;
        case 12: _t->slot_extrude(); break;
        case 13: _t->slot_bevelEdge(); break;
        case 14: _t->slot_changeFR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->slot_changeFG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->slot_changeFB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->slot_changeVX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->slot_changeVY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->slot_changeVZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->slot_pushPullPP((*reinterpret_cast< glm::vec3(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< glm::vec3(*)>(_a[3])),(*reinterpret_cast< glm::vec3(*)>(_a[4]))); break;
        case 21: _t->slot_setCurrentJoint((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 22: _t->slot_rotX(); break;
        case 23: _t->slot_rotY(); break;
        case 24: _t->slot_rotZ(); break;
        case 25: _t->slot_skin(); break;
        case 26: _t->slot_changeJX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->slot_changeJY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->slot_changeJZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(Face * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::setClickFace)) {
                *result = 0;
            }
        }
        {
            typedef void (MyGL::*_t)(HalfEdge * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::setClickHalfEdge)) {
                *result = 1;
            }
        }
        {
            typedef void (MyGL::*_t)(Vertex * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::setClickVertex)) {
                *result = 2;
            }
        }
        {
            typedef void (MyGL::*_t)(Joint * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::setClickJoint)) {
                *result = 3;
            }
        }
        {
            typedef void (MyGL::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::setSkinButton)) {
                *result = 4;
            }
        }
        {
            typedef void (MyGL::*_t)(std::vector<Vertex*> & , std::vector<HalfEdge*> & , std::vector<Face*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::updateList)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &GLWidget277::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return GLWidget277::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget277::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void MyGL::setClickFace(Face * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGL::setClickHalfEdge(HalfEdge * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGL::setClickVertex(Vertex * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGL::setClickJoint(Joint * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGL::setSkinButton(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGL::updateList(std::vector<Vertex*> & _t1, std::vector<HalfEdge*> & _t2, std::vector<Face*> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
