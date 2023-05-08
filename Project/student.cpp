//
//  student.cpp
//  Project
//
//  Created by Dennis Phillips on 8/2/22.
//

#include "student.h"



/* Sets default values for Student object*/
Student::Student(){
    
    this -> studentId = "";
    this -> firstName = "";
    this -> lastName = "";
    this -> emailAdress = "";
    this -> age = 0;
    for(int i = 0; i < 3; i++) this -> daysInClass[i] = 0;
    this -> degree = DegreeProgram::DEFAULT;
    
    
}
/* Sets values for Student object with added data */
Student::Student(string studentId, string firstName, string lastName, string emailAdress, int age, int daysInClass[], DegreeProgram degree){
    
    this -> studentId = studentId;
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> emailAdress = emailAdress;
    this -> age = age;
    for(int i = 0; i < 3; i++) this -> daysInClass[i] = daysInClass[i];
    this -> degree = degree;
    
}

/* Getters */

string Student::getStudentId(){ return this -> studentId; }
string Student::getFirstName(){ return this -> firstName; }
string Student::getLastName(){ return this -> lastName; }
string Student::getEmailAdress(){ return this -> emailAdress; }
int Student::getAge(){ return this-> age;}
int* Student::getDaysInClass(){ return this -> daysInClass; }
DegreeProgram Student::getDegreeProgram(){ return this -> degree; }

/* Setters */

void Student::setStudentId(string studentId){this -> studentId = studentId;}
void Student::setFirstName(string firstName){this -> firstName = firstName;}
void Student::setLastName(string lastName){this -> lastName = lastName;}
void Student::setEmailAdress(string emailAdress){this -> emailAdress = emailAdress;}
void Student::setAge(int age){this -> age = age;}
void Student::setDaysInClass(int daysInClass[]){
    
    for(int i = 0; i < 3; i++) this -> daysInClass[i] = daysInClass[i];
    
}
void Student::setDegreeProgram(DegreeProgram degree){this -> degree = degree;}

/* Print */

void Student::print(){
    
    cout << this -> getStudentId() << '\t';
    cout << "First Name: " << this -> getFirstName() << '\t';
    cout << "Last Name: " << this -> getLastName() << '\t';
    cout << "Age : " << this -> getAge() << '\t';
    cout << "Days in course: {" << this -> getDaysInClass()[0] << ',';
    cout << this -> getDaysInClass()[1] << ',';
    cout << this -> getDaysInClass()[2] << "}"<< '\t';
    cout << "Degree program: " << degreeString[this -> getDegreeProgram()] << '\n';
}

