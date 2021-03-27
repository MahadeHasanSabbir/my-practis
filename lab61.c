//Stack implementation using array
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void stack_push(int *arr);
void stack_pop(int *arr);
void stack_peek(int *arr);
void stack_display( int *arr);

int top = 0, ssize;

int main (void)
{
    int option;
    printf("\n Welcome to stack.\n Enter Stack size to continue: ");
    scanf("%d", &ssize);
    int stackdata[ssize];

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
                stack_push(stackdata);
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 2:
                stack_pop(stackdata);
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 3:
                stack_peek(stackdata);
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 4:
                stack_display(stackdata);
                printf("\n Enter any key to continue.");
                getch();
                break;
            case 5:
                printf("\n Command complete successfully!");
                getch();
                break;
            default:
                printf("\n Enter right option! (1-5)");
        }
    }while(option != 5);

    return 0;
}

void stack_push(int *arr)
{
    if (top == ssize){
        printf("\n Overflow happened! unable to insert data.");
        return;
    }
    int a;
    printf("\n Enter data: ");
    scanf("%d", &a);
    arr[top] = a;
    top++;
}

void stack_pop(int *arr)
{
    if (top == 0){
        printf("\n Stack is Empty!");
        return;
    }
    top--;
    arr[top] = 0;
}

void stack_peek(int *arr)
{
    if (top == 0){
        printf("\n Stack is Empty!");
        return;
    }
    printf("\t %d", arr[top - 1]);
    return ;
}

void stack_display(int *arr)
{
    if (top == 0){
        printf("\n Stack is Empty!");
        return;
    }
    printf("\n Existing Stack is: ");
    int a = top;
    while(a > 0){
        printf("\t %d", arr[a - 1]);
        a--;
    }
}
