// grade.score.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "StudentList.h"


using namespace std;

void ReadStudentData();// Read student inf0 including first and last name and test score
void SortData(vector<Student> sortList); //Sorting Student data 
void WriteStudentData(); //Write sort data in the file

string inFilename;

vector<Student> sList;

int main()
{
	ReadStudentData();
	
	return 0;
}//End of Main

void ReadStudentData()
{
	cout << "Enter the name of the .txt file that you want to open for input.\n";
	cout << "Do not put spaces in the file name: ";
	cin >> inFilename;
	cout << endl;

	StudentList list(inFilename);

	sList = list.exposeStudentVector();

	cout << "Original Data :" << endl << endl;
	for (Student s : sList)
	{
		cout << s.getFirstName() << "  " << s.getLastName() << "  " << s.getscore() << endl;
	} //End of For

	cout << endl;

	//Sorting data 
	SortData(sList);
	cout << "Sorting By score Data :" << endl << endl;
	for (Student s : sList)
	{
		cout << s.getFirstName() << "  " << s.getLastName() << "  " << s.getscore() << endl;
	} //End of For

	//Write into output file
	WriteStudentData();

	cin.get();
	
} //End of Read Student Data

	void SortData(vector<Student> sortList)
	{
		for (int i = 0; i < sList.size() - 1; i++)
		{

			for (int j = 0; j < sList.size() - 1; j++)
			{
				if (sortList[j].getscore() < sortList[j + 1].getscore())
					swap(sortList[j], sortList[j + 1]);
				else if (sortList[j].getscore() == sortList[j + 1].getscore())
				{
					
						if(sortList[j].getLastName() > sortList[j+1].getLastName())
							swap(sortList[j], sortList[j + 1]);
						else if (sortList[j].getLastName() == sortList[j + 1].getLastName())
						{
							if (sortList[j].getFirstName() > sortList[j + 1].getFirstName())
								swap(sortList[j], sortList[j + 1]);
						} //End of Else IF
					
				} // End of Else IF 
			} //End of Inner For
		} //End of Outer For
		sList = sortList;
	}

	bool isPathRelative(string filename)
	{
		if (filename[0] == '.')
			return true;
		else
			return false;
	}//End of function isPathRelative

	string getAbsolutePath(string inFilename)
	{
		char *filepath;
		filepath = (char *)inFilename.c_str();
		char fullpath[_MAX_PATH];
		if (_fullpath(fullpath, filepath, _MAX_PATH) != NULL)
		{
			return fullpath;
		}
		return inFilename;
	} //End of function getAbsolutePath

	void WriteStudentData()
	{
		
		if (isPathRelative(inFilename))
		{
			inFilename = getAbsolutePath(inFilename);
		} //End of IF
		
		string filename = inFilename.substr(0, inFilename.rfind(".")) + "-graded.txt";
		

		ofstream studentfile(filename);
		
		try
		{
			if (studentfile.is_open())
			{
				for (Student s : sList)
				{
					studentfile << s.getLastName() << ", " << s.getFirstName() << ", " << s.getscore() << endl;
				} //End of For
				studentfile.close();
			}
			else
			{
				cout << "Unable to open file" << endl;

			} //End of If Else
		}
		catch (exception e)
		{
			cout << e.what() << '\n';
		}//End of Try--Catch Block
		cin.get();
	}


