#include <iostream> 
#include <string>
#include <fstream>
#include"course.h"
#include"student.h"
using namespace std;

ofstream fout;
ifstream fin;
class Student;
class Course;

//class Student {
//private:
//    string name;
//    int roll_num;
//    int age;
//    string contact;
//    Course** courses;
//    int ts;
//    int* attendance;
//    int* marks;
//
//public:
//    
//    Student(string n, int r, int a, string c);
//
//    void Update(string n, int r, int a, string c);
//    bool search(Course& a);
//
//    string getName();
//    int getRollNum();
//    int getAge();
//
//
//
//    void setName(string n);
//    void setRollNum(int r);
//    void setAge(int a);
//    void setContact(string c);
//
//
//    void print();
//    void disp(int i);
//    void registerCourse(Course& a);
//    void withdraw(Course& a);
//    void markAttendance(Course& a, int at);
//    void assignMarks(Course& a, int at);
//};
//
//class Course {
//
//private:
//    int  code;
//    string name;
//    string instructor;
//    int credits;
//    int capacity;
//    Student** students;
//    int ts;
//
//public:
//
//    Course(int code, string name, string instructor, int credits, int capacity);
//    void disp();
//    void print();
//    void enroll(Student& a);
//    int getid();
//    void unenroll(Student& a);
//    bool search(Student& a);
//};
//

Course::Course(int code, string name, string instructor, int credits, int capacity)
    : code(code), name(name), instructor(instructor), credits(credits), capacity(capacity) {

    students = new Student * [capacity];
    ts = 0;
}
void Course::disp()
{

    for (size_t i = 0; i < ts; i++)
    {
        students[i]->print();

    }

}

int Course::getid() {
    return code;

}
void Course::print() {

    cout << "Course: " << name << endl;
    cout << "Course ID: " << code << endl;
    cout << "instructor: " << instructor << endl;
    cout << "Credits: " << credits << endl;
}
int Course::getCredits() const {
    return credits;
}

void Course::enroll(Student& a) {

    if (ts == capacity) { cout << "Maximum Students already enrolled\n"; }
    else {

        for (int i = 0; i < ts; i++)
        {
            if (students[i]->getRollNum() == a.getRollNum()) { cout << "Student already enroll\n"; return; }


        }



        students[ts] = &a;
        ts++;
        if (!a.search(*this)) a.registerCourse(*this);

    }



}
void Course::unenroll(Student& a)
{

    bool flag = false; int i = 0;
    for (i = 0; i < ts; i++)
    {
        if (students[i]->getRollNum() == a.getRollNum()) { flag = true; break; }


    }
    if (!flag) { cout << "student to be unenroll not registered\n"; return; }
    else {
        int newSize = ts - 1;
        Student** newArray = new Student * [newSize];


        for (int j = 0, k = 0; j < ts; j++) {
            if (i != j) { newArray[k] = students[j]; k++; }
        }


        delete[] students;

        students = newArray;
        ts--;
        if (a.search(*this))a.withdraw(*this);

    }











}



int Course:: getCapacity() const {
    return capacity;
}
string Course:: getInstructor() {
    return instructor;
}
string Course ::getName()  {
    return name;
}

bool Course::search(Student& a)
{

    bool flag = false; int i = 0;
    for (i = 0; i < ts; i++)
    {
        if (students[i]->getRollNum() == a.getRollNum()) { flag = true; break; }


    }return flag;


}
Student::Student(string n, int r, int a, string c) :
    name(n), roll_num(r), age(a), contact(c) {
    ts = 0;
}
void Student::Update(string n, int r, int a, string c) {
    name = n;  roll_num = r; age = a; contact = c;
    ts = 0;
}
string Student::getName() { return name; }
int Student::getRollNum() { return roll_num; }
int Student::getAge() { return age; }



