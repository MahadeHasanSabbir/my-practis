//practice different types of inheritance
#include <iostream>
#include <stdlib.h>
using namespace std;

//create a class parson to create a person object
class person
{
    public:
        int age;
        long mobile;
        string name, gender;
        //constructor for class person to take personal information
        person()
        {
            cout << "\nName: ";
            cin >> name;
            cout << "Age: ";
            cin >> age;
            cout << "Gender: ";
            cin >> gender;
            cout << "Mobile name: ";
            cin >> mobile;
        }
};

//create a class bank account by inheritance of the class person
class bank_account: public person
{
    protected:
        string account_type;
        int account_no, money;
    public:
        //constructor for class bank account to take bank information.
        bank_account()
        {
            cout << "Account type: ";
            cin >> account_type;
            cout << "Account No: ";
            cin >> account_no;
            cout << "Amount of money: ";
            cin >> money;
        }
};

//create a class employee by multiple inheritance of class bank account
class employee:public bank_account
{
    protected:
        double gross_salary;
    public:
        int id, salary;
        string designation, password;
        //constructor for class employee to take employee information
        employee()
        {
            cout << "Employee ID: ";
            cin >> id;
            cout << "Designation: ";
            cin >> designation;
            cout << "Basic salary: ";
            cin >> salary;
            gross_salary = salary + (salary * 0.65);
            cout << "Password: ";
            cin >> password;
        }
        friend void about(employee em);
};

//function for check information
void about(employee em)
{
    int employee_id;
    string access, employee_password;
    system("cls");//use for clear the screen
    cout << "\tAbout Employee" << endl;
    cout << "Employee: " << em.name << "\t\t ID: " << em.id << endl;
    cout << "\nDesignation: " << em.designation << endl;
    cout << "\nGender: " << em.gender << "\t\t Age: " << em.age << "\t Mobile No: " << em.mobile << endl;
    cout << "\nDo you want to see bank information? (Yes/No): ";
    cin >> access;

    //check access for privacy
    if(access == "yes" || access == "Yes"){
        cout << "\nFill out this options.\nEmployee ID: ";
        cin >> employee_id;
        cout << "Password: ";
        cin >> employee_password;

        //check id and password for security
        if (employee_id == em.id && employee_password == em.password){
            cout << "\nAccount type: " << em.account_type << endl;
            cout << "Account no: " << em.account_no << endl;
            cout << "Amount of money(including salary): " << em.money + em.gross_salary << endl;
            cout << "Program complete successfully." << endl;
        }
        else{
            cout << "\nEmployee ID or password did not match!" << endl;
            cout << "Program terminated";
        }
    }
    else if(access == "no" || access == "No"){
        cout << "\nSalary: " << em.gross_salary << endl;
    }
    else{
        cout << "\nEnter yes or no! program terminated." << endl;
    }
}

//main function
int main()
{
    employee em;
    string permission;
    cout << "Do you want to see about " << em.name << " ? (Yes/No): ";
    cin >> permission;

    //check permission for show information
    if (permission == "yes" || permission == "Yes"){
        about(em);
    }
    else if (permission == "no" || permission == "No"){
        cout << "Program complete successfully." << endl;
    }
    else{
        cout << "Enter yes or no! program terminated." << endl;
    }

    return 0;
}
