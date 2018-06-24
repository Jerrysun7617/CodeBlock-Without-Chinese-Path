#include <iostream>

using namespace std;
public int[] getSwap(int[] num) {
    num[0]=num[0]+num[1];
    num[1]=num[0]-num[1];
    num[0]=num[0]-num[1];
    return num;
}

    vector<int> getSwap(vector<int> num) {
        // write code here
        num[0]=num[0]^num[1];
        num[1]=num[0]^num[1];
        num[0]=num[0]^num[1];
        return num;
    }
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
