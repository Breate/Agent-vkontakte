#include "answer.h"

Answer::Answer(QByteArray a)
{
    if(a.isEmpty())return;
    qDebug(a);
    QStringList list1=QString(a).split("\n\n");
    if(list1.size()==0)
    {
        answerCode=0;
        return;
    }
    qDebug(list1[0].toAscii());
    qDebug(list1[1].toAscii());
    QStringList list3 = QString(list1[0]).split(' ');
    answerCode=QString(list3[1]).toInt();
    list1[1].remove(QChar(' '));

    QStringList list2 = QString(list1[1]).split('\n');

    for(QStringList::iterator i=list2.begin();i!=list2.end();++i)
    {
        qDebug(QString(*i).toAscii());
    QStringList tmp = QString(*i).split(':');
    if(QString(tmp[0]).compare(QString("Set-Cookie"))){
        qDebug(QString(tmp[0]).toAscii());
        qDebug(QString(tmp[1]).toAscii());
        oHeaders.insert(tmp[0],tmp[1]);}
    else{
    Cookie tmp23(tmp[1]);
    Cookies.push_back(tmp23);
    }
    }
 if(list1.size()>1)data = QString(list1[1]).toAscii();
    }


    int Answer::StatusCode()
    {
        return answerCode;
    }


    QString Answer::redirectLocate()
    {
        return oHeaders["Location"];
    }

    QList<Cookie> Answer::getCookie()
    {
        return Cookies;
    }
    QByteArray Answer::getData()
    {
        return data;
    }
