#include <iostream>
#include <string>
using namespace std;

int main()
{
    string title;
    string url;
    string comment;
    double length = 0.0;
    int rating = 0;
    string sort_method;

    cin >> sort_method;

    while(getline(cin,title))
    {
        getline(cin, title);
        getline(cin, url);
        getline(cin, comment);
        cin >> length;
        cin >> rating;
        cin.ignore();  // what is this line done
    }
        cout << title << endl;
        cout << url << endl;
        cout << comment << endl;
        cout << length << endl;
        cout << rating << endl;

    while(1);
    return 0;
}
