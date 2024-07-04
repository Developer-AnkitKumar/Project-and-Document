#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
node* root = NULL;
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

node* insertNode(node* root, int data){
   
    if(root == NULL){
        return createNode(data);
    }
    if(data < root -> data){
        root -> left = insertNode(root -> left, data);
        
    }
    else if(data > root -> data){
         root -> right = insertNode(root -> right, data);
    }
    return root;
}

void inOrderTraversal(node* root) {
    if (root != NULL) {
     inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int minimumValue(node* root){
   int  minValue = root -> data;
   while(root -> left != NULL){
    minValue = root -> left -> data;
    root = root -> left;
   }
   return minValue;
}

node* deleteNode(node* root , int data){
    if(root == NULL){
        return root;
    }
    if(data < root -> data){
        root -> left = deleteNode(root -> left, data);
    }
    else if(data > root -> data){
         root -> right = deleteNode(root -> right, data);
    }
    else{
        if(root -> left == NULL){
            return root -> right;
        }
        else if(root -> right == NULL){
            return root -> left;
        }
        root -> data = minimumValue(root -> right );
        root -> right = deleteNode(root -> right,  root -> data);
    }
    return root;
}

int main(){
    int n;
    cout<<"enter a number of insret element into BSTree:";
    cin>>n;

    for(int i = 0; i<n; i++){
        int ele;
         cout << "Enter element " << i + 1 << ": ";
        cin>>ele;
         root = insertNode(root, ele);

    }
    cout<<"In-order traversal of the BST: "<<"\n";
    inOrderTraversal(root);
}