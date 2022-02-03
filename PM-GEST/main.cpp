#include "FenPrincipale.h"
#include "CSVBD.h"

#include <QApplication>

/**
 * @author William-Benoît Lambert
 * @version 1.0
 * @date 26 Janvier 2022
 */

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setApplicationName("Gestionnaire des emprunts matériel");
    app.setApplicationVersion("1.0");
    app.setApplicationDisplayName(app.applicationName());
    app.setWindowIcon(QIcon(":/icons/res/icons/SVG/BasicIcon.svg"));

    Q_CLASSINFO("Version", "1.0.0")
    Q_CLASSINFO("Author", "William-Benoit Lambert")
    Q_CLASSINFO("Copyright", "Copyright 2022 - William-Benoit Lambert")
    Q_CLASSINFO("URL", "https://opensource.org/licenses/MIT")

    FenPrincipale frame(new CSVBD());
    frame.show();

    return app.exec();
}
