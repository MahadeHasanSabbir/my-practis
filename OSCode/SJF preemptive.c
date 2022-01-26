#include <stdio.h>

typedef struct{
    int pno, brust, arrival, wait, remain, end;
}process;

int main(void){
    //normal variable
    int size = 0, totalb = 0;
    float average, totalw = 0;
    printf("\n Enter amount of process: ");
    scanf("%d", &size);

    //array variable
    process arr[size];

    //take burst time and arrival time of all process
    for(int i = 0; i < size; i++){
        arr[i].pno = i+1;
        arr[i].wait = 0;
        printf("\n Enter burst time of process \'%d\': ", i+1);
        scanf("%d", &arr[i].brust);
        printf(" Enter arrival time of process \'%d\': ", i+1);
        scanf("%d", &arr[i].arrival);
        arr[i].remain = arr[i].brust;
        totalb += arr[i].brust;
    }
    //using selection sort
    for (int i = 0; i < size; i++){
        //take one number from array i'th index element
        int temp = arr[i].arrival, t = size;
        //apply selection sort on this number
        for (int j = (i+1); j < size; j++){
            //find index of smaller number element
            if (temp > arr[j].arrival){
                t = j;
                temp = arr[j].arrival;
            }
        }
        //swap small number with taken number
        if(arr[i].arrival > arr[t].arrival){
            process tprocess;
            tprocess = arr[i];
            arr[i] = arr[t];
            arr[t] = tprocess;
        }
    }
    //calculate waiting time for all process
    for(int time = 0; time < totalb; time++){
        process temp[size];
        int j = 0;
        for(int i = 0; i < size; i++){
            if((arr[i].arrival <= time) && (arr[i].remain > 0)){
                temp[j] = arr[i];
                j++;
            }
        }
        //find index of smallest burst time process
        int t1 = temp[j - 1].remain, t2 = j - 1;
        for(int i = (j - 1); i >= 0; i--){
            if (t1 > temp[i].remain){
                t2 = temp[i].pno - 1;
                t1 = temp[i].remain;
            }
        }
        arr[t2].remain--;
        if(arr[t2].remain == 0){
            arr[t2].end = time + 1;
        }
    }
    //print all process waiting time
    printf("\n Waiting time per process:");
    for(int i = 0; i < size; i++){
        arr[i].wait = (arr[i].end - arr[i].brust) - arr[i].arrival;
        printf("\n Process \'%d\' = %d", arr[i].pno, arr[i].wait);
        totalw += arr[i].wait;
    }
    //average waiting time
    average = totalw / size;
    printf("\n Average waiting time = %0.2f\n", average);

    return 0;
}
