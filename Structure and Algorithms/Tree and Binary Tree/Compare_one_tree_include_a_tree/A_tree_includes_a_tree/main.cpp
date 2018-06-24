#include <iostream>

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

    void get_next(string & str,int *next,int n)          //  to  next point
    {
        next[0] = -1;
        int k = -1;
        for(int i = 1;i<n;i++)
        {
            while(k>-1 && str[k+1] != str[i])
                k=next[k];
            if(str[k+1] == str[i])
                k++;
            next[i] = k;
        }
    }
    int KMP(string &str,int slen,string &ptr,int plen)        // kmp
    {
        int *next = new int[plen];
        get_next(ptr,next,plen); //得到plen 的next指针
        int k = -1;
        for(int i = 0;i<slen;i++)
        {
            while(k>-1 && ptr[k+1] != str[i])
                k=next[k];
            if(ptr[k+1] == str[i])
                k++;
            if(k == plen -1 )
            {
                return i-plen+1;
            }
        }
        return -1; //否则就是没找到
    }

string preorder(TreeNode* A){
    if(A == NULL)
        return "#!";

    string str =  to_string(A->val)+ "!";

    str += preorder(A->left);

   str += preorder(A->right);

    return str;
}
bool chkIdentical(TreeNode* A, TreeNode* B) {
    // write code here

    if(A == NULL || B== NULL)
        return false;


    string mather = preorder(A);
    string son = preorder(B);

    cout<<mather<<"   "<<son<<endl;

    if(KMP(mather,mather.size(),son,son.size())<0)
       return false;
    else
        return true;
}


int main()
{
    int num[] = {1,2};
    int num1[] = {4};
    TreeNode *root = NULL;
    int index = 0;
    root = CreateBTree(root,num,index);
    TreeNode *root2 = NULL;
    index = 0;
    root2 = CreateBTree(root2,num1,index);

    cout<<chkIdentical(root,root2)<<endl;;

    while(1);
    return 0;
}