void Student::setName(string n) { name = n; }
void Student::setRollNum(int r) { roll_num = r; }
void Student::setAge(int a) { age = a; }
void Student::setContact(string c) { contact = c; }


void Student::print() {

    cout << "Name: " << name << endl;
    cout << "Roll Number: " << roll_num << endl;
    cout << "Age: " << age << endl;
    cout << "Contact: " << contact << endl;

}
string Student::getContact() {
    return contact;
}

void Student::disp(int n=0) {print();
    for (size_t i = 0; i < ts; i++)
    {
        
        courses[i]->print();
       if(n==2) cout << "Attendance :" << attendance[i] << "%" << endl;
       if (n == 1)cout << "Marks :" << marks[i] << "%"<<endl;

    }








}
bool Student::search(Course& a)
{

    bool flag = false; int i = 0;
    for (i = 0; i < ts; i++)
    {
        if (courses[i]->getid() == a.getid()) { flag = true; break; }


    }return flag;


}
void Student::assignMarks(Course& a, int at) {


    bool flag = false; int i = 0;
    for (i = 0; i < ts; i++)
    {
        if (courses[i]->getid() == a.getid()) { flag = true; break; }


    }
    if (!flag) { cout << "course to be marked not registered\n"; return; }
    else {

        marks[i] = at;




    }
}
void Student::markAttendance(Course& a, int at) {


    bool flag = false; int i = 0;
    for (i = 0; i < ts; i++)
    {
        if (courses[i]->getid() == a.getid()) { flag = true; break; }


    }
    if (!flag) { cout << "course to be marked attendance of not registered\n"; return; }
    else {

        attendance[i] = at;




    }




}
void Student::withdraw(Course& a) {
    bool flag = false; int i = 0;
    for (i = 0; i < ts; i++)
    {
        if (courses[i]->getid() == a.getid()) { flag = true; break; }


    }
    if (!flag) { cout << "course to be withdraw not registered\n"; return; }
    else {
        int newSize = ts - 1;
        Course** newArray = new Course * [newSize];


        for (int j = 0, k = 0; j < ts; j++) {
            if (i != j) { newArray[k] = courses[j]; k++; }
        }


        delete[] courses;

        courses = newArray;






        int* nmarks = new int[newSize];


        for (int j = 0, k = 0; j < ts; j++) {
            if (i != j) {
                nmarks[i] = marks[i]; k++;
            }
        }


        delete[] marks;



        marks = nmarks;
        marks[ts] = 0;



        int* nattendance = new int[newSize];


        for (int j = 0, k = 0; j < ts; j++) {
            if (i != j) {
                nattendance[i] = attendance[i]; k++;
            }
        }


        delete[] attendance;



        attendance = nattendance;












        ts = newSize;









        if (a.search(*this)) a.unenroll(*this);




    }







}
void Student::registerCourse(Course& a) {

    for (int i = 0; i < ts; i++)
    {
        if (courses[i]->getid() == a.getid()) { cout << "Course already registered\n"; return; }


    }



    int newSize = ts + 1;
    Course** newArray = new Course * [newSize];


    for (int i = 0; i < ts; i++) {
        newArray[i] = courses[i];
    }


    delete[] courses;


    courses = newArray;

    int* nmarks = new int[newSize];


    for (int i = 0; i < ts; i++) {
        nmarks[i] = marks[i];
    }


    delete[] marks;



    marks = nmarks;
    marks[ts] = 0;



    int* nattendance = new int[newSize];


    for (int i = 0; i < ts; i++) {
        nattendance[i] = attendance[i];
    }


    delete[] attendance;



    attendance = nattendance;
    attendance[ts] = 0;






    courses[ts] = &a;
    ts = newSize;
    if (!a.search(*this)) a.enroll(*this);













}

class flexsystem {
private:
    Student** stu;
    Course** cor;
    int ts;
    int tc;
public:
    flexsystem()
    {
        stu = NULL;
        cor = NULL;
        ts = 0;
        tc = 0;
    }

