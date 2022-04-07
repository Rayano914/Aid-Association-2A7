#ifndef STAT_caisse_H
#define STAT_caisse_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <iostream>
#include <vector>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


using namespace std;

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_caisse;
}

class stat_caisse : public QDialog
{
    Q_OBJECT

public:
    explicit stat_caisse(QWidget *parent = nullptr);
    ~stat_caisse();

    QChartView *chartView;
    void choix_pie();

private:
    Ui::stat_caisse *ui;
};

#endif // STAT_caisse_H
