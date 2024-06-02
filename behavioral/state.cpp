#include <iostream>
#include <map> 
#include <vector>
using namespace std;

enum class State{
    STATE_A,
    STATE_B,
};

enum class Event{
    EVENT_A,
    EVENT_B,
};

/* For prints */
ostream& operator<<(ostream& os, const State& s){
    switch(s)
    {
        case State::STATE_A:
            os << "state A active";
        break;

        case State::STATE_B:
            os << "state B active";
        break;
    }

    return os;
}

/* For prints */
ostream& operator<<(ostream& os, const Event& s){
    switch(s)
    {
        case Event::EVENT_A:
            os << "Event A";
        break;

        case Event::EVENT_B:
            os << "Event B";
        break;
    }

    return os;
}

int main (int ac, char* av[]){
    cout << "State Design Pattern Example" << '\n';

    /* State Transition Table */
    map<State, vector<pair<Event, State>>> table;

    /* Add the rules here */
    table[State::STATE_A] =  {{Event::EVENT_B, State::STATE_B}};
    table[State::STATE_B] =  {{Event::EVENT_A, State::STATE_A}};

    /* Set initial state */
    State currentState {State::STATE_A};

    while(true){
        cout << currentState << '\n';
        currentState = table[currentState][0].second;
    }

    /* */
    return 1;
}