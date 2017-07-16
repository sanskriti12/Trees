//binary tree implementation...

# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
 
 struct node* newnode(int item)
 {
 	struct node* temp=(struct node*)malloc(sizeof(struct node));
 	temp->data=item;
 	temp->left=temp->right=NULL;
 	return temp;
 }
 
 void inorder(struct node* root)
 {
 	if(root!=NULL)
 	{
 		inorder(root->left);
 		printf("%d",root->data);
 		inorder(root->right);
 		
	 }
 }
 
 struct node* insert(struct node* node,int data)
 {
 	if(node==NULL)
 	{
 		return newnode(data);
	 }
	 else if (data<node->data)
	 node->left=insert(node->left,data);
	 else if(data>node->data)
	 node->right=insert(node->right,data);
	 return node;
	 
 }
  
  struct node*search(struct node* root,int data)
  {
  	if(root==NULL||root->data==data)
  	return root;
  	if(root->data<data)
  	return search(root->right,data);
  	else
  	return search(root->left,data);
  }
 
   int main()
   {
   	struct node* root=NULL;
   	root=insert(root,50);
   	root=insert(root,30);
   	root=insert(root,20);
   	root=insert(root,70);
   	root=insert(root,60);
   	root=insert(root,80);
   	inorder(root);
}
