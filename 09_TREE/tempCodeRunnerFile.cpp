#include<iostream>
#include<vector>
#include<queue>
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
static int idx = -1;
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
void inorder_travel(Node* root){
    if(root==NULL)return;
    inorder_travel(root->left);
    cout << root->data << " ";
    inorder_travel(root->right);
};
void post_order(Node* root){
    if(root==NULL)return;
    pre_order_traverse(root->right);
    cout << root->data << " ";
    pre_order_traverse(root->left);

}
void level_traversal(Node* root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL); //it is for level wise printing.....
    while (q.size()>0){
        Node *curr = q.front();
        q.pop();
        // for level wise printing.....
        if(curr==NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        //ending........
        cout << curr->data;
        if(curr->left !=NULL){
            q.push(curr->left);
        }
        if(curr->right !=NULL){
            q.push(curr->right);
        }
    }
    cout <<endl;
    
}
int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    //Build_Tree returns us root and we are getting all subtree using this...
    Node* root = Build_Tree(preorder);
    cout << root->data << endl
         << root->left <<" at memory index..the root is : "
         << root->left->data << endl
         << root->right <<" at memory index...the root is : "
         << root->right->data;
    cout << "\nPreorder traversal of constructed tree is: ";
    pre_order_traverse(root);
    cout << "\ninorder traversal of constructed tree is: ";
    inorder_travel(root);
    cout<<"\npreorder traversal of constructed tree is: ";
    post_order(root);
    cout << "\n";
    level_traversal(root);
    return 0;
}