#include <stdio.h>

typedef struct{
    int pno, burst, wait, remain, end;
}process;

int main(void){
    //normal variable
    int size = 0, totalb = 0, robin;
    float average, totalw = 0;
    printf("\n Enter amount of process: ");
    scanf("%d", &size);
    printf("\n Enter time quantum: ");
    scanf("%d", &robin);

    //array variable
    process arr[size];

    //take burst time and arrival time of all process
    for(int i = 0; i < size; i++){
        arr[i].pno = i+1;
        arr[i].wait = 0;
        arr[i].end = 0;
        printf("\n Enter burst time of process \'%d\': ", i+1);
        scanf("%d", &arr[i].burst);
        arr[i].remain = arr[i].burst;
        totalb += arr[i].burst;
    }
    //calculate end time for all process
    int time = 0;
    while(time < totalb){
        for(int j = 0; j < size; j++){
            //reduce burst time and implement end time
            if (arr[j].remain > robin){
                arr[j].remain -= robin;
                time += robin;
            }
            else if (arr[j].remain > 0){
                int temp = robin - arr[j].remain;
                arr[j].end = time + (robin - temp);
                time -= temp;
                arr[j].remain = 0;
                time += robin;
            }
        }
    }
    //print all process waiting time
    printf("\n Waiting time per process:");
    for(int i = 0; i < size; i++){
        arr[i].wait = arr[i].end - arr[i].burst;
        printf("\n Process \'%d\' = %d", arr[i].pno, arr[i].wait);
        totalw += arr[i].wait;
    }
    //average waiting time
    average = totalw / size;
    printf("\n Average waiting time = %0.2f unit time\n", average);

    return 0;
}
