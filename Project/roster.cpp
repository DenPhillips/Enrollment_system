//
//  roster.cpp
//  Project
//
//  Created by Dennis Phillips on 8/2/22.
//

#include "roster.h"
#include <string>

/* Parses through long data string and adds to roster */
void Roster::parse(string student){
    /* find the index of first comma */
    size_t com = student.find(",");
    
    /* create a string of the first but of data from 0 to comma */
    string studentId = student.substr(0, com);
    
    /*move past first comma*/
    size_t nextcom = com + 1;
    
    /* get index of next comma */
    com = student.find(",", nextcom);
    
    /* get next string of data*/
    string firstName = student.substr(nextcom, com - nextcom);
    
    nextcom = com + 1;
    
    com = student.find(",", nextcom);
    
    string lastName = student.substr(nextcom, com - nextcom);
    
    nextcom = com + 1;
    
    com = student.find(",", nextcom);
    
    string emailAdress = student.substr(nextcom, com - nextcom);
    
    nextcom = com + 1;
    
    com = student.find(",", nextcom);
    
    int age = stoi(student.substr(nextcom, com - nextcom));
    
    nextcom = com + 1;
    
    com = student.find(",", nextcom);
    
    int daysInCourse1 = stoi(student.substr(nextcom, com - nextcom));
    
    nextcom = com + 1;
    
    com = student.find(",", nextcom);
    
    int daysInCourse2 = stoi(student.substr(nextcom, com - nextcom));
    
    nextcom = com + 1;
    
    com = student.find(",", nextcom);
    
    int daysInCourse3 = stoi(student.substr(nextcom, com - nextcom));
    
    nextcom = com + 1;
    
    com = student.find(",", nextcom);
    
    string degreeChoice = student.substr(nextcom, student.length() - 1);
    
    DegreeProgram degree = DEFAULT;
    if (degreeChoice  == "SECURITY"){
        degree = SECURITY;
    }
    else if (degreeChoice == "NETWORK"){
        degree = NETWORK;
    }
    else if( degreeChoice == "SOFTWARE"){
        degree = SOFTWARE;
    }
    
    add(studentId, firstName, lastName, emailAdress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

/* Method for adding students to roster */
void Roster::add(string studentID, string firstName, string lastName, string emailAdress,  int age,  int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree){
    
    int dayarr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAdress, age, dayarr, degree);
}

/* Removing student from roster */
void Roster::remove(string studentID){
    
    bool exist = false;
    
    for(int i = 0; i <= Roster::index; i++){
        if(classRosterArray[i] -> getStudentId() == studentID){
            exist = true;
            if(i < numStudents - 1){
                /* Changes data to last index, then shortens array length*/
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::index--;
        }
    }
    if(exist){
        cout << "Student: " << studentID << " removed." << std::endl;
    }
    
    if(!exist){
        cout << "Student with this ID was not found." << std::endl;
    }
    
    cout << std::endl;
}

/* Prints all the students in roster */
void Roster::printAll(){
    /* Loops though roster */
    for(int i = 0; i <= Roster::index; i++){
        /* Prints roster data */
        classRosterArray[i]->print();
    }
    cout << std::endl;
}

/* Prints average of days in course by student ID*/
void Roster::printAverageDaysInCourse(string studentID){
    
    for(int i = 0; i <= Roster::index; i++){
        if(Roster::classRosterArray[i] -> getStudentId() == studentID){
            cout << classRosterArray[i] -> getStudentId() << ": ";
            cout << (classRosterArray[i] -> getDaysInClass()[0] +
                     classRosterArray[i] -> getDaysInClass()[1] +
                     classRosterArray[i] -> getDaysInClass()[2])/ 3.0;
        }
    }
    /* New line */
    cout << std::endl;
   
}

/* Prints all invalid emails */
void Roster::printInvalidEmails(){
    bool invalid = false;
    
    for(int i = 0; i <= Roster::index; i++){
        string email = classRosterArray[i] -> getEmailAdress();
        if(email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos)
        {
            invalid = true;
            cout << classRosterArray[i]->getEmailAdress() << std::endl;
            
        }
    }
    cout << std::endl;
    
}

/* Prints all student in chosen degree */
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for(int i = 0; i <= Roster::index; i++){
        if(Roster::classRosterArray[i] -> getDegreeProgram() == degreeProgram){
            classRosterArray[i] -> print();
        }
    }
    cout << std::endl;
}

/* Deletes the roster object */
Roster::~Roster(){
    
    for(int i = 0; i < numStudents; i++){
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    cout << "Roster deleted" << std::endl;
}


