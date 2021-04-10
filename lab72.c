//implementation queue using linked list.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//create structure node for linked list
struct node
{
    int data;
    struct node *next;
};
//function prototype
void queue_insert();
void queue_delete();
void queue_display();
struct node* free_nodes(struct node * start);
//global variable
struct node *start = NULL, *last = NULL;
//main function start
int main(void)
{
    int option = 0;
    do {
        system("cls");
        printf("\n *****MAIN MENU*****");
        printf("\n 1: INSERT an element.");
        printf("\n 2: DELETE an element.");
        printf("\n 3: DISPLAY the Queue.");
        printf("\n 4: EXIT.");
        printf("\n insert option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                queue_insert();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 2:
                queue_delete();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 3:
                queue_display();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 4:
                start = free_nodes(start);
                printf("\n Command complete successfully.");
                free(start);
                getch();
                break;
            default:
                printf("\n Enter right option (1 - 4).\n Enter any key to continue.");
                getch();
        }
    } while (option != 4);

    return 0;
}//main function end
//user define function to insert data in queue
void queue_insert()
{
    struct node *new_node, *ptr;
    new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("\n Overflow happened! unable to insert data.");
        return;
    }
    int value;
    printf(" Enter data: ");
    scanf("%d", &value);
    new_node -> data = value;
    if (start == NULL){
        new_node -> next = start;
        start = new_node;
        last = start;
    }
    else {
        new_node -> next = last -> next;
        last -> next = new_node;
        last = new_node;
    }
    printf("\n Insert successfully.");

    return;
}
//user define function to delete data from queue
void queue_delete()
{
    if (start == NULL){
        printf(" Queue is empty!");
        return;
    }
    struct node *temp = start;
    start = start -> next;
    free(temp);
    printf("\n Delete successfully.");

    return;
}
//user define function to display data in queue
void queue_display()
{
    if (start == NULL){
        printf(" Queue is empty!");
        return;
    }
    struct node *ptr;
    ptr = start;
    printf(" Existing Queue is: ");
    while (ptr != NULL){
        printf("\t%d", ptr -> data);
        ptr = ptr -> next;
    }

    return;
}
//user define function to free allocated memory
struct node* free_nodes(struct node *start)
{
    if (start == NULL){
        return start;
    }
    struct node *dnode;
    while(start != NULL){
        dnode = start;
        start = start -> next;
        free(dnode);
    }

    return start;
}
