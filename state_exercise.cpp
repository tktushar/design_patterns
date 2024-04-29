#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class State{
    LOCKED,
    OPEN,
    ERROR
};

class CombinationLock
{
    vector<int> combination;
    vector<int> input
    
public:
    string status;

    CombinationLock(const vector<int> &combination) : combination(combination) {
      status = "LOCKED"
      map<
    }

    void enter_digit(int digit)
    {
      status += digit;
      input.push_back(digit);
      
    }
};

int main (void){
    CombinationLock cl({1,2,3});
    ASSERT_EQ("LOCKED", cl.status);
    cl.enter_digit(1);
    ASSERT_EQ("1", cl.status);
    cl.enter_digit(2);
    ASSERT_EQ("12", cl.status);
    cl.enter_digit(3);
    ASSERT_EQ("OPEN", cl.status);
}