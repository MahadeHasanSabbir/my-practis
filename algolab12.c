#include<stdio.h>

int main(void)
{
    int total;
    printf(" Number of elements: ");
    scanf("%d", &total);
    int number[total];
    printf(" Enter the elements: ");
    for (int i = 0; i < total; i++){
        scanf("%d", &number[i]);
    }
    //using insertion sort
    for (int i = 0; i < total; i++){
        //take one number from array i'th index element
        int temp = number[i];
        //apply insertion sort on this number
        for (int j = i; j > 0; j--){
            //swap small element to place it at the first
            if (temp < number[j-1]){
                int t = temp;
                number[j] = number[j-1];
                number[j-1] = temp;
            }
        }
    }
    //print sorted array
    printf(" After using insertion sort: ");
    for (int i = 0; i < total; i++){
        printf("%d ", number[i]);
    }
    return 0;
}
