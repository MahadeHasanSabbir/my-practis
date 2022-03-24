#include <stdio.h>

typedef struct{
    int pno, burst, priority, wait;
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
        do{
            printf("\n Enter burst time of process \'%d\': ", i+1);
            scanf("%d", &arr[i].burst);
        }while(arr[i].burst < 0);
        do{
            printf(" Enter priority of process \'%d\': ", i+1);
            scanf("%d", &arr[i].priority);
        }while(arr[i].priority < 0);

    }
    //using selection sort
    for (int i = 0; i < size; i++){
        //take one number from i'th index process
        int temp = arr[i].priority, t = size;
        //apply selection sort on this number
        for (int j = (i+1); j < size; j++){
            //find index of smaller priority process
            if (temp > arr[j].priority){
                t = j;
                temp = arr[j].priority;
            }
        }
        //swap smaller priority process with taken priority process
        if(arr[i].priority > arr[t].priority){
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
        arr[i+1].wait = arr[i].wait + arr[i].burst;
        totalw += arr[i].wait;
    }
    //average waiting time
    average = totalw / size;
    printf("\n\n Average waiting time = %0.2f unit time\n\n", average);

    return 0;
}
