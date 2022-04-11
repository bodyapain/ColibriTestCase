#ifndef DIRECTORIES_H
#define DIRECTORIES_H
#include <declarations.h>
#include <QWidget>

namespace Ui {
class Directories;
}

class Directories : public QWidget
{
    Q_OBJECT

public:
    explicit Directories(QWidget *parent = nullptr);
    ~Directories();


private:
    Ui::Directories *ui;
    QFileSystemModel *model;

};

#endif // DIRECTORIES_H
