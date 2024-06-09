#include <string>
#include <memory>
#include <iostream>
#include <vector>

// Component class
class FileSystemElement {
public:
    virtual void display(int indent = 0) const = 0;
    virtual ~FileSystemElement() = default;
};

// Leaf class
class File : public FileSystemElement {
private:
    std::string name;
public:
    File(const std::string& name) : name(name) {}
    
    void display(int indent = 0) const override {
        for(int i = 0; i < indent; ++i) std::cout << " ";
        std::cout << name << std::endl;
    }
};

// Composite class
class Directory : public FileSystemElement {
private:
    std::string name;
    std::vector<std::shared_ptr<FileSystemElement>> elements;
public:
    Directory(const std::string& name) : name(name) {}

    void add(const std::shared_ptr<FileSystemElement>& element) {
        elements.push_back(element);
    }

    void display(int indent = 0) const override {
        for(int i = 0; i < indent; ++i) std::cout << " ";
        std::cout << name << "/" << std::endl;
        for(const auto& element : elements) {
            element->display(indent + 2);
        }
    }
};

int main() {
    auto root = std::make_shared<Directory>("root");
    auto home = std::make_shared<Directory>("home");
    auto user = std::make_shared<Directory>("user");
    auto file1 = std::make_shared<File>("file1.txt");
    auto file2 = std::make_shared<File>("file2.txt");
    auto file3 = std::make_shared<File>("file3.txt");

    user->add(file1);
    user->add(file2);

    home->add(user);
    
    root->add(home);
    root->add(file3);

    root->display();

    return 0;
}