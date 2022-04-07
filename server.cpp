#include "server.h"
#include "messenger.h"
#include <QTextStream>
#include <QDebug>
namespace DuarteCorporation
{
server::server(QObject *parent)
    : QTcpServer(parent)
{

}
bool server::startServer(quint16 port)
{
  return listen(QHostAddress::Any, port);
}



void server::incomingConnection(qintptr handle)
{
    qDebug()<<"client connected with handle:"<<handle;
    auto socket = new messenger(handle, this);
    mSockets << socket;
    for (auto i : mSockets)
    {
        QTextStream T(i);
        T <<"se de conecter" <<handle;
        i->flush();
    }
    connect(socket, &messenger::DUReadyRead, [&](messenger *S){
        qDebug() << "DuReadyRead";
        QTextStream T(S);
       auto text = T.readAll();

       for(auto i : mSockets) {
           QTextStream k(i);
           k << text;
           i->flush();
       }
    });
    connect(socket, &messenger::DuStateChanged, [&](messenger *S, int ST){
        qDebug() <<"DuStateChanged"<<S->socketDescriptor();
        if (ST == QTcpSocket::UnconnectedState) {
            qDebug() <<"Unconnected state"<<S->socketDescriptor();
            mSockets.removeOne(S);
            for (auto i : mSockets){
                QTextStream k(i);
                k << "Server: le client"
                  <<S->socketDescriptor()
                  << "se deconncter";
                i->flush();
            }
        }
    });
}
}
