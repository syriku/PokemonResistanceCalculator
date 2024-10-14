#include "licensewindow.h"
#include "./ui_license.h"

void LicenseWindow::on_pushButton_clicked()
{
    this->close();
}

LicenseWindow::LicenseWindow(QWidget* parent)
    :QDialog(parent)
    ,ui(new Ui::LicenseWindow)
{
    ui->setupUi(this);
}

LicenseWindow::~LicenseWindow()
{
    delete ui;
}
