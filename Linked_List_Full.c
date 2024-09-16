#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node*next;
};
struct Node *start = NULL;

void create(int item){
	struct Node *p,*s;
	p = (struct Node*)malloc(sizeof(struct Node));
	p -> data = item;
	p -> next = NULL;
	if(start == NULL)
		start = p;
	else{
		s = start;
		while(s -> next != NULL)
			s = s -> next;
		s -> next = p;
	}
}

void insert_at_first(int item){
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p -> data = item;
	p -> next = NULL;
	p -> next = start;
	start = p;
	
}

void insert_after_a_given_value(int item,int x){
	struct Node *p,*s;
	p = (struct Node*)malloc(sizeof(struct Node));
	p -> data = item;
	p -> next = NULL;
	s = start;
	while(s -> data != x)
		s = s -> next;
	p -> next = s -> next;
	s -> next = p;
}

void insert_before_a_given_value(int item,int x){
	struct Node *p,*s,*q;
	p = (struct Node*)malloc(sizeof(struct Node));
	p -> data = item;
	p -> next = NULL;
	s = start;
	while(s -> data != x){
		q = s;
		s = s -> next;
	}
	q -> next = p;
	p -> next = s;
}

int search(int item){
	struct Node*temp,*s;
	int i=0;
	temp=start;
	while(temp->next!=NULL)
	{
		if(temp->data==item)
		{
			return i;
		}
		temp=temp->next;
		i++;
	}
	return -1;
	
}	
	

void display(){
	struct Node*p;
	p = start;
	printf("Elements are: \n");
	while(p != NULL){
		printf("%d ",p -> data);
		p = p -> next;
	}
	
}



int delete_first_node()
{
	int item;
	struct Node *s;
	s=start;
	start=s->next;
	item=s->data;
	free(s);
	return item;
}
int delete_last_node()
{
	int item;
	struct Node *temp;
	struct Node *s;
	s=start;
	while(s->next!=NULL)
	{
		temp =s;
		s=s->next;
	}
	item=s->data;
	temp->next=NULL;
	free(s);
	return item;
}




int main()
{
	int choice,item,x,n,val,v;
	printf("Enter how many nodes to enter : ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	  printf("Enter value : ");
	  scanf("%d",&val);
	  create(val);
	 }
	
	while(1){
		printf("\n1.Insert at first\n2.Insert after a given value\n3.Insert before a given value\n4.Delete first node\n5.Delete last value\n6.Search\n7.Display\n8.exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1 :printf("Enter item:");
					scanf("%d",&item); 
			        insert_at_first(item);
					break;
			case 2 :
					printf("Enter item:");
					scanf("%d",&item); 
					printf("Enter after which value:");
					scanf("%d",&x); 
					insert_after_a_given_value(item,x);
					break;
			case 3 :
					printf("Enter item:");
					scanf("%d",&item); 
					printf("Enter before which value:");
					scanf("%d",&x); 
					insert_before_a_given_value(item,x);
					break;
			case 4 : delete_first_node();
					 break;
			case 5 : delete_last_node();
					 break;
			
			case 6:
					printf("Enter item to search : ");
					scanf("%d",&v);
					printf("Item found at index : %d",search(v)+1);
					
					break;
			case 7 :display();
					break;
					
			case 8 : exit(1);
			default: printf("Wrong choice !! Try Again.");
				
		}
	}
	return 0;
}