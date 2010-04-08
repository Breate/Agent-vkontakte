#ifndef ANSWER_H
#define ANSWER_H
#include <QString>
#include <QStringList>
#include <QMap>
#include <QList>


#include "cookie.h"

class Answer
{
    int answerCode;
    QMap<QString,QString> oHeaders;
    QList<Cookie> Cookies;

    QByteArray data;
 public:
    Answer(QByteArray);

    int StatusCode();
    QString redirectLocate();
    QList<Cookie> getCookie();
    QByteArray getData();
};

#endif // ANSWER_H
