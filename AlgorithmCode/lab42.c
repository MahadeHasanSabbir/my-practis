#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Partition for quick sort function
int partition(int array[], int p, int r)
{
    int lastnum = array[r];
    int i = p - 1;
    for (int j = p; j <= (r - 1); j++) {
        if (array[j] >= lastnum) {
            //swap element in descending order
            int temp = array[++i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    //swap last element to proper place
    int temp = array[++i];
    array[i] = array[r];
    array[r] = temp;

    return i;
}
//Quick sort function
void quicksort(int Array[], int point, int range)
{
    if (point < range) {
        int partitionindex = partition(Array, point, range);
        quicksort(Array, point, partitionindex - 1);
        quicksort(Array, partitionindex + 1, range);
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
    printf("\n The random numbers:");
    //take random numbers as elements
    for (int i = 0; i < asize; i++) {
        elements[i] = (rand() % 500);
        printf("\t%d", elements[i]);
    }
    //Applying Quick sort on elements
    quicksort(elements, 0, asize - 1);
    //display elements
    printf("\n After Quick sort:  ");
    for (int i = 0; i < asize; i++) {
        printf("\t%d", elements[i]);
    }

    return 0;
}
