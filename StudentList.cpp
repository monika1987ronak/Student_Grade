#include "stdafx.h"
#include "StudentList.h"
using namespace std;

//Constructor of student class which is read the stuednt file
StudentList::StudentList(string filePath)
{
	ifstream studentFile(filePath);
	string lineContents;
	try
	{
		if (studentFile.is_open())
		{
			while (!studentFile.eof())
			{
				getline(studentFile, lineContents);
				lineContents.erase(std::remove(lineContents.begin(), lineContents.end(), ','), lineContents.end());
				Student s(lineContents);
				students.push_back(s);
			} //End of while

			studentFile.close();
		}
		else
		{
			cout << "Unable to open file" << endl;
		}
		
	}
	catch (exception e)
	{
		cout << e.what() << '\n';
		cin.get();
	} //End of Try--Catch Block
}

//Return the vector object of student class
std::vector<Student> StudentList::exposeStudentVector() const
{
	return students;
}