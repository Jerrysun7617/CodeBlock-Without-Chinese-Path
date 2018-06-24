#include <iostream>
#include <vector>
#include <sstream>
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
    if(index>=10)
        return node;
    node = new TreeNode(0);
    node -> val = num[index];
    node -> left = CreateBTree(node->left,num,++index);
    node -> right = CreateBTree(node->right,num,++index);

    return node;
}
string str;
string toString(TreeNode* root) {
    // write code here
    TreeNode * cur = root;
    if(cur == NULL){
        str += "#!";
        return str;
    }
    ostringstream stream;
    stream<<cur->val;  //n为int类型
    str += stream.str() + "!";
    toString(cur->left);
    toString(cur->right);

    return str;
}

int main()
{
    int num[] = {1,2,3,4,5,6,7,8,9,10};
    TreeNode *root = NULL;
    int index = 0;
    int st = 123;
    ostringstream stream;

    stream<<st;  //n为int类型
    string k = stream.str();


    cout<<k<<endl;

    vector<int> ts;
    root = CreateBTree(root,num,index);
    cout<<toString(root)<<endl;


    while(1);
    return 0;
}
