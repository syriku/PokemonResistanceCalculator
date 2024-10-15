#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , calculator(new DamageWindow) 
{
    ui->setupUi(this);
    cb = {
        ui->cb_Bug,
        ui->cb_Dark,
        ui->cb_Dragon,
        ui->cb_Electric,
        ui->cb_Fairy,
        ui->cb_Fighting,
        ui->cb_Fire,
        ui->cb_Flying,
        ui->cb_Ghost,
        ui->cb_Grass,
        ui->cb_Ground,
        ui->cb_Ice,
        ui->cb_Normal,
        ui->cb_Poison,
        ui->cb_Psychic,
        ui->cb_Rock,
        ui->cb_Steel,
        ui->cb_Water
    };
}

MainWindow::~MainWindow()
{
    delete calculator;
    delete ui;
    
}

void MainWindow::ToGetResistance(Pokemon::PokemonType arg, bool toClear=false)
{
    if(toClear)
    {
        pokemon.ClearType();
        stateChangedProcess = false;
        for(const auto& checkbox: cb)
        {
            checkbox->setChecked(false);
        }
        stateChangedProcess = true;
    }
    else
        pokemon.ChangeType(arg);
    auto names = pokemon.PrintTypes();
    if(names.begin() == names.end())
    {
        ui->lb_type->setText("属性：空");
    }
    else
    {
        QString types = "属性：";
        for(auto &i: names)
        {
            types += i.c_str();
            types += "+";
        }
        types = types.removeLast();
        ui->lb_type->setText(types);
    }
    auto resistance = pokemon.GetResistance();
    std::vector<QTableWidgetItem*> resistance_item;
    for(const auto& s: resistance)
    {
        resistance_item.push_back(new QTableWidgetItem(s.c_str()));
    }
    for(int i=0;i<3;i++)
    {
        ui->t_resistance->setItem(i,0, resistance_item[i]);
    }
    ui->t_resistance->resizeColumnsToContents();
    CheckableCheck();
}

void MainWindow::CheckableCheck()
{
    if(pokemon.types.size() < 2)
        for(const auto& checkbox: cb)
        {
            checkbox->setCheckable(true);
        }
    else if(pokemon.types.size() == 2)
    {
        for(const auto& checkbox: cb)
        {
            if(!checkbox->isChecked())
            {
                checkbox->setCheckable(false);
            }
        }
    }
}

void MainWindow::on_cb_Water_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Water);
}


void MainWindow::on_cb_Fire_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Fire);
}


void MainWindow::on_cb_Grass_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Grass);
}


void MainWindow::on_cb_Electric_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Electric);
}


void MainWindow::on_cb_Dragon_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Dragon);
}


void MainWindow::on_cb_Ice_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Ice);
}


void MainWindow::on_cb_Psychic_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Psychic);
}


void MainWindow::on_cb_Dark_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Dark);
}


void MainWindow::on_cb_Bug_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Bug);
}


void MainWindow::on_cb_Flying_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Flying);
}


void MainWindow::on_cb_Rock_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Rock);
}


void MainWindow::on_cb_Ground_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Ground);
}


void MainWindow::on_cb_Fighting_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Fighting);
}


void MainWindow::on_cb_Poison_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Poison);
}


void MainWindow::on_cb_Fairy_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Fairy);
}


void MainWindow::on_cb_Steel_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Steel);
}


void MainWindow::on_cb_Normal_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Normal);
}


void MainWindow::on_cb_Ghost_checkStateChanged(const Qt::CheckState &arg1)
{
    if(stateChangedProcess)
    ToGetResistance(Pokemon::Ghost);
}


void MainWindow::on_b_Clear_clicked()
{
    ToGetResistance(Pokemon::Normal, true);
}


void MainWindow::on_actionLicense_triggered()
{
    dialog.show();
}


void MainWindow::on_actioncalculator_triggered()
{
    calculator->show();
}

