// Utility.cpp
//
// Version
// 01 03/02/2019 Ang Kok Leong
//    Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes
#include "Utility.h"
#include <vector>
#include <string>


//----------------------------------------------------------------------------
// Global variables/defines

using namespace std;


//----------------------------------------------------------------------------
// Prototypes


//----------------------------------------------------------------------------
// Function implementations

//----------------------------------------------------------------------------
//Constructor of the Utility class

Utility::Utility() {

}

//----------------------------------------------------------------------------
//Deconstructor of the Utility class
Utility::~Utility() {

}

//----------------------------------------------------------------------------
//Output a string by skipping the delimiter based on the position of the string in the given data
string Utility::GetDataFromARow(string data, string delimiter, string::size_type position){
	Vector<string> v;
	string::size_type i = 0;
	string::size_type j = data.find(delimiter);

	string::size_type counter = 0;
	while (j != string::npos) {
		v.push_back(data.substr(i, j - i));
		i = ++j;
		j = data.find(delimiter, j);

		if (j == string::npos)
			v.push_back(data.substr(i, data.length()));
	}

	for (int k = 0; k < v.getCount(); k++) {
		if (!v.at(position).empty()){
			return v.at(position);
		}
	}

	return "";
}

//----------------------------------------------------------------------------
//Output the full name of the month based on the given numeric digit of the month
string Utility::GetMonthInString(int month){
	vector<string> monthVector;
	monthVector.push_back("January");
	monthVector.push_back("February");
	monthVector.push_back("March");
	monthVector.push_back("April");
	monthVector.push_back("May");
	monthVector.push_back("June");
	monthVector.push_back("July");
	monthVector.push_back("August");
	monthVector.push_back("September");
	monthVector.push_back("October");
	monthVector.push_back("November");
	monthVector.push_back("December");

	for (int i=0; i<monthVector.size(); i++){
		if(i == (month-1))
			return monthVector.at(i);
	}

	return "";
}


