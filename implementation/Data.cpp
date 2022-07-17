// Data.cpp
//
// Version
// 01 03/02/2019 Ang Kok Leong
//    Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <list>

#include "BST.h"
#include "Time.h"
#include "Date.h"
#include "WindLogType.h"
#include "Utility.h"
#include "Data.h"

//----------------------------------------------------------------------------
//Constructor of the Data class
Data::Data() {}

//----------------------------------------------------------------------------
//Destructor of the Data class
Data::~Data() {}

//----------------------------------------------------------------------------
//populate data into a vector by specifying a file name
void Data::populateData() {

	m_infile_reader.open("data/met_index.txt");
	string filename;

	while (!m_infile_reader.eof()) {
		getline(m_infile_reader, filename, '\n');

		filename = "data/" + filename;

		m_file_list.push_back(filename);
	}

	m_infile_reader.close();

	list<string>::iterator list_iterator;


	list<Date> dateList;
	list<WindLogType> dataList;
	list<WindLogType> yearList;


	for(list_iterator = m_file_list.begin(); list_iterator != m_file_list.end(); list_iterator++){

		string filename = *list_iterator;

		m_infile.open(filename.c_str());

		m_infile.ignore(999, '\n');

		string newRowOfData;
		cout << "Loading " << filename << endl;

		Date previousDateObj;
		Time previousTimeObj;
		int year = 0;

		while (!m_infile.eof()) {
			getline(m_infile, newRowOfData, '\n');

			if (newRowOfData != "") {
				istringstream dataiss(newRowOfData);
				dataiss >> m_windLogType;

				if(previousDateObj != m_windLogType.GetDate()){
					Date dateObj = m_windLogType.GetDate();
					m_date_tree.insert(dateObj);

					previousDateObj = m_windLogType.GetDate();
				}

				dataList.push_back(m_windLogType);

				if (year != m_windLogType.GetDate().GetYear()){
					bool status = false;

					for(int i=0;i<m_year_vec.getCount(); i++){
						if(m_year_vec.at(i) == m_windLogType.GetDate().GetYear()){
							status = true;
							break;
						}
					}

					if(status == false){
						m_year_vec.push_back(m_windLogType.GetDate().GetYear());
					}
					year = m_windLogType.GetDate().GetYear();
				}
			}

			if (m_infile.eof()) {
				cout << "Loading of " << filename << " has finished" << endl;
			}

		}

		m_infile.close();
	}

	cout << "Processing data into map data structure ...." << endl;

	list<WindLogType>::iterator data_iterator;

	for(int i=0; i<m_year_vec.getCount(); i++){
		for(data_iterator = dataList.begin(); data_iterator != dataList.end(); data_iterator++){
			if (m_year_vec.at(i) == data_iterator->GetDate().GetYear()){
				WindLogType windLogTypeObj = *data_iterator;
				yearList.push_back(windLogTypeObj);
			}
		}
		m_data_map.insert(pair<int, list<WindLogType> >(m_year_vec.at(i), yearList));
	}

	cout << "Completed process of data into map data structure." << endl;
}


//----------------------------------------------------------------------------
//Check whether the month and year exist in the binary tree after data population
bool Data::checkExistenceOfDataUsingMonthAndYear(int month, int year) {
	for (int day = 1; day <= 31; day++) {
		Date dateObj(day, month, year);

		if (m_date_tree.search(dateObj) == true)
			return true;
	}
	return false;
}

//----------------------------------------------------------------------------
//Check whether the year exist in the binary tree after data population
bool Data::checkExistenceOfDataUsingYear(int year) {

	for (int month = 1; month <= 12; month++) {
		if(checkExistenceOfDataUsingMonthAndYear(month, year) == true)
			return true;
	}

	return false;
}

