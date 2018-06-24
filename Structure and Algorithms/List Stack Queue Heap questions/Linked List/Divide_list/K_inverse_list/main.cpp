#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        // write code here
        stack<struct ListNode *>  test;
        ListNode * p = head;
        ListNode * newhead = new ListNode(0);
        ListNode * nh = newhead;
        if(p != NULL){
            ListNode * q = p;
            while(p != NULL){
                if( test.size() < k){
                    cout<<p->val <<" ";
                    test.push(p);
                    p = p->next;
                }
                if( test.size() >= k){
                    while(!test.empty()){
                        cout<<test.top()->val<<endl;
                        nh->val = test.top()->val;
                        test.pop();
                        if(!test.empty()|| p != NULL){
                            ListNode *  chg =new ListNode(101);
                            nh->next = chg;
                            nh = nh->next;
                        }
                    }
                    q = p;
                }
            }

            while(!test.empty()){
                nh->val = q->val ; //
                test.pop();

              if(!test.empty())
                {
                    ListNode *  chg =new ListNode(100);
                    nh->next = chg;
                    nh = nh->next;
                }
            }
            nh->next = NULL;
        }
        else{
            newhead = NULL;
        }
        /*
        while(newhead != NULL){
            cout<<newhead->val<<" ";
            newhead = newhead->next;
        }
        while(1);
        */
        return newhead;
    }
};
int main()
{
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    for(int i = 0; i < 5;i++)
    {
        ListNode * q = new ListNode(0);
        cin>>q->val;
        p->next = q;
        p = p->next;
    }
    p = NULL;


    class KInverse test;
    ListNode * ts = test.inverse(head,2);

    while(ts != NULL){
        cout<<ts->val<<" ";
    }

    while(1);
    return 0;
}
