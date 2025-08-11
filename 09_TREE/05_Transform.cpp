#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<conio.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
static int  idx = -1;
Node* Build_Tree(vector<int>& preorder){
    idx++;
    if(preorder[idx]==-1)return NULL;
    // create a new node /root node
    Node* root = new Node(preorder[idx]);
    // build left subtree
    root->left = Build_Tree(preorder);
    // build right subtree
    root->right = Build_Tree(preorder);
    return root;
}
void pre_order_traverse(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    pre_order_traverse(root->left);
    pre_order_traverse(root->right);
};
int SUMTREE(Node* root){
    if(root==NULL)return 0;
    int leftsum = SUMTREE(root->left);
    int rightsum = SUMTREE(root->right);
    root->data += leftsum + rightsum;
    return root->data;
}
int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1,4,5,6,7,8,9,};
    //Build_Tree returns us root and we are getting all subtree using this...
    Node* root = Build_Tree(preorder);


    cout << "before transform sumtree : ";
    pre_order_traverse(root);
    cout << "\n";
    SUMTREE(root);
    cout << "after transform sumtree : ";
    pre_order_traverse(root);
    return 0;
}