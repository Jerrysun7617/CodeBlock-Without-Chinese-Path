#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
TreeNode *CreateBTree(TreeNode *node,int *num,int& index)
{
    if(index>=2)
        return node;
    node = new TreeNode(0);
    node -> val = num[index];
    node -> left = CreateBTree(node->left,num,++index);
    node -> right = CreateBTree(node->right,num,++index);

    return node;
}
int get_height(TreeNode * root, int level , bool &res){
    if(root == NULL)
        return  level;
    int lh = get_height(root->left,level+1,res);
    if(!res) return level;
    int rh = get_height(root->right,level+1,res);
    if(!res) return level;
    if(lh-rh >1 || rh - lh > 1)
        res = false;
    return max(lh,rh);
}
bool chk(TreeNode* root) {
    // write code here
    queue< TreeNode*> qe;
    TreeNode * cur = root;
    while(cur != NULL){
        qe.push(cur->left);
        qe.push(cur->right);
        cur = qe.front();
        qe.pop();
    }
    while(!qe.empty()){
        cur = qe.front();
        qe.pop();
        if(cur != NULL)
            return false;
    }

    return true;
}

int main()
{
    int num[] = {1,2,3};
    TreeNode *root = NULL;
    int index = 0;
    int st = 123;


    root = CreateBTree(root,num,index);
    if(chk(root))
        cout<<"it is true"<<endl;
    else
        cout<<"it is false"<<endl;


    while(1);
    return 0;
}
