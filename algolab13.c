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
    //using selection sort
    for (int i = 0; i < total; i++){
        //take one number from array i'th index element
        int temp = number[i], t;
        //apply selection sort on this number
        for (int j = (i+1); j < total; j++){
            //find index of smaller number element
            if (temp > number[j]){
                t = j;
                temp = number[j];
            }
        }
        //swap small number with taken number
        if(number[i] > number[t]){
            temp = number[i];
            number[i] = number[t];
            number[t] = temp;
        }
    }
    //print sorted array
    printf(" After using selection sort: ");
    for (int i = 0; i < total; i++){
        printf("%d ", number[i]);
    }
    return 0;
}
