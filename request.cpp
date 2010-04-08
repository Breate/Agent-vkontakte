#include "request.h"

Request::Request()
{
}

void Request::setHost(const QString &name)
{
host=name;
}

void Request::setPath(const QString &name)
{
path=name;
}

void Request::setParam(const QString &name,const QString &value)
{
param.insert(name,value);
}

void Request::setoHeader(const QString &name,const QString &value)
{
oHeaders.insert(name,value);
}

void Request::setCookie(const Cookie &a)
{
Cookies.push_back(a);
}

QString Request::getHost()
{return host;}

QString Request::toString()
{
    QString x;
    QString y;
    if(!param.isEmpty()){
    for(QMap<QString,QString>::iterator i=param.begin();i!=param.end();++i)
    {
        if(i==param.begin())y+=QString("?%1=%2").arg(i.key()).arg(i.value());
        else y+=QString("&%1=%2").arg(i.key()).arg(i.value());
    }
}

    x+=QString("%1%2 HTTP/1.1").arg(path).arg(y);
    x+=QString("\n");
    x+=QString("HOST: %1\n").arg(host);

   if(!oHeaders.isEmpty())
   for(QMap<QString,QString>::iterator i=oHeaders.begin();i!=oHeaders.end();++i)
       x+=QString("%1: %2\r\n").arg(i.key()).arg(i.value());
   if(!Cookies.isEmpty())
       for(QList<Cookie>::iterator i=Cookies.begin();i!=Cookies.end();++i)
        x+=QString("Cookie: %1\n").arg((*i).toString());

   x+=("\r\n\r\n");
return x;
}
