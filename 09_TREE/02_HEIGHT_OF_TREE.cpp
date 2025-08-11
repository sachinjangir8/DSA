#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node *Build_Tree(vector<int> &trees)
{
    idx++;
    if (trees[idx] == -1)
        return NULL;
    // create a new node /root node
    Node *root = new Node(trees[idx]);
    // build left subtree
    root->left = Build_Tree(trees);
    // build right subtree
    root->right = Build_Tree(trees);
    return root;
}
int Height_of_tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefheight = Height_of_tree(root->left);
    int righeight = Height_of_tree(root->right);
    // return max(lefheight, righeight) + 1;
    // this is for count of NODES,.........
    return lefheight + righeight +1;
}
//sum of the all nodes..
int SUM_OF_NODES(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    int lef = SUM_OF_NODES(root->left);
    int rig = SUM_OF_NODES(root->right);
    return lef + rig + root->data;

}
int main()
{
    vector<int> trees = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = Build_Tree(trees);
    cout << root->left<<"\n";
    cout << root->data << " " << root->left->data;
    cout<<"\nheight of the tree..: "<<Height_of_tree(root);
    cout << "\nsum of all nodes : " <<SUM_OF_NODES(root); 
}