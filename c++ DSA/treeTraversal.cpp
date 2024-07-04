#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
}; 
node* root = NULL;
node * createNode(long long data){
    node * newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void preOrderTraversal(node * root)
{
    if(root != NULL){
        cout<<root->data<<" ";
        preOrderTraversal(root -> left);
        preOrderTraversal(root -> right);
    }
}

void postOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout<<root -> data<<" ";
}

void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root -> left);
    cout<<root -> data<<" ";
    inOrderTraversal(root -> right);
}

void levelOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    queue<node*>qroot;
    qroot.push(root);
    while(! qroot.empty()){
        node* temp = qroot.front();
       qroot.pop();
       cout<<temp-> data<<" ";
       if(temp -> left != NULL){
        qroot.push(temp->left); 
       }
       if(temp -> right != NULL){
        qroot.push(temp->right);
    }
}
}

int calculateHeight(node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int leftHeight = calculateHeight(root -> left);
        int rightHeight = calculateHeight(root -> right);

        return max(leftHeight, rightHeight)+1;
    }
}

int sizeOfTree(node* root){
    if(root == NULL){
        return 0;
    }
    return(1+ sizeOfTree(root -> left) + sizeOfTree(root -> right));
}

node* searchData(node* root, int data){
    if(root == NULL || root -> data == data){
        return root;
    }
    if(data < root -> data){
        return searchData(root -> left, data);
    }
    else{
        return searchData(root -> right, data);
    }
}

void search(int data){
    node* root = searchData(root , data);
    if(root != NULL){
        cout<<"data "<<data<<"is found\n";
    }
    else{
        cout<<"data "<<data<<"is not found\n";
    }
}
/*
void nodeAtLevel(node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout<<root -> data<<" ";
    }
    else if(level > 1){
       nodeAtLevel(root -> left, level-1);
       nodeAtLevel(root -> right, level-1);
    }
}
*/

int main()
{
    //node* root = createNode(1);
    root = createNode(1);
    root -> left = createNode(2);
     root -> right = createNode(3);
      root -> left -> left = createNode(4);
       root -> left -> right = createNode(5);
        root -> right -> left = createNode(6);

        //  int height = calculateHeight(root);
        //  for(int i=1; i <= height; i++){

        cout<<"preOrder traversal = "<<"\n";
         preOrderTraversal(root);
        cout<<"postOrder traversal = "<<"\n";
         postOrderTraversal(root);
        cout<<"inOrder traversal = "<<"\n";
         inOrderTraversal(root);
         cout<<"level order traversal = "<<"\n";
         levelOrderTraversal(root);
         cout<<"\n";
         cout<<"calculate height = "<<calculateHeight(root)<<"\n";
         cout<<"sizeOfTree = "<<sizeOfTree(root)<<"\n";
         cout<<"search 5: \n";
         search(5);
        // cout<<"node at level = "<<i<<": ";
        // nodeAtLevel(root, i);
        //  }
     return 0;
}