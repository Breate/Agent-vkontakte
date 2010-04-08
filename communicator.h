#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QTcpSocket>
#include "answer.h"
#include "request.h"
class Communicator : public QTcpSocket
{
public:
    Communicator();
    Answer *get(Request&);
};

#endif // COMMUNICATOR_H
