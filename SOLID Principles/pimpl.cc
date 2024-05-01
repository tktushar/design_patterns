#include <iostream>
using namespace std;

/*
    ======= PImpl Idiom in C++ ===============
    Motivation : 
    a. Hide implementation details of the PersonImpl.
       Customer only gets the header file, where only public
       functions are kept. 
    b. All hidden implementation can go into the cpp file,
       which we don't need to ship. It can be a library.
    c. It also gives some compilation speed boost. You just change 
       the implementation and the header stays the same, meaning
       no re-compilation for him.


*/

/* ======== Base class in .hpp file ====== */
// this will reside in the separate header
// whoever includes the header will see this only. 
// They have to take care of the implementation.
class Person{
public:
    string name;
    Person();
    ~Person();

    // Implementation 
    class PersonImpl;
    PersonImpl* impl;

    void greet();
};

/* ==== Implementation in .cc file ======*/
class Person::PersonImpl{
public:
    // this class should have the same
    // function implementation as the
    // Person class
    void greet(Person* p);
private:
    // trade secret functions here
};

void Person::PersonImpl::greet(Person *p){
    std::cout << "Hello Brother " << p->name << endl;
}


Person::Person()  : impl(new Person::PersonImpl){}
Person::~Person() {
    delete impl;
}

void Person::greet(){
    impl->greet(this);
}

int main(){
    Person p;
    p.name = "Tushar";
    Person::PersonImpl *pimpl;
    p.impl = pimpl;

    p.greet();

    return 0;
}