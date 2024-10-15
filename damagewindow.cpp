#include "damagewindow.h"
#include "./ui_damagewindow.h"

DamageWindow::DamageWindow(QWidget *parent)
    : QMainWindow{parent}
    ,ui(new Ui::DamageWindow)
{
    ui->setupUi(this);
}

DamageWindow::~DamageWindow()
{
    delete ui;
}
void DamageWindow::on_hs_Attack_valueChanged(int value)
{

}

