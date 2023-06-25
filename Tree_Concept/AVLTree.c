#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node *right;
struct Node *left;
int height;
}*root=NULL;

struct Node *CreateNode(int val){
struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
nn->data=val;
nn->left=NULL;
nn->right=NULL;
nn->height=1;
return nn;
}

int max(int a,int b){
return (a>b)?a:b;
}

int height(struct Node*root){
if(root==NULL)  return 0;
return root->height;
}

int getBalanced(struct Node* root){
if(root==NULL) return 0;
return height(root->left)-height(root->right);
}

struct Node* rightRotate(struct Node *y){
struct Node* x=y->left;
struct Node* temp=x->right;
x->right=y;
y->left=temp;
x->height=1+max(height(x->left),height(x->right));
y->height=1+max(height(y->left),height(y->right));
return x;
}

struct Node* leftRotate(struct Node *x){
struct Node*y=x->right;
struct Node* temp=y->left;
y->left=x;
x->right=temp;
x->height=1+max(height(x->left),height(x->right));
y->height=1+max(height(y->left),height(y->right));
return y;
}

struct Node* insert(struct Node* root,int val){
    if(root==NULL) return CreateNode(val);
    if(val > root->data){
       root->right=insert(root->right,val);
    }
    else if(val < root-> data){
        root->left=insert(root->left,val);
    }
    else{
        return root;
    }
       root->height=1+max(height(root->left),height(root->right));
       int bal=getBalanced(root);
       if(bal>1 && val < root->left->data){
        return rightRotate(root);
       }
       if(bal<-1 && val > root->right->data){
        return leftRotate(root);
       }
       if(bal>1 && val > root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
       }
       if(bal<-1 && val < root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
       }
       return root;
},

void inorder(struct Node* root){
if(root==NULL) return ;
inorder(root->left);
printf("%d   ",root->data);
inorder(root->right);
}

void main(){
root=insert(root,20);
root=insert(root,30);
root=insert(root,10);
root=insert(root,15);
root=insert(root,9);
root=insert(root,33);
printf("The InOrder Traversal: ");
inorder(root);
}

