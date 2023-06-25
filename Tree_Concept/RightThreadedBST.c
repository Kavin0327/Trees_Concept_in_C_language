 #include<stdio.h>
 #include<stdlib.h>

struct Tree{
int data;
struct Tree* left,*right;
int leftflag,rightflag;
} *root=NULL;

/*struct Tree * CreateNode(int val){
tree=(struct Tree*)malloc(sizeof(struct Tree));
tree->data=val;
tree->left=NULL;
tree->right=NULL;
tree->leftflag=1;
tree->rightflag=1;
return tree;
}*/

struct Tree* insert(struct Tree* root,int val){
struct Tree* temp,* newnode;
newnode=(struct Tree *)malloc(sizeof(struct Tree));
newnode->data=val;
newnode->leftflag=1;
newnode->rightflag=1;
newnode->left=newnode->right=NULL;
if(root==NULL){
/*root=(struct Tree*)malloc(sizeof(struct Tree));
root->data=val;
root->left=NULL;
root->right=NULL;
root->leftflag=1;
root->rightflag=1;*/
root=newnode;
return root;
}
else{
    temp=root;
    while(temp!=NULL){
      if(val < temp->data){
        if(temp->leftflag==0)
            {
            temp=temp->left;
        }
        else{
           /* newnode=(struct Tree *)malloc(sizeof(struct Tree));
            newnode->data=val;
            newnode->leftflag=1;
            newnode->rightflag=1;
            newnode->left=NULL;*/
            newnode->right=temp;
            temp->left=newnode;
            temp->leftflag=0;
            return root;
        }
      }
      else if(val >temp->data){
        if(temp->rightflag==0){
            temp=temp->right;
        }
        else{
          /*  newnode=(struct Tree*)malloc(sizeof(struct Tree));
            newnode->data=val;
            newnode->leftflag=1;
            newnode->rightflag=1;
            newnode->left=NULL;*/
            newnode->right=temp->right;
            temp->right=newnode;
            temp->rightflag=0;
            return root;
        }
      }
      else{
        printf("Already exist this %d element in tree",val);
      }
    }//while
 }//else
}//function

void inOrderSuccessor(struct Tree* root){
struct Tree *temp=root;
while(temp->leftflag==0){
    temp=temp->left;
}
while(temp!=NULL){
    printf("%d ",temp->data);
    if(temp->rightflag==0){
      temp=temp->right;
      while(temp->leftflag==0){
        temp=temp->left;
      }
    }
    else{
        temp=temp->right;
    }
}
printf("\n");
}

int main(){
int arr[]={6,1,3,8,7,11,9,13,5};
for(int i=0;i<=8;i++){
    root=insert(root,arr[i]);
}
printf("InOrderSuccessor: ");
inOrderSuccessor(root);
return 0;
}



