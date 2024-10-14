#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::ToGetResistance(Pokemon::PokemonType arg)
{
}

void MainWindow::on_cb_Water_checkStateChanged(const Qt::CheckState &arg1)
{
    
}

