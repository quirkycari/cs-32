
#include "Actor.h"
#include "StudentWorld.h"
#include "GameController.h"
// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp


void Peach::doSomething(){
    int ch;
    
    //if player is in waiting to roll state
    if(getState() == WAITING_TO_ROLL){
        ch = getWorld()->getAction(1);
        cout << ch;
            switch(ch){
                case ACTION_ROLL: {
                    setDieRoll((rand() % 10) + 1);
                    setTicks(getDieRoll()*8);
                    
                    setState(WALKING);
                    break;
                }
                default: {
                    return;
                    break;
                }
            }
        }
    
    if(getState() == WALKING){
        //update avatar's direction by moving 90 counterclockwise
        
        //if walkDir = left, change sprite dir to 180
        cout << "going here" << endl;
        
        //move 2 pixels in walk direction
        moveAtAngle(getWalkDir(), 2);
            
        //decrement ticks_to_move by 1
        setTicks(getTicks() - 1);
        cout << getTicks() << endl;
        
        //if ticks_to_move = 0, change state to walking
        if(getTicks() == 0){
            setState(WAITING_TO_ROLL);
            cout << "break";
        }
    }
}

void blueCoinSquare::doSomething(){
    
    //dummy function
}
