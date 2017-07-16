//find max element in a binary tree

# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
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
	node->left=node->right=NULL;
	return(node);
}
  int findMin(struct node* root)
  {
  	if(root==NULL)
  	return -1;
  	struct node* temp=root;
  	while(temp->left!=NULL)
  	{
  		temp=temp->left;
  		
	  }
	  return temp->data;
  }
  
    int main()
    {
    	struct node* newroot=NULL;
    	struct node* root=newnode(2);
    	root->left=newnode(1);
    	root->right=newnode(5);
    	root->left->right=newnode(3);
    	root->left->right->left=newnode(1);
    	root->left->right->right=newnode(7);
    	root->right->right=newnode(9);
    	root->right->right->left=newnode(4);
    	printf("Max element is %d",findMin(root));
    	return 0;
    	
	}

