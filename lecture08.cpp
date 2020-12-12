#include <iostream>
using namespace std;
class basic
{
    protected:
        int id, bsalary;
    public:
        void get_input()
        {
            cout << "Employee ID: ";
            cin >> id;
            cout << "Basic Salary = ";
            cin >> bsalary;
        }
};
class regular:public basic
{
    public:
        void gross_salary()
        {
            double gross;
            gross = bsalary + (bsalary * 0.5) + 2000 + 3000;
            cout << "ID " << id << " gross salary : " << gross << endl;
        }
};
class parttime:public base
{
    public:
        void gross_salary()
        {
            double gross;
            gross = bsalary + (bsalary * 0.25) + 1000 + 1500;
            cout << "ID " << id << " gross salary : " << gross << endl;
        }
};
int main()
{
    regular e1;
    parttime e2;
    e1.get_input();
    e2.get_input();
    e1.gross_salary();
    e2.gross_salary();
    return 0;
}
