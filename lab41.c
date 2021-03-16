#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct node
{
    struct node *previous;
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node* create_ll(struct node *start);
struct node* display(struct node *start);
struct node* insert_beginning(struct node *start);
struct node* insert_end(struct node *start);
struct node* insert_before(struct node *start);
struct node* delete_beginning(struct node *start);
struct node* delete_end(struct node *start);
struct node* delete_given(struct node *start);
struct node* free_nodes(struct node *start);

int main(void)
{
    int option;
    do
    {
        system("cls");
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Delete a node from the beginning");
        printf("\n 7: Delete a node from the end");
        printf("\n 8: Delete a given node");
        printf("\n 9: EXIT");

        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch(option){
            case 1:
                start = create_ll(start);
                printf("\n LINKED LIST CREATED\n Enter any key to continue.");
                getch();
                break;
            case 2:
                start = display(start);
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 3:
                start = insert_beginning(start);
                printf("\n Node inserted at the beginning!\n Enter any key to continue.");
                getch();
                break;
            case 4:
                start = insert_end(start);
                printf("\n Node inserted at the end!\n Enter any key to continue.");
                getch();
                break;
            case 5:
                start = insert_before(start);
                printf("\n Node inserted before given node!\n Enter any key to continue.");
                getch();
                break;
            case 6:
                start = delete_beginning(start);
                printf("\n The beginning node removed!\n Enter any key to continue.");
                getch();
                break;
            case 7:
                start = delete_end(start);
                printf("\n The end node removed!\n Enter any key to continue.");
                getch();
                break;
            case 8:
                start = delete_given(start);
                printf("\n The given node removed!\n Enter any key to continue.");
                getch();
                break;
            case 9:
                free_nodes(start);
                printf("\n Command complete successfully!");
                getch();
                break;
            default:
                printf("\n Enter the right option! (1 - 9)\n Enter any key to continue.");
                getch();
        }
    }while(option != 9);
    return 0;
}

struct node* create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);

    while (num != -1){
        new_node = (struct node*) malloc(sizeof(struct node));
        new_node -> data = num;

        if (start == NULL){
            new_node -> next = NULL;
            start = new_node;
            new_node -> previous = NULL;
        }
        else{
            ptr = start;
            while (ptr -> next != NULL){
                ptr = ptr -> next;
            }

            ptr -> next = new_node;
            new_node -> previous = ptr;
            new_node -> next = NULL;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }

    return start;
}

struct node* display(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;

    printf("\n Existing Linked list:");
    while (ptr != NULL){
        printf("\t %d", ptr -> data);
        preptr = ptr;
        ptr = ptr -> next;
    }
    printf("\n Existing Linked list:");
    while (preptr != NULL){
        printf("\t %d", preptr -> data);
        preptr = preptr -> previous;
    }

    return start;
}

struct node* insert_beginning(struct node *start)
{
    struct node *ptr, *new_node;
    int val;

    printf("\n Enter the data of the new node to be inserted: ");
    scanf("%d", &val);

    new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data = val;
    ptr = start;
    new_node -> next = ptr;
    ptr -> previous = new_node;
    start = new_node;
    new_node -> previous = NULL;

    return start;
}

struct node* insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int val;

    printf("\n Enter the data of the new node to be inserted: ");
    scanf("%d", &val);

    new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data = val;

    ptr = start;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    ptr -> next = new_node;
    new_node -> next = NULL;
    new_node -> previous = ptr;

    return start;
}

struct node* insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data of the given node: ");
    scanf("%d", &num);

    printf("\n Enter the data of the new node to be inserted: ");
    scanf("%d", &val);

    new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data = val;

    ptr = start;
    while(ptr -> data != num){
        preptr = ptr;
        ptr = ptr -> next;
    }

    preptr -> next = new_node;
    new_node -> previous = preptr;
    new_node -> next = ptr;
    ptr -> previous = new_node;

    return start;
}

struct node* delete_beginning(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = ptr -> next;
    (ptr -> next) -> previous = NULL;
    free(ptr);

    return start;
}

struct node* delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr -> next != NULL){
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = NULL;
    free(ptr);

    return start;
}

struct node* delete_given(struct node *start)
{
    struct node *ptr;
    int num;
    printf("\n Enter the data of the given node: ");
    scanf("%d", &num);

    ptr = start;
    while(ptr -> data != num){
        ptr = ptr -> next;
    }
    (ptr -> previous) -> next = ptr -> next;
    (ptr -> next) -> previous = ptr -> previous;
    free(ptr);

    return start;
}

struct node* free_nodes(struct node *start)
{
    struct node *ptr, *dnode;
    ptr = start;
    while(ptr != NULL){
        dnode = ptr;
        ptr = ptr -> next;
        free(dnode);
    }
    return ptr;
}
