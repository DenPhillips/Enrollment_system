//
//  main.cpp
//  Project
//
//  Created by Dennis Phillips on 8/2/22.
//

#include <iostream>
#include "roster.h"

int main() {
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Dennis,Phillips,dphi292@wgu.edu,35,7,14,28,SOFTWARE"
    };
    
    const int numStudents = 5;
    
    Roster classRoster;
    
    for(int i = 0; i < numStudents; i++){
        classRoster.parse(studentData[i]);
    }
    
    cout << "Programming laguage used: C++" << std::endl;
    cout << "WGU Student ID: 010139544" << std::endl;
    cout << "Student name: Dennis Phillips" << std::endl;
    cout << std::endl;
    
    cout << "All Students:" << std::endl;
    classRoster.printAll();
    
    cout << "Invalid Emails:" << std::endl;
    classRoster.printInvalidEmails();
    
    cout << "Average of days in courses by student ID:" << std::endl;
    for(int i = 0; i < numStudents; i++){
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i] -> getStudentId());
    }
    cout << std::endl;
    
    cout << "Students by degree:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    cout << "Remove a student:" << std::endl;
    classRoster.remove("A3");
    
    cout << "All Students:" << std::endl;
    classRoster.printAll();
    
    cout << "Remove a student:" << std::endl;
    classRoster.remove("A3");
    
    return 0;
}
