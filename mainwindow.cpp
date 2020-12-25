#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <stdio.h>
#include<ahelp.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
Convert_mode MainWindow::getMode()
{

    if(ui->rfc->isChecked())
        return Convert_RFC ;
    else
        return Convert_PDF ;


}

void MainWindow::on_pushButton_clicked()
{


    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();
    ui->plainTextEdit->setPlainText(originalText) ;
    QString * lol = cleartext(originalText,getMode());
    ui->plainTextEdit_2->setPlainText(*lol);
    clipboard->setText(*lol);

    delete  lol ;
}

void MainWindow::on_refresh_clicked()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->setPlainText(originalText) ;
    QString * lol = cleartext(originalText,getMode());
    ui->plainTextEdit_2->setPlainText(*lol);
    clipboard->setText(*lol);
    delete  lol ;
}
