#include <iostream>
#include <vector>
using namespace std;
//#define Violent_search

/*********
start: 19:20
Prediction: 19:35
end:19:45
*********/

#ifdef Violent_search
int steps_problem(int n) {
    // write code here
    if(n <= 2)
        return n;
    else
        return steps_problem(n-1) + steps_problem(n-2);
}
#endif
int steps_problem(int n) {
    //
    if(n <=2)
        return n;

    vector<int>matrix(n+1,0);

    matrix[1] = 1;
    matrix[2] = 2;

    for(int i = 3;i <= n ;i++){
        matrix[i] = matrix[i-1] + matrix[i-2];
    }

    return matrix[n];
}
int main()
{
    cout << "Hello world!" << endl;

    int n;
    while(cin>>n){ //走一步和走两步的方法问题
        cout<<steps_problem(n)<<endl;
    }

    return 0;
}
