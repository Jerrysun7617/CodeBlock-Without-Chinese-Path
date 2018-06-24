#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string input_line, word;    // first input one line code ending by return
    int sec  = 0;

    while(getline(cin, input_line))
    {
        vector <string> split_input;
		stringstream ss(input_line);
		while (ss >> word)
			split_input.push_back(word);  // input strings

        for(int i = 0; i <split_input.size();i++)
            cout<<split_input[i]<<" ";
        cout<<endl;
    }
     return 0;
}
