#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;

/*
        === Static Strategy Pattern ===
        Choose the strategy statically. Refer to 
        dynamic_strategy.cc first

        Can't switch from one to another at runtime.0
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

template <typename LS>
class TextProcessor{
public:
   void append_list(const vector<string>& items){
      list_strategy.start(oss);
      for(auto& item : items){
         list_strategy.add_list_item(oss, item);
      }
      list_strategy.end(oss);
   }

   void clear(){
      oss.str("");
   }

   string str() const {return oss.str();}

private : 
   ostringstream oss;
   LS list_strategy; // static instance of the strategy
};

int main(){
   vector<string> items{"monkey", "hen", "lion"};

   TextProcessor<MarkdownListStrategy> tpm; // this is the context of the strategy 
   tpm.append_list(items);
   cout << tpm.str() << endl;

   tpm.clear();

   TextProcessor<htmlListStrategy> tp;
   tp.append_list(items);
   cout << tp.str() << endl;


   return 0;
}



