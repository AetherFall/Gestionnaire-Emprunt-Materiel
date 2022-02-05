/****************************************************************************
** Meta object code from reading C++ file 'ModificationAppareil.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../PM-GEST/ModificationAppareil.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModificationAppareil.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModificationAppareil_t {
    const uint offsetsAndSize[40];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ModificationAppareil_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ModificationAppareil_t qt_meta_stringdata_ModificationAppareil = {
    {
QT_MOC_LITERAL(0, 20), // "ModificationAppareil"
QT_MOC_LITERAL(21, 21), // "verificationTextField"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 10), // "QLineEdit*"
QT_MOC_LITERAL(55, 7), // "refresh"
QT_MOC_LITERAL(63, 5), // "ajout"
QT_MOC_LITERAL(69, 11), // "suppression"
QT_MOC_LITERAL(81, 12), // "modification"
QT_MOC_LITERAL(94, 11), // "updateTable"
QT_MOC_LITERAL(106, 10), // "currentRow"
QT_MOC_LITERAL(117, 10), // "currentCol"
QT_MOC_LITERAL(128, 13), // "onCloseAction"
QT_MOC_LITERAL(142, 11), // "focusChange"
QT_MOC_LITERAL(154, 8), // "QWidget*"
QT_MOC_LITERAL(163, 1), // "a"
QT_MOC_LITERAL(165, 1), // "b"
QT_MOC_LITERAL(167, 12), // "verification"
QT_MOC_LITERAL(180, 4), // "text"
QT_MOC_LITERAL(185, 4), // "edit"
QT_MOC_LITERAL(190, 5) // "basic"

    },
    "ModificationAppareil\0verificationTextField\0"
    "\0QLineEdit*\0refresh\0ajout\0suppression\0"
    "modification\0updateTable\0currentRow\0"
    "currentCol\0onCloseAction\0focusChange\0"
    "QWidget*\0a\0b\0verification\0text\0edit\0"
    "basic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModificationAppareil[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   98,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  105,    2, 0x08,    4 /* Private */,
       5,    0,  106,    2, 0x08,    5 /* Private */,
       6,    0,  107,    2, 0x08,    6 /* Private */,
       7,    0,  108,    2, 0x08,    7 /* Private */,
       8,    2,  109,    2, 0x08,    8 /* Private */,
       8,    1,  114,    2, 0x28,   11 /* Private | MethodCloned */,
       8,    0,  117,    2, 0x28,   13 /* Private | MethodCloned */,
      11,    0,  118,    2, 0x08,   14 /* Private */,
      12,    2,  119,    2, 0x08,   15 /* Private */,
      12,    1,  124,    2, 0x28,   18 /* Private | MethodCloned */,
      12,    0,  127,    2, 0x28,   20 /* Private | MethodCloned */,
      16,    3,  128,    2, 0x08,   21 /* Private */,
      16,    2,  135,    2, 0x28,   25 /* Private | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3, QMetaType::Bool,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13,   14,   15,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3, QMetaType::Bool,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,   17,   18,

       0        // eod
};

void ModificationAppareil::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModificationAppareil *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->verificationTextField((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->refresh(); break;
        case 2: _t->ajout(); break;
        case 3: _t->suppression(); break;
        case 4: _t->modification(); break;
        case 5: _t->updateTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->updateTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateTable(); break;
        case 8: _t->onCloseAction(); break;
        case 9: _t->focusChange((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 10: _t->focusChange((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 11: _t->focusChange(); break;
        case 12: _t->verification((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 13: _t->verification((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLineEdit* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLineEdit* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLineEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModificationAppareil::*)(QString , QLineEdit * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModificationAppareil::verificationTextField)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ModificationAppareil::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ModificationAppareil.offsetsAndSize,
    qt_meta_data_ModificationAppareil,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ModificationAppareil_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QLineEdit *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QLineEdit *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QLineEdit *, std::false_type>


>,
    nullptr
} };


const QMetaObject *ModificationAppareil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModificationAppareil::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModificationAppareil.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ModificationAppareil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ModificationAppareil::verificationTextField(QString _t1, QLineEdit * _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
