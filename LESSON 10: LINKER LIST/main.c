
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node;


node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
// Duyet cac node trong danh sach lien ket
void duyet(node *head){
	while (head != NULL)
	{
		printf("%d ",head->value);
		head = head->next;
	}
}
// Dem cac node trong danh sach lien ket
int count(node *head)
{
    int dem = 0;
	while(head != NULL)
	{
		dem++;
		head = head->next;
	}
	printf("\n so phan tu trong danh sach %d", dem);
	return dem;
}
void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}



void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}



int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}
// Them node vao phia truoc
void push_front(node **array, int value)
{
	 node* temp;
    temp = createNode(value); 
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else
    {
    	temp->next = *array;
    	*array = temp;
	}
    
}
//Xoa phan tu dau danh sach lien ket
void pop_front(node **head)
{
	if(*head == NULL) return;
	node *temp = *head;
	*head = (*head)->next;
	free(temp);
}

bool empty(node **array)
{
	if( (*array) == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
    node* arr = NULL;
    push_back(&arr, 2);


   // empty(&arr);
    printf("Value test: %d\n", empty(&arr));
	return 0;
}



```
