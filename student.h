#pragma once
#include <iostream> 
#include <string>
#include"course.h"

using namespace std;
class Course;

class Student {
private:
    string name;
    int roll_num;
    int age;
    string contact;
public:
    Course** courses;
    int ts;
    int* attendance;
    int* marks;

public:

    Student(string n, int r, int a, string c);

    void Update(string n, int r, int a, string c);
    bool search(Course& a);

    string getName();
    int getRollNum();
    int getAge();
    string getContact();


    void setName(string n);
    void setRollNum(int r);
    void setAge(int a);
    void setContact(string c);


    void print();
    void disp(int i);
    void registerCourse(Course& a);
    void withdraw(Course& a);
    void markAttendance(Course& a, int at);
    void assignMarks(Course& a, int at);
};
