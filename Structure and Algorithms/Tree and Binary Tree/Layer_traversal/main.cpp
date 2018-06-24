#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
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

vector<vector<int> > printTree(TreeNode* root) {
    // write code here
    vector<vector<int> > prin;
    if(root == NULL)
        return prin;
    queue< TreeNode* > qe;
    qe.push(root);
    while(!qe.empty()){
        int size = qe.size();
        vector<int> row;
        for(int i = 0;i < size;i++){
            TreeNode *  last = qe.front();
            qe.pop();
            row.push_back(last->val);
            if(last->left != NULL) qe.push(last->left);
            if(last->right != NULL) qe.push(last->right);
        }
        prin.push_back(row);
    }
    return prin;
}

int main()
{
    int num[] = {1,2,3,4,5,6,7,8,9,10};
    TreeNode *root = NULL;
    int index = 0;
    vector< vector<int> > test;
    vector<int> ts;
    root = CreateBTree(root,num,index);
    test = printTree(root);

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
