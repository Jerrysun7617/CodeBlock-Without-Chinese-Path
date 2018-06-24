#include <iostream>

using namespace std;

template <class T>
class Spunky{
    public:
        Spunky(T x){
            cout<< x <<" is not a character"<<endl;
        }
};
template<> // we're gonna to use
class Spunky<char>{
public:
    Spunky(char x){
        cout<< x <<" is indeed a character"<<endl;
    }
};
int main()
{
    Spunky<int> obj1(7);
    Spunky<double> obj2(7.2);
    Spunky<char> obj3('g');

    while(1);
    return 0;
}
