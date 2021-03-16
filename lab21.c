#include <stdio.h>

int main(void)
{
    printf("Enter the elements of the matrix\n");
    int numarray[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf("%d", &numarray[i][j]);
        }
    }

    printf("\nThe elements of the matrix are\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", numarray[i][j]);
        }
        printf("\n");
    }

    printf("\nthe elements of the transposed matrix are\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", numarray[j][i]);
        }
        printf("\n");
    }

    return 0;
}
