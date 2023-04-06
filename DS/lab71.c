//implementation queue using Array.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//function prototype
void queue_insert();
void queue_delete();
void queue_display();
//global variable
int font = 0, rear = 0;
int arrqueue[10];
//main function start
int main(void)
{
    printf("\n Welcome to Queue!\n Queue size is \'10\'.\n Enter any key to continue.");
    getch();
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
                printf("\n Command complete successfully.");
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
    if ((rear == 10 && font == 0)||(rear == font && font != 0)){
        printf("\n Overflow happened!");
        return;
    }
    else if (rear == 10 && font != 0){
        rear = 0;
        printf(" Enter value: ");
        scanf("%d", &arrqueue[rear]);
        rear++;
    }
    else {
        printf(" Enter value: ");
        scanf("%d", &arrqueue[rear]);
        rear++;
    }

    return;
}
//user define function to delete data from queue
void queue_delete()
{
    if (rear == 0 && font == 0){
        printf(" Underflow happened!\n Queue is empty.");
    }
    arrqueue[font] = 0;
    if (font == 10){
        font = 0;
    }
    else{
        font++;
    }

    return;
}
//user define function to display data in queue
void queue_display()
{
    if (rear == 0 && font == 0){
        printf(" Underflow happened!\n Queue is empty.");
        return;
    }
    int i = font;
    printf(" Existing Queue is: ");
    for (int j = 0; j < 10; j++){
        printf("\t %d", arrqueue[i]);
        i++;
        if (i == rear){
            break;
        }
        else if (i == 10){
            i = 0;
        }
    }

    return;
}
