# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newnode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
int maxDepth(struct node* node)
{
	if(node==NULL)
	return 0;
	else{
		int ldepth=maxDepth(node->left);
		int rdepth=maxDepth(node->right);
		if(ldepth>rdepth)
		return(ldepth+1);
		else
		return(rdepth+1);
	}
}

int main()
{
	struct node* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->right=newnode(5);
	printf("height of tree is %d",maxDepth(root));
	return 0;
}
