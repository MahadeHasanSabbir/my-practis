#include <iostream>
using namespace std;
int findmax(int *a);
int main()
{
    int num[3];
    cout << "Enter three number:" << endl;
    for (int i = 0; i < 3; i++){
        cin >> num[i];
    }
    findmax(num);
    return 0;
}
int findmax(int *a)
{
    int temp = *a;
    for (int i = 0; i < 3; i++){
        if (temp < *(a + i)){
            temp = *(a + i);
        }
    }
    cout << "Max is: " << temp;
    return 0;
}
