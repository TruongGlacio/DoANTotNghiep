/****************************************************************************
** Meta object code from reading C++ file 'camWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../inc/camWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_camWidget_t {
    QByteArrayData data[30];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_camWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_camWidget_t qt_meta_stringdata_camWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "camWidget"
QT_MOC_LITERAL(1, 10, 5), // "ready"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 14), // "sendParameters"
QT_MOC_LITERAL(4, 32, 9), // "_sliderId"
QT_MOC_LITERAL(5, 42, 6), // "_value"
QT_MOC_LITERAL(6, 49, 18), // "sendSamplePosition"
QT_MOC_LITERAL(7, 68, 2), // "_x"
QT_MOC_LITERAL(8, 71, 2), // "_y"
QT_MOC_LITERAL(9, 74, 18), // "sendCenterPosition"
QT_MOC_LITERAL(10, 93, 2), // "_r"
QT_MOC_LITERAL(11, 96, 11), // "sendFingers"
QT_MOC_LITERAL(12, 108, 12), // "QVector<int>"
QT_MOC_LITERAL(13, 121, 8), // "_fingers"
QT_MOC_LITERAL(14, 130, 15), // "gestureDetected"
QT_MOC_LITERAL(15, 146, 6), // "_angle"
QT_MOC_LITERAL(16, 153, 8), // "_gesture"
QT_MOC_LITERAL(17, 162, 8), // "getImage"
QT_MOC_LITERAL(18, 171, 6), // "_image"
QT_MOC_LITERAL(19, 178, 17), // "getSamplePosition"
QT_MOC_LITERAL(20, 196, 17), // "getCenterPosition"
QT_MOC_LITERAL(21, 214, 10), // "getFingers"
QT_MOC_LITERAL(22, 225, 9), // "getVector"
QT_MOC_LITERAL(23, 235, 6), // "_label"
QT_MOC_LITERAL(24, 242, 15), // "QVector<double>"
QT_MOC_LITERAL(25, 258, 7), // "_vector"
QT_MOC_LITERAL(26, 266, 8), // "countFps"
QT_MOC_LITERAL(27, 275, 13), // "getParameters"
QT_MOC_LITERAL(28, 289, 15), // "showSliderValue"
QT_MOC_LITERAL(29, 305, 13) // "gestureDetect"

    },
    "camWidget\0ready\0\0sendParameters\0"
    "_sliderId\0_value\0sendSamplePosition\0"
    "_x\0_y\0sendCenterPosition\0_r\0sendFingers\0"
    "QVector<int>\0_fingers\0gestureDetected\0"
    "_angle\0_gesture\0getImage\0_image\0"
    "getSamplePosition\0getCenterPosition\0"
    "getFingers\0getVector\0_label\0QVector<double>\0"
    "_vector\0countFps\0getParameters\0"
    "showSliderValue\0gestureDetect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_camWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    2,   90,    2, 0x06 /* Public */,
       6,    2,   95,    2, 0x06 /* Public */,
       9,    3,  100,    2, 0x06 /* Public */,
      11,    1,  107,    2, 0x06 /* Public */,
      14,    2,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    1,  115,    2, 0x0a /* Public */,
      19,    2,  118,    2, 0x0a /* Public */,
      20,    3,  123,    2, 0x0a /* Public */,
      21,    1,  130,    2, 0x0a /* Public */,
      22,    2,  133,    2, 0x0a /* Public */,
      26,    0,  138,    2, 0x08 /* Private */,
      27,    0,  139,    2, 0x08 /* Private */,
      28,    1,  140,    2, 0x08 /* Private */,
      29,    1,  143,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,    7,    8,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   15,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,    7,    8,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 24,   23,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void camWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<camWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ready(); break;
        case 1: _t->sendParameters((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: _t->sendSamplePosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->sendCenterPosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 4: _t->sendFingers((*reinterpret_cast< const QVector<int>(*)>(_a[1]))); break;
        case 5: _t->gestureDetected((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->getImage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->getSamplePosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 8: _t->getCenterPosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 9: _t->getFingers((*reinterpret_cast< const QVector<int>(*)>(_a[1]))); break;
        case 10: _t->getVector((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2]))); break;
        case 11: _t->countFps(); break;
        case 12: _t->getParameters(); break;
        case 13: _t->showSliderValue((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 14: _t->gestureDetect((*reinterpret_cast< const QVector<int>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (camWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camWidget::ready)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (camWidget::*)(const QString & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camWidget::sendParameters)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (camWidget::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camWidget::sendSamplePosition)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (camWidget::*)(const int & , const int & , const double & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camWidget::sendCenterPosition)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (camWidget::*)(const QVector<int> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camWidget::sendFingers)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (camWidget::*)(const int & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&camWidget::gestureDetected)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject camWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_camWidget.data,
    qt_meta_data_camWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *camWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *camWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_camWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int camWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void camWidget::ready()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void camWidget::sendParameters(const QString & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void camWidget::sendSamplePosition(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void camWidget::sendCenterPosition(const int & _t1, const int & _t2, const double & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void camWidget::sendFingers(const QVector<int> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void camWidget::gestureDetected(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_imageBox_t {
    QByteArrayData data[14];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_imageBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_imageBox_t qt_meta_stringdata_imageBox = {
    {
QT_MOC_LITERAL(0, 0, 8), // "imageBox"
QT_MOC_LITERAL(1, 9, 18), // "sendSamplePosition"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "_x"
QT_MOC_LITERAL(4, 32, 2), // "_y"
QT_MOC_LITERAL(5, 35, 17), // "getCenterPosition"
QT_MOC_LITERAL(6, 53, 2), // "_r"
QT_MOC_LITERAL(7, 56, 10), // "getFingers"
QT_MOC_LITERAL(8, 67, 12), // "QVector<int>"
QT_MOC_LITERAL(9, 80, 8), // "_fingers"
QT_MOC_LITERAL(10, 89, 15), // "gestureDetected"
QT_MOC_LITERAL(11, 105, 6), // "_angle"
QT_MOC_LITERAL(12, 112, 8), // "_gesture"
QT_MOC_LITERAL(13, 121, 12) // "gestureClear"

    },
    "imageBox\0sendSamplePosition\0\0_x\0_y\0"
    "getCenterPosition\0_r\0getFingers\0"
    "QVector<int>\0_fingers\0gestureDetected\0"
    "_angle\0_gesture\0gestureClear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_imageBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   44,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,
      10,    2,   54,    2, 0x0a /* Public */,
      13,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,    3,    4,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void,

       0        // eod
};

void imageBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<imageBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSamplePosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->getCenterPosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 2: _t->getFingers((*reinterpret_cast< const QVector<int>(*)>(_a[1]))); break;
        case 3: _t->gestureDetected((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->gestureClear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (imageBox::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&imageBox::sendSamplePosition)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject imageBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_imageBox.data,
    qt_meta_data_imageBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *imageBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *imageBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_imageBox.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int imageBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void imageBox::sendSamplePosition(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
