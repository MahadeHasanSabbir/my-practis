#include <stdio.h>

typedef struct{
    int pno, burst, arrival, wait, remain, end, priority;
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
        arr[i].end = 0;
        printf("\n Enter burst time of process \'%d\': ", i+1);
        scanf("%d", &arr[i].burst);
        printf(" Enter arrival time of process \'%d\': ", i+1);
        scanf("%d", &arr[i].arrival);
        printf(" Enter priority of process \'%d\': ", i+1);
        scanf("%d", &arr[i].priority);
        arr[i].remain = arr[i].burst;
        totalb += arr[i].burst;
    }
    //calculate end time for all process
    for(int time = 0; time < totalb; time++){
        process temp[size];
        int j = 0;
        for(int i = 0; i < size; i++){
            if((arr[i].arrival <= time) && (arr[i].remain > 0)){
                temp[j] = arr[i];
                j++;
            }
        }
        if(j > 0){
            //find index of smallest priority number process
            int t1 = temp[0].priority, t2 = temp[0].pno - 1;
            for(int i = 1; i < j; i++){
                if (t1 > temp[i].priority){
                    t2 = temp[i].pno - 1;
                    t1 = temp[i].priority;
                }
            }
            //reduce process burst time
            arr[t2].remain--;
            //implement end time
            if(arr[t2].remain == 0){
                arr[t2].end = time + 1;
            }
        }
    }
    //print all process waiting time
    printf("\n Waiting time per process:");
    for(int i = 0; i < size; i++){
        arr[i].wait = (arr[i].end - arr[i].burst) - arr[i].arrival;
        printf("\n Process \'%d\' = %d", arr[i].pno, arr[i].wait);
        totalw += arr[i].wait;
    }
    //average waiting time
    average = totalw / size;
    printf("\n Average waiting time = %0.2f\n", average);

    return 0;
}
