#ifndef WEATHER_H_
#define WEATHER_H_

#include <iostream>
#include <fstream>
#include "Utility.h"

using namespace std;


/**
 * @class Weather
 * @brief  Store information about Weather
 *
 * Weather is used to store information about wind speed, ambient air temperature, solar radiation
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
class Weather {
public:

	/**
	 * @brief  Constructor for Weather class
	 *
	 * This constructor creates an object using Weather class.
	 */
	Weather();
	/**
	 * @brief  Destructor for Weather class
	 *
	 * This destructor destroy the Weather object.
	 */
	virtual ~Weather();

	/**
	 * @brief  Set the m_wind_speed in the Weather object
	 *
	 * This Mutator changes the value of m_wind_speed to a new value.
	 *
	 * @return void
	 */
	void SetWindSpeed(float newWindSpeed);

	/**
	 * @brief  Returns the m_wind_speed in Weather object
	 *
	 * This accessor returns the value of m_wind_speed.
	 *
	 * @return m_wind_speed - the wind speed in Weather class
	 */
	float GetWindSpeed();

	/**
	 * @brief  Set the m_solar_radiation in Weather object
	 *
	 * This Mutator changes the value of m_solar_radiation to a new value.
	 *
	 * @return void
	 */
	void SetSolarRadiation(float newSolarRadiation);

	/**
	 * @brief  Returns the m_solar_radiation in Weather object
	 *
	 * This accessor retrieve the m_solar_radiation
	 *
	 * @return m_solar_radiation - the solar radiation of Weather class
	 */
	float GetSolarRadiation();

	/**
	 * @brief  Set the m_temperature in  Weather object
	 *
	 * This Mutator changes the value of m_temperature to a new value.
	 *
	 * @return void
	 */
	void SetTemperature(float newTemperature);

	/**
	 * @brief	Return the m_temperature in Weather object
	 *
	 * This Mutator changes the value of m_temperature to a new value.
	 *
	 * @return m_temperature - the air ambient temperature in Weather class
	 */
	float GetTemperature();

private:
	float m_wind_speed;
	float m_solar_radiation;
	float m_temperature;

};

/**
 * @brief  Overloaded operator >> for Weather class
 *
 * Allows customize insertion of data into Weather class
 *
 * @param input - input stream
 * @param W - Weather object
 * @return istream - input stream from the calling class WindLogType
 */
istream & operator >>(istream & input, Weather & W);

/**
 * @brief  Overloaded operator << for Weather class
 *
 * Allows customize output of data into Weather class
 *
 * @param input - input stream
 * @param W - Weather object
 * @return istream - input stream from the calling class WindLogType
 */
ostream & operator <<(ostream & output, Weather & W);



#endif /* WEATHER_H_ */
