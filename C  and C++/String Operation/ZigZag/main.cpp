#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {

        if(s.empty() || numRows <=1)
            return s;

            const int len = (int)s.length();
            string * str = new string[numRows];
        int row =0,step =1;
        for(int i = 0 ; i < len; i++){
            str[row].push_back(s[i]);

            if(row == 0)
                step = 1;
            else if (row = numRows)
                step = -1;
            row += step;
        }

        s.clear();

        for(int j = 0; j < numRows;j++)
            s.append(str[j]);

        delete[] str;

        return s;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    string test = "Apalindromeisaword,phrase,number";
    int row = 10;

    class Solution  Test01;

    string getreturn = Test01.convert(test,row);

    cout<<getreturn<<endl;
    while(1);
    return 0;
}
