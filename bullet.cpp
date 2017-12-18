#include "bullet.h"

bullet::bullet(int x=0,int y=0)
{
    //set pixmap
    this->setPixmap(QPixmap(":/res/red_bullet.png").scaled(50, 50));
    //set bullet position to the spawner's position
    this->setPos(x,y);
}

void bullet::fly()
{
    //get bullet position
    int x=this->x();
    int y=this->y();
    //move bullet per signal sent
    setPos(x,y-3);
    //remove bullet if over the screen
    if(y<0) delete this;
}
