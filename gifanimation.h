#ifndef GIFANIMATION_H
#define GIFANIMATION_H
#include<QObject>


class QLabel;
class QMovie;
class GifAnimation : QObject
{
public:
    GifAnimation(QObject *parent = nullptr);
    void startMovie();
    void setFilename(const QString &filename)
    {
        mFilename = filename;
    }
    QString getFilename()
    {
        return mFilename;
    }
    QLabel *getWidget() const
    {
        return mLabel;
    }
private:
    QLabel *mLabel;
    QMovie *mMovie;
    QString mFilename;
};

#endif // GIFANIMATION_H
