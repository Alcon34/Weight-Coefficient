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

void WeightCoefficient::Calculation_of_mass_v1()
{
    float Weight_Relations = ui->lineEdit_35->text().toFloat();
    float Theoretical_Mass =  ui->lineEdit_36->text().toFloat();
    ui->lineEdit_39->setText(QVariant((100*(Theoretical_Mass/(Weight_Relations+100)))/ui->lineEdit->text().toFloat()).toString());
    ui->lineEdit_40->setText(QVariant((Weight_Relations*(Theoretical_Mass/(Weight_Relations+100)))/ui->lineEdit_2->text().toFloat()).toString());
}

void WeightCoefficient::Calculation_of_mass_v2()
{
    float Weight_Relations = ui->lineEdit_35->text().toFloat();
    float Component_Weight_A =  ui->lineEdit_39->text().toFloat();
    ui->lineEdit_36->setText(QVariant(Component_Weight_A*((100+Weight_Relations)/100)).toString());
    ui->lineEdit_40->setText(QVariant((((Component_Weight_A*((100+Weight_Relations)/100))/(100+Weight_Relations))*Weight_Relations)/ui->lineEdit_2->text().toFloat()).toString());
}

void WeightCoefficient::Calculation_of_mass_v3()
{
    float Weight_Relations = ui->lineEdit_35->text().toFloat();
    float Component_Weight_B =  ui->lineEdit_40->text().toFloat();
    ui->lineEdit_39->setText(QVariant((Component_Weight_B*((100/Weight_Relations)))/ui->lineEdit->text().toFloat()).toString());
    ui->lineEdit_36->setText(QVariant(Component_Weight_B*((100/Weight_Relations))+Component_Weight_B).toString());

}

void WeightCoefficient::on_pushButton_4_clicked() //1 кнопка рачитать
{
    Calculation_of_mass_v1();

}

void WeightCoefficient::on_pushButton_clicked() //2 кнопка рачитать
{
    Calculation_of_mass_all();
}

void WeightCoefficient::Calculation_of_mass_all() //расчет весового коффициента
{
     float Component_Weight_A =  ui->lineEdit_39->text().toDouble();
     float Component_Weight_B =  ui->lineEdit_40->text().toDouble();

     float Massing_A_st = ui->lineEdit_3->text().toFloat()+ui->lineEdit_5->text().toDouble()+ui->lineEdit_7->text().toDouble();
     float Massing_B_st = ui->lineEdit_9->text().toFloat()+ui->lineEdit_10->text().toDouble()+ui->lineEdit_11->text().toDouble();

     float Massing_A = ui->lineEdit_4->text().toFloat()+ui->lineEdit_6->text().toDouble()+ui->lineEdit_8->text().toDouble();
     float Massing_B = ui->lineEdit_12->text().toFloat()+ui->lineEdit_13->text().toDouble()+ui->lineEdit_14->text().toDouble();
     qDebug()<<" Massing_A_st"<<Massing_A_st ;
     qDebug() <<" Massing_B_st"<<Massing_B_st ;
     qDebug() <<" Massing_A"<<Massing_A ;
     qDebug() <<" Massing_B"<<Massing_B ;

     double da = Massing_A-Massing_A_st;
     double db = Massing_B-Massing_B_st;

     double da_end = (da/3)/Component_Weight_A;
     double db_end = (db/3)/Component_Weight_B;

     double da_end_ten = roundDouble(da_end, 3);
     double db_end_ten = roundDouble(db_end, 3);

     ui->lineEdit_27->setText(QVariant(da_end_ten).toString());
     ui->lineEdit_28->setText(QVariant(db_end_ten).toString());
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

