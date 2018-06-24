#include <iostream>
using namespace std;

class stud {
public:
    stud()
    {
        cout << "Constructor Used" << endl;
    }
    ~stud()
    {
        cout << "Destructor Used" << endl;
    }
};

int main()
{

    char *ch = new char[100];
    delete ch;

    stud* S = new stud[6];
    delete[] S;

    system("pause");

    return 0;
}
