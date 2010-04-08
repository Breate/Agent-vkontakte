#include "cookie.h"

Cookie::Cookie(QString &a)
{
    a.remove(QChar(' '));
    QStringList slist=a.split(';');
    for(QStringList::iterator i=slist.begin();i!=slist.end();i++)
    {
        QStringList tmp=QString(*i).split('=');
        data.insert(tmp[0],tmp[1]);
    }
    }

void Cookie::addVaridata(QString &a,QString &b)
{
data.insert(a,b);
}

QString Cookie::toString()
{
    QString x;
    if(!data.isEmpty())
    for(QMap<QString,QString>::iterator i=data.begin();i!=data.end();++i)
        x+=QString("%1=%2;").arg(i.key()).arg(i.value());

    return x;
}
