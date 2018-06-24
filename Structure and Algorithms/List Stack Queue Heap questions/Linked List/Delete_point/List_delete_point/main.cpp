#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Remove {
public:
    ListNode* removeNode(ListNode* pHead, int delVal) {
        // write code here
        if(pHead == NULL)
            return pHead;

        ListNode * p = pHead;
        //if delete the head
        if(p->val == delVal)
        {
            p = p->next;
            pHead->next =  NULL;
            pHead = NULL;
            pHead = p;
        }else{
            while(p->val != delVal && p->next != NULL)
            {
                p = p->next;
            }
            if(p->next == NULL){ // the last one
                if(p->val == delVal){
                    //delete the last one;
                    ListNode*q = pHead;
                    while(q->next != p){
                        q = q->next;
                    }
                    q->next = NULL;
                    p = NULL;
                }
            }
            else{ // not the last one
                ListNode*q = pHead;
                while(q->next != p){
                    q = q->next;
                }
                q->next = p->next;
                p = NULL;
            }
        }
        return pHead;
    }

    ListNode* clear(ListNode* head, int val) {
        // write code here
        if(head == NULL)
            return head;
        ListNode* thr = head;

            while(thr != NULL){
                if(thr->val == val){
                     if(thr == head){
                        thr = thr->next;
                        head = NULL;
                        head = thr;
                     }
                     else{
                        ListNode* qe = head;
                        while(qe->next != thr )
                            qe = qe->next;
                        if(qe->next->next == NULL){
                            qe->next = NULL;
                            thr = NULL;
                        }
                        else{
                            qe->next  = qe->next->next;
                            thr = NULL;
                            thr = qe;
                        }
                     }
                }
                else
                    thr = thr->next;
            }

        return head;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    cin>>head->val;
    for(int i = 0; i < 5; i++){
        ListNode * q = new ListNode(0);
        cin>>q->val;
        p->next = q;
        p = q;
    }
    p->next = NULL;

    int delVal = 0 ;
    cout<<"Please input a delete value"<<endl;
    cin>>delVal;
    class Remove test;
    //ListNode * tr = test.removeNode(head,delVal);
     ListNode * tr = test.clear(head,delVal);


    ListNode * cl = tr;
    while(cl){
        cout<<cl->val<<" ";
        cl = cl->next;
    }
    //cout<<cl->val<<endl;
    while(1);
    return 0;
}
