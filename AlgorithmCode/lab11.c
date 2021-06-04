#include<stdio.h>

int main(void)
{
    int total;
    printf(" Number of elements: ");
    scanf("%d", &total);
    int number[total];
    printf(" Enter the numbers: ");
    for (int i = 0; i < total; i++){
        scanf("%d", &number[i]);
    }
    //using bubble sort algorithm
    printf(" After using bubble sort: ");
    for (int i = 0; i < (total - 1); i++){
        for (int j = 0; j < (total - i - 1); j++){
            if (number[j] > number[j+1]){
                int temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < total; i++){
        printf("%d ", number[i]);
    }

    return 0;
}
