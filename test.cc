#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int main(){
    std::unordered_map<string, int> map;
    map["hello"] = 10;
    cout << map["hello"]; 

    return 0;
}