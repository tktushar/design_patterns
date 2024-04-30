#include <iostream>
using namespace std;
/*
    === Motivation ====
    1. Sometimes its easy to copy an object than create a new one.
    2. An object that already was built (maybe using builder), 
       can be deep copied, i.e, the object and all its reference are copied
    3. Prototype is partially or fully initialised existing object.
    4. The prototype might have pointers to objects within it. That's when this
       pattern makes the most sense.
    5. Just creating auto a = protype and modifying the pointer contents of prototype won't 
       work.
    6. Using = for assignment is insufficient for such case. We want = to perform a deep copy
       and not shallow copy, because pointers are involved.
    7. Use a copy constructor which is basically an overloaded constructor that takes in the
       object of the same type and creates an object initialised from its fields.
*/ 

// ======== = does a shallow copy by default ============= //
struct Address{
    string street;
    Address(const string& street) : street(street) {};
};

struct Contact{
    string name;
    Address* address;

    // normal constructor
    Contact(const string& name, Address* address) : name(name), address(address) {};

    // copy constructor
    Contact(const Contact& contact) : name{contact.name} , address{new Address{contact.address->street}} {}
    // could also give Address a copy constructot too

};

int main(){

    Contact ravi{"Ravi", new Address{"shehar"}};
    // Contact tk = ravi is a shallow copy here. This copy will point to the same Address object for both
    // tk and Ravi
    Contact tk{ravi}; // make a deep copy constructor

    return 0;
}