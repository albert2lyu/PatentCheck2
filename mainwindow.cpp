#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QSettings>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    textDlg = new TextDlg(this);
    textDlg->hide();

    QSettings setting("SIPO-HN", "PatentCheck2");

    connect(ui->actionSettings_2, SIGNAL(triggered()), this, SLOT(showSettings()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(check()));

}

void MainWindow::initPatent(){

}

void MainWindow::checkClaims(){

}

void MainWindow::checkDesriptions(){

}

void MainWindow::checkFigures(){

}

void MainWindow::check(){
    // 如果内容全部为空
    if(ui->claimsTextEdit->toPlainText() == "" && \
            ui->descriptionTextEdit->toPlainText() == "" && \
            ui->drawingsTextEdit->toPlainText() == ""){
        int ret = QMessageBox::warning(this, tr("NO Content Input!"), \
                                                tr("No content is input.\nPlease paste your content here."), \
                                                QMessageBox::Cancel | QMessageBox::Ok);
        return;
    }


    // 生成通知书
    textDlg->show();

}

void MainWindow::showSettings(){
    ui->stackedWidget->setCurrentIndex(1);  // 0 is input widget, 1 is settings widget
    return;

}

MainWindow::~MainWindow()
{
    delete ui;
}
