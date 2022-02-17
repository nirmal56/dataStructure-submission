#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
 
struct Node *addToEmpty(struct Node *last, int data)// This function is only for empty list
{
    if (last != NULL)
      return last;
 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
 
    temp -> data = data;
    last = temp;
 
    last -> next = last;
 
    return last;
}
 
struct Node *addBegin(struct Node *last, int data)//insert first
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
 
    return last;
}
 
struct Node *addEnd(struct Node *last, int data)//insert last
{
    if (last == NULL)
        return addToEmpty(last, data);
     
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
 
    return last;
}

struct Node* insord(int ele,struct Node* first,struct Node* last){
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	struct Node* save;
	first= first->next;
	new->data = ele;
	if(first == NULL){
		new->next = new;
		first=last=new;
		return last;
	}
	//if new node precedes all other nodes in list
	if(new->data <= first->data){
		new->next = first;
		last->next = new;
		first = new;
		return last;
	}
	//searching predecessor of new node
	save = first;
	while(save != last && new->data >= save->next->data){
		save= save->next;
	}
	new->next = save->next;
	save->next = new;
	if(save == last){
		last = new;
	}
	return last;
}

void traverse(struct Node *last)//display linked list
{
    struct Node *p;
 
    if (last == NULL)
    {
        printf( "List is empty." );
        return;
    }
 
    p = last -> next;
 
    do
    {
        printf("%d " , p -> data );
        p = p -> next;
 
    }
    while(p != last->next);
 
}
struct Node* deleteNode(struct Node* last, int key)
{
	struct Node * curr = last->next, *prev;
    prev = last;
    if(last == last->next){
        return NULL;
    }
    while(curr!=last){
        if(curr->data == key){
            prev-> next = curr->next;
            free(curr);
            return last;
        }
        prev = curr;
        curr = curr->next;
    }

    if(curr->data == key){
        prev-> next = curr->next;
        free(curr);
        return prev;
    }
    printf("Not Found \n");
    return last;
    
}
 
int main()
{
    struct Node *last = NULL;
	struct Node *first = (struct Node*)malloc(sizeof(struct Node));

 
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);	
    
    traverse(last);
    printf("\n");
    
    last = deleteNode(last, 6);
    traverse(last);
    printf("\n");
    
    first=last;
    last= insord(6,first,last);
    last= insord(7,first,last);
    traverse(last);
    printf("\n");
 
    return 0;
}
