#include <iostream>
#include <memory>
using namespace std;

// Incomplete

/*
    Understand prototype.cc first

    === Motivation ====
    1. There should be an existing prototype that the user can copy
    2. This looks ugly sitting there, with random fields. Why expose this
       to the user. Its not even expresive, nobody would know that we want
       them to use this as prototype
    3. We can create a Prototype Factory, a class that takes already posseses
       a prototype.

*/

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

// ========= Prototype Factory ===== //
struct EmployeeFactory{
    static unique_ptr<Contact> new_employee(const string& name){

        static Contact p{"", new Address{"Bannergatta Road"}};
        return create_employee(name, p);

    }

private:
    unique_ptr<Contact> create_employee(const string& name, const Contact& prototype){
        auto result = make_unique<Contact>prototype;
        result->name = name;
        return result;
    }
};

int main(){
    return 0;
}
