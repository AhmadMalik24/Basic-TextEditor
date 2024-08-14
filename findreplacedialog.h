#ifndef FINDREPLACEDIALOG_H
#define FINDREPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class FindReplaceDialog;
}

class FindReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindReplaceDialog(QWidget *parent = nullptr);
    ~FindReplaceDialog();
public:
    QString findText() const;
    QString replaceText() const;


private:
    Ui::FindReplaceDialog *ui;
};

#endif
