#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *rptr;
	struct node *lptr;
};

struct node *douIns(struct node *l,struct node *r,struct node *m,int x){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	
	new->data = x;

	//insert in empty node
	if(r == NULL){
		new->lptr = NULL;
		new->rptr = NULL;
		l=r=new;
		return new;
	}

	//insert leftmost node
	if(m == l){
		new->lptr = NULL;
		new->rptr = m;
		m->lptr = new;
		l=new;
		return new;
	}

	//if inserttion in middle
	new->lptr = m->lptr;
	new->rptr = m;
	m->lptr = new;
	new->lptr->rptr = new;
	return new;
}

void display(struct node *l){
	struct node *save;
	save=l;
	while(save != NULL){
		printf("%d,",save->data);
		save=save->rptr;
	}
}

int main(){
	struct node *lp = NULL;   
	struct node *rp = NULL;
	struct node *mp = NULL;

	struct node *new = (struct node *)malloc(sizeof(struct node));

	new = douIns( lp, rp, mp, 1);
	new = douIns( lp, rp, new, 2);
	new = douIns( lp, rp, new, 0);
	display(new);


}
