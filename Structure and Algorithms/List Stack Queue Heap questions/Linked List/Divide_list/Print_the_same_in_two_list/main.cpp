#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Divide {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
        // write code here
        ListNode * th = headA;
        ListNode * nx = headB;

        vector<int> vc;

        while(th != NULL && nx != NULL){

            if(th->val < nx->val){
                th = th->next;
            }
            else if ( th->val == nx->val){
                 //   cout<<th->val<<" ";
                vc.push_back(th->val);
                th = th->next;
                nx = nx->next;
            }
            else
                nx = nx->next;
        }

       // for(int i = 0; i < ts.size();i++)
        //cout<<ts[i]<<" ";

        return vc;
    }
};
int main()
{
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    for(int i = 0; i < 9;i++)
    {
        ListNode * q = new ListNode(0);
        cin>>q->val;
        p->next = q;
        p = p->next;
    }
    p = NULL;

    ListNode * head1 = new ListNode(0);
    p = head1;
    for(int i = 0; i < 9;i++)
    {
        ListNode * q = new ListNode(0);
        cin>>q->val;
        p->next = q;
        p = p->next;
    }
    p = NULL;

    p = head;
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    p = head1;
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    class Divide test;
    vector<int> ts = test.findCommonParts(head,head1);

    for(int i = 0; i < ts.size();i++)
        cout<<ts[i]<<" ";

    while(1);
    return 0;
}
