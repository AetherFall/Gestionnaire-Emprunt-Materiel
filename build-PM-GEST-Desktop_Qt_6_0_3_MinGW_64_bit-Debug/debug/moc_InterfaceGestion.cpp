/****************************************************************************
** Meta object code from reading C++ file 'InterfaceGestion.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../PM-GEST/InterfaceGestion.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InterfaceGestion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InterfaceGestion_t {
    const uint offsetsAndSize[14];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_InterfaceGestion_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_InterfaceGestion_t qt_meta_stringdata_InterfaceGestion = {
    {
QT_MOC_LITERAL(0, 16), // "InterfaceGestion"
QT_MOC_LITERAL(17, 21), // "ouvertureInterfaceEmp"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 21), // "ouvertureInterfaceObj"
QT_MOC_LITERAL(62, 22), // "ouvertureInterfaceType"
QT_MOC_LITERAL(85, 24), // "ouvertureInterfaceDepart"
QT_MOC_LITERAL(110, 13) // "onCloseAction"

    },
    "InterfaceGestion\0ouvertureInterfaceEmp\0"
    "\0ouvertureInterfaceObj\0ouvertureInterfaceType\0"
    "ouvertureInterfaceDepart\0onCloseAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InterfaceGestion[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    0 /* Private */,
       3,    0,   45,    2, 0x08,    1 /* Private */,
       4,    0,   46,    2, 0x08,    2 /* Private */,
       5,    0,   47,    2, 0x08,    3 /* Private */,
       6,    0,   48,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InterfaceGestion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InterfaceGestion *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ouvertureInterfaceEmp(); break;
        case 1: _t->ouvertureInterfaceObj(); break;
        case 2: _t->ouvertureInterfaceType(); break;
        case 3: _t->ouvertureInterfaceDepart(); break;
        case 4: _t->onCloseAction(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject InterfaceGestion::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_InterfaceGestion.offsetsAndSize,
    qt_meta_data_InterfaceGestion,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_InterfaceGestion_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *InterfaceGestion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InterfaceGestion::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InterfaceGestion.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InterfaceGestion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
