#include <iostream>

using namespace std;

class node{
    public:
    int value;
    node * next;
    node(){
        value = 0;
        next = NULL;
    }
};
int main()
{
    node * head,* curr;
    head = new node();
    head->next = NULL;
    head->value = 15;

    for(int i = 0; i < 15;i++)
    {
        curr = new node();
        curr->value = i;
        curr->next = head;
        head = curr;
    }
     while (head!=NULL)
    {
        cout << head->value << endl;
        head = head->next;
    }
    while(1);
    return 0;
}
