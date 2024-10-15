#ifndef DAMAGEWINDOW_H
#define DAMAGEWINDOW_H

#include <QMainWindow>
#include "./DamageCalculator/pokemondamage.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class DamageWindow;
}
QT_END_NAMESPACE

class DamageWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit DamageWindow(QWidget *parent = nullptr);
    ~DamageWindow();

signals:

private slots:

    void on_sb_hpss_valueChanged(int arg1);

    void on_sb_hpiv_valueChanged(int arg1);

    void on_sb_hpp_valueChanged(int arg1);

    void on_sb_hpv_valueChanged(int arg1);

    void on_sb_defss_valueChanged(int arg1);

    void on_sb_defiv_valueChanged(int arg1);

    void on_sb_defp_valueChanged(int arg1);

    void on_cb_defn_currentIndexChanged(int index);

    void on_sb_defv_valueChanged(int arg1);

    void on_cb_Level_currentIndexChanged(int index);

    void on_sb_Attack_valueChanged(int arg1);

    // void on_spinBox_5_valueChanged(int arg1);

    // void on_doubleSpinBox_valueChanged(double arg1);

    void on_sb_Factor_valueChanged(double arg1);

    void on_sb_Power_valueChanged(int arg1);

    // void on_sb_hpss_editingFinished();

    // void on_sb_hpiv_editingFinished();

    // void on_sb_hpp_editingFinished();

    // void on_sb_hpv_editingFinished();

    // void on_sb_defss_editingFinished();

    // void on_sb_defiv_editingFinished();

    // void on_sb_defp_editingFinished();

    // void on_sb_defv_editingFinished();

    // void on_sb_Attack_editingFinished();

    // void on_sb_Power_editingFinished();

    // void on_sb_Factor_editingFinished();

    void on_b_Calculate_clicked();

private:
    Ui::DamageWindow* ui;
    void CalculateStat(bool);
    Pokemon::PokemonDamage pokemon;
};

#endif // DAMAGEWINDOW_H
