#include <stdio.h>

typedef struct{
    int pno, brust, wait;
}process;

int main(void){
    //normal variable
    int size = 0;
    float average, totalw = 0;
    printf("\n Enter amount of process: ");
    scanf("%d", &size);

    //array variable
    process arr[size];

    //take burst time of all process
    for(int i = 0; i < size; i++){
        arr[i].pno = i+1;
        arr[i].wait = 0;
        printf("\n Enter burst time of process \'%d\': ", i+1);
        scanf("%d", &arr[i].brust);
    }
    //using selection sort
    for (int i = 0; i < size; i++){
        //take one number from array i'th index element
        int temp = arr[i].brust, t = size;
        //apply selection sort on this number
        for (int j = (i+1); j < size; j++){
            //find index of smaller number element
            if (temp > arr[j].brust){
                t = j;
                temp = arr[j].brust;
            }
        }
        //swap small number with taken number
        if(arr[i].brust > arr[t].brust){
            process tprocess;
            tprocess = arr[i];
            arr[i] = arr[t];
            arr[t] = tprocess;
        }
    }
    //print all process waiting time
    printf("\n Waiting time per process:");
    for(int i = 0; i < size; i++){
        printf("\n Process \'%d\' = %d", arr[i].pno, arr[i].wait);
        arr[i+1].wait = arr[i].wait + arr[i].brust;
        totalw += arr[i].wait;
    }
    //average waiting time
    average = totalw / size;
    printf("\n Average waiting time = %0.2f\n", average);

    return 0;
}
