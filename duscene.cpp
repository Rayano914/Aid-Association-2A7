#include "duscene.h"
#include "gifanimation.h"
#include <QLabel>

Duscene::Duscene(QObject *parent)
    : QGraphicsScene(parent)
{
mGifAnimation = new GifAnimation(this);
mGifAnimation->setFilename("C:/Users/Malek Ayedi/Desktop/movie.gif");
mGifAnimation->startMovie();
addWidget(mGifAnimation->getWidget());
}
