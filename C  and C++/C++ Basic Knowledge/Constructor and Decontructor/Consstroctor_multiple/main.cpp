#include <iostream>

using namespace std;
class base {
  public:
      base(){}
    base( int test)
    { cout<<"Constructing base test \n"; }
    ~base()
    { cout<<"Destructing base \n"; }
};

class derived: public base {
  public:
    derived()
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};

int main(void)
{
  derived *d = new derived();
  delete d;
  //base *b = d;
  //delete b;
  getchar();


  return 0;
}

