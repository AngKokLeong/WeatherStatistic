#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include "WindLogType.h"
#include "Utility.h"
#include "BST.h"
#include "Date.h"
#include <array>


/**
 * @class Data
 * @brief A class that contains the data manipulation of csv data and IO of csv data
 *
 *	This class that contains the data manipulation of csv data and IO of csv data
 *
 * @author Ang Kok Leong
 * @version 01
 * @date 10/03/2019 Ang Kok Leong, Started
 *
 *
 * @todo
 *
 */


class Data {

public:

	/**
	 * @brief  Constructor for Data class
	 *
	 *	This constructor create an object from Data class
	 *
	 */
	Data();

	/**
	 * @brief  Destructor for Data class
	 *
	 *	This destructor destroy the object from Data class
	 *
	 */
	virtual ~Data();


	/**
	 * @brief populate data into a vector by specifying a file name
	 *
	 * This function populates all related data from source file using the given file name
	 *
	 * @return void
	 */
	void populateData();

	/**
	 * @brief Verify the existence of the data in the binary tree using month and year
	 *
	 * This function verify the binary tree for the matching data using month and year as a reference
	 *
	 * @return bool return true if there is a matching data with month and year else false
	 */
	bool checkExistenceOfDataUsingMonthAndYear(int month, int year);

	/**
	 * @brief Check for the existence of data in binary tree using year
	 *
	 * This function verify the binary tree for the matching data using year as a reference
	 *
	 * @return bool return true if there is a matching data with year else return false
	 */
	bool checkExistenceOfDataUsingYear(int year);

	/**
	 * @brief Calculate the total wind speed per month
	 *
	 * This function calculate the total wind speed per month using month and year
	 *
	 * @return sumOfWindSpeed - total wind speed per month
	 */
	float calculateTotalWindSpeedPerMonth(int month, int year);

	/**
	 * @brief Calculate the total ambient air temperature per month
	 *
	 * This function calculate the total ambient air temperature per month using month and year
	 *
	 * @return sumOfAmbientAirTemperature - total ambient air temperature per month
	 */
	float calculateTotalAmbientAirTemperaturePerMonth(int month, int year);


	/**
	 * @brief Calculate the total solar radiation per month
	 *
	 * This function calculate the total solar radiation per month using month and year
	 *
	 * @return sumOfSolarRadiation - total solar radiation per month
	 */
	float calculateTotalSolarRadiationPerMonth(int month, int year);

	/**
	 * @brief Calculate the total number of record for wind speed per month
	 *
	 * This function calculate the total number of record for wind speed per month using month and year
	 *
	 * @return numberOfWindSpeedRecord - total number of record for wind speed per month
	 */
	int calculateWindSpeedRecordPerMonth(int month, int year);

	/**
	 * @brief Calculate the total number of record for ambient air temperature per month
	 *
	 * This function calculate the total number of record for ambient air temperature per month using month and year
	 *
	 * @return numberOfAmbientAirTemperatureRecord - total number of record for ambient air temperature per month
	 */
	int calculateAmbientAirTemperatureRecordPerMonth(int month, int year);

	/**
	 * @brief Calculate the total number of record for solar radiation per month
	 *
	 * This function calculate the total number of record for solar radiation per month using month and year
	 *
	 * @return numberOfAmbientAirTemperatureRecord - total number of record for solar radiation per month
	 */
	int calculateSolarRadiationRecordPerMonth(int month, int year);

	/**
	 * @brief Calculate the average wind speed per month
	 *
	 * This function calculate the average wind speed per month using month and year
	 *
	 * @return AverageWindSpeed - Average wind speed per month
	 */
	float calculateAverageWindSpeedPerMonth(int month, int year);

	/**
	 * @brief Calculate the average ambient air temperature per month
	 *
	 * This function calculate the average ambient air temperature per month using month and year
	 *
	 * @return AverageAmbientAirTemperature - Average ambient air temperature per month
	 */
	float calculateAverageAmbientAirTemperaturePerMonth(int month, int year);

	/**
	 * @brief Calculate the average solar radiation per month
	 *
	 * This function calculate the average solar radiation per month using month and year
	 *
	 * @return AverageSolarRadiation - Average solar radiation per month
	 */
	float calculateAverageSolarRadiationPerMonth(int month, int year);

	/**
	 * @brief Calculate the average wind speed per year
	 *
	 * This function calculate the average wind speed per year
	 *
	 * @return AverageWindSpeed - Average solar radiation per year
	 */
	float calculateAverageWindSpeedPerYear(int year);

	/**
	 * @brief Calculate the average ambient air temperature per year
	 *
	 * This function calculate the average ambient air temperature per year
	 *
	 * @return AverageAmbientAirTemperature - Average ambient air temperature per year
	 */
	float calculateAverageAmbientAirTemperaturePerYear(int year);

	/**
	 * @brief Calculate the total solar radiation per year
	 *
	 * This function calculate the total solar radiation per year
	 *
	 * @return totalSolarRadiation - Total solar radiation per year
	 */
	float calculateTotalSolarRadiationPerYear(int year);


	/**
	 * @brief Output wind speed, solar radiation, ambient air temperature for that given year to a file
	 *
	 * This function output the file with the following details (wind speed, solar radiation, ambient air temperature) to a file
	 *
	 * @return void
	 */
	void outputDataToFile(int year, string fileName);


	/**
	 * @brief Calculate highest solar radiation for the given date
	 *
	 * This function output the highest solar radiation
	 *
	 * @return solar_radiation - return highest solar radiation in a given date
	 */
	float calculateHighestSolarRadiation(Date &date);


	/**
	 * @brief Display all time with the given highest solar radiation
	 *
	 * This function search the solar radiation in the map with the highest solar radiation of the given date
	 *
	 * @return void
	 */
	void printAllTimingOfHighestSolarRadiation(Date &date, float highestSolarRadiation);


	/**
	 * @brief Check if the binary tree is empty
	 *
	 * This function returns boolean value whether binary tree is empty
	 *
	 * @return boolean TRUE/FALSE
	 */
	bool checkBinaryTreeIsEmpty();

	/**
	 * @brief Check if map is empty
	 *
	 * This function returns boolean value whether map is empty
	 *
	 * @return boolean TRUE/FALSE
	 */
	bool checkMapIsEmpty();



private:
	ifstream m_infile_reader;
	ifstream m_infile;
	ofstream m_ofile;
	WindLogType m_windLogType;
	Utility m_util;
	list<string> m_file_list;
	BST<Date> m_date_tree;
	map<int, list<WindLogType> > m_data_map;
	Vector<int> m_year_vec;
};

#endif
