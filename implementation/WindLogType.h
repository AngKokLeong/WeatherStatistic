
#include "Weather.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef WINDLOGTYPE_H_
#define WINDLOGTYPE_H_

/**
 * @class WindLogType
 * @brief  A class which contains Date, Time and Weather classes
 *
 * WindLogType class stores Date, Time and Weather classes to capture data from csv file
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

class WindLogType {
public:

	/**
	 * @brief  Constructor for WindLogType class
	 *
	 * This constructor creates an object using WindLogType class.
	 */
	WindLogType();

	/**
	 * @brief  Destructor for WindLogType class
	 *
	 * This destructor destroy the WindLogType object.
	 */
	virtual ~WindLogType();

	/**
	 * @brief  Set the m_weather in the WindLogType object
	 *
	 * This Mutator changes the object of m_weather to a new object.
	 *
	 * @return void
	 */
	void SetWeather(Weather newWeather);

	/**
	 * @brief  Returns the m_weather in WindLogType object
	 *
	 * This accessor returns the object of m_weather.
	 *
	 * @return m_weather - the Weather object in WindLogType class
	 */
	Weather GetWeather();

	/**
	 * @brief  Set the m_date in the WindLogType object
	 *
	 * This Mutator changes the object of m_date to a new object.
	 *
	 * @return void
	 */
	void SetDate(Date newDate);

	/**
	 * @brief  Returns the m_date in WindLogType object
	 *
	 * This accessor returns the object of m_date.
	 *
	 * @return m_date - the Date object in WindLogType class
	 */
	Date GetDate();

	/**
	 * @brief  Returns the m_time in WindLogType object
	 *
	 * This accessor returns the object of m_time.
	 *
	 * @return m_time - the Time object in WindLogType class
	 */
	Time GetTime();

	/**
	* @brief  Set the m_time in WindLogType object
	*
	* This mutator set the object of m_time.
	*
	* @return void
	*/
	void SetTime(Time newTime);




private:
	Date m_date;
	Time m_time;
	Weather m_weather;

};

/**
 * @brief  Overloaded the operator >> in WindLogType class
 *
 * Overloaded this operator >> to insert data to three different members in WindLogType classes
 *
 * @return istream - input stream
 */
istream & operator>>(istream & input, WindLogType & W);


#endif
