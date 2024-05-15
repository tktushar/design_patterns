#include <iostream>
using namespace std;

/*
    == Template Pattern ==

    Motivation : Some parts of an algorithm implementation
    are different and we can let the derived classes implement 
    them.

    Superclass defines the skeleton only. Straightforward
    pattern that demostrates polymorphismc.

    Remember : Be Open to extension but closed for modification

*/

class Game // abstract class
{
public:
    Game(int num_players) : number_of_players{num_players}{
       cout << "Game initialized" << endl;  
    };

    /*
        == central idea ==
        this function is made purely virtual 
        because subclasses are allowed to have
        their own impplementation of this.
        They could use rest of non-virtual
        methods as is.
    */
    virtual void start(void) = 0; // pure virtual function

protected:
    int number_of_players;

};

class Chess : public Game{
public:
    Chess () : Game(2) {
        cout << "Game of Chess is created" << endl;
    }

    void start () override {
        cout << "A game of chess is now ongoing" << endl;
    }
};


int main(){
    Chess chess_game;
    chess_game.start();
    return 0;
}