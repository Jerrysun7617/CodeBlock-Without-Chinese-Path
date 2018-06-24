#include <iostream>

using namespace std;

class base {
public:
    int num = 0;
    virtual void somemethod() final;
};
class derived: public base{
public:
    int derive;

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
