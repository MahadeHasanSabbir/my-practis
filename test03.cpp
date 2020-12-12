#include <iostream>
#include <stdlib.h>
using namespace std;

class book
{
    protected:
        int book_id, prize;
        string name, author;
    public:
        book()
        {
            system("cls");
            cout << "Book Name  : ";
            cin >> name;
            cout << "Book Author: ";
            cin >> author;
            cout << "Book ID    : ";
            cin >> book_id;
            cout << "Prize      : ";
            cin >> prize;
        }
        void bookdiscription()
        {
            system("cls");
            cout << "\tDescription of your book." << endl;
            cout << " Book Name   : " << name << endl;
            cout << " Book Author : " << author << endl;
            cout << " Book ID     : " << book_id << endl;
            cout << " Book Prize  : " << prize << endl;
        }
        virtual void billprocess() = 0;
};
class customer: public book
{
    protected:
        int cust_id;
        string cust_name, mobile;
    public:
        customer()
        {
            system("cls");
            cout << "Customer Name: ";
            cin >> cust_name;
            cout << "Customer ID  : ";
            cin >> cust_id;
            cout << "Mobile No    : ";
            cin >> mobile;
        }
        void customerdiscription()
        {
            cout << " Customer name = " << cust_name << endl;
            cout << " Customer ID = " << cust_id << endl;
            cout << " Mobile no = " << mobile << endl;
        }
};
class bill: public customer
{
    protected:
        int quantity, total_prize;
    public:
        void billprocess ()
        {
            bookdiscription();
            cout << "\n\tInvoice" << endl;
            cout << "\n Quantity of book: ";
            cin >> quantity;
            total_prize = prize * quantity;
            cout << " Total Prize is \'" << total_prize << "\'" << endl;
            customerdiscription();
        }
};
int main()
{
    book *pointer;
    bill b1;
    pointer = &b1;
    pointer -> billprocess();

    return 0;
}
