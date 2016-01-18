/*
 * Movie.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef MOVIE_H_
#define MOVIE_H_
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "Type.h"
#include "Professional.h"
#include "SortStaffById.h"
#include "StaffComparator.h"
#include <fstream>
// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
using namespace std;

/*******************************************************************************
* class name : Movie													       *
* explanation : Movie object.												   *
*******************************************************************************/
class Movie {
private:
	string id;
	string name;
	int length;
	int year;
	float rank;
	vector<Type*> types;
	string summary;
	vector<Professional*> staff;
	StaffComparator* comparator;

	friend class boost::serialization::access;
	//friend std::ostream & operator<<(std::ostream &os, const Movie &mov);

	/*******************************************************************************
	 * function name : mergeWithoutDuplicates								       *
	 * input : type id as string.											       *
	 * output : type with that type string.									       *
	 * explanation : template method to merge 2 vector to one					   *
	 * 				 vector without duplicates.								       *
	 *******************************************************************************/
	template<typename T>
	vector<T> mergeWithoutDuplicates(vector<T> vector1, vector<T> vector2);

public:

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version){
		ar & BOOST_SERIALIZATION_NVP(id);
		ar & BOOST_SERIALIZATION_NVP(name);
		ar & BOOST_SERIALIZATION_NVP(length);
		ar & BOOST_SERIALIZATION_NVP(year);
		ar & BOOST_SERIALIZATION_NVP(rank);
		ar & BOOST_SERIALIZATION_NVP(types);
		ar & BOOST_SERIALIZATION_NVP(summary);
		ar & BOOST_SERIALIZATION_NVP(staff);
		ar & BOOST_SERIALIZATION_NVP(comparator);
	}

	/*******************************************************************************
	* function name : ~Movie												       *
	* input : nothing														       *
	* output : nothing.														       *
	* explanation : destructor of a Movie.										   *
	*******************************************************************************/
	virtual ~Movie();
	/*******************************************************************************
	 * function name : Movie												       *
	 * input : all movie parameters: code, length, year and rank as int,		   *
	 *	  types as vector of string and summary as string.					       *
	 * output : nothing.													       *
	 * explanation : constructor of movie object, fill all the members of the movie.*
	 *******************************************************************************/
	Movie(string id, string name, int length, int year, float rank, string summary);
	Movie();
	/*******************************************************************************
	 * function name : getId												       *
	 * input : nothing.														       *
	 * output : id as int.													       *
	 * explanation : return the id member as int.							       *
	 *******************************************************************************/
	string getId();

	/*******************************************************************************
	 * function name : getName												       *
	 * input : nothing.														       *
	 * output : name as string.												       *
	 * explanation : return the name member as string.						       *
	 *******************************************************************************/
	string getName();

	/*******************************************************************************
	 * function name : getLength											       *
	 * input : nothing.														       *
	 * output : length as int.												       *
	 * explanation : return the length member as int.						       *
	 *******************************************************************************/
	int getLength();

	/*******************************************************************************
	 * function name : getYear												       *
	 * input : nothing.														       *
	 * output : year as int.												       *
	 * explanation : return the year member as int.							       *
	 *******************************************************************************/
	int getYear();

	/*******************************************************************************
	 * function name : getRank												       *
	 * input : nothing.														       *
	 * output : rank as float.												       *
	 * explanation : return the rank member as int.							       *
	 *******************************************************************************/
	float getRank();

	/*******************************************************************************
	 * function name : getTypes												       *
	 * input : nothing.														       *
	 * output : types as vector of pointers to Type.						       *
	 * explanation : return the types member as vector of string.			       *
	 *******************************************************************************/
	vector<Type*>& getTypes();

	/*******************************************************************************
	 * function name : getSummary											       *
	 * input : nothing.														       *
	 * output : sammary as string.											       *
	 * explanation : return the sammary member as string.					       *
	 *******************************************************************************/
	string getSummary();

	/*******************************************************************************
	 * function name : getStaff												       *
	 * input : nothing.														       *
	 * output : staff as vector of professional objects.						       *
	 * explanation : return the staff member as vector of professional objects.       *
	 *******************************************************************************/
	vector<Professional*>& getStaff();

	/*******************************************************************************
	 * function name : addProfessional										       *
	 * input : pofessional as professional object.							       *
	 * output : nothing.													       *
	 * explanation : adding the professional to the staff vector.				   *
	 *******************************************************************************/
	void addProfessional(Professional* professionalToAdd);

	/*******************************************************************************
	* function name : addType												       *
	* input : type as a string.												       *
	* output : nothing.														       *
	* explanation : adding the type to the types vector.						   *
	*******************************************************************************/
	void addType(Type* typeToAdd);

	/*******************************************************************************
	 * function name : removeProfessional									       *
	 * input : pofessional id as id.										       *
	 * output : nothing.													       *
	 * explanation : remove the professional with that id from the staff vector.   *
	 *******************************************************************************/
	void removeProfessional(int professionalToRemoveId);

	/*******************************************************************************
	 * function name : removeType											       *
	 * input : type as string.												       *
	 * output : nothing.													       *
	 * explanation : remove the type with that id from the types vector.		   *
	 *******************************************************************************/
	void removeType(string typeToRemove);

	/*******************************************************************************
	 * function name : toString												       *
	 * input : nothing.														       *
	 * output : the movie details as string.								       *
	 * explanation : return all the movie details.							       *
	 *******************************************************************************/
	string toString();

	/*******************************************************************************
	 * function name : operator+											       *
	 * input : movie as a const movie object.								       *
	 * output : movie as a const movie object.								       *
	 * explanation : overloading of the + operator. this function add movie to     *
	 *				another movie and creating a new movie.					       *
	 *******************************************************************************/

	Movie operator+(Movie& otherMovie);
	/*******************************************************************************
	 * function name : setComparator										       *
	 * input : comparator as comparator object.								       *
	 * output : nothing.													       *
	 * explanation : setting the comparator object with the specific type of       *
	 *				comparator to sort the staff vector.						       *
	 *******************************************************************************/
	void setSortingType(int sortingType);

	/*******************************************************************************
	 * function name : setComparator										       *
	 * input : comparator as comparator object.								       *
	 * output : nothing.													       *
	 * explanation : setting the comparator object with the specific type of       *
	 *				comparator to sort the staff vector.					       *
	 *******************************************************************************/
	void setComparator(StaffComparator* comparator);

	/*******************************************************************************
	 * function name : getSortingType										       *
	 * input : comparator as comparator object.								       *
	 * output : nothing.													       *
	 * explanation : setting the comparator object with the specific type of       *
	 *				comparator to sort the staff vector.					       *
	 *******************************************************************************/
	int getSortingType();

	/*******************************************************************************
	 * function name : setStaff												       *
	 * input : staff as vector of pointers to Professional.					       *
	 * output : nothing.													       *
	 * explanation : setting the staff vector with a vector of pointers to         *
	 *				 Professional.											       *
	 *******************************************************************************/
	void setStaff(vector<Professional*> staff);

	/*******************************************************************************
	 * function name : setTypes												       *
	 * input : staff as vector of pointers to Type.							       *
	 * output : nothing.													       *
	 * explanation : setting the types vector with a vector of pointers to         *
	 *				 TYpe.													       *
	 *******************************************************************************/
	void setTypes(vector<Type*> types);

	/*******************************************************************************
	* function name : findProfessional										       *
	* input : professional id as int.										       *
	* output : professional with that id.									       *
	* explanation : finding professional with that id.						       *
	*******************************************************************************/
	Professional* findProfessional(int ProfessionalId);

	/*******************************************************************************
	* function name : findType												       *
	* input : type id as string.											       *
	* output : type with that type string.									       *
	* explanation : finding type with that type string.						       *
	*******************************************************************************/
	Type* findType(string type);
};
#endif /* MOVIE_H_ */
