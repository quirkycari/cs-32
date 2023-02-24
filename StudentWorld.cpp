#include "StudentWorld.h"
#include "GameConstants.h"
#include "Board.h"
#include "Actor.h"
#include <string>
#include <vector>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    m_peach = nullptr;
    actors.clear();
}

int StudentWorld::init()
{
    
    //initializing board and all data structures that go with it
    Board bd;
    
    string board_file = assetPath() + "board0" + to_string(getBoardNumber()) + ".txt";
    Board::LoadResult result = bd.loadBoard(board_file);
    
    if(result == Board::load_fail_file_not_found){
        cerr << "Could not find board01.txt data file\n";
    }
    else if(result == Board::load_fail_bad_format){
        cerr << "Your board was improperly formatted\n";
    }
    else if(result == Board::load_success){
        cerr << "Successfully loaded board\n";
        
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
            Board::GridEntry ge = bd.getContentsOf(i,j);
                switch(ge){
                        //empty
                    case Board::empty:
                        cerr << "Location (" << i << ", " << j << ") is empty" << endl;
                        break;
                    case Board::player:
                        //allocating and inserting peach
                        cerr << "Location (" << i << ", " << j << ") is a player" << endl;
                        m_peach = new Peach(this,i,j);
                        break;
                    case Board::blue_coin_square:
                        cerr << "Location (" << i << ", " << j << ") is a blue coin square" << endl;
                        actors.push_back(new blueCoinSquare(this,i,j));
                        break;
                    case Board::red_coin_square:
                        cerr << "Location (" << i << ", " << j << ") is a red coin square" << endl;
                    case Board::left_dir_square:
                        cerr << "Location (" << i << ", " << j << ") is a left dir square" << endl;
                    case Board::right_dir_square:
                        cerr << "Location (" << i << ", " << j << ") is a right dir square" << endl;
                    case Board::up_dir_square:
                        cerr << "Location (" << i << ", " << j << ") is a up dir square" << endl;
                    case Board::down_dir_square:
                        cerr << "Location (" << i << ", " << j << ") is a down dir square" << endl;
                    case Board::event_square:
                        cerr << "Location (" << i << ", " << j << ") is an event square" << endl;
                    case Board::bank_square:
                        cerr << "Location (" << i << ", " << j << ") is a bank square" << endl;
                    case Board::star_square:
                        cerr << "Location (" << i << ", " << j << ") is a star square" << endl;
                    case Board::bowser:
                        cerr << "Location (" << i << ", " << j << ") is a bowser" << endl;
                    case Board::boo:
                        cerr << "Location (" << i << ", " << j << ") is a boo" << endl;
                }
            }
        }
    }
    //initialize data structures to keep track of game world
    
    //allocate and insert peach and yoshi
    
    //allocate and insert baddies, squares, etc.
    
    //start countdown timer for 99 seconds
	startCountdownTimer(99);
    
    //startCountdownTimer(5); // this placeholder causes timeout after 5 seconds
    
    
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit ESC.
    // Notice that the return value GWSTATUS_NOT_IMPLEMENTED will cause our framework to end the game.

    setGameStatText("Game will end in a few seconds");
    
    m_peach->doSomething();
    
    if (timeRemaining() <= 0)
		return GWSTATUS_NOT_IMPLEMENTED;
    
	return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    for(Actor* a: actors){
        delete a;
    }
    actors.clear();
    
    delete m_peach;
    m_peach = nullptr;
    
}

StudentWorld::~StudentWorld(){
    cleanUp();
}
