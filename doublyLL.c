#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *lptr;  
    struct node *rptr;  
    int data;  
};  
struct node *head;  
void insBeg();  
void insLast();  
void insSpec();  
void delBeg();  
void delLast();  
void delSpec();  
void display();  
void search();  
void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {   
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete after  given data\n7.display\n8.Exit\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
                insBeg();  
                break;  
            case 2:  
                insLast();  
                break;  
            case 3:  
                insSpec();  
                break;  
            case 4:  
                delBeg();  
                break;  
            case 5:  
                delLast();  
                break;  
            case 6:  
                delSpec();  
                break;  
            case 7:  
                display();  
                break;  
            case 8:   
                exit(0);  
                break;     
        }  
    }  
}  
void insBeg()  
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       ptr->rptr = NULL;  
       ptr->lptr = NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->lptr=NULL;  
       ptr->rptr = head;  
       head->lptr=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
void insLast()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->rptr = NULL;  
           ptr->lptr = NULL;   
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->rptr!=NULL)  
          {  
              temp = temp->rptr;  
          }  
          temp->rptr = ptr;  
          ptr ->lptr=temp;  
          ptr->rptr = NULL;  
          }  
             
       }  
     printf("\nnode inserted\n");  
    }  
void insSpec()  
{  
   struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the location");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->rptr;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", loc);  
               return;  
           }  
       }  
       printf("Enter value");  
       scanf("%d",&item);  
       ptr->data = item;  
       ptr->rptr = temp->rptr;  
       ptr -> lptr = temp;  
       temp->rptr = ptr;  
       temp->rptr->lptr=ptr;  
       printf("\nnode inserted\n");  
   }  
}  
void delBeg()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->rptr == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> rptr;  
        head -> lptr = NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
  
}  
void delLast()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->rptr == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->rptr != NULL)  
        {  
            ptr = ptr -> rptr;   
        }  
        ptr -> lptr -> rptr = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  
void delSpec()  
{  
    struct node *ptr, *temp;  
    int val;  
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> rptr;  
    if(ptr -> rptr == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(ptr -> rptr -> rptr == NULL)  
    {  
        ptr ->rptr = NULL;  
    }  
    else  
    {   
        temp = ptr -> rptr;  
        ptr -> rptr = temp -> rptr;  
        temp -> rptr -> lptr = ptr;  
        free(temp);  
        printf("\nnode deleted\n");  
    }     
}  
void display()  
{  
    struct node *ptr;  
    printf("\n printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->rptr;  
    }  
}   
