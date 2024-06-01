#include <iostream>
#include <memory>

using namespace std;

/*
    === Chain of Responsibility ==
    
    Motivation
    ----------
    As the name states, its a chain of components who all 
    get a chance to process a command or a query, optionally
    having default processing implementation and an ability 
    to terminate the chain

    Original GoF pattern

    Types :
    ------
    a. Pointer Chain : how it used to be implemented
    b. Broker Chain  : Chain of Responsibility + Observer design pattern
                       + Command/Query design pattern
    

*/

// a bill that the government is discussing on
class Bill
{
public:
    Bill(string name, int stage) : name{name}, stage{stage} {
        cout << "bill has been created" <<endl;
    }
    string name;
    int stage;
};


//   == Abstract Class ==

// a bill modifier handler. we inherit this to make concrete bill modifiers
class BillModifier{
public:
    BillModifier(Bill &bill) : bill{bill} {};
 
    void add(BillModifier* bm){
        if(next) next->add(bm); // follow till the end of list
        else next = bm;         // add to the end of the list
    }

    // virtual because each concrete BillModifier will
    // have its own behaviour. But there should be a defautlt:
    // i.e, call the handle for the whole chain
    virtual void handle(){
        if(next) next->handle();
    }

private:
    BillModifier* next{nullptr};

protected:
    Bill& bill;
};

// Concrete Implementation
class LokSabhaModifier : public BillModifier{
public:
    LokSabhaModifier(Bill &bill) : BillModifier{bill} {};

    void handle() override {
        cout << "Bill has reached Lok Sabha" << endl;
        BillModifier::handle();
    }
};

class RajyaSabhaModifier : public BillModifier{
public:
    RajyaSabhaModifier(Bill &bill) : BillModifier{bill} {};

    void handle() override {
        cout << "Bill has reached Rajya Sabha" << endl;
        BillModifier::handle();
    }
};

int main(){
    Bill bill{"RTI", 0};
    BillModifier root{bill};

    RajyaSabhaModifier rm{bill};
    LokSabhaModifier lsm{bill};

    root.add(&rm);
    root.add(&lsm);

    root.handle();

    return 0;
}
