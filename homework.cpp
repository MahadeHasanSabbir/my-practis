#include <iostream>
using namespace std;
int main()
{
    //take input for row and column to create array
    int row, col;
    cout << "Enter the number of Row and Column:" << endl;
    cin >> row >> col;
    int arrayd2[row][col], rowsum[row] , colsum[col];

    //take the value of two dimensional array
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "value for row" << i+1 << " and column" << j+1 << ": ";
            cin >> arrayd2[i][j];
        }
    }

    //print the entire array
    cout << "Array is = {";
    for(int i = 0; i < row; i++){
        cout << " {";
        for(int j = 0; j < col; j++){
            cout << arrayd2[i][j];
            //separate row and column
            if((j+1) == col){ cout << "}";}
            else{cout << ", ";}
        }
        if((i+1) == row){ cout << " ";}
        else{cout << ", ";}
    }
    cout <<"}" << endl;

    //make sum for row and column
    for(int i = 0; i < row; i++){
        rowsum[i] = 0;
        for(int j = 0; j < col; j++){ rowsum[i] += arrayd2[i][j];}
    }
    for(int j = 0; j < col; j++){
        colsum[j] = 0;
        for(int i = 0; i < row; i++){ colsum[j] += arrayd2[i][j];}
    }

    //print the sum of row
    for(int i = 0; i < row; i++){
        cout << "Sum of Row" << i+1 <<": " << rowsum[i] << endl;
    }

    //print the sum of column
    for(int j = 0; j < col; j++){
        cout << "Sum of Column" << j+1 << ": " << colsum[j] << endl;
    }

    return 0;
}
