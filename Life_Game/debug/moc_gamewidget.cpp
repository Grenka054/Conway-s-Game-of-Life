/****************************************************************************
** Meta object code from reading C++ file 'gamewidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../gamewidget.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_GameWidget_t {
    uint offsetsAndSizes[20];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[19];
    char stringdata5[12];
    char stringdata6[10];
    char stringdata7[10];
    char stringdata8[8];
    char stringdata9[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_GameWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_GameWidget_t qt_meta_stringdata_GameWidget = {
    {
        QT_MOC_LITERAL(0, 10),  // "GameWidget"
        QT_MOC_LITERAL(11, 13),  // "newGeneration"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 5),  // "count"
        QT_MOC_LITERAL(32, 18),  // "switch_auto_update"
        QT_MOC_LITERAL(51, 11),  // "clear_field"
        QT_MOC_LITERAL(63, 9),  // "paintGrid"
        QT_MOC_LITERAL(73, 9),  // "QPainter&"
        QT_MOC_LITERAL(83, 7),  // "pointer"
        QT_MOC_LITERAL(91, 13)   // "paintUniverse"
    },
    "GameWidget",
    "newGeneration",
    "",
    "count",
    "switch_auto_update",
    "clear_field",
    "paintGrid",
    "QPainter&",
    "pointer",
    "paintUniverse"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_GameWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       1,    0,   53,    2, 0x2a,    3 /* Public | MethodCloned */,
       4,    0,   54,    2, 0x0a,    4 /* Public */,
       5,    0,   55,    2, 0x0a,    5 /* Public */,
       6,    1,   56,    2, 0x08,    6 /* Private */,
       9,    1,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GameWidget.offsetsAndSizes,
    qt_meta_data_GameWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_GameWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameWidget, std::true_type>,
        // method 'newGeneration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'newGeneration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switch_auto_update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clear_field'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'paintGrid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPainter &, std::false_type>,
        // method 'paintUniverse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPainter &, std::false_type>
    >,
    nullptr
} };

void GameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newGeneration((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->newGeneration(); break;
        case 2: _t->switch_auto_update(); break;
        case 3: _t->clear_field(); break;
        case 4: _t->paintGrid((*reinterpret_cast< std::add_pointer_t<QPainter&>>(_a[1]))); break;
        case 5: _t->paintUniverse((*reinterpret_cast< std::add_pointer_t<QPainter&>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *GameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
