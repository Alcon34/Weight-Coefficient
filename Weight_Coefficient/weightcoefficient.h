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
    void Calculation_of_mass_v1();
    void Calculation_of_mass_v2();
    void Calculation_of_mass_v3();
    void Calculation_of_mass_all();
    double roundDouble(double doValue, int nPrecision);
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
};

#endif // WEIGHTCOEFFICIENT_H
