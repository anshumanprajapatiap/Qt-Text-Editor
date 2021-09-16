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

    label->setGeometry(0, 0, 1200, 900);
    label->setText(" <h1>Anshuman Prajapati</h1>\
                   <b>Email:</b> anshumanprajapati2000@gmai.com\
                   <br><b>Phone: </b> 9755689712\
                   \
                   <h2>Experience</h2>\
                   \
                   <p> <b> RF Enterprise </b> |  Back-End Developer |<i> Free-lanced </i> | May June \
                    \
                   <br>\
                   Designed and implemented a API and dashboard of automobile trading using Django and Ajax to stored and retrieve data in SQLLite, for carsify.in\
                   <br> Tools/technology  : Python, Django,  SQLite,  Ajax,  API.\
                   </p>\
                   \
                   <p> <b> HireXp </b> |  Internship |<i> Software Developer Intern </i> | September 2020 - March 2021 \
                   <br>\
                   Developed the LSTM model for sentiment analysis using NLTK & keras, and the gensim-lda model for topic modeling and the amara,ai interface.\
                   <br> Tools/technology  : HTML, CSS, Gensimlda, NLTK, Keras, LSTM.\
                   </p>\
                   \
                   <p> <b> 7 Institute of performing arts Pvt. Ltd. </b>| Project lead & Back-end developer |<i> Free-lanced </i> | Oct 2020– Feb 2021\
                   <br>\
                   eveloped django backend with SQLlite database and integrated profile, course, and Institute management. sipaindia.com\
                   <br> Lead an8 person team for the institute, event, and production house websites, three from graphics design and five from web front-End.\
                   <br> Tools/technology : Django, Python, SQLite.\
                   </p>\
                   \
                   <h2>Education</h2>\
                   \
                   \
                   <table>\
                     <tr>\
                       <th>Instiute</th>\
                       <th>Passing Year</th>\
                       <th>Course</th>\
                       <th>Percentage/CGPA</th>\
                       <th>Specialization</th>\
                     </tr>\
                     <tr>\
                       <td>University Institute of Technology - RGPV </td>\
                       <td>2022</td>\
                       <td>Higher secondary</td>\
                       <td>7.68</td>\
                       <td>Information Technology</td>\
                     </tr>\
                     <tr>\
                       <td>Anupama Hr. Sec. School, Satna </td>\
                       <td>2018</td>\
                       <td>B.Tech</td>\
                       <td>62.6</td>\
                       <td>PCM</td>\
                     </tr>\
                     <tr>\
                       <td>St. Michael’s Sen. Sec. School, Satna  </td>\
                       <td>2016</td>\
                       <td>Secondary standard</td>\
                       <td>8.20</td>\
                       <td>NaN</td>\
                     </tr>\
                   \
                   </table>\
                   \
                   <h2>Projects</h2>\
                   <p>\
                     <b>AADIT Virtual Assistant | Django, PostgreSQL, API, Ajax </b>\
                     <br>\
                     Designed API for keyword search, attendance automation and database for   students and campus-related information.\
                   </p>\
                   <p>\
                     <b>PWS web compiler | Django, Python, API, Ajax </b>\
                     <br>\
                     Designed and built an API for server system interaction, to building and running programs in C, C++, Java, and Python, as well as a practise and contest hosting platform for competitive programming.\
                   </p>\
                   <p>\
                     <b>E-commerce Web application | Django, Python, SQLite </b>\
                     <br>\
                     Implemented full-stack B2C and B2B management system, designed customer - shop schema, and shop inventory system.\
                   </p>\
                   \
                   <p>\
                     <b>Intelligence Traffic System | Python, IoT, Adobe XD </b>\
                     <br>\
                     Implemented live time sensors, for reading and modifying the system, and designed the User Interface for E-Challan.\
                   </p>\
                   \
                   <h2>Position of Responsibility</h2>\
                   \
                   <p><b>Licensee</b> | TEDxRGPV | June 2021 – May 2022\
                     <br>Acquired one year university license to organise independent TEDx event.\
                   </p>\
                   \
                   <p><b>Co-Founder & Presiden</b> |  Asper | Feb 2020 – Feb 2022\
                     <br>Design & Development Society aims at providing training to potential\
                   <br>learners with an opportunity to try hands over industrial projects.\
                   </p>\
                   \
                   <p><b>Technical Staff Member</b> | BookBucke |Aug 2019 – Feb 2021\
                     <br>College platform to buy, sell or rent pre-owned books, driving the prices down by 30% , Extended it to 6 colleges in Bhopal. A customer base of around 550.\
                   </p>\
                    ");
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




