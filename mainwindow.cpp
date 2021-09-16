#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>

#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Text Editor");
    this->setCentralWidget(ui->textEdit);

    connect(ui->actionFont, &QAction::triggered, this, &MainWindow::selectFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::selectFont()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        ui->textEdit->setFont(font);
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

void MainWindow::on_actionResume_triggered()
{
    QLabel *label = new QLabel();

    label->setGeometry(50, 50, 1200, 700);
    label->setText("<h1>Anshuman Prajapati</h1>\
                    <p><b>Email: </b>anshumanprajapati2000@gmai.com</p>\
                    <p><b>Phone: </b>9755689712</p>\
                    <h2>Experience</h2>");
    label->show();

}

void MainWindow::on_actionResume_pdf_triggered()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile( "Anshuman.pdf" ) );

}


void MainWindow::on_actionsuperscript_triggered(bool checked)
{
    if(checked){
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
         if(ui->textEdit->hasFocus())
            ui->textEdit->mergeCurrentCharFormat(format);
    }
    else{
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
         if(ui->textEdit->hasFocus())
            ui->textEdit->mergeCurrentCharFormat(format);
    }

}


void MainWindow::on_actionsubscript_triggered(bool checked)
{
    if(checked){
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
         if(ui->textEdit->hasFocus())
            ui->textEdit->mergeCurrentCharFormat(format);
    }
    else{
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
         if(ui->textEdit->hasFocus())
            ui->textEdit->mergeCurrentCharFormat(format);
    }

}



void MainWindow::on_actionFontsinc_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    int fontSize = ui->textEdit->font().pointSize() +2;
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(fontSize);
    ui->textEdit->setTextCursor( cursor );
}


void MainWindow::on_actionFontsdec_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    int fontSize = ui->textEdit->font().pointSize() -2;
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(fontSize);
    ui->textEdit->setTextCursor( cursor );
}




