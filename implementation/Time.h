#ifndef TIME_H_
#define TIME_H_

#include <iostream>
using namespace std;


/**
 * @class Time
 * @brief  Store information about time in terms of hours and minutes
 *
 * @author Ang Kok Leong
 * @version 01
 * @date 03/03/2019 Ang Kok Leong, Started
 *
 *
 * @todo
 *
 * @bug
 */

class Time{


public:

	/**
	 * @brief  Constructor for Time class
	 *
	 * This constructor creates the time object and upon creation all members in this class are
	 * Initialise with either 0 or "".
	 */
	Time();


	/**
	 * @brief  Constructor for Time class
	 *
	 * This constructor creates the Time object and upon creation all members in this class are
	 * Initialise with user input of hours and minutes.
	 */
	Time(int hours, int minutes);



	/**
	 * @brief  Destructor for Date class
	 *
	 * This destructor destroys the Time object
	 *
	 */
	virtual ~Time();


	/**
	 * @brief  Returns the hour in the Time object
	 *
	 * This function returns the integer data type for Hour from the time object.
	 *
	 * @return the hour in the Time object as integer datatype
	 */

	int GetHours();


	/**
	 * @brief  Returns the minutes in the Time object
	 *
	 * This function returns the integer data type for Minute from the time object.
	 *
	 * @return the minute in the Time object as integer datatype
	 */
	int GetMinutes();


	/**
	 * @brief  Set the minutes in time
	 *
	 * A mutator which reassigned the value of the minutes for the time object
	 *
	 * @param  minutes - Minutes in time
	 * @return void
	 */
	void SetMinutes(int minutes);

	/**
	 * @brief  Set the hours in time
	 *
	 * A mutator which reassigned the value of the hours for the time object
	 *
	 * @param  hour - Hour in time
	 * @return void
	 */
	void SetHours(int hours);

	/**
	 * @brief  Overloaded operator = for Time class
	 *
	 * Allow assigning Time object to another Time Object
	 *
	 * @param T - Time object
	 * @return Time Object
	 */
	Time& operator= (const Time& t);

	/**
	 * @brief  Overloaded operator == for Time class
	 *
	 * Allows comparison of two Time object
	 *
	 * @param T - Time object
	 * @return boolean TRUE/FALSE
	 */

	bool operator== (const Time& t) const;

	/**
	 * @brief  Overloaded operator != for Time class
	 *
	 * Allows comparison of two Time object
	 *
	 * @param T - Time object
	 * @return boolean TRUE/FALSE
	 */
	bool operator!= (const Time& t) const;

	/**
	 * @brief  Overloaded operator <= for Time class
	 *
	 * Allows comparison of two Time object
	 *
	 * @param T - Time object
	 * @return boolean TRUE/FALSE
	 */

	bool operator<= (const Time& t) const;

	/**
	 * @brief  Overloaded operator < for Time class
	 *
	 * Allows comparison of two Time object
	 *
	 * @param T - Time object
	 * @return boolean TRUE/FALSE
	 */
	bool operator< (const Time& t) const;

	/**
	 * @brief  Overloaded operator >= for Time class
	 *
	 * Allows comparison of two Time object
	 *
	 * @param T - Time object
	 * @return boolean TRUE/FALSE
	 */
	bool operator>= (const Time& t) const;

	/**
	 * @brief  Overloaded operator > for Time class
	 *
	 * Allows comparison of two Time object
	 *
	 * @param T - Time object
	 * @return boolean TRUE/FALSE
	 */
	bool operator> (const Time& t) const;




private:
	int m_hours;
	int m_minutes;

};

/**
 * @brief  Overloaded operator >> for Time class
 *
 * Allows customize insertion of data into Time class
 *
 * @param input - input stream
 * @param T - Time object
 * @return istream - input stream from the calling class Time
 */
istream & operator >>(istream & input, Time & T);


/**
 * @brief  Overloaded operator << for Time class
 *
 * Allows customize insertion of data into Time class
 *
 * @param os - output stream
 * @param T - Time object
 * @return ostream - output stream from the calling class Time
 */
ostream & operator <<(ostream & os, Time & T);


#endif /* TIME_H_ */
