#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

void insert_queue();
void delete_queue();
void display();
struct node* free_nodes(struct node *start);

struct node *start = NULL;

int main(void)
{
    int option = 0;

    do {
        system("cls");
        printf("\n *****MAIN MENU*****");
        printf("\n 1: INSERT an element in the queue");
        printf("\n 2: DELETE an element from the queue");
        printf("\n 3: DISPLAY the queue");
        printf("\n 4: EXIT.");
        printf("\n Enter option: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                insert_queue();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 2:
                delete_queue();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 3:
                display();
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 4:
                start = free_nodes(start);
                printf("\n Command complete successfully!");
                free(start);
                getch();
                break;
            default:
                printf("\n Enter right option (1 - 4).\n Enter any key to continue.");
                getch();
        }
    } while (option != 4);

    return 0;
}

void insert_queue()
{
    struct node *new_node, *ptr = NULL, *preptr = NULL;
    new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("\n Overflow happened!");
        return;
    }

    int val, prn;
    printf("\n Enter the value:");
    scanf("%d", &val);
    new_node -> data = val;
    printf("\n Enter its priority:");
    scanf("%d", &prn);
    new_node -> priority = prn;

    if (start == NULL){
        new_node -> next = NULL;
        start = new_node;
    }
    else {
        ptr = start;
        while ((ptr -> next != NULL) && (ptr -> priority <= prn)){
            preptr = ptr;
            ptr = ptr -> next;
        }
        if (ptr == start) {
            if (ptr -> priority > prn) {
                new_node -> next = ptr;
                start = new_node;
            }
            else {
                new_node -> next = ptr -> next;
                ptr -> next = new_node;
            }
        }
        else {
            if (ptr -> priority > prn) {
                new_node -> next = preptr -> next;
                preptr -> next = new_node;
            }
            else {
                new_node -> next = ptr -> next;
                ptr -> next = new_node;
            }
        }
    }

    return;
}

void delete_queue()
{
    if (start == NULL){
        printf("\n Queue is Empty!");
        return;
    }

    struct node *temp;
    temp = start;
    start = start -> next;
    free(temp);

    return;
}

void display()
{
    if (start == NULL){
        printf("\n Queue is Empty!");
        return;
    }

    struct node *ptr;
    printf("\n Existing Queue is: ");
    ptr = start;
    while(ptr != NULL){
        printf("\n Value: %d [priority = %d]", ptr -> data, ptr -> priority);
        ptr = ptr -> next;
    }

    return;
}

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
