#include <iostream>
using namespace std;


/*
        == Property Proxy ==
        
        Suppose you wish to intercept the assignment operation
        of a class's data member. One way is to use getter and 
        setter methods for modification. But...this means that
        we need to change all the code like class.member = 10
        to class.setMember(10). We want to keep the old style 
        of setting things.


*/

/* This acts as a proxy for the Creature class */
template <typename T> 
struct Property{
    T value;

    Property(T value) {

    }

    operator T(){
        return value;
    }

    T operator=(T new_value){
        cout << "Assignment here \n";
        return value = new_value;
    }
};

struct Creature
{
    // int strenght{10};
    // int agility{10};

    /* 
        Replace the type iwth Property
    */
    Property<int> strenght{10};
    Property<int> agility{12};
};

int main (int ac, char* av[]){

    Creature c;
    c.strenght = 11;
    return 1;
}