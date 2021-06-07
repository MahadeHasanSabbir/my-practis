#include <stdio.h>
int main(void)
{
    int asize, i, element;
    printf(" Number of elements: ");
    scanf("%d", &asize);
    int elements[asize];
    printf(" Enter the numbers: ");
    for (i = 0; i < asize; i++){
        scanf("%d", &elements[i]);
    }
    printf(" Enter the element to search in the array: ");
    scanf("%d", &element);
    //apply linear search
    for (i = 0; i < asize; i++){
        if (elements[i] == element){
            break;
        }
    }
    if (i > -1){
        printf("\n The element is present at index %d", i);
    }
    else{
        printf("\n Element not found in the list!");
    }
    return 0;
}
