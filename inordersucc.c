# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* Find( struct node* root,int data)
 {
 	if(root==NULL)
 	return NULL;
 	else if(root->data==data) return root;
 	else if(root->data<data)
 	return Find(root->right,data);
 	else
 	return Find(root->left,data);
 }
 
 struct node* Findmin(struct node* root)
 {
 	if(root==NULL)
 	return NULL;
 	while(root->left!=NULL)
 	root=root->left;
 	return root;
 }
struct node* Getsuccessor(struct node* root,int data)
{
	struct node* current=Find(root,data);
	if(current==NULL)
	return NULL;
	if(current->right!=NULL)//node has right subtree
	{
		return Findmin(current->right);
	}
	else//no right subtree
	{
		struct node* successor=NULL;
		struct node* ancestor=root;
		while(ancestor!=current)
		{
			if(current->data<ancestor->data){
				successor=ancestor;
				ancestor=ancestor->left;
			}
			else
			ancestor=ancestor->right;
		}
		return successor;
		
	}
}

void inorder(struct node* node)
 {
 	if(node==NULL)
 	return;
 	inorder(node->left);
 	printf("%d",node->data);
 	inorder(node->right);
 }
 
 
 struct node* newnode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
 
 
 int main()
{
	struct node* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->right=newnode(5);
	printf("inorder traversal of binary tree is");
	inorder(root);
	printf("\n");
	struct node* successor=Getsuccessor(root,1);
	{
	
	if(successor==NULL)
	{
	
	printf("no succ found\n");
    }
	else
	printf("successor is %d ",successor->data);
}
	
}
 

