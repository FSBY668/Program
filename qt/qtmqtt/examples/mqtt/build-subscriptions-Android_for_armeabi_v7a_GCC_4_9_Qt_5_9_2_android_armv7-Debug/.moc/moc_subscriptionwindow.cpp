/****************************************************************************
** Meta object code from reading C++ file 'subscriptionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../subscriptions/subscriptionwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subscriptionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SubscriptionWindow_t {
    QByteArrayData data[9];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SubscriptionWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SubscriptionWindow_t qt_meta_stringdata_SubscriptionWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SubscriptionWindow"
QT_MOC_LITERAL(1, 19, 13), // "updateMessage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "QMqttMessage"
QT_MOC_LITERAL(4, 47, 3), // "msg"
QT_MOC_LITERAL(5, 51, 12), // "updateStatus"
QT_MOC_LITERAL(6, 64, 36), // "QMqttSubscription::Subscripti..."
QT_MOC_LITERAL(7, 101, 5), // "state"
QT_MOC_LITERAL(8, 107, 21) // "on_pushButton_clicked"

    },
    "SubscriptionWindow\0updateMessage\0\0"
    "QMqttMessage\0msg\0updateStatus\0"
    "QMqttSubscription::SubscriptionState\0"
    "state\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SubscriptionWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       8,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void SubscriptionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SubscriptionWindow *_t = static_cast<SubscriptionWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMessage((*reinterpret_cast< const QMqttMessage(*)>(_a[1]))); break;
        case 1: _t->updateStatus((*reinterpret_cast< QMqttSubscription::SubscriptionState(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttMessage >(); break;
            }
            break;
        }
    }
}

const QMetaObject SubscriptionWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SubscriptionWindow.data,
      qt_meta_data_SubscriptionWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SubscriptionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SubscriptionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SubscriptionWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SubscriptionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
