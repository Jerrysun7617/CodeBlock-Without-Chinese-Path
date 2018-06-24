#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
}TreeNode;
/*
**num 前序序列
**index 下标
*/
TreeNode *CreateBTree(TreeNode *node,int *num,int& index)
{
    if(index>=10)
        return node;
    node = new TreeNode(0);
    node -> val = num[index];
    node -> left = CreateBTree(node->left,num,++index);
    node -> right = CreateBTree(node->right,num,++index);

    return node;
}

void preorder(TreeNode* root,vector<int> &order){
    if(root == NULL)
        return;
    order.push_back(root->val);
    preorder(root->left,order);
    preorder(root->right,order);
}
void inorder(TreeNode* root,vector<int> &order){
    if(root == NULL)
        return;

    inorder(root->left,order);
    order.push_back(root->val);
    inorder(root->right,order);
}
void posterorder(TreeNode* root,vector<int> &order){
    if(root == NULL)
        return;
    posterorder(root->left,order);
    posterorder(root->right,order);
    order.push_back(root->val);
}
vector< vector<int> > convert(TreeNode* root) {
    // write code here

    vector< vector<int> > printorder;
    vector<int> order;
    preorder(root,order);
    printorder.push_back(order);
    order.clear();

    inorder(root,order);
    printorder.push_back(order);
    order.clear();

    posterorder(root,order);
    printorder.push_back(order);
    order.clear();

    return printorder;
}

int main()
{
    int num[] = {479,141,279,511,562,326,203,117,168,351};
    TreeNode *root = NULL;
    int index = 0;
    vector< vector<int> > test;
    vector<int> ts;
    root = CreateBTree(root,num,index);
    test = convert(root);

    vector< vector<int> >::iterator it;
    vector<int>::iterator itr;
    for(it = test.begin();it < test.end();it++){
        for(itr = it->begin() ; itr < it->end() ;  itr++){
                cout<<*itr<<" ";
        }
        cout<<endl;
    }
    while(1);
    return 0;
}
