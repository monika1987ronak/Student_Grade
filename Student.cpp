#include "stdafx.h"
#include "Student.h"

using namespace std;

//Constructor of Student class which takes firstname , lastname and score
Student::Student(std::string studentInformation)
{
	stringstream studentStream(studentInformation); // a stream of student information
	studentStream >> firstName;
	studentStream >> lastName;
	studentStream >> score;

} //End of Constructor

//Return the firstname
std::string Student::getFirstName()
{
	return firstName;
} 

//Return the lastname
std::string Student::getLastName()
{
	return lastName;
}

//Return the score
int Student::getscore()
{
	return score;
}

