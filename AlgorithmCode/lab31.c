#include <stdio.h>

void merge(int arr[], int l, int m, int h)
{
    int arr1[m],arr2[m];
    int n1,n2,i,j,k;
    n1 = m - l + 1;
    n2 = h - m;
    for(i = 0; i < n1; i++) {
        arr1[i] = arr[l+i];
    }
    for(j = 0; j < n2; j++) {
        arr2[j] = arr[m+j+1];
    }
    i=0;
    j=0;
    for(k = l; k <= h; k++){
        if(arr1[i] <= arr2[j]) {
            arr[k] = arr1[i++];
        }
        else {
            arr[k] = arr2[j++];
        }
    }
}
void merge_sort(int arr[], int low, int high)
{
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(void)
{
    int asize, i;
    printf(" Number of elements: ");
    scanf("%d", &asize);
    int elements[asize];
    printf(" Enter the numbers: ");
    for (i = 0; i < asize; i++) {
        scanf("%d", &elements[i]);
    }

    merge_sort(&elements[0], 0, asize - 1);
    printf(" After using merge sort: ");
    for (i = 0; i < asize; i++){
        printf("%d\t", elements[i]);
    }

    return 0;
}
