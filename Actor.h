#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;


//actor - derived from GraphObject
class Actor: public GraphObject{
    public:
        Actor(StudentWorld* world, int imageID, int startX, int startY, int dir, int depth, double size): GraphObject(imageID, startX, startY, dir, depth, size), m_world(world) {};
    private:
        StudentWorld* m_world;
};

//players - peach & yoshi
class Player_Avatar: public Actor{
    
};

//Peach
class Peach: public Player_Avatar{
    
};

//Yoshi
class Yoshi: public Player_Avatar{
    
};

//baddies - boo & bowser
class Baddies: public Actor{
    
};

//Boo
class Boo: public Baddies{
    
};

//Bowser
class Bowser: public Baddies{
    
};

//squares - coin square, star square, directional square, bank square, event square, dropping square
class Square: public Actor{
    
};

//coin square
class coinSquare: public Square{
    
};

//star square
class starSquare: public Square{
    
};

//directional square
class directionalSquare: public Square{
    
};

//bank square
class bankSquare: public Square{
    
};

//event square
class eventSquare: public Square{
    
};

//dropping square
class droppingSquare: public Square{
    
};


//split it up into players (Peach & Yoshi), baddies (Boo & Bowser), squares, and vortex

#endif // ACTOR_H_
