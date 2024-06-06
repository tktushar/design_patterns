#include <iostream>
using namespace std;

/*
    === Singleton  ===

    Motivation :  
    ----------
    Used when we need a single instance of an object, like a database, a factory
    etc. It could also be that constructor call is expensive, or we don't want
    customers to make a copy of it. 

    Essentially, its a component that allows instantiation only once. 
    To achieve this the constructor is kept private and copy and 
    = operator are deleted.

    Need to take care of lazy initialization and thread safety.
    
    People don't like its smell, but there exists a correct usage of this
    pattern

    Issues :
    -------


*/

class Singleton{
    // private constructor
    Singleton(){
        cout << "Singleton Initialised" << endl;
    }

    // prevent users from using copy constructor
    Singleton(const Singleton&) = delete;

    // Prevents the user from doing Singleton = Singleton::get();
    void operator=(const Singleton&) = delete;

public:
    // static method to get the instance
    static Singleton& get(){
        static Singleton s;
        return s;
    }

    void sayHello(){
        cout << "hello";
    }
};

/* 
    == Monostate ==
    A variation of singleton but not the best practise
*/
class Printer{
    /*
        all changes will go to id
        since you can't inheret static
        members. Only one storage.

        And worse, the user would never
        know about this
    */ 
    static int id;
public:
    int get_id() const {return id;}
    void set_id(int value) {id = value;}
};

int main(){
    // can't store this db in a variable, but this is ugly. We have to 
    // use its member functions always. This is because = and copy constructor
    // are removed
    Singleton::get().sayHello();
    auto& x = Singleton::get();

        
    return 0;
}

