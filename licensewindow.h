#ifndef LICENSEWINDOW_H
#define LICENSEWINDOW_H

#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class LicenseWindow;
}
QT_END_NAMESPACE
class LicenseWindow: public QDialog
{
    Q_OBJECT
public:
    LicenseWindow(QWidget *parent = nullptr);
    ~LicenseWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LicenseWindow* ui;
};

#endif // LICENSEWINDOW_H
