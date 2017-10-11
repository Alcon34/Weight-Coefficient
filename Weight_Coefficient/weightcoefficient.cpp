#include "weightcoefficient.h"
#include "ui_weightcoefficient.h"

WeightCoefficient::WeightCoefficient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WeightCoefficient)
{
    ui->setupUi(this);
    QRegExp expCoef("[0-2]{0,1}");
    QRegExp expGram("[0-9]{0,4}");
    QRegExp expRatio("[1-9][0-9]?|100");
    QRegExp expTime("[1-9]{0,5}");
    QRegExp expSpeed("[1-9]{0,5}");
    ui->lineEdit->setValidator(new QRegExpValidator(expCoef, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(expCoef, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_5->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_6->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_7->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_8->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_9->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_10->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_11->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_12->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_13->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_14->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_15->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_16->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_17->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_18->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_19->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_20->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_21->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_22->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_23->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_24->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_25->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_26->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_36->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_39->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_40->setValidator(new QRegExpValidator(expGram, this));
    ui->lineEdit_35->setValidator(new QRegExpValidator(expRatio, this));
    ui->lineEdit_38->setValidator(new QRegExpValidator(expTime, this));
    ui->lineEdit_37->setValidator(new QRegExpValidator(expSpeed, this));
    ui->lineEdit_27->setValidator(new QRegExpValidator(expCoef, this));
    ui->lineEdit_28->setValidator(new QRegExpValidator(expCoef, this));
    ui->lineEdit_31->setValidator(new QRegExpValidator(expCoef, this));
    ui->lineEdit_33->setValidator(new QRegExpValidator(expCoef, this));
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setDisabled(true);

}

void WeightCoefficient::on_pushButton_4_clicked() //1 кнопка рачитать
{


}

void WeightCoefficient::on_pushButton_clicked() //2 кнопка рачитать
{
    Calculation_of_mass(1);

}

void WeightCoefficient::Calculation_of_mass(int i)
{
    double Component_Weight_A_1 =  ui->lineEdit_39->text().toDouble();
    double Component_Weight_A_2 =  ui->lineEdit_39->text().toDouble();
    double Component_Weight_A_3 =  ui->lineEdit_39->text().toDouble();
    double Component_Weight_A_1_st =  ui->lineEdit_40->text().toDouble();
    double Component_Weight_A_2_st =  ui->lineEdit_40->text().toDouble();
    double Component_Weight_A_3_st =  ui->lineEdit_40->text().toDouble();

    double Component_Weight_B_1 =  ui->lineEdit_40->text().toDouble();
    double Component_Weight_B_2 =  ui->lineEdit_40->text().toDouble();
    double Component_Weight_B_3 =  ui->lineEdit_40->text().toDouble();
    double Component_Weight_B_1_st =  ui->lineEdit_40->text().toDouble();
    double Component_Weight_B_2_st =  ui->lineEdit_40->text().toDouble();
    double Component_Weight_B_3_st =  ui->lineEdit_40->text().toDouble();

    double Weight_A = 1;
    double Weight_B = 2;

    double Component_Weight_A_sum_st = Component_Weight_A_1_st+Component_Weight_A_2_st+Component_Weight_A_3_st;
    double Component_Weight_B_sum_st = Component_Weight_B_1_st+Component_Weight_B_2_st+Component_Weight_B_3_st;
    double Component_Weight_A_sum = Component_Weight_A_1+Component_Weight_A_2+Component_Weight_A_3;
    double Component_Weight_B_sum = Component_Weight_B_1+Component_Weight_B_2+Component_Weight_B_3;

    double Coefficient_A_end = ((Component_Weight_A_sum_st+Component_Weight_A_sum)/i)/Weight_A;
    double Coefficient_B_end = ((Component_Weight_B_sum_st+Component_Weight_B_sum)/i)/Weight_B;

    ui->lineEdit_27->setText(QVariant(Coefficient_A_end).toString());
    ui->lineEdit_28->setText(QVariant(Coefficient_B_end).toString());
}

double WeightCoefficient::roundDouble(double doValue, int nPrecision)//преобразование точности
{
    static const double doBase = 10.0;
    double doComplete5, doComplete5i;

    doComplete5 = doValue * pow(doBase, (double) (nPrecision + 1));

    if (doValue < 0.0)
        doComplete5 -= 5.0;
    else
        doComplete5 += 5.0;

    doComplete5 /= doBase;
    modf(doComplete5, &doComplete5i);

    return doComplete5i / pow(doBase, (double) nPrecision);
}

WeightCoefficient::~WeightCoefficient()
{
    delete ui;
}

