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
    stack<TreeNode* > Store;
    TreeNode* current = NULL;
    Store.push(root);
    while(!Store.empty()){
        current = Store.top();
        order.push_back(current->val);
        Store.pop();
        if(current->right != NULL)Store.push(current->right);
        if(current->left != NULL)Store.push(current->left);
    }
}
void inorder(TreeNode* root,vector<int> &order){
    stack<TreeNode* > store;
    TreeNode* cur = root;
    //store.push(cur);
    while(!store.empty() || cur != NULL){
        if(cur != NULL)
        {
            store.push(cur);
            cur = cur->left;
        }
        else{
            cur = store.top();
            order.push_back(cur->val);
            cur = cur->right;
            store.pop();
        }
    }
}
void posterorder(TreeNode* root,vector<int> &order){
    stack<TreeNode * > S1,S2;
    TreeNode* cur = root;
    S1.push(cur);
    while(!S1.empty()){
        cur = S1.top();
        S2.push(cur);
        S1.pop();
        if(cur->left != NULL)
            S1.push(cur->left);
        if(cur->right != NULL)
            S1.push(cur->right);
        //cur = cur->right;
    }
    while(!S2.empty()){
        order.push_back(S2.top()->val);
        S2.pop();
    }
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
    int num[] = {1,2,3,4,5,6,7,8,9,10};
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
