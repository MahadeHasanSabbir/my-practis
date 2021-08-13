//implement heap-sort in descending order
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//function for make heap
void min_heapify(int A[], int i, int n)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if ((l < n) && (A[l] < A[smallest]))
        smallest = l;
    if ((r < n) && (A[r] < A[smallest]))
        smallest = r;

    if (smallest != i){
        int temp = A[smallest];
        A[smallest] = A[i];
        A[i] = temp;
        min_heapify(A, smallest, n);
    }

    return ;
}
//heap-sort function
void heapsort(int Array[], int n)
{
    //build min heap
    for(int i = n/2 - 1; i >= 0; i--)
        min_heapify(Array, i, n);
    //heapify array
    for (int i = n - 1; i >= 0; i--){
        int temp = Array[0];
        Array[0] = Array[i];
        Array[i] = temp;
        min_heapify(Array, 0, i);
    }

    return ;
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
    for (i = 0; i < asize; i++) {
        elements[i] = (rand() % 500);
        printf("\t%d", elements[i]);
    }
    //Applying Heap sort
    heapsort(elements, asize);
    //display elements
    printf("\n After Heap sort: ");
    for (i = 0; i < asize; i++)
        printf("\t%d", elements[i]);

    getch();
    return 0;
}
