#pragma once
#ifndef StudentList_h
#define StudentList_h

#include <string>
#include <vector>
#include <fstream> // file stream
#include <exception>
#include <iostream>
#include <algorithm>

#include "Student.h"
class StudentList
{
public:
	StudentList(std::string filePath);
	std::vector<Student> exposeStudentVector() const;
	
private:
	std::vector<Student> students;
};
#endif

