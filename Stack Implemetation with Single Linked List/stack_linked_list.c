#include <stdio.h> 
#include <stdlib.h>

struct stack 
{ 
    int grade; 
    struct stack *next; 
};
 
void construct(struct stack **); 
int isEmpty(struct stack *); 
void push(struct stack **, int x); 
int pop(struct stack **); 
int top(struct stack *); 
void Insert_Sort(struct stack **, int x); 
void sort_Stack(struct stack **); 
void show(struct stack *); 
void st_delete(struct stack **);

void construct(struct stack **head) 
{ 
    *head = NULL; 
} 
  
int isEmpty(struct stack *head) 
{ 
    if (head == NULL) 
        return 1; 
    return 0; 
} 
  
//insert element in stack
void push(struct stack **head, int vath) 
{ 
    struct stack *p = (struct stack *)malloc(sizeof(*p)); 
  
    if (p == NULL) 
    { 
        fprintf(stderr, "No available memory\n"); 
        return; 
    }  
    p->grade = vath; 
    p->next = *head; 
    *head = p; 
} 

//delete element from stack  
int pop(struct stack **head) 
{ 
    int x; 
    struct stack *temp; 
  
    x = (*head)->grade; 
    temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
  
    return x; 
} 
  
//return the top element of the stack
int top(struct stack *head) 
{ 
    return (head->grade); 
} 
  
//recursive implementation of insertionSort
void Insert_Sort(struct stack **head, int vath) 
{ 

    if (*head == NULL || (*head)->grade <= vath) 
    { 
       push(head,vath);
    } 
    else
    { 
       struct stack *tmp = (*head)->next;
       Insert_Sort(&tmp,vath);

    } 
} 
  
void sort_Stack(struct stack **head) 
{ 
	if (*head!=NULL)
	{
		int x = pop(head);
		struct stack *tmp = (*head)->next;
		push(head,x);
		Insert_Sort(&tmp,x);
	}

} 

//print the elements of the stack  
void show(struct stack *head) 
{ 
	if (head==NULL)
		return;
	printf("%d\n",head->grade);
	show(head->next);
} 

//delete all elements
void st_delete(struct stack **head)
{
    struct stack *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

//demo of using the stack
int main() 
{ 
    struct stack *top;
	int vathmologia,answer; 
    construct(&top);
	printf("\n"); 
	printf("Insertion of grades in a stack using a single linked list\n");
	printf("***********************************************************\n");
    printf("\n"); 
    int choice;
    while(1){
    	printf("Enter grade:");
    	scanf("%d",&vathmologia);
    	while (vathmologia<1 || vathmologia>10)
    	{
    		printf("Wrong data. Please enter grade [1,10]:");
    		scanf("%d",&vathmologia);
		}
        printf("\n");
        push(&top,vathmologia);
        printf("Is there any other student:(1 for yes and 0 for no):");
        scanf("%d",&choice);
    	while (choice<0 || choice>1)
    	{
        	printf("Wrong choice, 1 or 0 please:");
    		scanf("%d",&choice);
		}
		if (choice==0)
			break;
	}
	printf("Elements before sorting:\n")
	show(top);
	sort_Stack(&top);
	printf("Elements after sorting:\n")
	show(top);
    st_delete(&top);
    system("pause");
    return 0; 
} 


