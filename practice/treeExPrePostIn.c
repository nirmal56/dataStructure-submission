#include<stdio.h>
#include<stdlib.h>
struct node {
   char data; 
	
   struct node *lptr;
   struct node *rptr;
};

struct node *preTree(struct node *t){
	if(t == NULL){
		printf("empty");
	}
	
	printf("%c\t",t->data);
	
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
	
	printf("%c\t",t->data);
		
}
struct node *inTree(struct node *t){
char temp='\0';
	if(t == NULL){
		printf("empty");
	}
	
	if(t->lptr != NULL){
		inTree(t->lptr);
	}
	
	printf("%c\t",t->data);
		
	if(t->rptr != NULL){
		inTree(t->rptr);
	}
}
void main(){
	struct node *a = (struct node*)malloc(sizeof(struct node));
	struct node *b = (struct node*)malloc(sizeof(struct node));
	struct node *c = (struct node*)malloc(sizeof(struct node));
	struct node *d = (struct node*)malloc(sizeof(struct node));
	struct node *e = (struct node*)malloc(sizeof(struct node));
	struct node *f = (struct node*)malloc(sizeof(struct node));
	struct node *g = (struct node*)malloc(sizeof(struct node));
	struct node *h = (struct node*)malloc(sizeof(struct node));
	struct node *i = (struct node*)malloc(sizeof(struct node));

	a->data= 'A';
	b->data= 'B';
	c->data= 'C';
	d->data= 'D';
	e->data= 'E';
	f->data= 'F';
	g->data= 'G';
	h->data= 'H';
	i->data= 'I';
	
	a->lptr = b;
	a->rptr = d;
	
	b->lptr = c;
	b->rptr = NULL;
	
	c->lptr = NULL;
	c->rptr = NULL;
	
	d->lptr = e;
	d->rptr = g;
	
	e->rptr = f;
	e->lptr = NULL;
	
	f->lptr = NULL;
	f->rptr = NULL;
	
	g->rptr = NULL;
	g->lptr = NULL;

	printf("preOrder= ");preTree(a);
	printf("\n");
	printf("postOrder= ");postTree(a);
	printf("\n");
	printf("inOrder= ");inTree(a);
	printf("\n");
	
}
