#include <stdio.h>

int main(void)
{
    int range;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d", &range);
    for (int i = 0; i < range; i++){
        printf("\n");
        for (int j = 0; j < i; j++){
            printf("-1");
            printf("\t");
        }
        printf ("0");
        printf ("\t");
        for (int j = i; j < range -1; j++){
            printf("1");
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}
