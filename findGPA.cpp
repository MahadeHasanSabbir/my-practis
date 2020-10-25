#include <iostream>
using namespace std;
//class object
class subject
{
    public:
        string sname;
        string lettergpa;
        int number;
        float credit;
        float GPA;
        void input();
        void output()
        {
            cout << sname << "\tGPA: \'" << GPA << "\'\tletter GPA: " << lettergpa << endl;
        }
};
//global variable
int num;
//function prototype
float gpa(int subnum);
string LGPA(float lgpa);
float cgpa(float *cnum, float *ccdt)
{
    float sumofgpa = 0, sumofcredit = 0;
    for (int i = 0; i < num; i++){
        if (*(cnum + i) == 0){
            return 0;
        }
        sumofgpa += (*(cnum + i) * *(ccdt + i));
        sumofcredit += *(ccdt + i);
    }
    return (sumofgpa/sumofcredit);
}
//main function
int main(void)
{
    cout << "\tWelcome to this grading system program." << endl
    << "Number of subject for evaluation: ";
    cin >> num;
    subject subjects[num];
    float snum[num], scredit[num], sgpa[num];
    cout << "Fill out the options.\n";
    for (int i = 0; i < num; i++){
        subjects[i].input();
        snum[i] = subjects[i].number;
        scredit[i] = subjects[i].credit;
        sgpa[i] = gpa(snum[i]);
        subjects[i].GPA = sgpa[i];
        subjects[i].lettergpa = LGPA(sgpa[i]);
    }
    float result = cgpa(sgpa, scredit);
    string resultl = LGPA(result);
    cout << "\nYour CGPA is: \'" << result << "\' and Letter GPA is: " << resultl << endl;
    cout << "\n\tSubject wise result." << endl;
    for (int i = 0; i < num; i++){
        subjects[i].output();
    }
    cout << endl;
    return 0;
}
//user define class function
void subject::input()
{
    cout << "\nSubject name: ";
    cin >> sname;
    cout << "Obtained Number: ";
    cin >> number;
    cout << "Credit: ";
    cin >> credit;
}
//user define function
float gpa(int subnum)
{
    if (subnum <= 100 && subnum >= 80){
        return 4.0;
    }
    else if (subnum <= 79 && subnum >= 75){
        return 3.75;
    }
    else if (subnum <= 74 && subnum >= 70){
        return 3.5;
    }
    else if (subnum <= 69 && subnum >= 65){
        return 3.25;
    }
    else if (subnum <= 64 && subnum >= 60){
        return 3.0;
    }
    else if (subnum <= 59 && subnum >= 55){
        return 2.75;
    }
    else if (subnum <= 54 && subnum >= 50){
        return 2.5;
    }
    else if (subnum <= 49 && subnum >= 45){
        return 2.25;
    }
    else if (subnum <= 44 && subnum >= 40){
        return 2.0;
    }
    else if (subnum <= 39 && subnum >= 33){
        return 1.0;
    }
    else{
        return 0.0;
    }
}
string LGPA(float lgpa)
{
    if(lgpa <= 4.0 && lgpa >= 3.76){
        return "A+";
    }
    else if(lgpa <= 3.75 && lgpa >= 3.51){
        return "A";
    }
    else if(lgpa <= 3.5 && lgpa >= 3.26){
        return "A-";
    }
    else if(lgpa <= 3.25 && lgpa >= 3.01){
        return "B+";
    }
    else if(lgpa <= 3.0 && lgpa >= 2.76){
        return "B";
    }
    else if(lgpa <= 2.75 && lgpa >= 2.51){
        return "B-";
    }
    else if(lgpa <= 2.5 && lgpa >= 2.26){
        return "C+";
    }
    else if(lgpa <= 2.25 && lgpa >= 2.01){
        return "C";
    }
    else if(lgpa <= 2.0 && lgpa >= 1.01){
        return "D";
    }
    else if(lgpa == 1.0){
        return "E";
    }
    else if(lgpa == 0.0){
        return "F";
    }
}
