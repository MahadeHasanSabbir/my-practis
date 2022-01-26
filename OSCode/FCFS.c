#include <stdio.h>

int main(void){
    //normal variable
    int size = 0;
    float average, total = 0;
    printf("\n Enter amount of process: ");
    scanf("%d", &size);

    //array variable
    int burst[size], wait[size];

    //take burst size of all process
    for (int i = 0; i < size; i++){
        wait[i] = 0;
        printf(" Enter burst time of process \'%d\': ", i+1);
        scanf("%d", &burst[i]);
    }
    //print all process waiting time
    printf("\n Waiting time per process:");
    for (int i = 0; i < size; i++){
        total += wait[i];
        printf("\n Process \'%d\' = %d", i+1, wait[i]);
        wait[i+1] = wait[i] + burst[i];
    }
    //average waiting time
    average = total / size;
    printf("\n Average waiting time = %0.2f\n", average);

    return 0;
}
