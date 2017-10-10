#include "weightcoefficient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeightCoefficient w;
    w.show();

    return a.exec();
}
