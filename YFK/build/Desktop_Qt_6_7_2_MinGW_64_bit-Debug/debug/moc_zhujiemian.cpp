/****************************************************************************
** Meta object code from reading C++ file 'zhujiemian.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../zhujiemian.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zhujiemian.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSRightAreaENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSRightAreaENDCLASS = QtMocHelpers::stringData(
    "RightArea",
    "imageChanged",
    "",
    "path"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRightAreaENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject RightArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_CLASSRightAreaENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRightAreaENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRightAreaENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RightArea, std::true_type>,
        // method 'imageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void RightArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RightArea *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imageChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RightArea::*)(const QString & );
            if (_t _q_method = &RightArea::imageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *RightArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RightArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRightAreaENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int RightArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void RightArea::imageChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSZhujiemianENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSZhujiemianENDCLASS = QtMocHelpers::stringData(
    "Zhujiemian",
    "updateTime",
    "",
    "on_pushButton_clicked",
    "on_pushButton_2_clicked",
    "on_pushButton_3_clicked",
    "on_pushButton_4_clicked",
    "on_pushButton_5_clicked",
    "on_pushButton_6_clicked",
    "on_pushButton_7_clicked",
    "on_pushButton_8_clicked",
    "on_pushButton_9_clicked",
    "on_tableWidget_itemSelectionChanged",
    "on_tableWidget_2_itemSelectionChanged",
    "connectDB",
    "updateLeftImage",
    "path",
    "on_listWidget_2_itemEntered",
    "QListWidgetItem*",
    "item",
    "setFiveQrcImages"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZhujiemianENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x08,    1 /* Private */,
       3,    0,  111,    2, 0x08,    2 /* Private */,
       4,    0,  112,    2, 0x08,    3 /* Private */,
       5,    0,  113,    2, 0x08,    4 /* Private */,
       6,    0,  114,    2, 0x08,    5 /* Private */,
       7,    0,  115,    2, 0x08,    6 /* Private */,
       8,    0,  116,    2, 0x08,    7 /* Private */,
       9,    0,  117,    2, 0x08,    8 /* Private */,
      10,    0,  118,    2, 0x08,    9 /* Private */,
      11,    0,  119,    2, 0x08,   10 /* Private */,
      12,    0,  120,    2, 0x08,   11 /* Private */,
      13,    0,  121,    2, 0x08,   12 /* Private */,
      14,    0,  122,    2, 0x08,   13 /* Private */,
      15,    1,  123,    2, 0x08,   14 /* Private */,
      17,    1,  126,    2, 0x08,   16 /* Private */,
      20,    0,  129,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Zhujiemian::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSZhujiemianENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZhujiemianENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZhujiemianENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Zhujiemian, std::true_type>,
        // method 'updateTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_7_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_8_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_9_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableWidget_itemSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableWidget_2_itemSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectDB'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateLeftImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_listWidget_2_itemEntered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'setFiveQrcImages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Zhujiemian::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Zhujiemian *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateTime(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_5_clicked(); break;
        case 6: _t->on_pushButton_6_clicked(); break;
        case 7: _t->on_pushButton_7_clicked(); break;
        case 8: _t->on_pushButton_8_clicked(); break;
        case 9: _t->on_pushButton_9_clicked(); break;
        case 10: _t->on_tableWidget_itemSelectionChanged(); break;
        case 11: _t->on_tableWidget_2_itemSelectionChanged(); break;
        case 12: { bool _r = _t->connectDB();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->updateLeftImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->on_listWidget_2_itemEntered((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 15: _t->setFiveQrcImages(); break;
        default: ;
        }
    }
}

const QMetaObject *Zhujiemian::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Zhujiemian::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZhujiemianENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Zhujiemian::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
