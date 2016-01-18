/*
 * Movie.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#include "Movie.h"
using namespace std;

/*******************************************************************************
 * function name : Movie												       *
 * input : all movie parameters: code, length, year and rank as int,		   *
 *	  types as vector of string and summary as string.					       *
 * output : nothing.													       *
 * explanation : constructor of movie object, fill all the members of the movie.*
 *******************************************************************************/

Movie::Movie(string id, string name, int length, int year, float rank, string image,
		string summary) {
	this->id = id;
	this->name = name;
	this->length = length;
	this->year = year;
	this->rank = rank;
	this->types = vector<Type*>();
	this->summary = summary;
	this->image = image;
	this->staff = vector<Professional*>();
	this->comparator = new StaffComparator(1);
}

/*******************************************************************************
 * function name : ~Movie												       *
 * input : nothing														       *
 * output : nothing.													       *
 * explanation : destructor of a Movie.										   *
 *******************************************************************************/
Movie::~Movie() {
	//delete this->comparator;
}

/*******************************************************************************
 * function name : getId												       *
 * input : nothing.														       *
 * output : id as int.													       *
 * explanation : return the id member as int.							       *
 *******************************************************************************/
string Movie::getId() {
	return this->id;
}

/*******************************************************************************
 * function name : getName												       *
 * input : nothing.														       *
 * output : name as string.												       *
 * explanation : return the name member as string.						       *
 *******************************************************************************/
string Movie::getName() {
	return this->name;
}

/*******************************************************************************
 * function name : getLength											       *
 * input : nothing.														       *
 * output : length as int.												       *
 * explanation : return the length member as int.						       *
 *******************************************************************************/
int Movie::getLength() {
	return this->length;
}

/*******************************************************************************
 * function name : getYear												       *
 * input : nothing.														       *
 * output : year as int.												       *
 * explanation : return the year member as int.							       *
 *******************************************************************************/
int Movie::getYear() {
	return this->year;
}

/*******************************************************************************
 * function name : getRank												       *
 * input : nothing.														       *
 * output : rank as float.												       *
 * explanation : return the rank member as int.							       *
 *******************************************************************************/
float Movie::getRank() {
	return this->rank;
}

/*******************************************************************************
 * function name : getTypes												       *
 * input : nothing.														       *
 * output : types as vector of pointers to Type.						       *
 * explanation : return the types member as vector of string.			       *
 *******************************************************************************/
vector<Type*>& Movie::getTypes() {
	return this->types;
}

/*******************************************************************************
 * function name : getSummary											       *
 * input : nothing.														       *
 * output : sammary as string.											       *
 * explanation : return the sammary member as string.					       *
 *******************************************************************************/
string Movie::getSummary() {
	return this->summary;
}

/*******************************************************************************
 * function name : getSummary											       *
 * input : nothing.														       *
 * output : image as string.											       *
 * explanation : return the image member as string.					       *
 *******************************************************************************/
string Movie::getImage() {
	return this->image;
}

/*******************************************************************************
 * function name : getStaff												       *
 * input : nothing.														       *
 * output : staff as vector of professional objects.					       *
 * explanation : return the staff member as vector of professional objects.    *
 *******************************************************************************/
vector<Professional*>& Movie::getStaff() {
	return this->staff;
}

/*******************************************************************************
 * function name : addProfessional										       *
 * input : pofessional as professional object.							       *
 * output : nothing.													       *
 * explanation : adding the professional to the staff vector.				   *
 *******************************************************************************/
void Movie::addProfessional(Professional* professionalToAdd) {
	if (this->findProfessional(professionalToAdd->getId()) == NULL) {
		this->staff.push_back(professionalToAdd);
		sort(this->staff.begin(), this->staff.end(), *(this->comparator));
	}
}

/*******************************************************************************
 * function name : addType												       *
 * input : type as a string.											       *
 * output : nothing.													       *
 * explanation : adding the type to the types vector.						   *
 *******************************************************************************/
void Movie::addType(Type* typeToAdd) {
	if (this->findType(typeToAdd->getType()) == NULL) {
		typeToAdd->addMovie(this);
		this->types.push_back(typeToAdd);
	}
}

/*******************************************************************************
 * function name : removeProfessional									       *
 * input : pofessional id as id.										       *
 * output : nothing.													       *
 * explanation : remove the professional with that id from the staff vector.   *
 *******************************************************************************/
void Movie::removeProfessional(int professionalToRemoveId) {
	for (vector<Professional*>::iterator it = this->staff.begin();
			it != this->staff.end();) {
		if ((*it)->getId() == professionalToRemoveId) {
			staff.erase(it);
		} else {
			++it;
		}
	}
}

/*******************************************************************************
 * function name : removeType											       *
 * input : type as string.												       *
 * output : nothing.													       *
 * explanation : remove the type with that id from the types vector.		   *
 *******************************************************************************/
void Movie::removeType(string typeToRemove) {
	for (vector<Type*>::iterator it = this->types.begin();
			it != this->types.end();) {
		if ((*it)->getType() == typeToRemove) {
			(*it)->removeMovie(this->getId());
			types.erase(it);
		} else {
			++it;
		}
	}
}

/*******************************************************************************
 * function name : toString												       *
 * input : nothing.														       *
 * output : the movie details as string.								       *
 * explanation : return all the movie details.							       *
 *******************************************************************************/
