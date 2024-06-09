#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
#include <mutex>

using namespace std;

/*
        === Observer Pattern ===

        Motivation :
        -----------

        We want one object to know about events
        that occurered with another object : like
        a field change, object doing something
        or some altogether external events.

        Terminology : event and subscriber
                    : signal and slot (especially in QT)

        Observer likes to be informed about the observable
*/

/*
    Example :

    Ability to get notified whenever someone
    changes the age field of Person class
*/

/*
        == Abstract Implementations ==

        a. Observer
        b. Observable
*/

template <typename T>
class Observer{
public:
    // whose field changed and what field changed
    virtual void field_changed(T&, const string &field_name);
};

template <typename T>
class Observable{
public:
    // list of all subscriber who want to listen
    vector<Observer<T>*> observers;

    void notify(T& source, const std::string& field_name){
        for(auto& observer : observers)
            observer->field_changed(source, field_name);
    }

    void subscribe(Observer<T>& observer){
        observers.push_back(&observer);
    }

    /*
            == Dangerous ==
        This section is not thread safe. Check SaferObservable at
        the end of the file
    */

    void unsubscribe(Observer<T>& observer){
        observers.erase(std::remove(observers.begin(), observers.end(), &observer), observers.end());
    }
};

/*
    == Concrete Implemenations ==
*/

// Person class now has to implement Observable
class Person : public Observable<Person>{
    int age;
public:

    Person(int initialAge) : age(initialAge) {}
    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        age = newAge;
        // have the feature to now notify observers
        notify(*this, "age");
    }
};

class PersonObserver : public Observer<Person> {
public:
    void field_changed(Person& person, const string& field_name) override {
        if (field_name == "age") {
            cout << "Person's age has changed to: " << person.getAge() << endl;
        }
    }
};


int main(){
    Person person(25);
    PersonObserver observer;
    person.subscribe(observer);

    person.setAge(30);
    person.setAge(35);

    person.unsubscribe(observer);

    person.setAge(40);
   return 0;
}

template <typename T>
class SafeObservable{
    // list of all subscriber who want to listen
    vector<Observer<T>*> observers;
    
public:
    void notify(T& source, const std::string& field_name){
        for(auto& observer : observers)
            observer->field_changed(source, field_name);
    }

    void subscribe(Observer<T>& observer){
        observers.push_back(&observer);
    }

    /*
            == Dangerous ==
        This section is not thread safe. Check SaferObservable at
        the end of the file
    */

    void unsubscribe(Observer<T>& observer){
        observers.erase(std::remove(observers.begin(), observers.end(), &observer), observers.end());
    }
};

