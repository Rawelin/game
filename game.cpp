#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include "Game.h"

Game::Game()
{
    createScene();
    runGame();
}

void Game::createEnemy()
{
    Enemy *enemy;

    if(enemy_hit < 100)
    {
        if(counter < 8)
        {
            enemy = new StandardEnemy();
            scene->addItem(enemy);
        }
        if(enemy_hit > 10 && enemy_hit < 20)
        {
           enemy = new PredatorEnemy;
           scene->addItem(enemy);
        }
        if(enemy_hit > 50 && enemy_hit < 60)
        {
           enemy = new PredatorEnemy;
           scene->addItem(enemy);
        }
        if(enemy_hit > 80 && enemy_hit < 90)
        {
           enemy = new PredatorEnemy;
           scene->addItem(enemy);
        }
    }

}

void Game::createScene()
{
    enemy_hit = 0;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage("images/space2.jpg")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

  /*  QPushButton *button = new QPushButton;
    button->setText("START");
    button->setGeometry((this->width()/ 2 ) - 100, (this->height() /2) - 100, 200, 50);

    scene->addWidget(button);
    connect(button, SIGNAL(clicked(bool)), this, SLOT(runGame()));

*/
    show();
}

void Game::runGame()
{
    player = new Player();
    player->setPos(this->width() / 2 , this->height() - 80); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    // add the player to the scene
    scene->addItem(player);
     player->setFocus();

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(createEnemy()));
    timer->start(500);

    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("music/music.mp3"));
    music->play();
}