//----------------------------------------------------------------------------
//Calculate the total wind speed per month
float Data::calculateTotalWindSpeedPerMonth(int month, int year) {

	float sumOfWindSpeed = 0.0;

	if (checkExistenceOfDataUsingMonthAndYear(month, year) == true) {
		map<int, list<WindLogType> >::iterator it;
		list<WindLogType>::iterator data_iterator;
		for (it = m_data_map.begin(); it != m_data_map.end(); ++it) {
			if(it->first == year){
				for(data_iterator = it->second.begin(); data_iterator != it->second.end(); data_iterator++){
					if ((data_iterator->GetDate().GetMonth() == month) && (data_iterator->GetDate().GetYear() == year))
						sumOfWindSpeed += data_iterator->GetWeather().GetWindSpeed();
				}
			}
		}
	}

	return sumOfWindSpeed;
}

//----------------------------------------------------------------------------
//Calculate the total ambient air temperature per month
float Data::calculateTotalAmbientAirTemperaturePerMonth(int month, int year) {

	float sumOfAmbientAirTemperature = 0.0;

	if (checkExistenceOfDataUsingMonthAndYear(month, year) == true) {
		map<int, list<WindLogType> >::iterator it;

		list<WindLogType>::iterator data_iterator;
		for (it = m_data_map.begin(); it != m_data_map.end(); ++it) {
			if(it->first == year){
				for(data_iterator = it->second.begin(); data_iterator != it->second.end(); data_iterator++){
					if ((data_iterator->GetDate().GetMonth() == month) && (data_iterator->GetDate().GetYear() == year))
						sumOfAmbientAirTemperature += data_iterator->GetWeather().GetTemperature();
				}
			}
		}
	}

	return sumOfAmbientAirTemperature;
}

//----------------------------------------------------------------------------
//Calculate the total solar radiation per month
float Data::calculateTotalSolarRadiationPerMonth(int month, int year) {

	float sumOfSolarRadiation = 0.0;

	if (checkExistenceOfDataUsingMonthAndYear(month, year) == true) {
		map<int, list<WindLogType> >::iterator it;

		list<WindLogType>::iterator data_iterator;
		for (it = m_data_map.begin(); it != m_data_map.end(); ++it) {
			if(it->first == year){
				for(data_iterator = it->second.begin(); data_iterator != it->second.end(); data_iterator++){
					if ((data_iterator->GetDate().GetMonth() == month) && (data_iterator->GetDate().GetYear() == year))
						if(data_iterator->GetWeather().GetSolarRadiation() >= 100.0)
							sumOfSolarRadiation += data_iterator->GetWeather().GetSolarRadiation();
				}
			}
		}
	}

	if(sumOfSolarRadiation == 0.0)
		return sumOfSolarRadiation;

	return (sumOfSolarRadiation / 1000);
}

//----------------------------------------------------------------------------
//Calculate the total number of record for wind speed per month
int Data::calculateWindSpeedRecordPerMonth(int month, int year) {
	int numberOfWindSpeedRecord = 0;

	if (checkExistenceOfDataUsingMonthAndYear(month, year) == true) {
		map<int, list<WindLogType> >::iterator it;

		list<WindLogType>::iterator data_iterator;
		for (it = m_data_map.begin(); it != m_data_map.end(); ++it) {
			if(it->first == year){
				for(data_iterator = it->second.begin(); data_iterator != it->second.end(); data_iterator++){
					if ((data_iterator->GetDate().GetMonth() == month) && (data_iterator->GetDate().GetYear() == year))
						if(data_iterator->GetWeather().GetWindSpeed() >= 0.0 || data_iterator->GetWeather().GetWindSpeed() <= 0.0)
							++numberOfWindSpeedRecord;
				}
			}
		}
	}

	return numberOfWindSpeedRecord;
}

