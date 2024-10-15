#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QCheckBox>
#include "pokemonstate.h"
#include "licensewindow.h"
#include "damagewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cb_Water_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Fire_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Grass_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Electric_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Dragon_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Ice_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Psychic_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Dark_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Bug_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Flying_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Rock_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Ground_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Fighting_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Poison_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Fairy_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Steel_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Normal_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_Ghost_checkStateChanged(const Qt::CheckState &arg1);

    void on_b_Clear_clicked();

    void on_actionLicense_triggered();

    void on_actioncalculator_triggered();

private:
    Ui::MainWindow *ui;
    void ToGetResistance(Pokemon::PokemonType,bool);
    Pokemon::PokemonState pokemon;
    std::vector<QCheckBox*> cb;
    void CheckableCheck();
    bool stateChangedProcess = true;
    LicenseWindow* dialog;
    DamageWindow* calculator;
};
#endif // MAINWINDOW_H
