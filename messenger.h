#ifndef MESSENGER_H
#define MESSENGER_H

#include <QTcpSocket>
namespace DuarteCorporation
{
class messenger : public QTcpSocket
{
    Q_OBJECT
public:
    messenger(qintptr handle,QObject *parent =nullptr);
signals:
    void DUReadyRead(messenger *);
    void DuStateChanged(messenger *, int);
};
}
#endif // MESSENGER_H
