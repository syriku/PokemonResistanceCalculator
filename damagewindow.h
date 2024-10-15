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

    // void on_sb_hpv_valueChanged(int arg1);

    void on_sb_defss_valueChanged(int arg1);

    void on_sb_defiv_valueChanged(int arg1);

    void on_sb_defp_valueChanged(int arg1);

    void on_cb_defn_currentIndexChanged(int index);

    // void on_sb_defv_valueChanged(int arg1);

    void on_cb_Level_currentIndexChanged(int index);

private:
    Ui::DamageWindow* ui;
    void CalculateStat(bool);
    Pokemon::PokemonDamage pokemon;
};

#endif // DAMAGEWINDOW_H
