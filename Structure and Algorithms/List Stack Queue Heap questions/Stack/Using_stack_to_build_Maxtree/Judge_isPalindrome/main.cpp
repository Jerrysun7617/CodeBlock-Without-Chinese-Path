#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool isPalindrome(ListNode* pHead) {
    // write code here
    if(pHead == NULL)
        return false;
    stack<int> lt;
    ListNode*  qe = pHead;
    while(qe){
        lt.push(qe->val);
        qe = qe->next;
    }
    qe = pHead;
    while(qe){
        if(qe->val != lt.top())
            return false;
        qe = qe->next;
        lt.pop();
    }
    return true;
}
int main()
{
    cout << "Hello world!" << endl;

    while
    return 0;
}
