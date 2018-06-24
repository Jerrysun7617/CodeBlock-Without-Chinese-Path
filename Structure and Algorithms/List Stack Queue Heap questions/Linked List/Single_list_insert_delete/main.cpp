#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next;
    node()
    {
        value = 0;
        next = NULL;
    }
};
int main()
{
    node *head=NULL,
        *curr=NULL,         //当前节点
        *insert=NULL,       //插入节点
        *next=NULL,         //后继节点
        *pre=NULL;          //前驱节点
    head = new node();
    head->next = NULL;
    head->value = 15;
    for (size_t i = 0; i < 10; i++)
    {
        curr = new node();
        curr->value = i;
        curr->next = head;
        head = curr;
    }
    curr = head;            //取出头结点
    while (curr->value != 5)
    {
        curr = curr->next;
    }
                            //找到值为5的节点
    next = curr->next;       //找到值为5的节点的后继节点
    insert = new node();    //生成一个新的节点，值为20
    insert->value = 20;
    curr->next = insert; //当前节点的后继节点为插入节点
    insert->next = next; //插入节点的后继节点为值为5的节点的后继节点
    curr = head;            //遍历链表，输出每一个元素
    while (curr!=NULL)
    {
        cout << curr->value<<endl;
        curr = curr->next;
    }
    curr = head;            //找到头结点
    while (curr->value!=20)
    {
        pre = curr;
        curr = curr->next;
    }
    //找到值为20的节点，注意现在是单向链表，每个节点中不保存它的前驱节点，所以在遍历的过程中要人为保存一下前驱节点
    next = curr->next;       //找到当前节点的后继节点(当前节点就是值为20的节点)
    pre->next = next;        //当前节点的前驱节点的后继节点为当前节点的后继节点
    delete curr;            //删除当前节点
    curr = head;            //遍历这个链表输出每个元素
    while (curr != NULL)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
    while (true)
    {

    }
}
