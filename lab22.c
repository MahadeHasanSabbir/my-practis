#include <stdio.h>

int main(void)
{
    int rows[2], columns[2];
    printf("Enter the number of the rows in the first matrix: ");
    scanf("%d", &rows[0]);
    printf("Enter the number of the columns in the first matrix: ");
    scanf("%d", &columns[0]);
    printf("Enter the number of the rows in the second matrix: ");
    scanf("%d", &rows[1]);
    printf("Enter the number of the columns in the second matrix: ");
    scanf("%d", &columns[1]);
    if (rows[1] != columns[0]){
        printf("multiplication is impossible!!\n");
        return 1;
    }
    int arr1[rows[0]][columns[0]], arr2[rows[1]][columns[1]], arr[rows[0]][columns[1]];
    printf("Enter the elements of the first matrix\n");
    for (int i = 0; i < rows[0]; i++){
        for (int j = 0; j < columns[0]; j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix\n");
    for (int i = 0; i < rows[1]; i++){
        for (int j = 0; j < columns[1]; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("The elements of the product matrix are\n");
    int sum;
    for (int i = 0; i < rows[0]; i++){
        for (int j = 0; j < columns[1]; j++){
            sum = 0;
            for (int k = 0; k < rows[1]; k++){
                sum += (arr1[i][k] * arr2[k][j]);
            }
            arr[i][j] = sum;
        }
    }
    for (int i = 0; i < rows[0]; i++){
        for (int j = 0; j < columns[1]; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
