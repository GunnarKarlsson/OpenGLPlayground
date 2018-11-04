#include <QApplication>
#include <QSurfaceFormat>
#include "gamewindow.h"
#include "common.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setVersion(4,2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSamples(4);
    QSurfaceFormat::setDefaultFormat(format);

    GameWindow window;
    window.resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    window.setFormat(format);
    window.show();

    return a.exec();
}
