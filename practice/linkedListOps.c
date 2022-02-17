#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node *link;
};

void display(struct Node *n){
	struct Node *save;
	save=n;
	do{
		printf("%d,",save->info);
		save=save->link;
	}
	while(save != NULL);
}

struct Node* insAtBeg(int x, struct Node *first){  //insert at begining of linked list
	struct Node *new;
	new=(struct Node*)malloc(sizeof(struct Node));
	if(new == NULL){
		printf("overfowed\n");
		return first;
	}
	else{
		new->info=x;
		new->link=first;	
		return new;
	}
}

struct Node* insAtEnd(int x, struct Node *first){  //insert at ending of linked list
	struct Node *new;
	new=(struct Node*)malloc(sizeof(struct Node));
	struct Node *save;

	new->info=x;
	new->link=NULL;	
	
	save= first;
	if(save->link == NULL){
		printf("empty\n");
		return new;
	}
	while(save->link != NULL){
		save=save->link;
	}
	save->link=new;
	return first;
}

struct Node* insOrd(int x, struct Node *first){    //inserts in ordered linked list in ordered manner
	struct Node *new;
	new=(struct Node*)malloc(sizeof(struct Node));
	struct Node *save;
	
	save= first;
	
	if(save == NULL){
		printf("empty\n");
		return new;
	}
	
	new->info=x;
	
	if(new->info <= first->info){
		new->link=first;
		return new;
	}
	
	while(save->link != NULL && new->info >= save->link->info){
		save=save->link;
	}
	
	new->link =save->link;
	save->link=new;
	return first;
}

int countNodes(struct Node* first){
	struct Node* save;
	int cnt=0;
	if(first == NULL){
		cnt =0;
		return cnt;
	}
	
	save=first;
	while(save->link != NULL){
		save=save->link;
		cnt+=1;
	}
	
	return cnt+1;
}

struct Node* copy(struct Node *first){    
	struct Node *new;
	new=(struct Node*)malloc(sizeof(struct Node));
	struct Node *begin;
	struct Node *pred;
	struct Node *save;
	
	if(first == NULL){
		printf("empty\n");
		return NULL;
	}
	if(new == NULL){
		printf("underflowed");
	}
	
	new->info=first->info;
	begin=new;
	
	save= first;
		
	pred=new;
	save=save->link;
	
	while(save!= NULL){
		new=(struct Node*)malloc(sizeof(struct Node));
		if(new == NULL){
		printf("underflowed");
		return NULL;
		}
		
		new->info=save->info;
		pred->link=new;
		
		pred=new;
		save=save->link;
	}
	return begin;
	
}
struct Node* delete(struct Node* x, struct Node *first){
	
	if(first == NULL){
		printf("Underflowed");
		return 0;
	}
	
	struct Node *pred;
	pred=(struct Node*)malloc(sizeof(struct Node));
	struct Node *save;
	
	save= first;
	
	while(save != x && save->link != NULL){
		pred=save;
		save=save->link;
	}
	if(save != x){
		printf("Element not found");
		return 0;
	}
	
	if(x == first){
		first=first->link;
		return first;
	}
	else{
		pred->link=x->link;
		return first;
	}free(x);
}

void main(){
	int data1=1;
	struct Node *first,*second,*third,*fourth;
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	
	first->info=2;
	first->link=second;
	
	second->info=3;
	second->link=third;

	third->info=4;
	third->link=NULL;
	
	first=insAtBeg(1,first);
	first=insAtEnd(6,first);
	first=insOrd(5,first);
	display(first);
	
	printf("\ntotal nodes:%d\n",countNodes(first));
	fourth=copy(first);
	printf("\n");
	display(fourth);
		
	first=delete(second,first);//delete is not working.
	
	printf("\n");
	display(first);
	
	printf("\ntotal nodes:%d\n",countNodes(first));

}