    void  addstudent()
    {
        cout << "Enter name : ";
        string n;
        cin >> n;
        cout << "Enter roll number: ";
        int r;
        cin >> r;
        int a;
        cout << "Enter age : ";
        cin >> a;
        cout << "Enter contact : "; string c;
        cin >> c;
        if (r < 0 || a < 0) { cout << "invalid input \n Enter values again"; addstudent(); return; }
        for (size_t i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r)
            {
                cout << "Roll number already in use \n Enter values again"; addstudent(); return;

            }

        }

        int newSize = ts + 1;
        Student** newArray = new Student * [newSize];


        for (int i = 0; i < ts; i++) {
            newArray[i] = stu[i];
        }


        delete[] stu;


        stu = newArray;









        stu[ts] = new Student(n, r, a, c);
        ts++;













    }
    void  removestudent()
    {

        int r;
        cout << "enter roll no :";
        cin >> r;
        bool flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student to be enrolled not registered n the system\n"; removestudent(); return; }
        else {
            for (int j = 0; j < tc; j++)
            {
                if (cor[j]->search(*stu[i])) { cor[j]->unenroll(*stu[i]); }


            }

            int newSize = ts - 1;
            Student** newArray = new Student * [newSize];


            for (int j = 0, k = 0; j < ts; j++) {
                if (i != j) { newArray[k] = stu[j]; k++; }
            }


            delete[] stu;

            stu = newArray;
            ts--;


        }



    }
    void removeCourse()
    {

        int r;
        cout << "enter Course id :";
        cin >> r;
        bool flag = false; int i = 0;
        for (i = 0; i < tc; i++)
        {
            if (cor[i]->getid() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student to be enrolled not registered n the system\n"; removestudent(); return; }
        else {
            for (int j = 0; j < tc; j++)
            {
                if (stu[j]->search(*cor[i])) { stu[j]->withdraw(*cor[i]); }


            }

            int newSize = tc - 1;
            Course** newArray = new Course * [newSize];


            for (int j = 0, k = 0; j < tc; j++) {
                if (i != j) { newArray[k] = cor[j]; k++; }
            }


            delete[] cor;

            cor = newArray;
            tc--;


        }






    }
    void addCourse()
    {
        cout << "Enter course name : ";
        string n;
        cin >> n;
        cout << "Enter course id : ";
        int id;
        cin >> id;
        int c, ca;
        cout << "Enter credits : ";
        cin >> c;
        cout << "Enter instructor name : "; string t;
        cin >> t;
        cout << "Enter capacity : ";
        cin >> ca;

        if (id < 1 || ca < 1 || c < 1)
        {
            cout << "invalid input \n Enter values again"; addCourse(); return;
        }
        for (size_t i = 0; i < tc; i++)
        {
            if (cor[i]->getid() == id)
            {
                cout << "Course code already in use \n Enter values again"; addCourse(); return;

            }




        }


        int newSize = tc + 1;
        Course** newArray = new Course * [newSize];


        for (int i = 0; i < tc; i++) {
            newArray[i] = cor[i];
        }


        delete[] cor;


        cor = newArray;


        cor[tc] = new Course(id, n, t, c, ca);

        tc++;




    }
    void enroll()
    {
        cout << "Enter course id : ";
        int id;
        cin >> id;
        cout << "Enter roll number: ";
        int r;
        cin >> r;
        if (id < 1 || r < 1)
        {
            cout << "invalid input \n Enter values again"; enroll(); return;
        }

        bool flag = false; int j = 0;
        for (j = 0; j < tc; j++)
        {
            if (cor[j]->getid() == id) { flag = true; break; }


        }
        if (!flag) { cout << "Course to be enrolled not registered n the system\n"; enroll(); return; }

        flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student to be enrolled not registered n the system\n"; enroll(); return; }

        cor[j]->enroll(*stu[i]);







    }
    void regis()
    {
        cout << "Enter course id : ";
        int id;
        cin >> id;
        cout << "Enter roll number: ";
        int r;
        cin >> r;
        if (id < 1 || r < 1)
        {
            cout << "invalid input \n Enter values again"; enroll(); return;
        }


        bool flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student to be Register in course not registered in the system\n"; regis(); return; }
        flag = false; int j = 0;
        for (j = 0; j < tc; j++)
        {
            if (cor[j]->getid() == id) { flag = true; break; }


        }
        if (!flag) { cout << "Course to register not registered in the system\n"; regis(); return; }

        stu[i]->registerCourse(*cor[j]);







    }
    void unenroll()
    {
        cout << "Enter course id : ";
        int id;
        cin >> id;
        cout << "Enter roll number: ";
        int r;
        cin >> r;
        if (id < 1 || r < 1)
        {
            cout << "invalid input \n Enter values again"; unenroll(); return;
        }

        bool flag = false; int j = 0;
        for (j = 0; j < tc; j++)
        {
            if (cor[j]->getid() == id) { flag = true; break; }


        }
        if (!flag) { cout << "Course to be unenrolled not registered n the system\n"; unenroll(); return; }

        flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student to  unenrolled not registered n the system\n"; unenroll(); return; }


        if (!cor[j]->search(*stu[i]))
        {
            cout << "Student to  unenroll not registered in Course\n"; unenroll(); return;
        }
        else
        {
            cor[j]->unenroll(*stu[i]);
        }





    }
    void withdraw()
    {
        cout << "Enter course id : ";
        int id;
        cin >> id;
        cout << "Enter roll number: ";
        int r;
        cin >> r;
        if (id < 1 || r < 1)
        {
            cout << "invalid input \n Enter values again"; unenroll(); return;
        }

        bool flag = false; int j = 0;
        for (j = 0; j < tc; j++)
        {
            if (cor[j]->getid() == id) { flag = true; break; }


        }
        if (!flag) { cout << "Course to be unenrolled not registered n the system\n"; unenroll(); return; }

        flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student to  unenrolled not registered n the system\n"; unenroll(); return; }


        if (!cor[j]->search(*stu[i]))
        {
            cout << "Student to  unenroll not registered in Course\n"; unenroll(); return;
        }
        else
        {
            stu[i]->withdraw(*cor[j]);
        }





    }
    void dispstu() {
        for (size_t i = 0; i < ts; i++)
        {
            stu[i]->print();

        }
    }
    void upstu()
    {
        int r;
        cout << "enter roll no to be updated :";
        cin >> r;
        bool flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student to be enrolled not registered n the system\n"; upstu(); return; }
        else {


            cout << "Enter name : ";
            string n;
            cin >> n;
            cout << "Enter roll number: ";
            int r;
            cin >> r;
            int a;
            cout << "Enter age : ";
            cin >> a;
            cout << "Enter contact : "; string c;
            cin >> c;
            if (r < 0 || a < 0) { cout << "invalid input \n Enter values again"; upstu(); return; }
            for (size_t j = 0; j < ts; j++)
            {
                if (stu[j]->getRollNum() == r)
                {
                    cout << "Roll number already in use \n Enter values again"; upstu();  return;

                }

            }
            stu[i]->Update(n, r, a, c);


        }

    }
    void menu()
    {



        char choice;

        do {
            cout << "Menu: \n";
            cout << "1. Enroll a student\n";
            cout << "2. Course Registration\n";
            cout << "3. Attendance\n";
            cout << "4. Marks\n";
            cout << "5. Course Withdraw\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                Stumenu();
                db();
                break;
            case '2':
                coregMenu(); db();
                break;
            case '3':
                attmenu(); db();
                break;
            case '4':
                markmenu(); db();
                break;
            case '5':
                cowiMenu(); db();
                break;
            case '6':
                cout << "System exited"; return;
                
            default:
                cout << "Invalid choice. Please enter again.\n";
            }
        } while (choice != '6');



    }



    void Stumenu() {
        char choice;

        do {
            cout << "Student Menu: \n";
            cout << "1. Display Enrolled Students\n";
            cout << "2. Add a Student\n";
            cout << "3. Remove a Student\n";
            cout << "4. Edit Student Detail\n";
            cout << "5. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                dispstu(); db();
                break;
            case '2':
                addstudent(); db();
                break;
            case '3':
                removestudent(); db();
                break;
            case '4':
                upstu(); db();
                break;
            case '5':
                 return;
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
            }
        } while (choice != '5');
    }
    void dispcourse()
    {
        for (size_t i = 0; i < tc; i++)
        {
            cor[i]->print();

        }
    }

    void coregMenu() {
        char choice;

        do {
            cout << "Menu: \n";
            cout << "1. Display Al Courses\n";
            cout << "2. Register a Course to a Student\n";
            cout << "3. Add course to the system\n";
            cout << "4. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                dispcourse(); db();
                break;
            case '2':
               
               regis(); db();
                break;
            case '3':
                addCourse(); db();
                break;
            case '4':
               return;
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
            }
        } while (choice != '4');
    }

    void stuco(int n=0)
    {
        
        cout << "Enter roll number: ";
        int r;
        cin >> r;
        if ( r < 1)
        {
            cout << "invalid input \n Enter values again"; stuco(); return;
        }


        bool flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student not registered in the system\n"; stuco(); return; }
        stu[i]->disp(n);




   }
    void cowiMenu() {
        char choice;

        do {
            cout << "Menu: \n";
            cout << "1. Display Courses already enrolled by a student \n";
            cout << "2. Withdraw a Course from a Student\n";
            cout << "3. Remove course from the system\n";
            cout << "4. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                stuco(); db();
                break;
            case '2':
                withdraw(); db();
                break;
            case '3':
                removeCourse(); db();
                break;
            case '4':
               return;
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
            }
        } while (choice != '4');
    }
    void markmenu()
    {
        char choice;

        do {
            cout << "Menu: \n";
            cout << "1. Display marks of a student \n";
            cout << "2. Assign marks a Student\n";
          
            cout << "3. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                stuco(1); db();
                break;
            case '2':
                assmark(); db();
                break;
            case '3':
            
               return;
                
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
            }
        } while (choice != '3');

    }
    void attmenu()
    {
        char choice;

        do {
            cout << "Menu: \n";
            cout << "1. Display Attendance of a student \n";
            cout << "2. Assign attendance a Student\n";

            cout << "3. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                stuco(2); db();
                break;
            case '2':
              assat(); db(); break;
            case '3':

               return;
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
            }
        } while (choice != '3');

    }
    void assat()
    {
        cout << "Enter course id : ";
        int id;
        cin >> id;
        cout << "Enter roll number: ";
        int r;
        cin >> r;
        if (id < 1 || r < 1)
        {
            cout << "invalid input \n Enter values again"; enroll(); return;
        }


        bool flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student not registered in the system\n"; assat(); return; }
        flag = false; int j = 0;
        for (j = 0; j < tc; j++)
        {
            if (cor[j]->getid() == id) { flag = true; break; }


        }
        if (!flag) { cout << "Course  not registered in the system\n"; assat(); return; }
        cout << "enter attendace : ";
        int m;
        cin >> m;
        
             
        stu[i]->markAttendance(*cor[j], m);
    
    
    
    
    }
    void assmark()
    {
        cout << "Enter course id : ";
        int id;
        cin >> id;
        cout << "Enter roll number: ";
        int r;
        cin >> r;
        if (id < 1 || r < 1)
        {
            cout << "invalid input \n Enter values again"; enroll(); return;
        }


        bool flag = false; int i = 0;
        for (i = 0; i < ts; i++)
        {
            if (stu[i]->getRollNum() == r) { flag = true; break; }


        }
        if (!flag) { cout << "Student not registered in the system\n"; assat(); return; }
        flag = false; int j = 0;
        for (j = 0; j < tc; j++)
        {
            if (cor[j]->getid() == id) { flag = true; break; }


        }
        if (!flag) { cout << "Course  not registered in the system\n"; assat(); return; }
        cout << "enter marks : ";
        int m;
        cin >> m;
        stu[i]->assignMarks(*cor[j],m);






    }
    int validate_input(istream& is, int& num, string& line) {
        while (is >> num) {
            
            if (num<0) {
                return num;
            }
        }
    }
    void db()
    {
        fout.open("database.txt", ofstream::out | ofstream::trunc);
        fout.close();
        fout.open("database.txt");
            fout << ts << endl;
            for (size_t i = 0; i < ts; i++)
            {
                fout << stu[i]->getRollNum()<< endl;
                fout << stu[i]->getName() << endl;
                fout << stu[i]->getAge() << endl;
                fout << stu[i]->getContact() << endl;
            }
            fout << tc << endl;
            for (size_t i = 0; i < tc; i++)
            {
                fout << cor[i]->getid() << endl;
                fout << cor[i]->getName() << endl;
                fout << cor[i]->getInstructor() << endl;
                fout << cor[i]->getCapacity() << endl;
                fout << cor[i]->getCredits() << endl;
            }

            fout << ts << endl;
            for (size_t i = 0; i < ts; i++)
            {
                fout << stu[i]->getRollNum() << endl;
                fout << stu[i]->ts << endl;
                for (size_t j = 0; j < stu[i]->ts; j++)
                {
                    fout << stu[i]->courses[j]->getid() << endl;
                    fout << stu[i]->marks[j]<< endl;
                    fout << stu[i]->attendance[j] << endl;
                }
               
            }
            fout.close();


    }
    void dbscan() {
        fin.open("database.txt");
        if (fin.is_open())cout << "bindas";
        int st, ag, rn,cr;
        string con, na;
        fin >>st;
        ts = st;
        fin.ignore(1000, '\n');
        stu = new Student * [st];
        for (size_t i = 0; i < st; i++)
        {
            fin >> rn;
            
            fin.ignore(1000, '\n');
            fin >> na;
            fin >> ag;
            fin.ignore(1000, '\n');
            fin >> con;
            stu[i] = new Student(na, rn, ag, con);
        }
        fin >> st;
        tc = st;
        fin.ignore(1000, '\n');
        cor = new Course * [st];
        for (size_t i = 0; i < st; i++)
        {
            fin >> rn;
            fin.ignore(1000, '\n');
            fin >> na;
            
            fin >> con;
            fin >> ag;
            fin.ignore(1000, '\n');
            fin >> cr;
            fin.ignore(1000, '\n');
            cor[i] = new Course( rn,na,con,cr,ag);
        }


        fin >> st;
        fin.ignore(1000, '\n');
        for (size_t i = 0; i < st; i++)
        {
            fin >> rn;
            fin.ignore(1000, '\n');
            fin >> rn;
            fin.ignore(1000, '\n');
            for (size_t j = 0; j < rn; j++)
            {
                fin >> ag; fin.ignore(1000, '\n'); int k;
                for ( k = 0; k< tc; k++)
                {
                    if (cor[k]->getid() == ag)break;

                }
                stu[i]->registerCourse(*cor[k]);
                fin >> cr;
                fin.ignore(1000, '\n');
                 stu[i]->marks[j] =cr;
                 fin >> cr;
                 fin.ignore(1000, '\n');
                 stu[i]->attendance[j] = cr;
            }

        }

        fin.close();


    }
};


int main() {

    flexsystem a;
    a.dbscan();
    a.menu();
    a.db();
    return 0;
}
