// singly circular linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* head = NULL;

node* create_node(int data);
void add_first(int data);
void display();
void add_last(int data);

int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    display();
    add_last(40);
    add_last(50);
    add_last(60);
    display();
    return 0;
}

node* create_node(int data)
{
    node* ptr = (node*) malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("Memory not created !");
    else
    {
        ptr->data = data;
        ptr->next = NULL;
    }
    return ptr;
}

void add_first(int data)
{
    node *new_node = create_node(data);
    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        node* trav = head;

        while(trav->next != head)
        {
            trav = trav->next;
        }
        new_node->next = head;
        head = new_node;
        trav->next = head;
    }
}

void display()
{
    if(head == NULL)
        printf("List is empty !");
    else
    {
        node *trav = head;
        printf("Head");
        do
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }while(trav!=head);
        printf("\n");
    }
}

void add_last(int data)
{
    node* new_node = create_node(data);
    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        node* trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
        trav->next = new_node;
        new_node->next = head;
    }
}