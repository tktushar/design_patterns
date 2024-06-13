#include <iostream>
#include <memory>
#include <map>
#include <string>
using namespace std;

/*
    == Abstract Factory Method ==

*/

// HotDrink abstract interface. This could be in a separate .hpp 
struct HotDrink{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

// An actual hotdrink
struct Tea : HotDrink{
    void prepare(int volume) override {
        cout << "preparing lemon tea " << volume << "ml" << endl;
    }
};

struct Coffee : HotDrink{
    void prepare(int volume) override {
        cout << "preparing hot coffee of " << volume << "ml" << endl;
    }
};

// === Abstract Factory Interface === //
struct HotDrinkFactory{
    virtual unique_ptr<HotDrink> make() const = 0;
};

// === Concrete Factory ===
struct TeaFactory : HotDrinkFactory{
    unique_ptr<HotDrink> make() const override{
        return make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactory{
    unique_ptr<HotDrink> make() const override{
        return make_unique<Coffee>();
    }
};

/* == Actual Drink Factory == */
class DrinkFactory{
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;

public:
    DrinkFactory(){
        // factories themselves have to be unique_ptrs
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"]    = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string &name){
        auto drink = hot_factories[name]->make();
        drink->prepare(100);
        return drink;
    }
};


int main(){
    cout << "Abstract Factory Example" << endl;

    DrinkFactory df;
    df.make_drink("coffee");

    return 0;
}