string Movie::toString(){
	string movie;
	stringstream lengthStr;
	stringstream rankStr;
	stringstream yearStr;
	lengthStr << this->length;
	rankStr << this->rank;
	yearStr << this->year;
	movie = this->id + " " + this->name + " " + lengthStr.str() + " "
			+ yearStr.str() + " " + rankStr.str();
	int typesSize = this->types.size();
	if (typesSize > 0) {
		movie += " ";
	}
	for (int i = 0; i < typesSize; i++) {
		if (i == (typesSize - 1)) {
			movie += this->types.at(i)->getType();
		} else {
			movie += this->types.at(i)->getType() + ",";
		}
	}
	movie += " " + this->image;
	movie += " " + this->summary + "\n";
	for (vector<Professional*>::iterator it = this->staff.begin();
			it != this->staff.end(); ++it) {
		movie += (*it)->toString();
	}
	return movie;
}

/*******************************************************************************
 * function name : operator+										           *
 * input : movie as a const movie object.								       *
 * output : movie as a const movie object.								       *
 * explanation : overloading of the + operator. this function add movie to     *
 *				another movie and creating a new movie.					       *
 *******************************************************************************/

Movie Movie::operator+(Movie& otherMovie) {
	Movie movie = otherMovie;
	StaffComparator* comparator	= new StaffComparator(1);
	movie.setComparator(comparator);
	movie.setSortingType(otherMovie.getSortingType());
	if (this->getLength() > otherMovie.getLength()) {
		movie = *this;
	}
	string newId = this->id + "_" + otherMovie.getId();
	vector<Type*> newTypes = this->mergeWithoutDuplicates(this->getTypes(),
			otherMovie.getTypes());
	vector<Professional*> newStaff = this->mergeWithoutDuplicates(
			this->getStaff(), otherMovie.getStaff());
	Movie newMovie(newId, movie.name, movie.length, movie.year, movie.rank, movie.image,
			movie.summary);
	newMovie.setStaff(newStaff);
	newMovie.setTypes(newTypes);
	return newMovie;
}

/*******************************************************************************
 * function name : setSortingType										       *
 * input : comparator as a int.											       *
 * output : nothing.													       *
 * explanation : setting the comparator object with the specific type of       *
 *				comparator to sort the staff vector.					       *
 *******************************************************************************/
void Movie::setSortingType(int sortingType) {
	this->comparator->setSortingType(sortingType);
	sort(this->staff.begin(), this->staff.end(), *(this->comparator));
}

/*******************************************************************************
 * function name : setComparator										       *
 * input : comparator as comparator object.								       *
 * output : nothing.													       *
 * explanation : setting the comparator object with the specific type of       *
 *				comparator to sort the staff vector.					       *
 *******************************************************************************/
void Movie::setComparator(StaffComparator* comparator) {
	this->comparator = comparator;
	sort(this->staff.begin(), this->staff.end(), *(this->comparator));
}

/*******************************************************************************
 * function name : getSortingType										       *
 * input : comparator as comparator object.								       *
 * output : nothing.													       *
 * explanation : setting the comparator object with the specific type of       *
 *				comparator to sort the staff vector.					       *
 *******************************************************************************/
int Movie::getSortingType() {
	return this->comparator->getSortingType();
}

/*******************************************************************************
 * function name : setStaff												       *
 * input : staff as vector of pointers to Professional.					       *
 * output : nothing.													       *
 * explanation : setting the staff vector with a vector of pointers to         *
 *				 Professional.											       *
 *******************************************************************************/
void Movie::setStaff(vector<Professional*> staff) {
	this->staff = staff;
	sort(this->staff.begin(), this->staff.end(), *(this->comparator));

}

/*******************************************************************************
 * function name : setTypes												       *
 * input : staff as vector of pointers to Type.							       *
 * output : nothing.													       *
 * explanation : setting the types vector with a vector of pointers to         *
 *				 TYpe.													       *
 *******************************************************************************/
void Movie::setTypes(vector<Type*> types) {
	this->types = types;
}

/*******************************************************************************
 * function name : findProfessional										       *
 * input : professional id as int.										       *
 * output : professional with that id.									       *
 * explanation : finding professional with that id.						       *
 *******************************************************************************/
Professional* Movie::findProfessional(int ProfessionalId) {
	for (vector<Professional*>::iterator it = this->staff.begin();
			it != this->staff.end(); ++it) {
		if ((*it)->getId() == ProfessionalId) {
			return (*it);
		}
	}
	return NULL;
}

/*******************************************************************************
 * function name : findType												       *
 * input : type id as string.											       *
 * output : type with that type string.									       *
 * explanation : finding type with that type string.					       *
 *******************************************************************************/
Type* Movie::findType(string type) {
	for (vector<Type*>::iterator it = this->types.begin();
			it != this->types.end(); ++it) {
		if ((*it)->getType() == type) {
			return (*it);
		}
	}
	return NULL;
}

/*******************************************************************************
 * function name : mergeWithoutDuplicates								       *
 * input : type id as string.											       *
 * output : type with that type string.									       *
 * explanation : template method to merge 2 vector to one					   *
 * 				 vector without duplicates.								       *
 *******************************************************************************/
template<typename T>
vector<T> Movie::mergeWithoutDuplicates(vector<T> vector1, vector<T> vector2) {
	vector<T> newVector = vector1;
	int find;
	for (typename vector<T>::iterator it = vector2.begin(); it != vector2.end();
			++it) {
		find = 0;
		for (typename vector<T>::iterator it2 = newVector.begin();
				it2 != newVector.end(); ++it2) {
			if ((*it) == (*it2)) {
				find = 1;
				break;
			}
		}
		if (find == 0) {
			newVector.push_back(*it);
		}
	}
	return newVector;
}
