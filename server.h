#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
namespace DuarteCorporation
{


class messenger;

class server : public QTcpServer
{
public:
    server(QObject *parent = nullptr);
    bool  startServer(quint16 port);
protected:
   void incomingConnection(qintptr handle);
private:
    QList<messenger *> mSockets;
};
}
#endif // SERVER_H
