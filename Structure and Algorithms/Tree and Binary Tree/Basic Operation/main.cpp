#include <iostream>
#include <stack>
using namespace std;

typedef struct BTree
{
    int    value;
    struct BTree *lchild;
    struct BTree *rchild;
}BTree;
/*
**num ǰ������
**index �±�
*/
BTree *CreateBTree(BTree *node,int *num,int& index)
{
    if(num[index] == 0)
        return NULL;
    else
    {
        node = new BTree;
        node -> value = num[index];
        node -> lchild = CreateBTree(node->lchild,num,++index);
        node -> rchild = CreateBTree(node->rchild,num,++index);
    }
    return node;
}
//�ݹ飭��ǰ�����
void preOrder(BTree * root)
{
    if(root == NULL)
        return;
    //cout<< root->value << " ";����//��������ĸ��ڵ��ֵ
    cout<<root->value<<" ";
    preOrder(root -> lchild);       //�ݹ顡������
    preOrder(root -> rchild);       //�ݹ顡������
}
//�ǵݹ飭��ǰ�����
void preOrder_dxm(BTree * root)
{
    stack<BTree*> S;
    BTree *p = root;
    while(p != NULL || !S.empty())
    {
        while(p != NULL)
        {
            cout << p -> value << " ";
            S.push(p);
            p = p -> lchild;
        }
        if(!S.empty())
        {
            S.pop();
            if(S.empty())
                return ;
            p = S.top();
            S.pop();
            p = p -> rchild;
        }
    }
}
//�ݹ飭���������
void inOrder(BTree * root)
{
    if(root == NULL)
        return;
    inOrder(root -> lchild);
    cout << root -> value << " ";
    inOrder(root -> rchild);
}
//�ǵݹ飭���������
void inOrder_dxm(BTree * root)
{
    stack<BTree*> S;
    BTree *p = root;
    while(p != NULL || !S.empty())
    {
        while(p != NULL)
        {
            //cout << p -> value << " ";
            S.push(p);
            p = p -> lchild;
        }
        if(!S.empty())
        {
            p = S.top();
            cout << p -> value << " ";
            S.pop();
            if(S.empty())
                return ;
            //S.pop();
            p = S.top();
            cout << p -> value << " ";
            S.pop();
            p = p -> rchild;
        }
    }
}

//�ݹ飭���������
void postOrder(BTree * root)
{
    if(root == NULL)
        return;
    postOrder(root -> lchild);
    postOrder(root -> rchild);
    cout << root -> value << " ";
}
//�ǵݹ飭���������

void postOrder_dxm(BTree * root)
{
    stack<BTree*> S;
    BTree *cur;
    BTree *pre = NULL;
    S.push(root);
    while(!S.empty())
    {
        cur = S.top();
        if((cur -> lchild == NULL && cur -> rchild == NULL) ||
           (pre != NULL && (pre == cur -> lchild || pre == cur ->rchild)))
        {
            cout << cur -> value << " ";
            S.pop();
            pre = cur;
        }
        else
        {
            if(cur -> rchild != NULL)
                S.push(cur -> rchild);
            if(cur -> lchild != NULL)
                S.push(cur -> lchild);
        }
    }
}
//������������
int getdepth(BTree *root)
{
    if(root == NULL)
        return 0;
    int lchild_depth = getdepth(root -> lchild);
    int rchild_depth = getdepth(root -> rchild);
    return max(lchild_depth,rchild_depth) + 1;
}

//�������Ҷ�ӽڵ�ĸ���
int getleaves(BTree *root)
{
    if(root == NULL)
        return 0;
    if(root -> lchild == NULL && root -> rchild == NULL)
        return 1;
    return 1 + getleaves(root -> lchild) + getleaves(root -> rchild);
}
//��״��ӡ������
void print(BTree *root,int h)
{
    if(root != NULL)
    {
        print(root -> rchild,h+1);
        for(int i=0; i<h; i++)
            cout << "   ";
        cout << root -> value;
        print(root -> lchild,h+1);
    }
    cout << endl;
}
int main()
{
  int num[] = {1,2,4,8,0,0,9,0,0,5,10,0,0,11,0,0,3,6,12,0,0,13,0,0,7,14,0,0,15,0,0};
    BTree *root = NULL;
    int index = 0;
    root = CreateBTree(root,num,index);

    cout << "ǰ��ǵݹ����: " << endl;
    preOrder_dxm(root);
    cout << endl;

    cout << "����ݹ����: " << endl;
    inOrder_dxm(root);
    cout << endl;

    cout << "�����ǵݹ����: " << endl;
    postOrder_dxm(root);
    cout << endl << endl;;

    cout << "�˶���������״Ϊ: " << endl;
    print(root,1);

    while(1);
    return 0;
}
