#include <stdio.h>

int binarysearch(int num, int *arr, int low, int high)
{
    int mid;
    if (low > high){
        printf(" Element not found in the list!");
        return -1;
    }
    mid = (low + high) / 2;
    if (num == arr[mid]) {
        return (mid);
    }
    else if (num < arr[mid]) {
        binarysearch(num, &arr[0], low, mid - 1);
    }
    else {
        binarysearch(num, &arr[0], mid + 1, high);
    }
}

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
    i = binarysearch(element, &elements[0], 0, asize - 1);
    if (i > -1){
        printf(" The element is present at index %d", i);
    }
    return 0;
}
