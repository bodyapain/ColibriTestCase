#include "directories.h"
#include "ui_directories.h"
#include <declarations.h>

Directories::Directories(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Directories)
{
    ui->setupUi(this);   
}

Directories::~Directories()
{
    delete ui;
}
