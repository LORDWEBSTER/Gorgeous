/**
 * C program to search the particular node(element) from the Singly Linked List
 */


#include <stdio.h>
#include <stdlib.h>


/* Structure of a node */
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;


void createList(int n);
int countNodes();
void displayList();
void searchelement(int m);


int main()
{
    int n,m, total;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /* Count number of nodes in list */
    total = countNodes();

    printf("\nTotal number of nodes = %d\n", total);

    printf("\n Search particular element from the list: ");
    scanf("%d",&m);

    searchelement(m);

    return 0;
}


/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Read data of node from the user
         */
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link data field with data
        head->next = NULL; // Link address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/*
 * Counts total number of nodes in the list
 */
int countNodes()
{
    int count = 0;
    struct node *temp;

    temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

//Search the particular element in the linked list

void  searchelement(int m)
{
    struct node *temp;
int position;
    temp = head;

    while(temp!= NULL)
    {
        if(temp->data==m)
        {
            position=temp;
            printf("\nElement found whose address is %d", position);
            exit(0);
        }
         else
         {
        temp = temp->next;
    }
    }
    position =  0;
        if(position ==0)
        printf("\n Element not found in the list");

}
/*
 * Displays the entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\t", temp->data); // Print data of current node
            printf("address =%d\n", temp->next);
            temp = temp->next;                 // Move to next node
        }
    }
}
