#include <iostream>

using namespace std;

namespace Jerry{
    int jer = 1;
}
namespace Carol{
    int jer =2;
}
int main()
{
    cout << Jerry::jer <<"  "<<Carol::jer<< endl;

    getchar();
    return 0;
}
