#ifndef WEIGHTCOEFFICIENT_H
#define WEIGHTCOEFFICIENT_H

#include <QMainWindow>
#include <QDebug>
#include <QtMath>

namespace Ui {
class WeightCoefficient;
}

class WeightCoefficient : public QMainWindow
{
    Q_OBJECT

public:
    explicit WeightCoefficient(QWidget *parent = 0);
    ~WeightCoefficient();

private:
    Ui::WeightCoefficient *ui;

private slots:
    double roundDouble(double doValue, int nPrecision);
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void Calculation_of_mass(int i);
};

#endif // WEIGHTCOEFFICIENT_H
