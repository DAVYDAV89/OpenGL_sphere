#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_X_clicked(bool _state)
{
    ui -> glWidget -> X = _state;
}

void MainWindow::on_Y_clicked(bool _state)
{

    ui -> glWidget -> Y = _state;
}

void MainWindow::on_Z_clicked(bool _state)
{
    ui -> glWidget -> Z = _state;
}

void MainWindow::on_checkBox_clicked(bool _state)
{
    ui -> glWidget -> wired = _state;
}

void MainWindow::on_R_valueChanged(int _r)
{
    ui -> glWidget -> R = _r;
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

