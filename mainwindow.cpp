#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
//Timer::Timer(int hours, int min, int sec)

//{
//    timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(timerProcess()));
//    timer->start(hours*3600000+min*60000+sec*1000);
//}
//Timer::~Timer(){}
QString filename;
QString filename_sec;
void MainWindow::on_pushButton_clicked()
{

    filename = QFileDialog::getOpenFileName(this,"Выбрать файл","C:\\");
}


void MainWindow::on_pushButton_2_clicked()
{

     filename_sec = QFileDialog::getExistingDirectory(this,"Указать директорию","C:\\");
}

int a = 1;
QString strBuf = "";
void MainWindow::on_pushButton_3_clicked()
{
    QFile file(filename);
    QString str = ui->nameEdit->text();
    QString type = ui->comboBox->currentText();
    QString buf = str;

    if(ui->comboBox_2->currentIndex() == 0){ //перезаписать существуюущий файл

        QFile changedFile(filename_sec + "/" + str + type);
        if(QFile::exists(filename_sec + "/" + str + type)){
            changedFile.remove();
        }
        bool ok = changedFile.open(QIODevice::ReadWrite);
        file.open(QIODevice::ReadWrite| QIODevice::Text);

        QTextStream in(&file);
        QString line ="";
        if(ui->comboBox_3->currentIndex() == 0){//заменить все символы единицами
            while (!in.atEnd())
            {
                      line = in.readLine (); // Прочитать всю строку
                qDebug() << line;
            }
            for(int i =0;i < std::size(line);++i)
            {
                line[i] = '1';
            }
            changedFile.write(line.toUtf8());
            if(ui->checkBox_2->isChecked()){//перезаписать в входной файл
                file.remove();
                file.open(QIODevice::ReadWrite);
                file.write(line.toUtf8());
            }
        }

        if(ui->comboBox_3->currentIndex() == 1){//XOR
            quint32 key = 073;
            while (!in.atEnd())
            {
                      line = in.readLine (); // Прочитать всю строку
                qDebug() << line;
            }
            for(int i =0;i < std::size(line);++i)
            {
                line[i] = QChar(line[i].toLatin1()^key);
            }
            changedFile.write(line.toUtf8());
            if(ui->checkBox_2->isChecked()){//перезаписать в входной файл
                file.remove();
                file.open(QIODevice::ReadWrite);
                file.write(line.toUtf8());
            }
        }
        changedFile.close();
        file.close();
    }
    if(ui->comboBox_2->currentIndex() == 1)//индексация файлов
    {
        if(buf != strBuf){
            a = 1;
            strBuf = buf;
        }


        if(QFile::exists(filename_sec + "/" + buf + type))
        {

            str = buf + QString::number(a);
            a++;
        }
        QFile changedFile(filename_sec + "/" + str + type);

        bool ok = changedFile.open(QIODevice::ReadWrite);
        file.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream in(&file);
        QString line ="";
        if(ui->comboBox_3->currentIndex() == 0){//заменить все символы единицами
            while (!in.atEnd())
            {
                      line = in.readLine (); // Прочитать всю строку
                qDebug() << line;
            }
            for(int i =0;i < std::size(line);++i)
            {
                line[i] = '1';
            }
            changedFile.write(line.toUtf8());
            if(ui->checkBox_2->isChecked()){
                file.remove();
                file.open(QIODevice::ReadWrite);

                file.write(line.toUtf8());
            }
        }

        if(ui->comboBox_3->currentIndex() == 1){//XOR
            quint32 key = 073;
            while (!in.atEnd())
            {
                      line = in.readLine (); // Прочитать всю строку
                qDebug() << line;
            }
            for(int i =0;i < std::size(line);++i)
            {
                line[i] = QChar(line[i].toLatin1()^key);
            }
            changedFile.write(line.toUtf8());
            if(ui->checkBox_2->isChecked()){//перезаписать в входной файл
                file.remove();
                file.open(QIODevice::ReadWrite);
                file.write(line.toUtf8());
            }
        }
        changedFile.close();
        file.close();
    }
    if(ui->checkBox->isChecked()){//удалить входной файл
        file.remove();
    }
}

//void Timer::timerProcess(){
//
//void MainWindow::on_checkBox_3_stateChanged(int arg1)
//{
//    if(ui->checkBox_3->isChecked()){
//        int hours = ui->timeEdit->time().hour();
//        int min = ui->timeEdit->time().minute();
//        int sec = ui->timeEdit->time().second();
//       Timer supw(hours, min,  sec);
//    }

//}

