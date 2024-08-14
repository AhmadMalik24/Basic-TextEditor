#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "syntaxhighlighter.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "findreplacedialog.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , highlighter(nullptr)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->MainWindow_2);
    highlighter = new SyntaxHighlighter(ui->MainWindow_2->document());

    // new code
    setupCompleter();


    // Create and configure the zoom slider
    zoomSlider = new QSlider(Qt::Horizontal, this);
    zoomSlider->setRange(10, 200); // Zoom from 10% to 200%
    zoomSlider->setValue(100); // Default zoom level (100%)
    zoomSlider->setTickInterval(10);
    zoomSlider->setTickPosition(QSlider::TicksBelow);

    // Create a central widget and set a vertical layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(ui->MainWindow_2); // Add QPlainTextEdit to the layout
    layout->addWidget(zoomSlider); // Add zoomSlider to the layout

    // Set the central widget with layout
    setCentralWidget(centralWidget);

    // Connect slider value change to zoom function
    connect(zoomSlider, &QSlider::valueChanged, this, &MainWindow::onZoomSliderValueChanged);


}
//----------------------------------------------------------------------------------------------------------------------------------

void MainWindow::setupCompleter()
{
    QStringList wordList;
    wordList << "alignas" << "alignof" << "and" << "and_eq" << "asm" << "auto"
             << "bitand" << "bitor" << "bool" << "break" << "case" << "catch"
             << "char" << "char16_t" << "char32_t" << "class" << "compl" << "concept"
             << "const" << "constexpr" << "const_cast" << "continue" << "co_await"
             << "co_return" << "co_yield" << "decltype" << "default" << "delete"
             << "do" << "double" << "dynamic_cast" << "else" << "enum" << "explicit"
             << "export" << "extern" << "false" << "float" << "for" << "friend"
             << "goto" << "if" << "inline" << "int" << "long" << "mutable"
             << "namespace" << "new" << "noexcept" << "not" << "not_eq" << "nullptr"
             << "operator" << "or" << "or_eq" << "private" << "protected" << "public"
             << "register" << "reinterpret_cast" << "requires" << "return"
             << "short" << "signed" << "sizeof" << "static" << "static_assert"
             << "static_cast" << "struct" << "switch" << "template" << "this"
             << "thread_local" << "throw" << "true" << "try" << "typedef"
             << "typeid" << "typename" << "union" << "unsigned" << "using"
             << "virtual" << "void" << "volatile" << "wchar_t" << "while"
             << "xor" << "xor_eq";


    completer = new QCompleter(wordList, this);
    completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWrapAround(false);

    // Assuming 'codeEditor' is the name of your CodeEditor instance in the .ui file
    ui->MainWindow_2->setCompleter(completer);
}


//----------------------------------------------------------------------------------------------------------------------------------




MainWindow::~MainWindow()
{
    delete ui;
    delete highlighter;
}

//------------Slots--------------

void MainWindow::onZoomSliderValueChanged(int value) {
    qreal scaleFactor = value / 100.0; // Convert slider value to scale factor

    // Apply zoom to text in QPlainTextEdit
    QTextCursor cursor = ui->MainWindow_2->textCursor();
    QTextCharFormat format = cursor.charFormat();
    QFont font = format.font();
    font.setPointSize(10 * scaleFactor); // Adjust font size
    format.setFont(font);

    cursor.select(QTextCursor::Document);
    cursor.setCharFormat(format);

    ui->MainWindow_2->setTextCursor(cursor);
}

void MainWindow::on_actionCut_triggered()
{
    ui->MainWindow_2->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->MainWindow_2->copy();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->MainWindow_2->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->MainWindow_2->redo();
}


void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->MainWindow_2->clear();
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->MainWindow_2->setPlainText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    //QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->MainWindow_2->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->MainWindow_2->toPlainText();
    out << text;
    file.flush();
    file.close();

}


void MainWindow::on_actionClose_triggered()
{
    if (ui->MainWindow_2->document()->isModified()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Unsaved Changes",
                                    "You have unsaved changes. Do you want to save them before closing?",
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if (reply == QMessageBox::Cancel) {
            return; // Cancel the close operation
        } else if (reply == QMessageBox::Yes) {
            on_actionSave_triggered(); // Call save function if implemented
        }
    }
    this->close();
}


void MainWindow::on_actionFindReplace_triggered()
{
    FindReplaceDialog dialog(this);

    // Show the dialog and check if the user pressed OK
    if (dialog.exec() == QDialog::Accepted) {
        QString findText = dialog.findText();
        QString replaceText = dialog.replaceText();

        if (!findText.isEmpty()) {
            QString content = ui->MainWindow_2->toPlainText();
            content.replace(findText, replaceText, Qt::CaseSensitive); // Replace all occurrences
            ui->MainWindow_2->setPlainText(content); // Set the updated text back to the editor
        }
    }
}

