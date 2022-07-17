#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "WindLogType.h"
#include "Utility.h"
#include "Data.h"

using namespace std;


/**
 * @class Program
 * @brief A class that acts like a main program
 *
 *	This Program class is created to emulate the main method
 *
 * @author Ang Kok Leong
 * @version 01
 * @date 10/03/2019 Ang Kok Leong, Started
 *
 *
 * @todo
 *
 */


class Program {
public:

	/**
	 * @brief  Constructor for Program class
	 *
	 *	This constructor create an object from Program class
	 *
	 */
	Program();

	/**
	 * @brief  Destructor for Program class
	 *
	 *	This destructor destroy the object from Program class
	 *
	 */
	virtual ~Program();


	/**
	 * @brief  Print instruction to user
	 *
	 * This function print the instruction to user to inform them how to navigate this program.
	 *
	 * @return void
	 */
	void displayMenu();


	/**
	 * @brief  Print information about average wind speed and average ambient air temperature for the specific month and year
	 *
	 * Prints the data about average wind speed and average ambient air temperature with the specific month and year
	 *
	 * @return void
	 */
	void printAverageWindSpeedAndAmbientAirTemperaturePerMonth(int month, int year);

	/**
	 * @brief  Print information about average wind speed and average ambient air temperature for the specific year
	 *
	 * Prints the data about average wind speed and average ambient air temperature with the specific year
	 *
	 * @return void
	 */
	void printAverageWindSpeedAndAmbientAirTemperaturePerYear(int year);

	/**
	 * @brief  Print information about total solar radiation for the specific year
	 *
	 * Prints the data about total solar radiation with the specific year
	 *
	 * @return void
	 */
	void printTotalSolarRadiationPerYear(int year);


	/**
	 * @brief  Print information about highest solar radiation for the specific date
	 *
	 * Prints the data about highest solar radiation with the specific date
	 *
	 * @return void
	 */
	void printHighestSolarRadiation(Date &date);

	/**
	 * @brief Execute the main program
	 *
	 * Execute the main program
	 *
	 * @return void
	 */
	void execute();

private:
	Utility m_util;
	Data m_data;
};

#endif
