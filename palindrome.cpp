#include <iostream>
using namespace std;
bool ispalindrom(int x){
    int num = 0, numarray[10];
    do{
        numarray[num] = x%10;
        x = x / 10;
        num++;
    }while(x > 0);
    for(int i = 0; i < (num - 1); i++){
        if(numarray[i] != numarray[num - i - 1]){
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    if(ispalindrom(n)){
        cout << n << "true";
    }
    else{
        cout << n << "false";
    }
    return 0;
}
