#include <iostream> 
#include <string>
using namespace std;
class Course {




public:
    void enroll(Student& a);
    int getid() {};
    void unenroll(Student& a);
};

class Student {
private:
    string name;
    int roll_num;
    int age;
    string contact;
    Course** courses;
    int no_C;
    int* attendance;
    int* marks;

public:

    Student(string n, int r, int a, string c) :
        name(n), roll_num(r), age(a), contact(c) {}


    string getName() { return name; }
    int getRollNum() { return roll_num; }
    int getAge() { return age; }



    void setName(string n) { name = n; }
    void setRollNum(int r) { roll_num = r; }
    void setAge(int a) { age = a; }
    void setContact(string c) { contact = c; }


    void enroll() {  }
    void registerCourse(Course& a) {

        for (int i = 0; i < no_C; i++)
        {
            if (courses[i]->getid() == a.getid()) { cout << "Course already registered\n"; return; }


        }



        int newSize = no_C + 1;
        Course** newArray = new Course * [newSize];


        for (int i = 0; i < no_C; i++) {
            newArray[i] = courses[i];
        }


        delete[] courses;


        courses = newArray;

        int* nmarks = new int[newSize];


        for (int i = 0; i < no_C; i++) {
            nmarks[i] = marks[i];
        }


        delete[] marks;



        marks = nmarks;
        marks[no_C] = 0;



        int* nattendance = new int[newSize];


        for (int i = 0; i < no_C; i++) {
            nattendance[i] = attendance[i];
        }


        delete[] attendance;



        attendance = nattendance;
        attendance[no_C] = 0;






        courses[no_C] = &a;
        no_C = newSize;
        a.enroll(*this);













    }
    void withdraw(Course& a) {
        bool flag = false; int i = 0;
        for (i = 0; i < no_C; i++)
        {
            if (courses[i]->getid() == a.getid()) { flag = true; break; }


        }
        if (!flag) { cout << "course to be withdraw not registered\n"; return; }
        else {
            int newSize = no_C - 1;
            Course** newArray = new Course * [newSize];


            for (int j = 0, int k = 0; j < no_C; j++) {
                if (i != j) { newArray[k] = courses[j]; k++; }
            }


            delete[] courses;

            courses = newArray;






            int* nmarks = new int[newSize];


            for (int j = 0, int k = 0; j < no_C; j++) {
                if (i != j) {
                    nmarks[i] = marks[i]; k++;
                }
            }


            delete[] marks;



            marks = nmarks;
            marks[no_C] = 0;



            int* nattendance = new int[newSize];


            for (int j = 0, int k = 0; j < no_C; j++) {
                if (i != j) {
                    nattendance[i] = attendance[i]; k++;
                }
            }


            delete[] attendance;



            attendance = nattendance;












            no_C = newSize;









            a.unenroll(*this);




        }







    }
    void markAttendance(Course& a, int at) {


        bool flag = false; int i = 0;
        for (i = 0; i < no_C; i++)
        {
            if (courses[i]->getid() == a.getid()) { flag = true; break; }


        }
        if (!flag) { cout << "course to be marked attendance of not registered\n"; return; }
        else {

            attendance[i] = at;




        }




    }
    void assignMarks(Course& a, int at) {


        bool flag = false; int i = 0;
        for (i = 0; i < no_C; i++)
        {
            if (courses[i]->getid() == a.getid()) { flag = true; break; }


        }
        if (!flag) { cout << "course to be marked not registered\n"; return; }
        else {

            marks[i] = at;




        }
    }
};

int main() {


    return 0;
}