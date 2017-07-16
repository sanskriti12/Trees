//delete a node in a bst.

# include<stdio.h>
# include<stdlib.h>
struct node
{
	int key;
	struct node* left;
	struct node* right;
};
struct node* newnode(int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->key);
		inorder(root->right);
	}
}
struct node* insert(struct node* node,int key)
{
	if(node==NULL)
	return newnode(key);
	if(key<node->key)
	node->left=insert(node->left,key);
	else
	node->right=insert(node->right,key);
	return node;
}
struct node* minvalue(struct node*node)
{
	struct node* current=node;
	while(current->left!=NULL)
	current=current->left;
	return current;
}

struct node* deleteNode(struct node* root,int key)
{
	if(root==NULL)
	return root;
	if(key<root->key)
	root->left=deleteNode(root->left,key);
	else if(key>root->key)
	root->right=deleteNode(root->right,key);
	else
	{
		if(root->left==NULL)
		{
			struct node* temp=root->right;
			free(temp);
			return(temp);
		}
		else if(root->right==NULL)
		{
			struct node* temp=root->left;
			free(root);
			return temp;
		}
	
	struct node* temp=minvalue(root->right);
	root->key=temp->key;
	root->right=deleteNode(root->right,temp->key);
}
return root;
}
int main()
{
struct node* root=NULL;
   	root=insert(root,50);
   	root=insert(root,30);
   	root=insert(root,20);
   	root=insert(root,40);
   	root=insert(root,70);
   	root=insert(root,60);
   	printf("inorder traversal of tree is");
   	inorder(root);
   	printf("\ndelete\n");
   	root=deleteNode(root,20);
   	
   	printf("inorder traversal of tree is");
   	inorder(root);
   	
}
