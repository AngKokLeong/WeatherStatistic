// Weather.cpp
//
// Version
// 01 03/02/2019 Ang Kok Leong
//    Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes
#include "Weather.h"
#include "Utility.h"
#include <iostream>
#include <string>

//----------------------------------------------------------------------------
// Global variables/defines

using namespace std;

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

//----------------------------------------------------------------------------
//Constructor of the Weather class

Weather::Weather() {
	// TODO Auto-generated constructor stub
	m_wind_speed = 0.0;
	m_solar_radiation = 0.0;
	m_temperature = 0.0;
}

//----------------------------------------------------------------------------
//Destructor of the Weather class

Weather::~Weather() {
	// TODO Auto-generated destructor stub
}

//----------------------------------------------------------------------------
//Set the m_wind_speed in the Weather object
void Weather::SetWindSpeed(float newWindSpeed){
	m_wind_speed = newWindSpeed;
}

//----------------------------------------------------------------------------
//Get the m_wind_speed in the Weather object
float Weather::GetWindSpeed(){
	return m_wind_speed;
}


//----------------------------------------------------------------------------
//Set the m_solar_radiation in the Weather object
void Weather::SetSolarRadiation(float newSolarRadiation){
	m_solar_radiation = newSolarRadiation;
}

//----------------------------------------------------------------------------
//Get the m_solar_radiation in the Weather object
float Weather::GetSolarRadiation(){
	return m_solar_radiation;
}


//----------------------------------------------------------------------------
//Set the m_temperature in the Weather object
void Weather::SetTemperature(float newTemperature){
	m_temperature = newTemperature;
}

//----------------------------------------------------------------------------
//Get the m_temperature in the Weather object
float Weather::GetTemperature(){
	return m_temperature;
}

//----------------------------------------------------------------------------
//Overloaded operator for Weather class
istream & operator>>(istream & input, Weather & W){

	Utility utilObj;

	string data;
	//retrieve a single row of data from csv
	getline(input, data, '\n');

	//retrieve the data column by specifying the number of the column starting from the left of the
	//excel spreadsheet counting from 0
	string wind_speed = utilObj.GetDataFromARow(data, ",", 10);
	string solar_radiation = utilObj.GetDataFromARow(data, ",", 11);
	string temperature = utilObj.GetDataFromARow(data, ",", 17);

	size_t findwindspeedNA = wind_speed.find("N/A");

	if (findwindspeedNA == string::npos)
		W.SetWindSpeed(stof(wind_speed));
	else
		W.SetWindSpeed(0.0);

	size_t findsolarradiationNA = solar_radiation.find("N/A");

	if (findsolarradiationNA == string::npos)
		W.SetSolarRadiation(stof(solar_radiation));
	else
		W.SetSolarRadiation(0.0);

	size_t findtemperatureNA = temperature.find("N/A");

	if(findtemperatureNA == string::npos)
		W.SetTemperature(stof(temperature));
	else
		W.SetTemperature(0.0);


	return input;
}

//----------------------------------------------------------------------------
//Overloaded operator for Weather class
ostream & operator <<(ostream & output, Weather & W){
	output << "Wind Speed: " << W.GetWindSpeed() << "Solar Radiation: " <<W.GetSolarRadiation() << "Temperature: " <<W.GetTemperature() ;
	return output;
}
