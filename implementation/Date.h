// Date.h

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "Vector.h"

using namespace std;

/**
 * @class Date
 * @brief  Store information about date
 *
 * Date class is used to store day, month, year in numeric form
 *
 *
 * @author Ang Kok Leong
 * @version 01
 * @date 03/02/2019 Ang Kok Leong, Started
 *
 *
 * @todo
 *
 * @bug
 */


class Date{

public:

	/**
	 * @brief  Constructor for Date class
	 *
	 * This constructor creates the date class and upon creation, all members in this class are
	 * initialize with either 0 or "".
	 */
	Date();

	/**
	 * @brief  Overloaded Constructor for Date class
	 *
	 * This constructor creates the date class and upon creation all members in this class are
	 * initialize with user specified day, month and year.
	 *
	 * @param  day - day of the Date
	 * @param  month - month of the Date
	 * @param  year - year of the Date
	 *
	 */
	Date(int day, int month, int year);

	/**
	 * @brief  Destructor for Date class
	 *
	 * This destructor destroys the Date class
	 *
	 */

	virtual ~Date();

	/**
	 * @brief  Returns the day in the date object
	 *
	 * This function returns the integer data type of day from the date object.
	 *
	 * @return m_day - the day of the date as integer datatype
	 */
	int GetDay();

	/**
	 * @brief  Returns the month in the date object
	 *
	 * This function returns the string datatype of the month from the date object
	 *
	 * @return m_month - int datatype for month of date object
	 */
	int GetMonth();


	/**
	 * @brief  Returns the year in the date object
	 *
	 *This function returns the year of the date object in integer format
	 *
	 * @return m_year - year of the date object
	 */
	int GetYear();

	/**
	 * @brief  Set the day of the date
	 *
	 * A mutator which reassigned the value of the day for the date object
	 *
	 * @param  newDay - Day of the date
	 * @return void
	 */
	void SetDay(int newDay);

	/**
	 * @brief  Set the month of the date
	 *
	 * A mutator that set the month in the date object
	 *
	 * @param  newMonth - The month from the date
	 * @return void
	 */
	void SetMonth(int newMonth);

	/**
	 * @brief  Set the year of the date
	 *
	 * A mutator that set the year in the date object
	 *
	 * @param  newYear - The year from the date
	 * @return void
	 */
	void SetYear(int newYear);



	/**
	 * @brief  Overloaded operator = for Date class
	 *
	 * Allows assigning to another Date object
	 *
	 * @param d - Date object
	 * @return Date Object
	 */
	Date& operator= (const Date& d);

	/**
	 * @brief  Overloaded operator == for Date class
	 *
	 * Allows comparison between two Date object
	 *
	 * @param d - Date object
	 * @return boolean TRUE/FALSE result of both object comparison
	 */
	bool operator== (const Date& d) const;

	/**
	 * @brief  Overloaded operator != for Date class
	 *
	 * Allows comparison between two Date object
	 *
	 * @param d - Date object
	 * @return boolean TRUE/FALSE result of both object comparison
	 */
	bool operator!= (const Date& d) const;

	/**
	 * @brief  Overloaded operator <= for Date class
	 *
	 * Allows comparison between two Date object
	 *
	 * @param d - Date object
	 * @return boolean TRUE/FALSE result of both object comparison
	 */
	bool operator<= (const Date& d) const;

	/**
	 * @brief  Overloaded operator < for Date class
	 *
	 * Allows comparison between two Date object
	 *
	 * @param d - Date object
	 * @return boolean TRUE/FALSE result of both object comparison
	 */
	bool operator< (const Date& d) const;

	/**
	 * @brief  Overloaded operator >= for Date class
	 *
	 * Allows comparison between two Date object
	 *
	 * @param d - Date object
	 * @return boolean TRUE/FALSE result of both object comparison
	 */
	bool operator>= (const Date& d) const;


	/**
	 * @brief  Overloaded operator > for Date class
	 *
	 * Allows comparison between two Date object
	 *
	 * @param d - Date object
	 * @return boolean TRUE/FALSE result of both object comparison
	 */
	bool operator> (const Date& d) const;



private:
	int m_day;
	int m_month;
	int m_year;
};

/**
 * @brief  Overloaded operator >> for Date class
 *
 * Allows customize insertion of data into Date class
 *
 * @param input - input stream
 * @param D - Date object
 * @return istream - input stream from the calling class Date
 */
istream & operator >>(istream & input, Date & D);


/**
 * @brief  Overloaded operator << for Date class
 *
 * Allows customize insertion of data into Date class
 *
 * @param os - output stream
 * @param D - Date object
 * @return ostream - output stream from the calling class Date
 */
ostream & operator <<(ostream & os, Date & D);



//overload the operators


#endif
