/****************************************************************************
** Meta object code from reading C++ file 'ImageViewer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/ImageViewer.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
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
struct qt_meta_stringdata_ImageViewer_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[24];
    char stringdata5[26];
    char stringdata6[24];
    char stringdata7[30];
    char stringdata8[27];
    char stringdata9[31];
    char stringdata10[30];
    char stringdata11[30];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ImageViewer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ImageViewer_t qt_meta_stringdata_ImageViewer = {
    {
        QT_MOC_LITERAL(0, 11),  // "ImageViewer"
        QT_MOC_LITERAL(12, 23),  // "on_actionOpen_triggered"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 26),  // "on_actionSave_as_triggered"
        QT_MOC_LITERAL(64, 23),  // "on_actionExit_triggered"
        QT_MOC_LITERAL(88, 25),  // "on_actionInvert_triggered"
        QT_MOC_LITERAL(114, 23),  // "on_actionFSHS_triggered"
        QT_MOC_LITERAL(138, 29),  // "on_actionEdgeMirror_triggered"
        QT_MOC_LITERAL(168, 26),  // "on_actionEKVHist_triggered"
        QT_MOC_LITERAL(195, 30),  // "on_actionConvolution_triggered"
        QT_MOC_LITERAL(226, 29),  // "on_pushButtonExplicit_clicked"
        QT_MOC_LITERAL(256, 29)   // "on_pushButtonImplicit_clicked"
    },
    "ImageViewer",
    "on_actionOpen_triggered",
    "",
    "on_actionSave_as_triggered",
    "on_actionExit_triggered",
    "on_actionInvert_triggered",
    "on_actionFSHS_triggered",
    "on_actionEdgeMirror_triggered",
    "on_actionEKVHist_triggered",
    "on_actionConvolution_triggered",
    "on_pushButtonExplicit_clicked",
    "on_pushButtonImplicit_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ImageViewer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

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

       0        // eod
};

Q_CONSTINIT const QMetaObject ImageViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ImageViewer.offsetsAndSizes,
    qt_meta_data_ImageViewer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ImageViewer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ImageViewer, std::true_type>,
        // method 'on_actionOpen_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSave_as_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionExit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionInvert_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionFSHS_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionEdgeMirror_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionEKVHist_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionConvolution_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonExplicit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonImplicit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ImageViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionOpen_triggered(); break;
        case 1: _t->on_actionSave_as_triggered(); break;
        case 2: _t->on_actionExit_triggered(); break;
        case 3: _t->on_actionInvert_triggered(); break;
        case 4: _t->on_actionFSHS_triggered(); break;
        case 5: _t->on_actionEdgeMirror_triggered(); break;
        case 6: _t->on_actionEKVHist_triggered(); break;
        case 7: _t->on_actionConvolution_triggered(); break;
        case 8: _t->on_pushButtonExplicit_clicked(); break;
        case 9: _t->on_pushButtonImplicit_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ImageViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageViewer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ImageViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
