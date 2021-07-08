#include <stdio.h>

int partition(int array[], int p, int r)
{
    int var = array[r];
    int i = p - 1;
    for (int j = p; j <= (r - 1); j++) {
        if (array[j] <= var) {
            int temp = array[++i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[++i];
    array[i] = array[r];
    array[r] = temp;

    return i;
}

void quicksort(int Arr[], int point, int range)
{
    if (point < range) {
        int q = partition(Arr, point, range);
        quicksort(Arr, point, q - 1);
        quicksort(Arr, q + 1, range);
    }

    return;
}

int main(void)
{
    int asize;
    printf(" Enter array size: ");
    scanf("%d", &asize);
    int elements[asize];
    printf(" Enter elements: ");
    for (int i = 0; i < asize; i++) {
        scanf("%d", &elements[i]);
    }
    quicksort(elements, 0, asize - 1);
    printf("\n After quick sort:");
    for (int i = 0; i < asize; i++) {
        printf("\t%d", elements[i]);
    }

    return 0;
}
