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

void DamageWindow::on_sb_hpss_valueChanged(int arg1)
{
    pokemon.hp.speciesStrength = arg1;
    CalculateStat(true);
}


void DamageWindow::on_sb_hpiv_valueChanged(int arg1)
{
    pokemon.hp.IV = arg1;
    CalculateStat(true);
}



void DamageWindow::on_sb_hpp_valueChanged(int arg1)
{
    pokemon.hp.points = arg1;
    CalculateStat(true);

}


// void DamageWindow::on_sb_hpv_valueChanged(int arg1)
// {

// }


void DamageWindow::on_sb_defss_valueChanged(int arg1)
{
    pokemon.def.speciesStrength = arg1;
    CalculateStat(false);
}


void DamageWindow::on_sb_defiv_valueChanged(int arg1)
{
    pokemon.def.IV = arg1;
    CalculateStat(false);
}


void DamageWindow::on_sb_defp_valueChanged(int arg1)
{
    pokemon.def.points = arg1;
    CalculateStat(false);
}


void DamageWindow::on_cb_defn_currentIndexChanged(int index)
{
    // change the nature factor
    switch (index)
    {
    case 0:
        pokemon.def.nature = UNCHANGED;
        break;
    case 1:
        pokemon.def.nature = PLUS;
        break;
    case 2:
        pokemon.def.nature = MINUS;
        break;
    default:
    ;
    }
    CalculateStat(false);
}


// void DamageWindow::on_sb_defv_valueChanged(int arg1)
// {

// }

void DamageWindow::CalculateStat(bool hp)
{
    if(hp)
    {
        pokemon.hp.CalculateStat();
        ui->sb_hpv->setValue(pokemon.hp.value);
    }
    else
    {
        pokemon.def.CalculateStat();
        ui->sb_defv->setValue(pokemon.def.value);
    }
}

void DamageWindow::on_cb_Level_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        pokemon.level = 100;
        pokemon.hp.level = 100;
        pokemon.def.level = 100;
        break;
    case 1:
        pokemon.level = 50;
        pokemon.hp.level = 50;
        pokemon.def.level = 50;
        break;
    default:
        ;
    }
    CalculateStat(true);
    CalculateStat(false);
}

