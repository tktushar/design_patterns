#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

/*
        === Strategy Pattern ===
        Choose the algorithm to execute at runtime.
        Looks similar to template but the differece is:
         a. Template class chooses the concrete implementation
            at runtime. Since the skeleton class keeps some
            functions virtual. Rest of the code is shared
            between two implementations
         b. Implementations in strategy pattern are chosen 
            at the runtime. The implementations are 'contained'
            in separate classes.

        Two ways to implement :
         a. Dynamic strategy
         b. Static strategy

*/


/* 
   two output formats
   markdown list : 
   * list_item
   * list_item_2
   
   html list:
      <ul>
         <li> list_item </li>
      </ul>
*/

enum class OutputFormat{
   markdown,
   html,
};

class ListStrategy{
public :
   virtual void start(ostringstream &oss){}; // not purely virtual, cuz markdown doesn't need it
   virtual void add_list_item(ostringstream& oss, const string& item) = 0;
   virtual void end(ostringstream &oss){};
};

/* 
   == Dynamic Approach == 
*/
class TextProcessor{


private : 
   ostringstream oss;
   unique_ptr<ListStrategy> list_strategy;

}



