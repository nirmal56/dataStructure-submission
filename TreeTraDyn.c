#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* lptr;
    struct node* rptr;
};
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->lptr = NULL;
    node->rptr = NULL;
 
    return (node);
}
 
struct node *preTree(struct node *t){
	if(t == NULL){
		printf("empty");
	}
	
	printf("%d\t",t->data);
	
	if(t->lptr != NULL){
		preTree(t->lptr);
	}
	
	if(t->rptr != NULL){
		preTree(t->rptr);
	}
}
struct node *postTree(struct node *t){
char temp='\0';
	if(t == NULL){
		printf("empty");
	}

	if(t->lptr != NULL){
		postTree(t->lptr);
	}
	
	if(t->rptr != NULL){
		postTree(t->rptr);
	}
	
	printf("%d\t",t->data);
		
}
struct node *inTree(struct node *t){
char temp='\0';
	if(t == NULL){
		printf("empty");
	}
	
	if(t->lptr != NULL){
		inTree(t->lptr);
	}
	
	printf("%d\t",t->data);
		
	if(t->rptr != NULL){
		inTree(t->rptr);
	}
}
/* Driver program to test above functions*/
int main()
{
    struct node* root = newNode(1);
    root->lptr = newNode(2);
    root->rptr = newNode(3);
    root->lptr->lptr = newNode(4);
    root->lptr->rptr = newNode(5);
 
    printf("\nPreorder traversal of binary tree is \n");
    preTree(root);
 
    printf("\nInorder traversal of binary tree is \n");
    inTree(root);
 
    printf("\nPostorder traversal of binary tree is \n");
    postTree(root);
 
    return 0;
}
