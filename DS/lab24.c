#include <stdio.h>

int main(void)
{
    int student, subject;
    printf("Enter the number of student: ");
    scanf("%d", &student);
    printf("Enter the number of subject: ");
    scanf("%d", &subject);
    int number[student][subject];
    for(int i = 0; i < student; i++){
        printf("Enter the marks obtained by student %d\n", i+1);
        for (int j = 0; j < subject; j++){
            printf("marks[%d][%d] = ", i, j);
            scanf("%d", &number[i][j]);
        }
    }
    for (int i = 0; i < subject; i++){
        printf("The highest marks obtained in the subject %d = ", i+1);
        int max = number[0][i];
        for (int j = 1; j < student; j++){
            if(max < number[j][i]){
                max = number[j][i];
            }
        }
        printf("%d \n", max);
    }
    return 0;
}
