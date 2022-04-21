#ifndef DUSCENE_H
#define DUSCENE_H
#include <QGraphicsScene>

class GifAnimation;
class Duscene : public QGraphicsScene


{
public:
    Duscene(QObject *parent = nullptr);
private:
    GifAnimation *mGifAnimation;
};

#endif // DUSCENE_H
