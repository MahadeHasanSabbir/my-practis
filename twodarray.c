#include <stdio.h>
#define row 10
#define col 10
int main (void){
    int r,c;
    int mul[row][col];
    printf("\n  -----------------------------------------\n");
    printf("\t    Multiplication table\n");
    printf("  -----------------------------------------\n   ");
    for (int j = 1; j <= col; j++){
        printf("%4d", j);
    }
    printf("\n  ----------=====================----------\n");
    for (int i = 0; i < row; i++){
        r = i + 1;
        printf("%2d|", r);
        for (int j = 1; j <= col; j++){
            c = j;
            mul[i][j] = r * c;
            printf("%4d", mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}
