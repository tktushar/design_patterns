#include <iostream>
#include <memory>
using namespace std;

// Incomplete 

// HotDrink abstract interface. This could be in a separate .hpp 
struct HotDrink{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

// An actual hotdrink
struct Tea : HotDrink{
    void prepare(int volume) override {
        cout << "prepare lemon tea " << volume << "ml" << endl;
    }
};

struct Coffee : HotDrink{
    void prepare(int volume) override {
        cout << "hot hot coffee" << endl;
    }
};

// ======= Abstract Factory Interface =========== //
struct HotDrinkFactory{
    virtual unique_ptr<HotDrink> make() const = 0;
};

// Factory Object
struct TeaFactory : HotDrinkFactory{
    unique_ptr<HotDrink> make() const override{
        return make_unique<Tea>();
    }
};

int main(){
    cout << "Abs";
    return 0;
}



