#include "damagewindow.h"
#include "./ui_damagewindow.h"
#include <QString>

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


void DamageWindow::on_sb_hpv_valueChanged(int arg1)
{
    pokemon.hp.value = arg1;
}


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


void DamageWindow::on_sb_defv_valueChanged(int arg1)
{
    pokemon.def.value = arg1;
}

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


void DamageWindow::on_sb_Attack_valueChanged(int arg1)
{
    pokemon.attack = arg1;
}


void DamageWindow::on_sb_Factor_valueChanged(double arg1)
{
    pokemon.factor = arg1;
}


void DamageWindow::on_sb_Power_valueChanged(int arg1)
{
    pokemon.power = arg1;
}


// void DamageWindow::on_sb_hpss_editingFinished()
// {
//     pokemon.hp.speciesStrength = ui->sb_hpss->value();
//     CalculateStat(true);
//     pokemon.Damage();
// }


// void DamageWindow::on_sb_hpiv_editingFinished()
// {
//     pokemon.hp.IV = ui->sb_hpiv->value();
//     CalculateStat(true);
//     pokemon.Damage();

// }


// void DamageWindow::on_sb_hpp_editingFinished()
// {
//     pokemon.hp.points = ui->sb_hpp->value();
//     CalculateStat(true);
//     pokemon.Damage();

// }


// void DamageWindow::on_sb_hpv_editingFinished()
// {
//     pokemon.hp.value = ui->sb_hpv->value();
//     pokemon.Damage();
// }


// void DamageWindow::on_sb_defss_editingFinished()
// {
//     pokemon.def.speciesStrength = ui->sb_defss->value();
//     CalculateStat(true);
//     pokemon.Damage();

// }


// void DamageWindow::on_sb_defiv_editingFinished()
// {
//     pokemon.def.IV = ui->sb_defiv->value();
//     CalculateStat(true);
//     pokemon.Damage();

// }


// void DamageWindow::on_sb_defp_editingFinished()
// {
//     pokemon.def.points = ui->sb_defp->value();
//     CalculateStat(true);
//     pokemon.Damage();

// }


// void DamageWindow::on_sb_defv_editingFinished()
// {
//     pokemon.def.value = ui->sb_defv->value();
//     pokemon.Damage();
// }


// void DamageWindow::on_sb_Attack_editingFinished()
// {
//     pokemon.attack = ui->sb_Attack->value();
//     pokemon.Damage();
// }


// void DamageWindow::on_sb_Power_editingFinished()
// {
//     pokemon.power = ui->sb_Power->value();
//     pokemon.Damage();
// }


// void DamageWindow::on_sb_Factor_editingFinished()
// {
//     pokemon.factor = ui->sb_Factor->value();
//     pokemon.Damage();
// }


void DamageWindow::on_b_Calculate_clicked()
{
    int max = pokemon.Damage();
    int min = max * 0.85;
    float maxPer = float(max*100) / pokemon.hp.value;
    float minPer = float(min*100) / pokemon.hp.value;
    QString ans = "造成伤害：";
    char dmg1[10], dmg2[10];
    ans = ans + QString::number(minPer, 'f', 1) + "% ~ " + QString::number(maxPer, 'f', 1) + "%"; 
    ui->l_Damage->setText(ans);
    ui->l_Damage->adjustSize();
}

