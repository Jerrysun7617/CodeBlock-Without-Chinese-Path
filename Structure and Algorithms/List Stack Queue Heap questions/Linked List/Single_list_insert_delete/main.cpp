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
        *curr=NULL,         //��ǰ�ڵ�
        *insert=NULL,       //����ڵ�
        *next=NULL,         //��̽ڵ�
        *pre=NULL;          //ǰ���ڵ�
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
    curr = head;            //ȡ��ͷ���
    while (curr->value != 5)
    {
        curr = curr->next;
    }
                            //�ҵ�ֵΪ5�Ľڵ�
    next = curr->next;       //�ҵ�ֵΪ5�Ľڵ�ĺ�̽ڵ�
    insert = new node();    //����һ���µĽڵ㣬ֵΪ20
    insert->value = 20;
    curr->next = insert; //��ǰ�ڵ�ĺ�̽ڵ�Ϊ����ڵ�
    insert->next = next; //����ڵ�ĺ�̽ڵ�ΪֵΪ5�Ľڵ�ĺ�̽ڵ�
    curr = head;            //�����������ÿһ��Ԫ��
    while (curr!=NULL)
    {
        cout << curr->value<<endl;
        curr = curr->next;
    }
    curr = head;            //�ҵ�ͷ���
    while (curr->value!=20)
    {
        pre = curr;
        curr = curr->next;
    }
    //�ҵ�ֵΪ20�Ľڵ㣬ע�������ǵ�������ÿ���ڵ��в���������ǰ���ڵ㣬�����ڱ����Ĺ�����Ҫ��Ϊ����һ��ǰ���ڵ�
    next = curr->next;       //�ҵ���ǰ�ڵ�ĺ�̽ڵ�(��ǰ�ڵ����ֵΪ20�Ľڵ�)
    pre->next = next;        //��ǰ�ڵ��ǰ���ڵ�ĺ�̽ڵ�Ϊ��ǰ�ڵ�ĺ�̽ڵ�
    delete curr;            //ɾ����ǰ�ڵ�
    curr = head;            //��������������ÿ��Ԫ��
    while (curr != NULL)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
    while (true)
    {

    }
}
