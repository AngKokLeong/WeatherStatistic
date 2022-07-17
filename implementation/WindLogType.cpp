// WindLogType.cpp
//
// Version
// 01 03/02/2019 Ang Kok Leong
//    Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes
#include "WindLogType.h"
#include <string>

//----------------------------------------------------------------------------
// Global variables/defines

using namespace std;

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

//----------------------------------------------------------------------------
//Constructor of the WindLogType class
WindLogType::WindLogType() {}

//----------------------------------------------------------------------------
//Deconstructor of the WindLogType class
WindLogType::~WindLogType() {}


//----------------------------------------------------------------------------
//Set the m_date in the WindLogType object
void WindLogType::SetDate(Date newDate){
	m_date = newDate;
}

//----------------------------------------------------------------------------
//Returns the m_date in WindLogType object
Date WindLogType::GetDate(){
	return m_date;
}

//----------------------------------------------------------------------------
//Returns the m_time in WindLogType object
Time WindLogType::GetTime(){
	return m_time;
}

//----------------------------------------------------------------------------
//Returns the m_time in WindLogType object
void WindLogType::SetTime(Time newTime){
	m_time = newTime;
}


//----------------------------------------------------------------------------
//Set the m_weather in the WindLogType object
void WindLogType::SetWeather(Weather newWeather){
	m_weather = newWeather;
}

//----------------------------------------------------------------------------
//Returns the m_weather in WindLogType object
Weather WindLogType::GetWeather(){
	return m_weather;
}

//----------------------------------------------------------------------------
//Overloaded operator for WindLogType class
istream & operator>>(istream & input, WindLogType & W){

	Weather weatherObj;
	Date dateObj;
	Time timeObj;

	input >> dateObj >> timeObj >> weatherObj;

	W.SetDate(dateObj);
	W.SetTime(timeObj);
	W.SetWeather(weatherObj);

	return input;

}

/*
bool WindLogType::operator== (const WindLogType& w) const{

	if (this->m_date == w.m_date && this->m_time == w.m_time) {
		return true;
	}

	return false;
}
*/
