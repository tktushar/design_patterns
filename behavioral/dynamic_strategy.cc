#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

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
   Goal of the example:
   -------------------

   two output formats
   markdown list : 
   * list_item
   * list_item_2
   
   html list:
      <ul>
         <li> list_item </li>
      </ul>

   Write a functionality that allows 
   creating a osstringstream fow both
   these at runtime, given a bunch of
   list_item
*/

enum class OutputFormat{
   markdown,
   html,
};

/* Abstract strategy */
class ListStrategy{
public :
   virtual void start(ostringstream &oss){}; // not purely virtual, because markdown doesn't need it
   virtual void add_list_item(ostringstream& oss, const string& item) = 0;
   virtual void end(ostringstream &oss){};   // not purely virtual, because markdown doesn't need it
};

/* 
   == Dynamic Approach == 
*/

/* Concrete Strategies */
class MarkdownListStrategy : public ListStrategy{
public:
   void add_list_item(ostringstream& oss, const string& item) override{
      oss << "* " << item << endl;
   }
};

class htmlListStrategy : public ListStrategy{
public:
   void start(ostringstream &oss) override{
      oss << "<ul>\n";
   }

   void add_list_item(ostringstream& oss, const string& item) override{
      oss << "<li> " << item << "</li>\n";
   }

   void end(ostringstream &oss) override{
      oss << "</ul>\n";
   }
};

class TextProcessor{
public:
   void set_output_format(const OutputFormat& format){

      switch(format){
         case OutputFormat::markdown:
            list_strategy = make_unique<MarkdownListStrategy>();
            break;

         case OutputFormat::html:
            list_strategy = make_unique<htmlListStrategy>();
            break;
      }
   }

   void append_list(const vector<string>& items){
      list_strategy->start(oss);
      for(auto& item : items){
         list_strategy->add_list_item(oss, item);
      }
      list_strategy->end(oss);
   }

   void clear(){
      oss.str("");
   }
   string str() const {return oss.str();}

private : 
   ostringstream oss;
   // unique_ptr because we want the list_strategy to be owned by text processor
   // and when we change strategy, the old strategy should no longer exist
   unique_ptr<ListStrategy> list_strategy;
};

int main(){
   vector<string> items{"monkey", "hen", "lion"};

   TextProcessor tp; // this is the context of the strategy 

   tp.set_output_format(OutputFormat::markdown);
   tp.append_list(items);

   cout << tp.str() << endl;

   tp.clear();
   tp.set_output_format(OutputFormat::html);
   tp.append_list(items);
   cout << tp.str() << endl;


   return 0;
}



