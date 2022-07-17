// Time.cpp
//
// Version
// 01 03/03/2019 Ang Kok Leong
//    Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "Time.h"
#include "Vector.h"
#include "Utility.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

//Constructor of the Time class
Time::Time(){
	m_hours = 0;
	m_minutes = 0;
}

Time::Time(int hours, int minutes){
	Time::SetHours(hours);
	Time::SetMinutes(minutes);
}

//----------------------------------------------------------------------------
//Deconstructor of the date class

Time::~Time(){}

//----------------------------------------------------------------------------
// Set the Hour from the time object

void Time::SetHours(int hours){
	m_hours = hours;
}

//----------------------------------------------------------------------------
// Set the Minute from the time object

void Time::SetMinutes(int minutes){
	m_minutes = minutes;
}

//----------------------------------------------------------------------------
// Get the Hour from the time object

int Time::GetHours(){
	return m_hours;
}

//----------------------------------------------------------------------------
// Get the minutes from the Time object

int Time::GetMinutes(){
	return m_minutes;
}


//----------------------------------------------------------------------------
// Overloads the operator >> to input the data from the file to Time class

istream & operator >>(istream & input, Time & T){

	string data;

	getline(input, data, '\n');

	Utility utilObj;

	//extract the first column of the data row from csv
	string time = utilObj.GetDataFromARow(data, ",", 0);

	//convert the string to a stream to ignore the date
	istringstream iss(time);
	iss.ignore(256, ' ');

	//extract the time
	string newData;
	getline(iss, newData, ',');

	vector<string> v;

	string delimiter = ":";
	size_t position = 0;
	string token;

	while ((position = newData.find(delimiter)) != string::npos){
		token = newData.substr(0, position);
		v.push_back(token);
		newData.erase(0,position+delimiter.length());
	}
	//insert the final value into vector
	v.push_back(newData);

	for (int k = 0; k < v.size(); k++) {
		if (k == 0)
			T.SetHours(stoi(v.at(k)));
		else if (k == 1)
			T.SetMinutes(stoi(v.at(k)));
	}

	//reset the stream reader back to original
	input.seekg(0);

	return input;
}

//----------------------------------------------------------------------------
// Overloads the operator >> to input the data from the file to Time class
ostream & operator <<(ostream & os, Time & T)
{
	os << T.GetHours() << ":" << T.GetMinutes();
	return os;
}

//----------------------------------------------------------------------------
// Overloads the operator = to compare two time object
Time& Time::operator= (const Time& t) {

	this->m_hours = t.m_hours;
	this->m_minutes = t.m_minutes;

	return *this;
}


//----------------------------------------------------------------------------
// Overloads the operator == to compare two time object
bool Time::operator== (const Time& t) const{
	if((this->m_hours < t.m_hours) ||
		(this->m_hours > t.m_hours) ||
		(this->m_hours == t.m_hours && this->m_minutes < t.m_minutes) ||
		(this->m_hours == t.m_hours && this->m_minutes > t.m_minutes))
	{
		return false;
	}
	else
	{
		return true;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator != to compare two time object
bool Time::operator!= (const Time& t) const{
	if((this->m_hours < t.m_hours) ||
		(this->m_hours > t.m_hours) ||
		(this->m_hours == t.m_hours && this->m_minutes < t.m_minutes) ||
		(this->m_hours == t.m_hours && this->m_minutes > t.m_minutes))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator <= to compare two time object
bool Time::operator<= (const Time& t) const{
	if((this->m_hours < t.m_hours) ||
		(this->m_hours == t.m_hours && this->m_minutes < t.m_minutes) ||
		(this->m_hours == t.m_hours && this->m_minutes == t.m_minutes))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator < to compare two time object
bool Time::operator< (const Time& t) const{
	if((this->m_hours < t.m_hours) ||
		(this->m_hours == t.m_hours && this->m_minutes < t.m_minutes))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator >= to compare two time object
bool Time::operator>= (const Time& t) const{
	if((this->m_hours > t.m_hours) ||
		(this->m_hours == t.m_hours && this->m_minutes > t.m_minutes) ||
		(this->m_hours == t.m_hours && this->m_minutes == t.m_minutes))
		{
			return true;
		}
		else
		{
			return false;
		}
}


//----------------------------------------------------------------------------
// Overloads the operator > to compare two time object
bool Time::operator>(const Time& t) const {
	if ((this->m_hours > t.m_hours) || (this->m_hours == t.m_hours && this->m_minutes > t.m_minutes)) {
		return true;
	} else {
		return false;
	}
}

