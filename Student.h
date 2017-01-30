#pragma once
#ifndef Student_h
#define Student_h

#include <string>
#include <sstream>

class Student
{
private:

	std::string firstName;
	std::string lastName;
	int score;

public:
	Student(std::string studentInformation);
	std::string getFirstName();
	std::string getLastName();
	int getscore();


};
#endif
