#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        //create a list
        ListNode * now = new ListNode(val);
        if(A.size() == 0 )
            return now;
        sort(A.begin(),A.end());
        /*
    cout<<"input:"<<endl;
    for(int i = 0; i< 5;i++)
    {
       cout<<A[i]<<" ";
    }
    cout<<endl;*/
        ListNode * head = new ListNode(A[0]);
        ListNode * p = head;
        for(int i = 1; i < A.size();i++){
            ////cout<<i<<"  "<<p->val<<endl;
            ListNode * q = new ListNode(A[i]);
            p->next = q;
            p = q;
        }
        //cout<<"  "<<p->val<<endl;
        p->next = head;//�γ�ѭ��


        if(val <= head->val){
            p = head;
            while(p->next != head){
                p = p->next;
            }
            p->next = NULL; //find the last node, interrupt
            now->next = head; //��now��nextָ��head
            head = now; // now ���head return
            //p->next = NULL; //��ѭ��


          /* ����*/
           /*
        ListNode * ts = head;

        cout<<"����"<<endl;
        while(ts->next != head){
            cout<<ts->val<<" ";
            ts = ts->next;
        }
        cout<<ts->val<<endl;*/

            return head;
        }
        p = head;
        while((p->next->val)<val)
        {
            if(p->next == head){
                p->next = now;
                now->next = NULL;
                return head;
            }
            p = p->next;
        }
        ListNode * q = p->next; // ����
        p->next = now;
        now->next = q;
        p = head;
        while(p->next != head)
            p = p->next;
        p->next = NULL;
       return head;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    int A[5] = {1,3,4,5,7};
    int nxt[5] = {1,2,3,4,0};
    vector<int> Av;
    vector<int> nxtv;
    for(int i = 0; i< 5;i++)
    {
        Av.push_back(A[i]);
        nxtv.push_back(nxt[i]);
    }
    int val = 8;
    class InsertValue ins;
    //for()
    ListNode * test = new ListNode(0);
    test =ins.insert(Av,nxtv,val);

    ListNode * p = test;
    while(p->next != NULL){
        cout<<p->val<<" ";
        p= p->next ;
    }
    cout<<p->val<<endl;
    while(1);
    return 0;
}
