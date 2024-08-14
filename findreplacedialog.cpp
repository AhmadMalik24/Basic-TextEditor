#include "findreplacedialog.h"
#include "ui_findreplacedialog.h"

FindReplaceDialog::FindReplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindReplaceDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &QDialog::accept);
}

FindReplaceDialog::~FindReplaceDialog()
{
    delete ui;
}

QString FindReplaceDialog::findText() const
{
    return ui->findLineEdit->text();
}

QString FindReplaceDialog::replaceText() const
{
    return ui->replaceLineEdit->text();
}
