#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#include <time.h>
#include <conio.h>

#define size 12

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *T[size];

void insert_key(int key)
{
    srand(time(0));
    int range = 0;
    do {
        int num = rand() % 500;
        struct node *newNode = (struct node*) malloc(sizeof(struct node));
        newNode -> data = num;
        newNode -> next = NULL;
        newNode -> prev = NULL;

        int pos = num % size;

        if (T[pos] == NULL) {
            T[pos] = newNode;
        }
        else {
            newNode -> next = T[pos];
            T[pos] -> prev = newNode;
            T[pos] = newNode;
        }
        range++;
    } while (range < key);

    return ;
}

void print_table()
{
    int i;
    struct node *temp;

    for (i = 0; i < size; i++) {
        temp = T[i];
        printf(" T[%2d] --> ", i);
        while(temp != NULL) {
            printf("%d --> ", temp->data);
            temp = temp -> next;
        }
        printf("NULL \n");
    }

    return ;
}

int search_key (int key)
{
    struct node *temp;
    int i = key % size;

    temp = T[i];
    while (temp != NULL) {
        if (temp -> data == key) {
            return i;
        }
        temp = temp -> next;
    }

    return 0;
}

void delete_key(int key)
{
    int pos = search_key(key);
    if(pos == 0) {
        printf("\n Key not found in hash table. unable to delete!");

        return ;
    }
    struct node *temp;
    int i = key % size;
    temp = T[i];
    while (temp != NULL){
        if (temp -> data == key){
            if (temp -> prev == NULL)
                T[i] = temp -> next;
            if (temp -> prev != NULL)
                (temp -> prev) -> next = temp -> next;
            if (temp -> next == NULL){
                free(temp);
                printf("\n key deleted from hash table!");

                return ;
            }
            (temp -> next) -> prev = temp -> prev;
            free(temp);
            printf("\n key deleted from hash table!");

            return ;
        }
        temp = temp -> next;
    }

    return ;
}

int main(void)
{
    for (int i = 0; i < size; i++)
        T[i] = NULL;

    int choice, k;
    while(1) {
        system("cls");
        printf("\n  ***** MENU *****\n");
        printf(" 1.Insert a number\n");
        printf(" 2.Delete a number\n");
        printf(" 3.Search a number\n");
        printf(" 4.Show Hash Table\n");
        printf(" 0.Exit Program\n");

        printf("\n Choose an option: ");
        scanf("%d",&choice);

        switch(choice) {
        case 0:
            printf("\n Exit successful.");
            exit(0);
            break;

        case 1:
            // insert random numbers
            printf("\n Enter the number of key's to be inserted: ");
            scanf("%d", &k);
            insert_key(k);
            printf("\n Key's inserted.\n Enter any key to continue.");
            getch();
            break;

        case 2:
            // delete a number
            printf("\n Enter key to delete: ");
            scanf("%d", &k);
            delete_key(k);
            printf("\n Enter any key to continue.");
            getch();
            break;

        case 3:
            // search for a number
            printf("\n Enter key to search in hash table: ");
            scanf("%d", &k);
            int pos = search_key(k);
            if(pos != 0)
                printf("\n Key found in hash table.");
            else
                printf("\n Key not found in hash table.");
            printf("\n Enter any key to continue.");
            getch();
            break;

        case 4:
            //print hashtable
            printf("\n --- HASH TABLE --- \n");
            print_table();
            printf("\n Enter any key to continue.");
            getch();
            break;
        default:
            printf("\n Enter option (0-4)!\n Enter any key to continue.");
            getch();
            break;
        }
    }

    return 0;
}
