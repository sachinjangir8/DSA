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
void KTH_LEVEL(Node * root, int k) {
    if(root==NULL)return;
    if(k==1){
        cout << root->data << " ";
        return;
    }
    KTH_LEVEL(root->left, k - 1);
    KTH_LEVEL(root->right, k - 1);
};
int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1,4,5,6,7,8,9,};
    //Build_Tree returns us root and we are getting all subtree using this...
    Node* root = Build_Tree(preorder);


    pre_order_traverse(root);
    cout << "nothinf\n";

    cout << root->data << endl
         << root->left <<" at memory index..the root is : "
         << root->left->data << endl
         << root->right <<" at memory index...the root is : "
         << root->right->data;

    cout << "\n";
    KTH_LEVEL(root,3);
    return 0;
}