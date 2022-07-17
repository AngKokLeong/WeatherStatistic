// Date.cpp
//
// Version
// 01 03/02/2019 Ang Kok Leong
//    Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "Date.h"
#include "Vector.h"
#include <iostream>
#include <iomanip>


//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Prototypes
using namespace std;


//----------------------------------------------------------------------------
// Function implementations

//----------------------------------------------------------------------------
//Constructor of the date class
Date::Date(){
	m_day = 0;
	m_month = 0;
	m_year = 0;
}


//----------------------------------------------------------------------------
//Overloaded Constructor of the date class
Date::Date(int day, int month, int year){
	Date::SetDay(day);
	Date::SetMonth(month);
	Date::SetYear(year);
}


//----------------------------------------------------------------------------
//Deconstructor of the date class

Date::~Date(){}

//----------------------------------------------------------------------------
// Get the day of the date
int Date::GetDay(){
	return m_day;
}

//----------------------------------------------------------------------------
// Get the month of the date
int Date::GetMonth(){
	return m_month;
}

//----------------------------------------------------------------------------
// Get the year of the date
int Date::GetYear(){
	return m_year;
}

//----------------------------------------------------------------------------
// Set the day of the date
void Date::SetDay(int newDay){
	m_day = newDay;
}

//----------------------------------------------------------------------------
// Set the month of the date
void Date::SetMonth(int newMonth){
	m_month = newMonth;
}

//----------------------------------------------------------------------------
// Set the year of the date
void Date::SetYear(int newYear){
	m_year = newYear;
}


//----------------------------------------------------------------------------
// Overloads the operator >> to input the data from the file to Date class

istream & operator >>(istream & input,  Date & D){

	string dateString;

	//retrieve the date only
	getline(input,dateString, ' ');

	vector<string> v;

	string delimiter = "/";
	size_t position = 0;
	string token;

	while ((position = dateString.find(delimiter)) != string::npos){
		token = dateString.substr(0, position);
		v.push_back(token);
		dateString.erase(0,position+delimiter.length());
	}
	//insert the final value into vector
	v.push_back(dateString);

	for (int k = 0; k < v.size(); k++) {
		if (k == 0)
			D.SetDay(stoi(v.at(k)));
		else if (k == 1)
			D.SetMonth(stoi(v.at(k)));
		else if (k == 2)
			D.SetYear(stoi(v.at(k)));
	}

	//reset the stream reader back to original
	input.seekg(0);

	return input;
}


//----------------------------------------------------------------------------
// Overloads the operator << to output individual member from the Date class
ostream & operator <<(ostream & os, Date & D)
{
	os << D.GetDay() << "/" << D.GetMonth() << "/" << D.GetYear();
	return os;
}

//----------------------------------------------------------------------------
// Overloads the operator = to allow  the data from the file to Date class

Date& Date::operator= (const Date& d){
	this->m_day = d.m_day;
	this->m_month = d.m_month;
	this->m_year = d.m_year;

	return *this;
}

//----------------------------------------------------------------------------
// Overloads the operator == to compare the data from both Date object
bool Date::operator== (const Date& d) const
{
	if((this->m_year < d.m_year) ||
		(this->m_year > d.m_year) ||
		(this->m_year == d.m_year && this->m_month < d.m_month) ||
		(this->m_year == d.m_year && this->m_month > d.m_month) ||
		(this->m_year == d.m_year && this->m_month == d.m_month && this->m_day < d.m_day) ||
		(this->m_year == d.m_year && this->m_month == d.m_month && this->m_day > d.m_day))
	{
		return false;

	}else{
		return true;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator != to compare the data from both Date object
bool Date::operator!= (const Date& d) const
{
	if((this->m_year < d.m_year) ||
		(this->m_year > d.m_year) ||
		(this->m_year == d.m_year && this->m_month < d.m_month) ||
		(this->m_year == d.m_year && this->m_month > d.m_month) ||
		(this->m_year == d.m_year && this->m_month == d.m_month && this->m_day < d.m_day) ||
		(this->m_year == d.m_year && this->m_month == d.m_month && this->m_day > d.m_day))
	{
		return true;

	}else{
		return false;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator <= to compare the data from both Date object
bool Date::operator<= (const Date& d) const
{
	if (this->m_year < d.m_year ||
	   (this->m_year == d.m_year && this->m_month < d.m_month) ||
	   (this->m_year == d.m_year && this->m_month == d.m_month && this->m_day < d.m_day) ||
	   (this->m_year == d.m_year && this->m_month == d.m_month && this->m_day == d.m_day) ||
	   (this->m_year == d.m_year && this->m_month == d.m_month) ||
		(this->m_year == d.m_year))
	{
		return true;
	}
	else{
		return false;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator >= to compare the data from both Date object
bool Date::operator>= (const Date& d) const
{
	if (this->m_year > d.m_year ||
	   (this->m_year == d.m_year && this->m_month > d.m_month) ||
	   (this->m_year == d.m_year && this->m_month == d.m_month && this->m_day > d.m_day) ||
	   (this->m_year == d.m_year && this->m_month == d.m_month && this->m_day == d.m_day) ||
	   (this->m_year == d.m_year && this->m_month == d.m_month) ||
		(this->m_year == d.m_year))
	{
		return true;
	}
	else{
		return false;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator < to compare the data from both Date object
bool Date::operator< (const Date& d) const
{
	if (this->m_year < d.m_year ||
	   (this->m_year == d.m_year && this->m_month < d.m_month) ||
	   (this->m_year == d.m_year && this->m_month == d.m_month && this->m_day < d.m_day))
	{
		return true;
	}
	else{
		return false;
	}
}

//----------------------------------------------------------------------------
// Overloads the operator > to compare the data from both Date object
bool Date::operator> (const Date& d) const
{
	if (this->m_year > d.m_year ||
	   (this->m_year == d.m_year && this->m_month > d.m_month) ||
	   (this->m_year == d.m_year && this->m_month == d.m_month && this->m_day > d.m_day))
	{
		return true;
	}
	else{
		return false;
	}
}

