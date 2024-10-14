#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pokemonstate.h"

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

private:
    Ui::MainWindow *ui;
    void ToGetResistance(Pokemon::PokemonType);
    Pokemon::PokemonState pokemon;
};
#endif // MAINWINDOW_H
