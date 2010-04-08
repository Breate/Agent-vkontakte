#ifndef REQUEST_H
#define REQUEST_H


#include <QMap>
#include <QList>
#include <QString>


#include "cookie.h"

class Request
{
    QString host;
    QString path;
    QMap<QString,QString> param;
    QMap<QString,QString> oHeaders;
    QList<Cookie> Cookies;

public:
    Request();
    void setHost(const QString&);
    void setPath(const QString&);

    void setParam  (const QString&,const QString &);
    void setoHeader(const QString&,const QString &);
    void setCookie (const Cookie &);

    QString getHost();
    QString toString();

};

#endif // REQUEST_H
