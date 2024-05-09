#include <iostream>
#include <vector>
using namespace std;

/* 
   == Open Close Principle ==
   Open to extension (by inheritence for example)
   but close for modification 

*/

/* 
    == Original intention
    Just a filter to get objects by color

*/

enum class Color {red, green, blue};
enum class Size  {small, medium, large};


struct Product{
    string name;
    Color color;
    Size size;
};

class ProductFilter{ 

    // originally intended to filter out products by color
    vector<Product*> FilterByColor(vector<Product*> products) {
        vector<Product*> ret;
        return ret;
    }
};

/* 
    === New requirement ===
    Filter should filter by Size, and both size and color.

    Open Close principle says that you can't modify Product 
    class anymore. You could extend it, but adding more functions
    is not allowd    
*/

class ProductFiler{
public:
    // originally intended to filter out products by color
    vector<Product*> FilterByColor(vector<Product*> products) {
        // implementation
        cout << "filtering by color" << endl;
        vector<Product*> ret;
        return ret;
    }

    // this breaks the open close principle
    vector<Product*> FilterBySize(vector<Product*> products, string size){
        cout << "filtering by size" << endl;
        vector<Product*> ret;
        return ret;
    };
};

/*
    == Design Pattern to solve this ==
    Can only do something with inheritence. 
    This pattern is called Specification Design Pattern. 
*/

/*
    Abstract Interface for guys who want
    to design a filter now.
*/
template <typename T> class Specification{
public:
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> class Filter{
public:
    virtual vector<T*> filter(vector<T*> iterms, Specification<T>&) = 0;
};

/*
    Concrete implementation
*/

class ColorSpecification : public Specification<Product>{
public:
    ColorSpecification(Color color) : color{color}{};
    
    bool is_satisfied(Product* iterm) override {
        cout << "called" <<endl; true;
        return true;
        };

    Color color;

};

class BetterFilter : public Filter<Product>{
public:
    virtual vector<Product*> filter(vector<Product*> items, 
                                    Specification<Product>& spec) override
    {
        // for(auto& item : items){
        //     if(spec.is_satisfied(&item)){
        //         // do stuff
        //     }
        // }
        spec.is_satisfied(items[0]);
    
    }
};



int main (){
    Product fruit{"orange", Color::green, Size::small};
    Product toy{"orange", Color::green, Size::small};

    ProductFiler filter;
    vector<Product*> prods{&fruit, &toy};
    filter.FilterByColor(prods);

    BetterFilter bf;
    ColorSpecification spec{Color::green};

    bf.filter(prods, spec);

    return 0;
}