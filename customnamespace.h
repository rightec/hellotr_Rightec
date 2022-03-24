#ifndef CUSTOMNAMESPACE_H
#define CUSTOMNAMESPACE_H

#include <QTranslator>

namespace ContosoData
{

class ObjectManager
{
public:
    void DoSomething() {}
};


class TrManager
{
public:
    explicit TrManager(){}
    ~TrManager(){}

    QTranslator *getTranslator() {return &translator;}
    QString     getFile() {return file;}
    void setFile(QString _file){file = _file;}
private:
    QTranslator translator;
    QString     file;

};

}
#endif // CUSTOMNAMESPACE_H
