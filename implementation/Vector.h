#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <vector>
using namespace std;

/**
 * @class Vector
 * @brief  Dynamic array for Vector
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
template <class T>
class Vector{

public:

	/**
	 * @brief  Constructor for Vector class
	 *
	 * This constructor creates the Vector class and upon creation all members in this class are
	 * initialize with either NULL for pointers and 0 for counters in vectors.
	 */
	Vector();

	/**
	 * @brief  Destructor for Vector class
	 *
	 * This destructor destroy the Vector object that are created in this class are
	 * initialize with either NULL for pointers and 0 for counters in vectors.
	 */

	virtual ~Vector();

	/**
	 * @brief  Return the generic datatype data stored in the vector based on the position that the data is stored in the vector
	 *
	 * This function returns the generic data in the vector based on the position specified by the user
	 *
	 * @param  position - Position in the vector
	 * @return return the position of the generic datatype specified by the user that is stored in the vector
	 */
	T& at(int position);


	/**
	 * @brief  Insert the generic data to the back of the vector
	 *
	 * A mutator which reassigned the value of the day for the date object
	 *
	 * @param  elem - Data that is to be insert into vector
	 * @return void
	 */
	void push_back(const T& elem);



	/**
	 * @brief  Get the number of data stored in the vector
	 *
	 * This function returns the number of data stored in the vector
	 *
	 * @return return the current number of the data stored in the vector
	 */
	int getCount();



	/**
	 * @brief  Get the capacity/limit of the vector
	 *
	 * This function returns the capacity/limit of the vector
	 *
	 * @return capacity of the vector
	 */
	int getCapacity();

	/**
	 * @brief  Check whether the vector is full
	 *
	 * This function checks whether the vector is full
	 *
	 * @param  boolean value true/false
	 * @return void
	 */
	bool isFull();


	/**
	 * @brief  Resize the vector based on the variable specified
	 *
	 * A function that resize the vector based on the specified size in integer
	 *
	 * @param  newSize - the size of the vector in integer datatype
	 * @return void
	 */
	void resize(int newSize);


	/**
	 * @brief  Create a vector based on the size specified
	 *
	 * A function that creates the vector based on the specified size in integer
	 *
	 * @param  size - the size of the vector in integer datatype
	 * @return void
	 */
	void create(int size);

	/**
	 * @brief  Clear off all data in the vector
	 *
	 * This function clear all members in the class to NULL for pointers or 0 for counters
	 *
	 * @return void
	 */
	void clear();

private:
	vector<T> m_list;
	//T* m_start;
	//T* m_end;
	//int m_count;
	//int m_capacity;

};


//----------------------------------------------------------------------------
// Function implementations

//----------------------------------------------------------------------------
//Constructor of the Vector class
template <class T>
Vector<T>::Vector(){
	clear();
}

//----------------------------------------------------------------------------
//Destructor of the Vector class
template <class T>
Vector<T>::~Vector(){
	clear();
}



//----------------------------------------------------------------------------
// Clear all data in the vector by setting all pointer to NULL and all counters to 0

template <class T>
void Vector<T>::clear(){
	m_list.clear();
	//m_start = NULL;
	//m_end = NULL;
	//m_count = 0;
	//m_capacity = 0;
}

//----------------------------------------------------------------------------
// Add a data/object to the back of the vector

template <class T>
void Vector<T>::push_back(const T& elem){

	m_list.push_back(elem);
	/*
	 if (m_count == (m_capacity - 1)){
		resize(m_capacity*2);
	}
	*m_end = elem;
	m_end++;
	m_count++;
	*/

}

//----------------------------------------------------------------------------
// Get the capacity of the vector

template <class T>
int Vector<T>::getCapacity()
{
	return m_list.max_size();
}

//----------------------------------------------------------------------------
// Get the current number of data stored in the vector object

template <class T>
int Vector<T>::getCount(){
	return m_list.size();
}

//----------------------------------------------------------------------------
// Create a vector where the size is based on the number specified
template <class T>
void Vector<T>::create(int size){
	m_list.resize(size);
	//m_list = new T[size];
	//m_start = m_list;
	//m_end = m_list;
	//m_capacity = size;
}

//----------------------------------------------------------------------------
// Check whether this vector is full or not

template <class T>
bool Vector<T>::isFull(){
	//return (m_count == m_capacity);
	return m_list.size() == m_list.max_size();
}


//----------------------------------------------------------------------------
// Resize the vector according to the specified size in integer

template <class T>
void Vector<T>::resize(int newSize){


	m_list.resize(newSize);
	/*
	T* newList = new T[newSize];
	T* newListPointer = newList;
	T* oldListPointer = m_list;

	//while looping the old array to copy all details from old array to new array
	while (oldListPointer != (m_list + m_count)){
		//populate the new array from old array
		*newListPointer = *oldListPointer;

		//this means move the pointer to next location
		newListPointer++;
		oldListPointer++;
	}

	//reinitialize the starting point of the new array
	m_start = newList;

	//defining the ending point of the new array
	m_end = newList+m_count;

	//defining the size of the new array
	m_capacity = newSize;

	//delete the old array
	delete[] m_list;
	//repopulate the new array
	m_list = newList;
	*/
}

//----------------------------------------------------------------------------
// Return the generic datatype of the data based on the position in the vector

template <class T>
T& Vector<T>::at(int i){
	if(i>=0 && i<m_list.size()){
		return m_list.at(i);
	}
}

#endif /* VECTOR_H_ */
