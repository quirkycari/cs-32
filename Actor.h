#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

//enumeration for roll states
enum roll_or_walk{WAITING_TO_ROLL = 0, WALKING = 1};

//player id
enum playerNum{PEACH = 1, YOSHI = 2};

//actor - derived from GraphObject
class Actor: public GraphObject{
    public:
        //constructor
        Actor(StudentWorld* world, int imageID, int startX, int startY, int dir, int depth, double size): GraphObject(imageID, startX, startY, dir, depth, size), m_world(world) {};
        StudentWorld* getWorld() {
            return m_world;
        }
        
    virtual void doSomething() = 0;
    
    private:
        StudentWorld* m_world;
};

//players - peach & yoshi
//sprite direction is direction that player faces
//starting direction is 0 = right
class Player_Avatar: public Actor{
    public:
        //constructor
        Player_Avatar(StudentWorld* world, int imageID, int startX, int startY, double size): Actor(world, imageID, startX, startY, 0, 0, 1), coins(0), state(WAITING_TO_ROLL) {};
        
        //doSomething
        virtual void doSomething();
    
        //getter and setter for coins
        int getCoins(){return coins;};
        void setCoins(int newCoins){coins = newCoins;};
    
        //getter and setter for walking direction
        int getWalkDir(){return walkDir;};
        void setWalkDir(int newDir){walkDir = newDir;};
    
        //getter and setter for state
        int getState(){return state;};
        void setState(int newState){state = newState;};
    
        //die roll
        int getDieRoll(){return die_roll;};
        void setDieRoll(int newRoll){die_roll = newRoll;};
    
        //ticks_to_move
        int getTicks(){return ticks_to_move;};
        void setTicks(int newTicks){ticks_to_move = newTicks;};
    
        //check for square in front
        bool checkForSquare(int walkDir);
    
        //check for ability to move
        bool canMove(int walkDir);
    
        //reset direction
        void resetDir(int walkDir);
        
        //virtual getter
        virtual int getPlayerNum() = 0;
        
    private:
        int state;
        int walkDir = right;
        int die_roll = 0;
        int ticks_to_move = 0;
        int coins;
};

//Peach

//assume peach is player 1, use left side of keyboard --> wasd to move
class Peach: public Player_Avatar{
    public:
    Peach(StudentWorld* world, int startX, int startY): Player_Avatar(world, IID_PEACH, SPRITE_WIDTH * startX, SPRITE_HEIGHT * startY, 1),coins(0), grantedForThisTurn(false){};
       // virtual void doSomething();
        
        virtual int getPlayerNum() {return playerNum;};
    
        bool granted(){return grantedForThisTurn;};
        void setGranted(bool newGrant){grantedForThisTurn = newGrant;};

    private:
        bool grantedForThisTurn;
        int coins;
        const int playerNum = PEACH;
        
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
    public:
        Square(StudentWorld* world, int imageID, int startX, int startY, int dir, double size): Actor(world, imageID, startX, startY, dir, 1, 1) {};
    private:
};

//coin squares

//do i need separate classes for blue and red coin squares???

class blueCoinSquare: public Square{
    public:
        blueCoinSquare(StudentWorld* world, int startX, int startY): Square(world,IID_BLUE_COIN_SQUARE,SPRITE_WIDTH * startX, SPRITE_HEIGHT * startY, 0, 1), alive(true){};
        virtual void doSomething();
        
        bool isAlive(){return alive;};
        void grantCoins(Player_Avatar* avatar){avatar->setCoins(avatar->getCoins() + 3);};
    private:
        bool alive;
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
