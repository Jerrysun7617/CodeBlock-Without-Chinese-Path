#include <iostream>

using namespace std;

template<class T>
class Bucky{
    T first,second;
    public:
        Bucky(T a, T b){
            first =  a;
            second = b;
        }
        T bigger();
};
template<class T>
T Bucky<T>::bigger(){
    return (first > second ? first : second);
}

int main()
{
    Bucky<int> bo(65,102);
    cout<<bo.bigger();

    while(1);
    return 0;
}
