#include "FenPrincipale.h"
#include "CSVBD.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale frame(new CSVBD());
    frame.show();

    return app.exec();
}
