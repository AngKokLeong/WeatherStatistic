// Program.cpp
//
// Version
// 01 03/02/2019 Ang Kok Leong
//    Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Utility.h"
#include "Program.h"

//----------------------------------------------------------------------------
// Global variables/defines

using namespace std;

//----------------------------------------------------------------------------
// Prototypes


//----------------------------------------------------------------------------
// Function implementations

//----------------------------------------------------------------------------
//Constructor of the Program class
Program::Program() {}

//----------------------------------------------------------------------------
//Deconstructor of the Program class
Program::~Program() {

}

//----------------------------------------------------------------------------
//Prints the instruction to user on how to navigate this program
void Program::displayMenu(){
	cout << "Menu" << endl;
	cout << "==========================================================" << endl;
	cout << "1. Average wind speed and average ambient air temperature for a specified month and year." << endl;
	cout << "2. Average wind speed and average ambient air temperature for each month of a specified year." << endl;
	cout << "3. Total solar radiation in kWh/m^2 for each month of a specified year." << endl;
	cout << "4. Output to a file with average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m^2 for each month of a specified year." << endl;
	cout << "5. Highest Solar Radiation at a specific time given the day." << endl;
	cout << "6. Exit" << endl;
}

//----------------------------------------------------------------------------
//Print information about average wind speed and average ambient air temperature for the specific month and year

void Program::printAverageWindSpeedAndAmbientAirTemperaturePerMonth(int month, int year){

	float totalWindSpeed = m_data.calculateWindSpeedRecordPerMonth(month, year);
	float totalAmbientAirTemperature = m_data.calculateAmbientAirTemperatureRecordPerMonth(month, year);
	float averageWindSpeed = m_data.calculateAverageWindSpeedPerMonth(month, year);
	float averageAmbientAirTemperature = m_data.calculateAverageAmbientAirTemperaturePerMonth(month, year);

	cout << fixed << setprecision(1);
	if(totalWindSpeed > 0 && totalAmbientAirTemperature > 0){
		cout << m_util.GetMonthInString(month) << " " << year << ": " << averageWindSpeed << " km/h, " << averageAmbientAirTemperature << " degrees C" << endl;
		cout << endl << endl;
	}else if(totalWindSpeed == 0 && totalAmbientAirTemperature == 0){
		cout << m_util.GetMonthInString(month) << " " << year << ": " << "No Data" << endl << endl << endl;
	}

}

//----------------------------------------------------------------------------
//Print information about average wind speed and average ambient air temperature for the specific year

void Program::printAverageWindSpeedAndAmbientAirTemperaturePerYear(int year){

	cout << year << endl;
	cout << fixed << setprecision(1);

	for(int i = 1; i <= 12; i++){
		float totalWindSpeed = m_data.calculateTotalWindSpeedPerMonth(i, year);
		float totalAmbientAirTemperature = m_data.calculateTotalAmbientAirTemperaturePerMonth(i,year);
		float averageWindSpeed = m_data.calculateAverageWindSpeedPerMonth(i, year);
		float averageAmbientAirTemperature = m_data.calculateAverageAmbientAirTemperaturePerMonth(i, year);

		if (totalWindSpeed == 0.0 && totalAmbientAirTemperature == 0.0){
			cout << m_util.GetMonthInString(i) << ": " << "No Data" << endl;
		}else if(totalWindSpeed > 0.0 && totalAmbientAirTemperature > 0.0){
			cout << m_util.GetMonthInString(i) << ": " << averageWindSpeed << " km/h, " << averageAmbientAirTemperature << " degrees C" << endl;
		}
	}
	cout << endl << endl;
}

//----------------------------------------------------------------------------
//Print information about total solar radiation for the specific year

void Program::printTotalSolarRadiationPerYear(int year){
	cout << year << endl;

	cout << fixed << setprecision(1);
	for(int i = 1; i <= 12; i++){
		float totalOfSolarRadiation = m_data.calculateTotalSolarRadiationPerMonth(i, year);

		if(totalOfSolarRadiation == 0.0){
			cout << m_util.GetMonthInString(i) << ": " << "No Data" << endl;
		}else if(totalOfSolarRadiation > 0.0){
			cout << m_util.GetMonthInString(i) << ": " << totalOfSolarRadiation << " kWh/m^2, " << endl;
		}
	}

	cout << endl << endl;
}


void Program::printHighestSolarRadiation(Date &date){

	//call the data function
	float highestSolarRadiation = m_data.calculateHighestSolarRadiation(date);

	cout << "Date: " << date << endl;
	cout << "High solar radiation for the day: " << highestSolarRadiation << " W/m2" << endl << endl;


	cout << "Time:" << endl;
	m_data.printAllTimingOfHighestSolarRadiation(date, highestSolarRadiation);
	cout << endl;
	//print all highest solar radiation
}

//----------------------------------------------------------------------------
//Execute the main program
void Program::execute(){

	m_data.populateData();

	int userInput = 0;

	while(userInput != 6){
		displayMenu();

		cout << "Please key in an option: ";
		cin >> userInput;

		int month, year;
		string date;

		if(userInput == 1){
			cout << "Key in the month and year(month <space> year): " ;
			cin >> month >> year;
			printAverageWindSpeedAndAmbientAirTemperaturePerMonth(month, year);
		}else if(userInput == 2){
			cout << "Key in the year: ";
			cin >> year;
			printAverageWindSpeedAndAmbientAirTemperaturePerYear(year);
		}else if(userInput == 3){
			cout << "Key in the year: ";
			cin >> year;
			printTotalSolarRadiationPerYear(year);
		}else if(userInput == 4){
			cout << "Key in the year: ";
			cin >> year;
			m_data.outputDataToFile(year, "WindTempSolar.csv");
		}else if(userInput == 5){

			cout << "Key in a date(dd/mm/yyyy):";
			cin >> date;

			istringstream dateiss(date);
			Date dateObj;
			dateiss >> dateObj;

			printHighestSolarRadiation(dateObj);

		}else if(userInput == 6){


		}else{
			cout << "Key in a digit within 1 to 6" << endl;
		}

	}
}
