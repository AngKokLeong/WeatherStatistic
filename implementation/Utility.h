#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>
#include <iostream>
#include <sstream>
#include "Vector.h"

using namespace std;

/**
 * @class Utility
 * @brief A class that contains commonly used methods
 *
 *	This Utility class contains methods that are commonly used
 *
 * @author Ang Kok Leong
 * @version 01
 * @date 10/03/2019 Ang Kok Leong, Started
 *
 *
 * @todo
 *
 */

class Utility {
public:

	/**
	 * @brief  Constructor for Utility class
	 *
	 *	This constructor create an object from Utility class
	 *
	 */
	Utility();

	/**
	 * @brief  Destructor for Utility class
	 *
	 *	This destructor destroy the object from Utility class
	 *
	 */
	virtual ~Utility();

	/**
	 * @brief  Output a string by skipping the delimiter based on the position of the string in the given data
	 *
	 *	Output a string by skipping the delimiter based on the position of the string in the given data
	 *
	 * @return result - a string will be the output of this function
	 */
	string GetDataFromARow(string data, string delimiter, string::size_type position);

	/**
	 * @brief  Output the full name of the month based on the given numeric digit of the month
	 *
	 *	Output the full name of the month based on the given numeric digit of the month
	 *
	 * @return result - a string will be the output of this function
	 */
	string GetMonthInString(int month);

private:

};

#endif /* UTILITY_H_ */
