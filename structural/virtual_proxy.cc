#include <iostream>
using namespace std;


/*
        == Virtual Proxy ==
        
        Feels like working with an object when the object hasn't
        been even created yet
        Provides a placeholder for that object by doing lazy initialization

*/

class Image{
public :
    virtual void draw() = 0;
};

/*
    Bitmap is a huge object.
    We don't want to load the file in the constructor
    unless somebody wants to call the draw method

*/
class Bitmap : public Image{
public:
    Bitmap(const string& filename){
        cout << "loading bitmap " << filename << endl;
    }

    void draw() override {
        cout << "Drawing bitmap" << endl;
    }
};

class LazyBitmap : public Image{
public:
    LazyBitmap(const string& filename) : filename{filename} {
        cout << "deferring initialization " << endl;
    }

    void draw() override {
        if(!bmp)
            bmp = new Bitmap(filename);
        cout << "Calling Bitmap->draw()" << endl;
        bmp->draw();
    }    

private :
    string filename;
    Bitmap* bmp = nullptr;
};

int main (int ac, char* av[]){
    // Bitmap bmp{"file1"};
    // bmp.draw();

    LazyBitmap bmp{"file1"};
    bmp.draw();

    return 0;    
}