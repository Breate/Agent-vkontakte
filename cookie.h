#ifndef COOKIE_H
#define COOKIE_H

#include <QMap>
#include <QString>
#include <QStringList>
class Cookie
{
    QMap<QString,QString> data;
public:
    Cookie(QString&);
    void addVaridata(QString &name,QString &value);
    QString toString();
};

#endif // COOKIE_H
