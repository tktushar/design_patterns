#include <iostream>

/* When creating a subclass, some interfaces should not be exposed 
   Have different interfaces for each functionality    
*/

// Abstract class Machine
class Machine{
public:
    Machine() {}

    virtual void change_gear() = 0;
    virtual void turn_on_ac() = 0;  //pure virtual, have to be implemented by derived
};

class Bike : Machine{
    Bike(){};

    void turn_on_ac(){
      // Bike Class has to implement this but this makes no sense.
      // The interface should be segregated  
    }
};

/* ======= Right Way ============= */

class TwoWheeler{
public:
    TwoWheeler(){};

    // relevant pure virtual functions 
};

class FourWheeler{
public:
    FourWheeler(){};

    // relevant pure virtual functions
};