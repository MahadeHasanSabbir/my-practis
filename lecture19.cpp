#include <iostream>
using namespace std;
class employee
{
    protected:
        double id;
        string name;
    public:
        void get_info ()
        {
            cout << "Name: ";
            cin >> name;
            cout << "ID: ";
            cin >> id;
        }
        virtual void info()
        {

        }
};
class account: public employee
{
    protected:
        int acno, money;
    public:
        void info ()
        {
            cout << "Account No: ";
            cin >> acno;
            cout << "Money: ";
            cin >> money;
            cout << "\nID: " << id << " Name: " << name << endl;
            cout << "Account no: " << acno << " Money: " << money << endl;

        }
};
int main()
{
    employee *ePtr;
    account acnt;
    ePtr = &acnt;
    ePtr -> get_info();
    static_cast < account* > (ePtr) -> info();
    return 0;
}
