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
 	node->left=node->right=NULL;
 	return(node);
 }
 void postorder(struct node* node)
 {
 	if(node==NULL)
 	return;
 	postorder(node->left);
 	postorder(node->right);
 	printf("%d",node->data);
 	
 }
 void inorder(struct node* node)
 {
 	if(node==NULL)
 	return;
 	inorder(node->left);
 	printf("%d",node->data);
 	inorder(node->right);
 }
 void preorder(struct node* node)
 {
 	if(node==NULL)
 	return;
 	printf("%d",node->data);
 	preorder(node->left);
 	preorder(node->right);
 }
 int main()
 {
 	 struct node* root=newnode(2);
    	root->left=newnode(1);
    	root->right=newnode(5);
    	root->left->right=newnode(3);
    	root->left->right->left=newnode(1);
    	root->left->right->right=newnode(7);
    	root->right->right=newnode(9);
    	root->right->right->left=newnode(4);
    	printf("postorder traversal is");
    	postorder(root);
    	printf("inorder taversal is");
    	inorder(root);
    	printf("preorder traversal is");
    	preorder(root);
    }
