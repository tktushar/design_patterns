#include <iostream>
using namespace std;
/* 
    ==== Facade Pattern ===
    Simple easy to understand interface
    over a large sophisticated body of code
        
*/

class SubsystemA {
public:
    void operationA() {
        cout << "Subsystem A operation" << endl;
    }
};

class SubsystemB {
public:
    void operationB() {
        cout << "Subsystem B operation" << endl;
    }
};

class SubsystemC {
public:
    void operationC() {
        cout << "Subsystem C operation" << endl;
    }
};

class Facade {
private:
    SubsystemA subsystemA;
    SubsystemB subsystemB;
    SubsystemC subsystemC;
public:
    void operation() {
        subsystemA.operationA();
        subsystemB.operationB();
        subsystemC.operationC();
    }
};

int main() {
    Facade facade;
    facade.operation();
    
    return 0;
}
