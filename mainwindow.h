#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionBold_triggered(bool checked);

    void on_actionNew_FIle_triggered();

    void on_actionOpen_File_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionPaste_triggered();

    void on_actionItalic_triggered(bool checked);

    void on_actionResume_triggered();

    void on_actionsuperscript_triggered(bool checked);

    void on_actionsubscript_triggered(bool checked);

    void selectFont();

    void on_actionFontsinc_triggered();

    void on_actionFontsdec_triggered();

    void on_actionResume_pdf_triggered();

private:
    Ui::MainWindow *ui;
    QString mFilename;
};

#endif // MAINWINDOW_H
