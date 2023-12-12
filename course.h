#pragma once
#include <iostream> 
#include <string>
#include"student.h"

using namespace std;
class Student;
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

    Course(int code, string name, string instructor, int credits, int capacity);
    void disp();
    void print();
    int getCapacity() const;
    string getName();
    string getInstructor();
    int getCredits() const;
    void enroll(Student& a);
    int getid();
    void unenroll(Student& a);
    bool search(Student& a);
};
