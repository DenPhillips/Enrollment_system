//
//  student.h
//  Project
//
//  Created by Dennis Phillips on 8/2/22.
//

#ifndef student_h
#define student_h
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
using std::string;
using std::cout;


class Student{

    private:
        string studentId;
        string firstName;
        string lastName;
        string emailAdress;
        int age;
        int daysInClass[3];
        DegreeProgram degree;
    public:
        /* Constructor with empty parameters */
        Student();
        
        /* Constructor to set parameters */
        Student(string studentId, string firstName, string lastName, string emailAdreess, int age, int daysinclass[], DegreeProgram degree);
        
        /* Getters */
        string getStudentId();
        string getFirstName();
        string getLastName();
        string getEmailAdress();
        int getAge();
        int* getDaysInClass();
        DegreeProgram getDegreeProgram();
    
        /* Setters */
        void setStudentId(string studentId);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAdress(string emailAdress);
        void setAge(int age);
        void setDaysInClass(int daysinClass[]);
        void setDegreeProgram(DegreeProgram degree);
       
        /* Prints student data*/
        void print();
};

#endif /* student_hpp */
