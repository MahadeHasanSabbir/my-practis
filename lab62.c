//Stack implementation using array
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

void stack_push();
void stack_pop();
void stack_peek();
void stack_display();
struct node* free_nodes(struct node *start);
struct node* start = NULL;

int main (void)
{
    int option;
    do {
        system("cls");
        printf("\n *****MAIN MENU*****");
        printf("\n 1: PUSH");
        printf("\n 2: POP");
        printf("\n 3: Peek");
        printf("\n 4: DISPLAY");
        printf("\n 5: EXIT");
        printf("\n Enter option: ");
        scanf("%d", &option);
        switch (option){
            case 1:
                stack_push();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 2:
                stack_pop();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 3:
                stack_peek();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 4:
                stack_display();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 5:
                start = free_nodes(start);
                printf("\n Command complete successfully!");
                free(start);
                getch();
                break;
            default:
                printf("\n Enter right option! (1-5)");
        }
    }while(option != 5);

    return 0;
}

void stack_push()
{
    struct node *new_node;

    new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("\n Overflow happened!");
        return;
    }

    int a;
    printf("\n Enter data: ");
    scanf("%d", &a);
    new_node -> data = a;
    new_node -> next = start;
    start = new_node;

    return;
}

void stack_pop()
{
    if (start == NULL){
        printf("\n Stack is Empty!");
        return;
    }

    struct node *temp;
    temp = start;
    start = start -> next;
    free(temp);

    return;
}

void stack_peek()
{
    if (start == NULL){
        printf("\n Stack is Empty!");
        return;
    }
    printf("\t %d", start -> data);

    return ;
}

void stack_display()
{
    if (start == NULL){
        printf("\n Stack is Empty!");
        return;
    }

    struct node *ptr;
    printf("\n Existing Stack is: ");
    ptr = start;
    while(ptr != NULL){
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
    }

    return;
}

struct node* free_nodes(struct node *start)
{
    if (start == NULL){
        return start;
    }
    struct node *ptr, *dnode;
    ptr = start;
    while(ptr != NULL){
        dnode = ptr;
        ptr = ptr -> next;
        free(dnode);
    }

    return ptr;
}
