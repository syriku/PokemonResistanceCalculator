#ifndef DAMAGEWINDOW_H
#define DAMAGEWINDOW_H

#include <QMainWindow>
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
    void on_hs_Attack_valueChanged(int value);

private:
    Ui::DamageWindow* ui;
};

#endif // DAMAGEWINDOW_H
