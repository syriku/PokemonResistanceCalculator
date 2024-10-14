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
    pokemon.ChangeType(arg);
    auto names = pokemon.PrintTypes();
    if(names.begin() == names.end())
    {
        ui->lb_type->setText("属性：空");
        return;
    }
    QString types = "属性：";
    for(auto &i: names)
    {
        types += i.c_str();
        types += "+";
    }
    types = types.removeLast();
    ui->lb_type->setText(types);
}

void MainWindow::on_cb_Water_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Water);
}


void MainWindow::on_cb_Fire_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Fire);
}


void MainWindow::on_cb_Grass_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Grass);
}


void MainWindow::on_cb_Electric_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Electric);
}


void MainWindow::on_cb_Dragon_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Dragon);
}


void MainWindow::on_cb_Ice_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Ice);
}


void MainWindow::on_cb_Psychic_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Psychic);
}


void MainWindow::on_cb_Dark_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Dark);
}


void MainWindow::on_cb_Bug_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Bug);
}


void MainWindow::on_cb_Flying_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Flying);
}


void MainWindow::on_cb_Rock_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Rock);
}


void MainWindow::on_cb_Ground_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Ground);
}


void MainWindow::on_cb_Fighting_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Fighting);
}


void MainWindow::on_cb_Poison_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Poison);
}


void MainWindow::on_cb_Fairy_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Fairy);
}


void MainWindow::on_cb_Steel_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Steel);
}


void MainWindow::on_cb_Normal_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Normal);
}


void MainWindow::on_cb_Ghost_checkStateChanged(const Qt::CheckState &arg1)
{
    ToGetResistance(Pokemon::Ghost);
}

