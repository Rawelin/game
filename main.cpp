#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "player.h"
#include "game.h"


Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
   // game->show();

    return a.exec();
}
