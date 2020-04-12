/****************************************************************************
** Meta object code from reading C++ file 'PeopleDetectManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../HandDetectControlApp/PeopleDetectManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PeopleDetectManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PeopleDetectManager_t {
    QByteArrayData data[23];
    char stringdata0[321];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PeopleDetectManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PeopleDetectManager_t qt_meta_stringdata_PeopleDetectManager = {
    {
QT_MOC_LITERAL(0, 0, 19), // "PeopleDetectManager"
QT_MOC_LITERAL(1, 20, 21), // "SendTextMessageChange"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 8), // "QString&"
QT_MOC_LITERAL(4, 52, 7), // "message"
QT_MOC_LITERAL(5, 60, 16), // "SendLocationData"
QT_MOC_LITERAL(6, 77, 6), // "qpoint"
QT_MOC_LITERAL(7, 84, 21), // "CloseConnectionChange"
QT_MOC_LITERAL(8, 106, 29), // "QWebSocketProtocol::CloseCode"
QT_MOC_LITERAL(9, 136, 9), // "closeCode"
QT_MOC_LITERAL(10, 146, 6), // "reason"
QT_MOC_LITERAL(11, 153, 18), // "SendErrorToControl"
QT_MOC_LITERAL(12, 172, 16), // "QList<QSslError>"
QT_MOC_LITERAL(13, 189, 6), // "errors"
QT_MOC_LITERAL(14, 196, 12), // "DetectPeople"
QT_MOC_LITERAL(15, 209, 12), // "detectResult"
QT_MOC_LITERAL(16, 222, 11), // "onConnected"
QT_MOC_LITERAL(17, 234, 18), // "WebSocketDiconnect"
QT_MOC_LITERAL(18, 253, 12), // "OnDataChange"
QT_MOC_LITERAL(19, 266, 19), // "HandlingSocketError"
QT_MOC_LITERAL(20, 286, 9), // "PrintData"
QT_MOC_LITERAL(21, 296, 11), // "dataPackage"
QT_MOC_LITERAL(22, 308, 12) // "Disconnected"

    },
    "PeopleDetectManager\0SendTextMessageChange\0"
    "\0QString&\0message\0SendLocationData\0"
    "qpoint\0CloseConnectionChange\0"
    "QWebSocketProtocol::CloseCode\0closeCode\0"
    "reason\0SendErrorToControl\0QList<QSslError>\0"
    "errors\0DetectPeople\0detectResult\0"
    "onConnected\0WebSocketDiconnect\0"
    "OnDataChange\0HandlingSocketError\0"
    "PrintData\0dataPackage\0Disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PeopleDetectManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    1,   82,    2, 0x06 /* Public */,
       7,    2,   85,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x26 /* Public | MethodCloned */,
       7,    0,   93,    2, 0x26 /* Public | MethodCloned */,
      11,    1,   94,    2, 0x06 /* Public */,
      14,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  100,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,
      18,    1,  102,    2, 0x0a /* Public */,
      19,    1,  105,    2, 0x0a /* Public */,
      20,    1,  108,    2, 0x0a /* Public */,
      22,    0,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString,    9,   10,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void,

       0        // eod
};

void PeopleDetectManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PeopleDetectManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendTextMessageChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendLocationData((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->CloseConnectionChange((*reinterpret_cast< QWebSocketProtocol::CloseCode(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->CloseConnectionChange((*reinterpret_cast< QWebSocketProtocol::CloseCode(*)>(_a[1]))); break;
        case 4: _t->CloseConnectionChange(); break;
        case 5: _t->SendErrorToControl((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 6: _t->DetectPeople((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->onConnected(); break;
        case 8: _t->WebSocketDiconnect(); break;
        case 9: _t->OnDataChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->HandlingSocketError((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 11: _t->PrintData((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 12: _t->Disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PeopleDetectManager::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeopleDetectManager::SendTextMessageChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PeopleDetectManager::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeopleDetectManager::SendLocationData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PeopleDetectManager::*)(QWebSocketProtocol::CloseCode , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeopleDetectManager::CloseConnectionChange)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PeopleDetectManager::*)(const QList<QSslError> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeopleDetectManager::SendErrorToControl)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PeopleDetectManager::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeopleDetectManager::DetectPeople)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PeopleDetectManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_PeopleDetectManager.data,
    qt_meta_data_PeopleDetectManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PeopleDetectManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PeopleDetectManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PeopleDetectManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PeopleDetectManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void PeopleDetectManager::SendTextMessageChange(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PeopleDetectManager::SendLocationData(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PeopleDetectManager::CloseConnectionChange(QWebSocketProtocol::CloseCode _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 5
void PeopleDetectManager::SendErrorToControl(const QList<QSslError> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PeopleDetectManager::DetectPeople(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
