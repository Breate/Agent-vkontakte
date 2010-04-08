#include "communicator.h"

Communicator::Communicator():QTcpSocket()
{
}

Answer *Communicator::get(Request &a)
{

    QString host=a.getHost();
    qDebug(host.toAscii());
    this->connectToHost(host,80);
        if(!waitForConnected(30000)){
                qWarning() << "not connected";
                Answer *tmp=new Answer(QByteArray());
                return tmp;
        }

        QString rec=a.toString();
        rec.push_front("GET /");
qDebug(rec.toAscii());
    this->write(rec.toAscii());

    if(!waitForBytesWritten(2000)){
                qWarning() << "not writed";
                Answer *tmp=new Answer(QByteArray());
                return tmp;
            }
    QByteArray answer;
        while(waitForReadyRead(30000)){
                answer += readAll();
        }
        qDebug(answer);
    Answer *tmp=new Answer(answer);
    return tmp;

}
