/****************************************************************************
** Meta object code from reading C++ file 'camProcess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../inc/camProcess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camProcess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cvCamCapture_t {
    QByteArrayData data[5];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cvCamCapture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cvCamCapture_t qt_meta_stringdata_cvCamCapture = {
    {
QT_MOC_LITERAL(0, 0, 12), // "cvCamCapture"
QT_MOC_LITERAL(1, 13, 10), // "frameReady"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 33, 8) // "getFrame"

    },
    "cvCamCapture\0frameReady\0\0cv::Mat\0"
    "getFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cvCamCapture[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void cvCamCapture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cvCamCapture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameReady((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 1: _t->getFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cv::Mat >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cvCamCapture::*)(const cv::Mat & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cvCamCapture::frameReady)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cvCamCapture::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cvCamCapture.data,
    qt_meta_data_cvCamCapture,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cvCamCapture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cvCamCapture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cvCamCapture.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cvCamCapture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void cvCamCapture::frameReady(const cv::Mat & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_cvProcessFrame_t {
    QByteArrayData data[22];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cvProcessFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cvProcessFrame_t qt_meta_stringdata_cvProcessFrame = {
    {
QT_MOC_LITERAL(0, 0, 14), // "cvProcessFrame"
QT_MOC_LITERAL(1, 15, 10), // "imageReady"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "_image"
QT_MOC_LITERAL(4, 34, 18), // "sendCenterPosition"
QT_MOC_LITERAL(5, 53, 2), // "_x"
QT_MOC_LITERAL(6, 56, 2), // "_y"
QT_MOC_LITERAL(7, 59, 2), // "_r"
QT_MOC_LITERAL(8, 62, 11), // "sendFingers"
QT_MOC_LITERAL(9, 74, 12), // "QVector<int>"
QT_MOC_LITERAL(10, 87, 8), // "_fingers"
QT_MOC_LITERAL(11, 96, 10), // "sendVector"
QT_MOC_LITERAL(12, 107, 6), // "_label"
QT_MOC_LITERAL(13, 114, 15), // "QVector<double>"
QT_MOC_LITERAL(14, 130, 7), // "_vector"
QT_MOC_LITERAL(15, 138, 12), // "processFrame"
QT_MOC_LITERAL(16, 151, 7), // "cv::Mat"
QT_MOC_LITERAL(17, 159, 6), // "_frame"
QT_MOC_LITERAL(18, 166, 13), // "getParameters"
QT_MOC_LITERAL(19, 180, 12), // "_parameterId"
QT_MOC_LITERAL(20, 193, 6), // "_value"
QT_MOC_LITERAL(21, 200, 17) // "getSamplePosition"

    },
    "cvProcessFrame\0imageReady\0\0_image\0"
    "sendCenterPosition\0_x\0_y\0_r\0sendFingers\0"
    "QVector<int>\0_fingers\0sendVector\0"
    "_label\0QVector<double>\0_vector\0"
    "processFrame\0cv::Mat\0_frame\0getParameters\0"
    "_parameterId\0_value\0getSamplePosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cvProcessFrame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    3,   52,    2, 0x06 /* Public */,
       8,    1,   59,    2, 0x06 /* Public */,
      11,    2,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,   67,    2, 0x0a /* Public */,
      18,    2,   70,    2, 0x0a /* Public */,
      21,    2,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,

       0        // eod
};

void cvProcessFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cvProcessFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageReady((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendCenterPosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 2: _t->sendFingers((*reinterpret_cast< const QVector<int>(*)>(_a[1]))); break;
        case 3: _t->sendVector((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QVector<double>(*)>(_a[2]))); break;
        case 4: _t->processFrame((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        case 5: _t->getParameters((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 6: _t->getSamplePosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
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
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cv::Mat >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cvProcessFrame::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cvProcessFrame::imageReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (cvProcessFrame::*)(const int & , const int & , const double & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cvProcessFrame::sendCenterPosition)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (cvProcessFrame::*)(const QVector<int> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cvProcessFrame::sendFingers)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (cvProcessFrame::*)(int , const QVector<double> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cvProcessFrame::sendVector)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cvProcessFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cvProcessFrame.data,
    qt_meta_data_cvProcessFrame,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cvProcessFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cvProcessFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cvProcessFrame.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cvProcessFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void cvProcessFrame::imageReady(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cvProcessFrame::sendCenterPosition(const int & _t1, const int & _t2, const double & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void cvProcessFrame::sendFingers(const QVector<int> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cvProcessFrame::sendVector(int _t1, const QVector<double> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
