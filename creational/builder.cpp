#include <iostream>
#include <string>
using namespace std;

/*
    == Builder ==
    


*/
class Computer{
    /* Computer can't be directly created by anyone. Its kept
       hidden by making the constructor private. But, the builder
       must have access to it. Hence builder class is our frined.
    */
    friend class ComputerBuilder;

private :
    int ram;
    int storage;
    string storage_bus_type;

};

class ComputerBuilder{
private:
    Computer computer;

public:
    /* Return type of this function is a reference. Because of this
       compound operations like ComputerBuilder.addRAM().addStorage()
       can be done. This is called a fluent builder.
    */
    ComputerBuilder& addRAM(int ram_size){
        computer.ram = ram_size;
        return *this; //
    }

    ComputerBuilder& addStorage(int storage_size){
        computer.storage = storage_size;
        /* some more random complex opreations */
        switch(storage_size){
            case 512:
                computer.storage_bus_type = 'xy';
        }
        return *this;
    }

};

int main (){

    ComputerBuilder builder;
    builder.addRAM(128).addStorage(512);

    cout << "Hello\n";
    return 1;
}