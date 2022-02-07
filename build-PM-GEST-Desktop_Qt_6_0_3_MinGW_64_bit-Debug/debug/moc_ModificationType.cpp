/****************************************************************************
** Meta object code from reading C++ file 'ModificationType.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../PM-GEST/ModificationType.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModificationType.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModificationType_t {
    const uint offsetsAndSize[22];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ModificationType_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ModificationType_t qt_meta_stringdata_ModificationType = {
    {
QT_MOC_LITERAL(0, 16), // "ModificationType"
QT_MOC_LITERAL(17, 7), // "refresh"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 5), // "ajout"
QT_MOC_LITERAL(32, 11), // "suppression"
QT_MOC_LITERAL(44, 12), // "modification"
QT_MOC_LITERAL(57, 11), // "updateTable"
QT_MOC_LITERAL(69, 3), // "row"
QT_MOC_LITERAL(73, 3), // "col"
QT_MOC_LITERAL(77, 13), // "onCloseAction"
QT_MOC_LITERAL(91, 10) // "fileSearch"

    },
    "ModificationType\0refresh\0\0ajout\0"
    "suppression\0modification\0updateTable\0"
    "row\0col\0onCloseAction\0fileSearch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModificationType[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    0 /* Private */,
       3,    0,   69,    2, 0x08,    1 /* Private */,
       4,    0,   70,    2, 0x08,    2 /* Private */,
       5,    0,   71,    2, 0x08,    3 /* Private */,
       6,    2,   72,    2, 0x08,    4 /* Private */,
       6,    1,   77,    2, 0x28,    7 /* Private | MethodCloned */,
       6,    0,   80,    2, 0x28,    9 /* Private | MethodCloned */,
       9,    0,   81,    2, 0x08,   10 /* Private */,
      10,    0,   82,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModificationType::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModificationType *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->ajout(); break;
        case 2: _t->suppression(); break;
        case 3: _t->modification(); break;
        case 4: _t->updateTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->updateTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateTable(); break;
        case 7: _t->onCloseAction(); break;
        case 8: _t->fileSearch(); break;
        default: ;
        }
    }
}

const QMetaObject ModificationType::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ModificationType.offsetsAndSize,
    qt_meta_data_ModificationType,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ModificationType_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ModificationType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModificationType::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModificationType.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ModificationType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
