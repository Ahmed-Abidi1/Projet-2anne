/****************************************************************************
** Meta object code from reading C++ file 'vehicule_inter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../vehicule_inter.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vehicule_inter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSvehicule_interENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSvehicule_interENDCLASS = QtMocHelpers::stringData(
    "vehicule_inter",
    "on_fonction_clicked",
    "",
    "on_ges_appar_clicked",
    "on_ges_es_vert_clicked",
    "on_ges_mat_clicked",
    "on_ges_emp_clicked",
    "on_validerV_clicked",
    "on_annulerV_clicked",
    "on_modifierV_clicked",
    "on_supprimerV_clicked",
    "on_tableWidgetv_itemClicked",
    "QTableWidgetItem*",
    "item",
    "on_recherche_clicked",
    "on_trier_clicked",
    "on_pdf_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSvehicule_interENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    0,   96,    2, 0x08,    5 /* Private */,
       7,    0,   97,    2, 0x08,    6 /* Private */,
       8,    0,   98,    2, 0x08,    7 /* Private */,
       9,    0,   99,    2, 0x08,    8 /* Private */,
      10,    0,  100,    2, 0x08,    9 /* Private */,
      11,    1,  101,    2, 0x08,   10 /* Private */,
      14,    0,  104,    2, 0x08,   12 /* Private */,
      15,    0,  105,    2, 0x08,   13 /* Private */,
      16,    0,  106,    2, 0x08,   14 /* Private */,

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
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject vehicule_inter::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSvehicule_interENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSvehicule_interENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSvehicule_interENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<vehicule_inter, std::true_type>,
        // method 'on_fonction_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ges_appar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ges_es_vert_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ges_mat_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ges_emp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_validerV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_annulerV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modifierV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_supprimerV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableWidgetv_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>,
        // method 'on_recherche_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_trier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pdf_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void vehicule_inter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<vehicule_inter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_fonction_clicked(); break;
        case 1: _t->on_ges_appar_clicked(); break;
        case 2: _t->on_ges_es_vert_clicked(); break;
        case 3: _t->on_ges_mat_clicked(); break;
        case 4: _t->on_ges_emp_clicked(); break;
        case 5: _t->on_validerV_clicked(); break;
        case 6: _t->on_annulerV_clicked(); break;
        case 7: _t->on_modifierV_clicked(); break;
        case 8: _t->on_supprimerV_clicked(); break;
        case 9: _t->on_tableWidgetv_itemClicked((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 10: _t->on_recherche_clicked(); break;
        case 11: _t->on_trier_clicked(); break;
        case 12: _t->on_pdf_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *vehicule_inter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vehicule_inter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSvehicule_interENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int vehicule_inter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