//----------------------------------------------------------------------------
//Calculate the total number of record for ambient air temperature per month
int Data::calculateAmbientAirTemperatureRecordPerMonth(int month, int year) {

	int numberOfAmbientAirTemperatureRecord = 0;

	if (checkExistenceOfDataUsingMonthAndYear(month, year) == true) {
		map<int, list<WindLogType> >::iterator it;

		list<WindLogType>::iterator data_iterator;
		for (it = m_data_map.begin(); it != m_data_map.end(); ++it) {
			if(it->first == year){
				for(data_iterator = it->second.begin(); data_iterator != it->second.end(); data_iterator++){
					if ((data_iterator->GetDate().GetMonth() == month) && (data_iterator->GetDate().GetYear() == year))
						if(data_iterator->GetWeather().GetTemperature() >= 0.0 || data_iterator->GetWeather().GetTemperature() <= 0.0)
							++numberOfAmbientAirTemperatureRecord;
				}
			}
		}
	}

	return numberOfAmbientAirTemperatureRecord;
}

//----------------------------------------------------------------------------
//Calculate the total number of record for solar radiation per month
int Data::calculateSolarRadiationRecordPerMonth(int month, int year) {
	int numberOfSolarRadiationRecord = 0;

	if (checkExistenceOfDataUsingMonthAndYear(month, year) == true) {
		map<int, list<WindLogType> >::iterator it;

		list<WindLogType>::iterator data_iterator;
		for (it = m_data_map.begin(); it != m_data_map.end(); ++it) {
			if(it->first == year){
				for(data_iterator = it->second.begin(); data_iterator != it->second.end(); data_iterator++){
					if ((data_iterator->GetDate().GetMonth() == month) && (data_iterator->GetDate().GetYear() == year))
						if(data_iterator->GetWeather().GetSolarRadiation() >= 100.0)
							++numberOfSolarRadiationRecord;
				}
			}
		}
	}

	return numberOfSolarRadiationRecord;
}

//----------------------------------------------------------------------------
//Calculate the average wind speed per year
float Data::calculateAverageWindSpeedPerYear(int year) {
	float totalAverageWindSpeed = 0.0;

	for (int i = 1; i <= 12; i++)
		totalAverageWindSpeed += calculateTotalWindSpeedPerMonth(i, year);

	if (totalAverageWindSpeed > 0.0)
		return totalAverageWindSpeed / 12;

	return totalAverageWindSpeed;
}

//----------------------------------------------------------------------------
//Calculate the average ambient air temperature per year
float Data::calculateAverageAmbientAirTemperaturePerYear(int year) {

	float totalAverageAmbientAirTemperature = 0.0;

	for (int i = 1; i <= 12; i++)
		totalAverageAmbientAirTemperature += calculateTotalAmbientAirTemperaturePerMonth(i, year);

	if (totalAverageAmbientAirTemperature > 0.0)
		return totalAverageAmbientAirTemperature / 12;

	return totalAverageAmbientAirTemperature;
}

//----------------------------------------------------------------------------
//Calculate the total solar radiation per year
float Data::calculateTotalSolarRadiationPerYear(int year) {

	float totalSolarRadiation = 0.0;

	for (int i = 1; i <= 12; i++)
		totalSolarRadiation += calculateTotalSolarRadiationPerMonth(i, year);

	return totalSolarRadiation;
}

//----------------------------------------------------------------------------
//Calculate the average wind speed per month
float Data::calculateAverageWindSpeedPerMonth(int month, int year) {
	return calculateTotalWindSpeedPerMonth(month, year) / calculateWindSpeedRecordPerMonth(month, year);
}

//----------------------------------------------------------------------------
//Calculate the average ambient air temperature per month
float Data::calculateAverageAmbientAirTemperaturePerMonth(int month, int year) {
	return calculateTotalAmbientAirTemperaturePerMonth(month, year) / calculateAmbientAirTemperatureRecordPerMonth(month, year);
}

