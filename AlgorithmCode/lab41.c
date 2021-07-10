#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Marge function
void merge(int array[], int l, int m, int h)
{
    int n1,n2,i,j,k = l;
    n1 = m - l + 1;
    n2 = h - m;
    int arr1[n1],arr2[n2];
    //create two sub array
    for(i = 0; i < n1; i++) {
        arr1[i] = array[l+i];
    }
    for(j = 0; j < n2; j++) {
        arr2[j] = array[m+j+1];
    }
    //merge sub array
    i = 0;
    j = 0;
    while(k <= h){
        if (i < n1){
            if (j >= n2) {
                array[k++] = arr1[i++];
            }
            else if(arr1[i] >= arr2[j]){
                array[k++] = arr1[i++];
            }
            else {
                array[k++] = arr2[j++];
            }
        }
        else {
            array[k++] = arr2[j++];
        }
    }

    return;
}
//Marge sort function
void merge_sort(int Array[], int low, int high)
{
    if(low < high) {
        int mid = (low + high) / 2;
        merge_sort(Array, low, mid);
        merge_sort(Array, mid + 1, high);
        merge(Array, low, mid, high);
    }

    return;
}
//main function
int main(void)
{
    int asize, i;
    printf("\n Number of elements: ");
    scanf("%d", &asize);
    int elements[asize];
    srand(time(0));
    
    //take random numbers as elements
    printf("\n The random numbers:");
    for (i = 0; i < asize; i++) {
        elements[i] = (rand() % 500);
        printf("\t%d", elements[i]);
    }
    //Applying Merge sort
    merge_sort(elements, 0, asize - 1);
    //display elements
    printf("\n After Merge sort: ");
    for (i = 0; i < asize; i++){
        printf("\t%d", elements[i]);
    }

    return 0;
}
