/********************************************************************************
** Form generated from reading UI file 'CodeWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEWIDGET_H
#define UI_CODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodeWidget
{
public:

    void setupUi(QWidget *CodeWidget)
    {
        if (CodeWidget->objectName().isEmpty())
            CodeWidget->setObjectName(QString::fromUtf8("CodeWidget"));
        CodeWidget->resize(800, 600);

        retranslateUi(CodeWidget);

        QMetaObject::connectSlotsByName(CodeWidget);
    } // setupUi

    void retranslateUi(QWidget *CodeWidget)
    {
        CodeWidget->setWindowTitle(QCoreApplication::translate("CodeWidget", "CodeWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CodeWidget: public Ui_CodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEWIDGET_H
