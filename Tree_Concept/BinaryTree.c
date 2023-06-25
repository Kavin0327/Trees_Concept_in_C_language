#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* left;
struct Node *right;
}*root=NULL;
struct Node* CreateNode(int data){
struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
nn->data=data;
nn->left=NULL;
nn->right=NULL;
return nn;
}

struct Node* insert(struct Node* root,int val){
if(root==NULL) return CreateNode(val);
if(root->data > val){
    root->left=insert(root->left,val);
}
else if(root->data < val)
  root->right=insert(root->right,val);
return root;
}
void inorder(struct Node *root){
if(root==NULL){
    return;
}
inorder(root->left);
printf("%d  ",root->data);
inorder(root->right);
}
int height(struct Node *root){
if(root==NULL) return 0;
int lh=height(root->left);
int rh=height(root->right);
if(lh>rh){
    return lh+1;
}else{
return rh+1;
 }
}
void printGivenOrder(struct Node* root,int level){
if(root==NULL) return ;
if(level==1) printf("%d ",root->data);
else if(level>1){
  printGivenOrder(root->left,level-1);
  printGivenOrder(root->right,level-1);
}
}

void level(struct Node*root){
if(root==NULL) return ;
int h=height(root);
for(int i=1;i<=h;i++){
    printGivenOrder(root,i);
}
}

int main(){
    printf("\n1.)Insert \n2.)Inorder\n3.)height\n4.)LevelOrder \n14.)Exit");
    while(1){
    printf("\nEnter the Choice:");
    int n;
    scanf("%d",&n);
    switch(n){
case 1:
    printf("Enter the data:");
    int val;
    scanf("%d",&val);
    root=insert(root,val);
    break;
case 2:
    printf("Inorder Traversal: ");
    inorder(root);
    break;
case 3:
    printf("The height of the Tree: %d",height(root));
    break;
case 4:
    printf("The Level Order Traversal:");
    level(root);
    break;
case 14:
   printf("Terminate the Program....%c",3);
   return;
    }
}
return 0;
}
