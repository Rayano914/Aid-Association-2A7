#include "messenger.h"
namespace DuarteCorporation
{
messenger::messenger(qintptr handle,QObject *parent) : QTcpSocket(parent)
{
   setSocketDescriptor(handle);
   connect(this, &messenger::readyRead, [&]() {
       emit DUReadyRead(this);
   });
   connect(this, &messenger::stateChanged, [&](int S){
      emit DuStateChanged(this, S);
   });
}

}
