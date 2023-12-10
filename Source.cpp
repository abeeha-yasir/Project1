
#include <iostream> 
#include <string>
using namespace std;
class Student {
private: 
    string name;
    int roll_num;
    int age;
    string contact;
    Course** courses;
    int ts;
    int* attendance;
    int* marks;

public:

    Student(string n, int r, int a, string c) :
        name(n), roll_num(r), age(a), contact(c) {}
    bool search(Course& a);

    string getName() { return name; }
    int getRollNum() { return roll_num; }
    int getAge() { return age; }



    void setName(string n) { name = n; }
    void setRollNum(int r) { roll_num = r; }
    void setAge(int a) { age = a; }
    void setContact(string c) { contact = c; }


    void print() {

        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_num << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;

    }
    void disp();
    void registerCourse(Course& a);
    void withdraw(Course& a);
    void markAttendance(Course& a, int at);
    void assignMarks(Course& a, int at);
};
class Course {

private:
    int  code;
    string name;
    string instructor;
    int credits;
    int capacity;
    Student** students;
    int ts;

public:

    Course(int code, string name, string instructor, int credits, int capacity)
        : code(code), name(name), instructor(instructor), credits(credits), capacity(capacity) {

        students = new Student * [capacity];
        ts = 0;
    }


    void disp()
    {

        for (size_t i = 0; i < ts; i++)
        {
            students[i]->print();

        }

    }

    void print() {

        cout << "Course: " << name << endl;
        cout << "Roll Number: " << code << endl;
        cout << "Age: " << instructor << endl;
        cout << "Contact: " << credits << endl;

    }

    void enroll(Student& a);
    int getid() { return code; };
    void unenroll(Student& a);





    bool search(Student& a);
};

void Course::disp()
{

    for (size_t i = 0; i < ts; i++)
    {
        students[i]->print();

    }

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


        for (int j = 0, int k = 0; j < ts; j++) {
            if (i != j) { newArray[k] = students[j]; k++; }
        }


        delete[] students;

        students = newArray;
        ts--;
        if (a.search(*this))a.withdraw(*this);

    }











}




bool Course::search(Student& a)
{

    bool flag = false; int i = 0;
    for (i = 0; i < ts; i++)
    {
        if (students[i]->getRollNum() == a.getRollNum()) { flag = true; break; }


    }return flag;


}























void Student::disp() {
    for (size_t i = 0; i < ts; i++)
    {
        courses[i]->print();
        cout << "Attendance :" << attendance[i] << endl;
        cout << "Marks :" << marks[i] << endl;

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


        for (int j = 0, int k = 0; j < ts; j++) {
            if (i != j) { newArray[k] = courses[j]; k++; }
        }


        delete[] courses;

        courses = newArray;






        int* nmarks = new int[newSize];


        for (int j = 0, int k = 0; j < ts; j++) {
            if (i != j) {
                nmarks[i] = marks[i]; k++;
            }
        }


        delete[] marks;



        marks = nmarks;
        marks[ts] = 0;



        int* nattendance = new int[newSize];


        for (int j = 0, int k = 0; j < ts; j++) {
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




int main() {

    Student bia("abeeha", 6655, 21, "03334403648");
    Student mojo("mojo", 6820, 19, "03334403648");

    Course oop(1, "oop", "mubashir", 3, 50);
    oop.enroll(mojo);
    bia.registerCourse(oop);
    bia.print();

    return 0;
=======
#include <iostream> 
#include <string>
using namespace std;
class Student {
private:
    string name;
    int roll_num;
    int age;
    string contact;
    Course** courses;
    int ts;
    int* attendance;
    int* marks;

public:

    Student(string n, int r, int a, string c) :
        name(n), roll_num(r), age(a), contact(c) {}
    bool search(Course& a);

    string getName() { return name; }
    int getRollNum() { return roll_num; }
    int getAge() { return age; }



    void setName(string n) { name = n; }
    void setRollNum(int r) { roll_num = r; }
    void setAge(int a) { age = a; }
    void setContact(string c) { contact = c; }


    void print() {

        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_num << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;

    }
    void disp();
    void registerCourse(Course& a);
    void withdraw(Course& a);
    void markAttendance(Course& a, int at);
    void assignMarks(Course& a, int at);
};
class Course {

private:
    int  code;
    string name;
    string instructor;
    int credits;
    int capacity;
    Student** students;
    int ts;

public:

    Course(int code, string name, string instructor, int credits, int capacity)
        : code(code), name(name), instructor(instructor), credits(credits), capacity(capacity) {

        students = new Student * [capacity];
        ts = 0;
    }


    void disp()
    {

        for (size_t i = 0; i < ts; i++)
        {
            students[i]->print();

        }

    }

    void print() {

        cout << "Course: " << name << endl;
        cout << "Roll Number: " << code << endl;
        cout << "Age: " << instructor << endl;
        cout << "Contact: " << credits << endl;

    }

    void enroll(Student& a);
    int getid() { return code; };
    void unenroll(Student& a);





    bool search(Student& a);
};

void Course::disp()
{

    for (size_t i = 0; i < ts; i++)
    {
        students[i]->print();

    }

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


        for (int j = 0, int k = 0; j < ts; j++) {
            if (i != j) { newArray[k] = students[j]; k++; }
        }


        delete[] students;

        students = newArray;
        ts--;
        if (a.search(*this))a.withdraw(*this);

    }











}




bool Course::search(Student& a)
{

    bool flag = false; int i = 0;
    for (i = 0; i < ts; i++)
    {
        if (students[i]->getRollNum() == a.getRollNum()) { flag = true; break; }


    }return flag;


}























void Student::disp() {
    for (size_t i = 0; i < ts; i++)
    {
        courses[i]->print();
        cout << "Attendance :" << attendance[i] << endl;
        cout << "Marks :" << marks[i] << endl;

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


        for (int j = 0, int k = 0; j < ts; j++) {
            if (i != j) { newArray[k] = courses[j]; k++; }
        }


        delete[] courses;

        courses = newArray;






        int* nmarks = new int[newSize];


        for (int j = 0, int k = 0; j < ts; j++) {
            if (i != j) {
                nmarks[i] = marks[i]; k++;
            }
        }


        delete[] marks;



        marks = nmarks;
        marks[ts] = 0;



        int* nattendance = new int[newSize];


        for (int j = 0, int k = 0; j < ts; j++) {
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




int main() {

    Student bia("abeeha", 6655, 21, "03334403648");
    Student mojo("mojo", 6820, 19, "03334403648");

    Course oop(1, "oop", "mubashir", 3, 50);
    oop.enroll(mojo);
    bia.registerCourse(oop);
    bia.print();

    return 0;

}
