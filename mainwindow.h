#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QSlider>

#include <QCompleter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SyntaxHighlighter;
class CodeEditor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionClose_triggered();

    void on_actionFindReplace_triggered();

    void onZoomSliderValueChanged(int value);

private:
    Ui::MainWindow *ui;
    SyntaxHighlighter *highlighter;

    QString file_path;

    QSlider *zoomSlider;



    void setupCompleter();
    QCompleter *completer;

};

#endif // MAINWINDOW_H
