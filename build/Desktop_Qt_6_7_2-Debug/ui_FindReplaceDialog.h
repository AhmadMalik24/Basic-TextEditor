/********************************************************************************
** Form generated from reading UI file 'FindReplaceDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDREPLACEDIALOG_H
#define UI_FINDREPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *findLineEdit;
    QLineEdit *replaceLineEdit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(320, 240);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(89, 20, 221, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        findLineEdit = new QLineEdit(verticalLayoutWidget);
        findLineEdit->setObjectName("findLineEdit");

        verticalLayout->addWidget(findLineEdit);

        replaceLineEdit = new QLineEdit(verticalLayoutWidget);
        replaceLineEdit->setObjectName("replaceLineEdit");

        verticalLayout->addWidget(replaceLineEdit);

        verticalLayoutWidget_2 = new QWidget(Dialog);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 81, 101));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        okButton = new QPushButton(Dialog);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(200, 170, 101, 41));
        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(80, 170, 111, 41));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Find", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Replace", nullptr));
        okButton->setText(QCoreApplication::translate("Dialog", "Ok", nullptr));
        cancelButton->setText(QCoreApplication::translate("Dialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDREPLACEDIALOG_H
