#include <iostream>

using namespace std;
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
#ifdef INSERT_ALgorighm
        ListNode * head, * temp,*print;
        print =  head = l1;

        while(l2 != NULL){
            temp = new ListNode(0);
            temp = l1 = head;
            while(l2->val < l1->val){
                temp = l1;
                l1 = l1->next;
            }
            ListNode * curr = l2;
            temp->next = curr;
            temp->next->next = curr->next;
            l1->next =NULL;
            //delete l1;
            l2 = l2->next;
        }

        while(head != NULL)
        {
           cout<<head->val<<endl;
           head = head->next;
        }

        return print;
    }
#else
        ListNode * merge_two,*head;
       head  = merge_two  = new ListNode(0);
        ListNode * newnode = new ListNode(0);
        //head = l1;
        while(l1!= NULL && l2!= NULL)
        {
            if(l1->val > l2->val){
                merge_two = l2;
                l2 = l2->next;
            }
            else{
                merge_two = l1;
                l1= l1->next;
            }
            cout<<merge_two->val<<endl;


            merge_two = merge_two->next;
            merge_two = new ListNode(0);

        }

        while(l1!= NULL){
            merge_two = l1;
            cout<<merge_two->val<<endl;
            merge_two = merge_two->next;
            merge_two = new ListNode(0);
            l1 = l1->next;
        }
        while(l2 != NULL){

            merge_two= l2;
           cout<<merge_two->val<<endl;
            merge_two = merge_two->next;
            merge_two = new ListNode(0);
            l2 = l2->next ;
        }
        merge_two->next = NULL;
        return head;
    }
#endif
};
int main()
{
   ListNode * list1, *head1,*curr1,*list2,*head2,*curr2;
   head1 = list1 = curr1 =  new ListNode(0);
   int value = 0;
   while(cin>>value)
   {
        if(value == 0)
            break;
        curr1->val = value;
        list1 = curr1;
        curr1  =  new ListNode(0);
        list1->next = curr1;
   }
   curr1 = NULL;

   head2 = list2 = curr2 =  new ListNode(0);
   while(cin>>curr2->val)
   {
        if(curr2->val == 0)
            break;
        list2 = curr2;
        curr2  =  new ListNode(0);
        list2->next = curr2;
   }
   curr2->next = NULL;

    ListNode * print = head1;
    while(print != NULL){

        cout<<print->val<<" ";
        print = print->next;
    }
    cout<<endl;

    print = head2;
    while(print != NULL){
        cout<<print->val<<" ";
        print = print->next;
    }
    cout<<endl;

    class Solution test;
    ListNode * together;
    together = test.mergeTwoLists(head1,head2);

    while(together != NULL){
        cout<<together->val<<" ";
        together = together->next;
    }
    cout<<endl;

    while(1);
    return 0;
}
