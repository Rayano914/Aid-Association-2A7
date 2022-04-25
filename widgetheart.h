#ifndef WIDGETHEART_H
#define WIDGETHEART_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widgetheart; }
QT_END_NAMESPACE

class Duscene;
class Widgetheart : public QWidget
{
    Q_OBJECT

public:
    Widgetheart(QWidget *parent = nullptr);
    ~Widgetheart();

private:
    Ui::Widgetheart *ui;
    Duscene *mScene;
};
#endif // WIDGETHEART_H
