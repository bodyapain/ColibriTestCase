include "text_data.h"

int TextData::makeDir(QString itsDir)
{
    bool err;
    err = dir.mkdir(itsDir);
    return !err;
}

int TextData::initWrite(QString itsFilePath)
{

    bool err;
    codec = QTextCodec::codecForName("CP866");
    QTextStream cout(stdout);
    filePath = itsFilePath;
    textFile.setFileName(filePath);
    if(!textFile.open(QIODevice::Append|QIODevice::ReadOnly|QIODevice::Text))
    {
        cout << "error: cannot open file to read!";
        err = true;
        return err;
    }
    else
    {
        textStream.setDevice(&textFile);
        err = false;
        return err;
    }

}


/*void  TextData::write(QString text)
{
    QString message = "следующие данные были записаны в  файл:\n\n";
    QTextStream cout(stdout);
    cout.setCodec(codec);
    textStream <<text <<"\n";
    cout << "\nfollowing data was written to file";
    cout << message;
    cout<< text << "\n";
}*/

void TextData::close()
{
    textFile.close();
}

