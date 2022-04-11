#ifndef TEXTDATA_H
#define TEXTDATA_H

#include "declarations.h"
class TextData
{
public:
    TextData(){}


    int makeDir(QString itsDir);
    int initWrite(QString itsFilePath);
    void write(QString text);
    void getAttribute();
    void close();
private:
    QFile textFile;
    QTextStream textStream;
    QString filePath;
    QTextCodec* codec;
    QDir dir;

};

#endif // TEXTDATA_H
