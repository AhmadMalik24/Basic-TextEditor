/********************************************************************************
** Form generated from reading UI file 'findreplacedialog.ui'
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

QT_BEGIN_NAMESPACE

class Ui_FindReplaceDialog
{
public:
    QLineEdit *findLineEdit;
    QLineEdit *replaceLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *FindReplaceDialog)
    {
        if (FindReplaceDialog->objectName().isEmpty())
            FindReplaceDialog->setObjectName("FindReplaceDialog");
        FindReplaceDialog->resize(320, 240);
        findLineEdit = new QLineEdit(FindReplaceDialog);
        findLineEdit->setObjectName("findLineEdit");
        findLineEdit->setGeometry(QRect(122, 20, 171, 26));
        replaceLineEdit = new QLineEdit(FindReplaceDialog);
        replaceLineEdit->setObjectName("replaceLineEdit");
        replaceLineEdit->setGeometry(QRect(120, 70, 171, 26));
        label = new QLabel(FindReplaceDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 91, 31));
        label_2 = new QLabel(FindReplaceDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 91, 31));
        label_3 = new QLabel(FindReplaceDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 10, 81, 51));
        pushButton = new QPushButton(FindReplaceDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 160, 87, 26));
        pushButton_2 = new QPushButton(FindReplaceDialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 160, 87, 26));
        pushButton_3 = new QPushButton(FindReplaceDialog);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(110, 160, 87, 26));

        retranslateUi(FindReplaceDialog);

        QMetaObject::connectSlotsByName(FindReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *FindReplaceDialog)
    {
        FindReplaceDialog->setWindowTitle(QCoreApplication::translate("FindReplaceDialog", "Dialog", nullptr));
        findLineEdit->setText(QString());
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("FindReplaceDialog", "Replace", nullptr));
        label_3->setText(QCoreApplication::translate("FindReplaceDialog", "Find", nullptr));
        pushButton->setText(QCoreApplication::translate("FindReplaceDialog", "Cancel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FindReplaceDialog", "Replace", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FindReplaceDialog", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindReplaceDialog: public Ui_FindReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDREPLACEDIALOG_H
