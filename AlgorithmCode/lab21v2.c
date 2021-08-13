#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;

};

struct node* start = NULL;
struct node* create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter \'0\' when complete.\n");
    printf("\n Enter the data: ");
    scanf("%d", &num);

    while (num != 0){
        new_node = (struct node*) malloc(sizeof(struct node));
        if (new_node == NULL){
            printf("\n Overflow happened!");
            return start;
        }
        new_node -> data = num;

        if (start == NULL){
            new_node -> next = NULL;
            start = new_node;
        }
        else{
            ptr = start;
            while (ptr -> next != NULL){
                ptr = ptr -> next;
            }
            ptr -> next = new_node;
            new_node -> next = NULL;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }

    return start;
}

int linearsearch(struct node *start, int check)
{
    struct node *ptr = start;
    int index = 0;
    while (ptr != NULL){
        if (ptr -> data == check){
            return index;
        }
        ptr = ptr -> next;
        index++;
    }

    return -1;
}

struct node* display(struct node *start)
{
    struct node *ptr = start;

    printf("\n Existing list:");
    while (ptr != NULL){
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
    }

    return start;
}

int main(void)
{
    start = create_ll(start);
    display(start);
    int element;
    printf("\n Enter the element to search in the list: ");
    scanf("%d", &element);
    //apply linear search
    int i = linearsearch(start, element);
    if (i > -1){
        printf("\n The element is present at index %d", i);
    }
    else{
        printf("\n Element not found in the list!");
    }
    return 0;
}
