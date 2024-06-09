#include <iostream>
#include <vector>
using namespace std;

//abstraction
class FileElement {
public:
    virtual void display(int indent = 0) = 0;
};

//instance
class File : public FileElement {
private:
    string name;

public:

    File(string const &name) : name{name} {}

    void display(int indent = 0) override {
    for(int i = 0; i < indent; ++i) std::cout << " ";
        cout << name;
    }
};

//composition
class Directory : public FileElement {
private:
    vector<FileElement*> elements;
    string name;

public:
    Directory(string const &name) : name{name} {}

    void add(FileElement *element) {
        elements.push_back(element);
    }

    void display(int indent = 0) {
        cout << name << "/ ->";
        for (auto& e : elements) {
            e->display();
        }
        cout << endl;
    }
};

int main(){

    // create root directory
    Directory home{"home"};
    Directory user{"user"};

    File f1{"file1"};
    File f2{"file2"};   

    home.add(&f1);
    home.add(&user);

    user.add(&f2);
    
    home.display();
}

/* expected print
    home
      user
        file2  
      file1
*/