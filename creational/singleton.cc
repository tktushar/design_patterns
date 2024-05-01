#include <iostream>
using namespace std;

/*
    === Most Hated Pattern ===
    People don't like its smell, but there exists a correct usage of this
    pattern

    Used when we need a single instance of an object, like a database, a factory
    etc. It could also be that constructor call is expensive, or we don't want
    customers to make a copy of it. 

    Essentially, its a component that allows instantiation only once. To achieve this
    the constructor is kept private and copy and = operator are deleted.

*/

class Singleton{
    // private constructor
    Singleton(){
        cout << "Singleton Initialised" << endl;
    }

public:
    // prevent users from using copy constructor
    Singleton(const Singleton&) = delete;

    // Nobody can use the = operator too, haha evil
    void operator=(const Singleton&) = delete;

    // static method to get the instance
    static Singleton& get(){
        static Singleton s;
        return s;
    }

    void sayHello(){
        cout << "hello";
    }
};

int main(){
    // can't store this db in a variable, but this is ugly. We have to 
    // use its member functions always. This is because = and copy constructor
    // are removed
    Singleton::get().sayHello();
        
    return 0;
}