//----------------------------------------------------------------------------
//Calculate the average solar radiation per month
float Data::calculateAverageSolarRadiationPerMonth(int month, int year) {
	return calculateTotalSolarRadiationPerMonth(month, year) / calculateSolarRadiationRecordPerMonth(month, year);
}

//----------------------------------------------------------------------------
//Output wind speed, solar radiation, ambient air temperature for that given year to a file
void Data::outputDataToFile(int year, string fileName) {

	m_ofile.open(fileName);

	m_ofile << year << endl;

	m_ofile << fixed << setprecision(1);

	if ((calculateAverageWindSpeedPerYear(year) == 0.0) && (calculateAverageAmbientAirTemperaturePerYear(year) == 0.0) && (calculateTotalSolarRadiationPerYear(year) == 0.0)) {
		m_ofile << "No Data";
	} else {
		for (int i = 1; i <= 12; i++) {
			float averageWindSpeedPerMonth = calculateAverageWindSpeedPerMonth(i, year);
			float averageAmbientAirTemperaturePerMonth = calculateAverageAmbientAirTemperaturePerMonth(i, year);
			float totalSolarRadiationPerMonth = calculateTotalSolarRadiationPerMonth(i, year);

			if ((averageWindSpeedPerMonth > 0.0) && (averageAmbientAirTemperaturePerMonth > 0.0)) {
				m_ofile << m_util.GetMonthInString(i) << "," << averageWindSpeedPerMonth << "," << averageAmbientAirTemperaturePerMonth << "," << totalSolarRadiationPerMonth << endl;
			}else{
				m_ofile << m_util.GetMonthInString(i) << endl;
			}
		}
	}

	m_ofile.close();
}


//----------------------------------------------------------------------------
//Find the highest solar radiation for the given date
float Data::calculateHighestSolarRadiation(Date &date){
	float solar_radiation = 0.0;

	if (checkExistenceOfDataUsingMonthAndYear(date.GetMonth(), date.GetYear()) == true) {
		map<int, list<WindLogType> >::iterator it;

		list<WindLogType>::iterator data_iterator;
		for (it = m_data_map.begin(); it != m_data_map.end(); ++it) {
			if(it->first == date.GetYear()){
				for(data_iterator = it->second.begin(); data_iterator != it->second.end(); data_iterator++){
					if ((data_iterator->GetDate().GetDay() == date.GetDay()) && (data_iterator->GetDate().GetMonth() == date.GetMonth()) && (data_iterator->GetDate().GetYear() == date.GetYear()))
						if(data_iterator->GetWeather().GetSolarRadiation() > solar_radiation)
							solar_radiation = data_iterator->GetWeather().GetSolarRadiation();
				}
			}
		}
	}

	return solar_radiation;
}

//----------------------------------------------------------------------------
//Output all the timing on the given date with the specified highest solar radiation
void Data::printAllTimingOfHighestSolarRadiation(Date &date, float highestSolarRadiation){

	if (checkExistenceOfDataUsingMonthAndYear(date.GetMonth(), date.GetYear()) == true) {
		map<int, list<WindLogType> >::iterator it;

		list<WindLogType>::iterator data_iterator;
		for (it = m_data_map.begin(); it != m_data_map.end(); ++it) {
			if(it->first == date.GetYear()){
				for(data_iterator = it->second.begin(); data_iterator != it->second.end(); data_iterator++){
					if((data_iterator->GetWeather().GetSolarRadiation() == highestSolarRadiation) && (data_iterator->GetDate() == date))
						cout << data_iterator->GetTime().GetHours() << ":" << data_iterator->GetTime().GetMinutes() << endl;
				}
			}
		}
	}
}

//----------------------------------------------------------------------------
//Check whether the binary tree is empty
bool Data::checkBinaryTreeIsEmpty(){
	return m_date_tree.isEmpty();
}

//----------------------------------------------------------------------------
//Check whether the map data structure is empty
bool Data::checkMapIsEmpty(){
	return m_data_map.empty();
}
