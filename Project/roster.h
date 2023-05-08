//
//  roster.h
//  Project
//
//  Created by Dennis Phillips on 8/2/22.
//

#ifndef roster_h
#define roster_h

#include <stdio.h>
#include "student.h"

class Roster {
    private:
    int index = -1;
    const static int numStudents = 5;
    
    public:
    Student *classRosterArray[numStudents];
    /* Parse through each stident in the roster*/
    void parse(string row);
    
    /* Add data to the roster */
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
    /* Removes data from the roster by providing student ID */
    void remove(string studentID);
    
    /*Prints the roster*/
    void printAll();
    
    /* Prints the average of days by student by providing student ID */
    void printAverageDaysInCourse(string studentID);
    
    /* Print all emails that dop not contain @ and a . */
    void printInvalidEmails();
    
    /* prints students by degree*/
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    ~Roster();
    
};
#endif /* roster_hpp */
