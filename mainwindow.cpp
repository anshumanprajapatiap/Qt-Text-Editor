#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBold_triggered(bool checked)
{
    checked ? ui->textEdit->setFontWeight(QFont::Bold) :
              ui->textEdit->setFontWeight(QFont::Normal);
}

void MainWindow::on_actionNew_FIle_triggered()
{
    mFilename = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a File");

    if(!file.isEmpty() )
    {
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text) )
        {
            mFilename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFilename);
    if(sFile.open(QFile::WriteOnly | QFile::Text) )
    {
        QTextStream out(&sFile);

        out<< ui->textEdit->toPlainText();

        sFile.flush();
        sFile.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save as File");
    if(!file.isEmpty() )
    {
        mFilename = file;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionItalic_triggered(bool checked)
{
    checked ? ui->textEdit->setFontItalic(checked) :
               ui->textEdit->setFontWeight(QFont::Normal);
}
