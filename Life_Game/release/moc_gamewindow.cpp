/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../gamewindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_GameWindow_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[22];
    char stringdata5[23];
    char stringdata6[22];
    char stringdata7[22];
    char stringdata8[22];
    char stringdata9[22];
    char stringdata10[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_GameWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_GameWindow_t qt_meta_stringdata_GameWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "GameWindow"
        QT_MOC_LITERAL(11, 13),  // "newGeneration"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 5),  // "count"
        QT_MOC_LITERAL(32, 21),  // "on_autoButton_clicked"
        QT_MOC_LITERAL(54, 22),  // "on_clearButton_clicked"
        QT_MOC_LITERAL(77, 21),  // "on_exitButton_clicked"
        QT_MOC_LITERAL(99, 21),  // "on_tickButton_clicked"
        QT_MOC_LITERAL(121, 21),  // "on_dumpButton_clicked"
        QT_MOC_LITERAL(143, 21),  // "on_openButton_clicked"
        QT_MOC_LITERAL(165, 21)   // "on_helpButton_clicked"
    },
    "GameWindow",
    "newGeneration",
    "",
    "count",
    "on_autoButton_clicked",
    "on_clearButton_clicked",
    "on_exitButton_clicked",
    "on_tickButton_clicked",
    "on_dumpButton_clicked",
    "on_openButton_clicked",
    "on_helpButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_GameWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x0a,    1 /* Public */,
       1,    0,   71,    2, 0x2a,    3 /* Public | MethodCloned */,
       4,    0,   72,    2, 0x08,    4 /* Private */,
       5,    0,   73,    2, 0x08,    5 /* Private */,
       6,    0,   74,    2, 0x08,    6 /* Private */,
       7,    0,   75,    2, 0x08,    7 /* Private */,
       8,    0,   76,    2, 0x08,    8 /* Private */,
       9,    0,   77,    2, 0x08,    9 /* Private */,
      10,    0,   78,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_GameWindow.offsetsAndSizes,
    qt_meta_data_GameWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_GameWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameWindow, std::true_type>,
        // method 'newGeneration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'newGeneration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_autoButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exitButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tickButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_dumpButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_openButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_helpButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newGeneration((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->newGeneration(); break;
        case 2: _t->on_autoButton_clicked(); break;
        case 3: _t->on_clearButton_clicked(); break;
        case 4: _t->on_exitButton_clicked(); break;
        case 5: _t->on_tickButton_clicked(); break;
        case 6: _t->on_dumpButton_clicked(); break;
        case 7: _t->on_openButton_clicked(); break;
        case 8: _t->on_helpButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *GameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
