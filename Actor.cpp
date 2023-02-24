#include "Actor.h"
#include "GameController.h"
#include "StudentWorld.h"
#include "Board.h"
// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp


//helper function to reset direction if goes over
void Player_Avatar::resetDir(int walkDir){
    if(getWalkDir()== 450){
        setWalkDir(up);
    }
    if(getWalkDir()== 360){
        setWalkDir(right);
    }
    if(getWalkDir()== 540){
        setWalkDir(left);
    }
}

//helper function square

bool Player_Avatar::checkForSquare(int walkDir){
    int newX;
    int newY;

    getPositionInThisDirection(getWalkDir(), 16, newX, newY);
    
    newX = newX / SPRITE_WIDTH;
    newY = newY / SPRITE_HEIGHT;

    Board::GridEntry ge = getWorld()->getBoard()->getContentsOf(newX,newY);
    
    if(ge == Board::empty){
        
        cout << getWalkDir() << endl;
        
        cout << "not blue coin square" << endl;
        return false;
    }
    
    if(ge != Board::empty){
        cout << "final dir: " << getWalkDir() << endl;
        
        //can move forward in this direction
        return true;
    }
    

    
    return false;
    
    

}

//can move

bool Player_Avatar::canMove(int walkDir){
    vector<int> visitedDirections;
    
    if(checkForSquare(walkDir)){
        return true;
    }
    
    else{
        
        setWalkDir(getWalkDir()+90);
        resetDir(walkDir);

        
        if(checkForSquare(getWalkDir())){
            return true;
        }
        
        else{
            setWalkDir(getWalkDir()+180);
            resetDir(walkDir);

        }
    }
    
    return false;
}



//player avatar doSomething

void Player_Avatar::doSomething(){
    int ch;
    
    //if player is in waiting to roll state
    if(getState() == WAITING_TO_ROLL){
        //only working for PEACH rn
        //nvm maybe
        ch = getWorld()->getAction(getPlayerNum());
      //  cout << ch;
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
        
        
        if(getX() % 16 == 0 && getY() %16 == 0){
            canMove(getWalkDir());
        }
        
        //if walkDir = left, change sprite dir to 180

        if(getWalkDir()==left){
            setDirection(left);
        }
        else{
            setDirection(right);
        }
        
        //move 2 pixels in walk direction
        moveAtAngle(getWalkDir(), 2);
        
            
        //decrement ticks_to_move by 1
        setTicks(getTicks() - 1);
                
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
