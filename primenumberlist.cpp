#include <iostream>
#include <cmath>

using namespace std;

bool findPrime(int n, int c) {

    if (n == 2) {
        return true;
    }
    if (n < 2){
        return false;
    }
    int cn = sqrt(n);
    for (int i = 2; i <= cn; i++) {
        if ((n % i) == 0) {
            return false;
        }
    }
    if (c > 0){
        cout << ", ";
    }
    return true;
}

int main(void)
{
    cout << " Find prime numbers between two digit" << endl;
    int startn = 0, endn = 0, i = 0, j = 0;
    cout << " Enter the start number : ";
    cin >> startn;
    if (startn < 0){
        cout << "\n Bad input! lower bound is smaller than zero." << endl;
        cout << " Enter any key to exit.";
        getch();
        return 1;
    }
    cout << " Enter the end number : ";
    cin >> endn;
    if (startn > endn){
        cout << "\n Bad input! Upper bound is smaller than lower bound." << endl;
        cout << " Enter any key to exit.";
        getch();
        return 1;
    }
    cout << " The prime numbers between "<< startn << " and " << endn << " are: ";
    for (i = startn; i <= endn; i++) {
        if (findPrime(i, j)) {
            cout << i;
            j++;
        }
    }
    cout << endl;
    cout << " Total prime number " << j << endl;
    return 0;
}
