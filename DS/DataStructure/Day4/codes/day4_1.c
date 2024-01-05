#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create_node(int data);
void add_first(int data);
void display();
void add_at_last(int data);
void add_at_pos(int data,int pos);
void delete_first();
void delete_last();
void delete_at_pos(int pos);

int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    //display();
    add_at_last(40);
    add_at_last(50);
    add_at_last(60);
   // display();
    add_at_pos(70,10);
    display();
   delete_first();
    display();
    delete_last();
    display();
    delete_at_pos(3);
    display();
    return 0;
}

struct node* create_node(int data) // 10
{
    struct node *ptr =(struct node*) malloc(sizeof(struct node));

    if(ptr == NULL)
        printf("Memory not created !");
    else
    {
        ptr->data = data; // 10
        ptr->next = NULL;
    }
    return ptr;
}


void add_first(int data) // 10
{
     struct node *new_node =create_node(data); // 10
     // new_node = 500

     if(head== NULL)
     {
        head = new_node; // head = 500
     }
     else
     {
        new_node->next = head; // 500->next = 100
        head = new_node;
     }
}

void display()
{

    if(head == NULL)
        printf("List is empty !");
    else
    {
         struct node *temp = head;
        printf("Head");
         while(temp!=NULL)
         {
            printf("->%d",temp->data);
            temp = temp->next;
         }
         printf("\n");
    }
}

void add_at_last(int data)
{
 struct node *new_node = create_node(data);

    if(head == NULL)
        head = new_node;
    else
    {   
        struct node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void add_at_pos(int data,int pos)
{
    struct node *new_node =create_node(data);
    
    if(head == NULL || pos <= 1)
    {
        add_first(data);
    }
    else
    {
        struct node *temp = head;

        for(int i = 1;i<pos-1 ;i++) // <9
        {
            if(temp->next == NULL)// if pos is more than actual nodes
                break;
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_first()
{
    if(head == NULL)
        printf("List is empty !");
    else if( head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        temp=NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is empty !");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;
        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}

void delete_at_pos(int pos)
{
    if(head == NULL)
        printf("List is empty !");
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else if (pos == 1)
    {
        delete_first();
    }
    else 
    {
        struct node *trav = head;
        for(int i = 1;i<pos-1;i++)
        {
            if(trav->next == NULL)
            {
                delete_last();
            }
            else
                trav = trav->next;
        }   
        struct node *temp = trav->next;
        trav->next = temp->next;
        free(temp);
        temp=NULL;
    }
}