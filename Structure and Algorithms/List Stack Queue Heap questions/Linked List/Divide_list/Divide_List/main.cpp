#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Divide {
public:
    ListNode* listDivide(ListNode* head, int val) {
        // write code here
        ListNode * p = head;
        ListNode * sm = new ListNode(100);
        ListNode * small = sm;
        ListNode * eq = new ListNode(100);
        ListNode * equ = eq;
        ListNode * bg = new ListNode(100);
        ListNode * big = bg;
        bool first_small = true;
        bool first_equ = true;
        bool first_big = true;
        if(p != NULL && p->next != NULL){
            while( p != NULL){
                ListNode * q = new ListNode(val);
                q->val = p->val;
                if(p->val <= val){
                    if(first_small){
                        first_small = false;
                        small->val = p->val;
                    }else{
                        small->next = q;
                        small = small->next;
                    }
                }
                else if(p->val == val){
                    if(first_equ){
                        first_equ = false;
                        equ->val = p->val;
                    }else{
                        equ->next = q;
                        equ = equ->next;
                    }
                }
                else{
                  if(first_big){
                        first_big = false;
                        big->val = p->val;
                    }else{
                        big->next = q;
                        big = big->next;
                    }
                }
                p = p->next;
            }
            small = equ = big = NULL;
            if(first_small)
                sm = NULL;
            if(first_equ)
                eq = NULL;
            if(first_big)
                bg = NULL;

            /*
            cout<<"small: ";
            while(sm != NULL){
                cout<<sm->val<<" ";
                sm = sm->next;
            }
            cout<<endl;
            cout<<"equal: ";
            while(eq != NULL){
                cout<<eq->val<<" ";
                eq = eq->next;
            }
            cout<<endl;
            cout<<"Big: ";
            while(bg != NULL){
                cout<<bg->val<<" ";
                bg = bg->next;
            }
            cout<<endl;
            */

            if(sm != NULL){
                small = sm;
                while(small->next != NULL)
                    small = small ->next;
                if(eq != NULL)
                {
                    small->next = eq;
                    while(small->next != NULL)
                        small = small ->next;
                    small->next = bg;
                }
                else
                    small->next = bg;
                small = sm;
            }
            else
            {
                if(eq != NULL)
                {
                    equ = eq;
                    while(equ->next != NULL)
                        equ = equ->next;
                    equ->next = bg;

                    small = eq;
                }
                else
                    small = bg;
            }
        }
        else{
            small = head;
        }


        return small;
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

    class Divide test;
    ListNode * bk =   test.listDivide(head,5);

    while(bk != NULL){
        cout<<bk->val<<" ";
        bk = bk->next;
    }
    cout<<endl;

    while(1);
    return 0;
}
