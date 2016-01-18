/*
 * Professional.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */
#include <vector>
#include <string>
#include <iostream>
#include "Professional.h"
#include "Movie.h"

/*******************************************************************************
* function name : professional											       *
* input : all the professional parameters: id, age and gender as int,	       *
*		  name as string.												       *
* output : nothing.														       *
* explanation : constructor of a professional, fill the members with the input.*
*******************************************************************************/

Professional::Professional(int id , int age, string specificDesc, string gender, string name) {
	this->id = id;
	this->specificDesc = specificDesc;
	this->name = name;
	this->age = age;
	this->gender = gender;
}

/*std::ostream & operator<<(std::ostream &os, const Professional &pro)
{
    return os << pro.age << pro.gender<<pro.id<< pro.movies<<
    		pro.name <<pro.specificDesc;
}*/

/*******************************************************************************
* function name : ~professional											       *
* input : nothing														       *
* output : nothing.														       *
* explanation : destructor of a professional.								   *
*******************************************************************************/
Professional::~Professional() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : getId													       *
* input : nothing.														       *
* output : id as int.													       *
* explanation : return the member of the id as int.						       *
*******************************************************************************/

int Professional::getId() {
	return this->id;
}

/*******************************************************************************
* function name : getProfession											       *
* input : nothing.														       *
* output : profession as string.										       *
* explanation : return the member of the professi*on as string.			       *
*******************************************************************************/

string Professional::getProfession() {
	return this->specificDesc;
}

/*******************************************************************************
* function name : getName												       *
* input : nothing.														       *
* output : name as string.												       *
* explanation : return the member of the name as string.				       *
*******************************************************************************/

string Professional::getName() {
	return this->name;
}

/*******************************************************************************
* function name : getAge												       *
* input : nothing.														       *
* output : age as int.													       *
* explanation : return the member of the age as int.						   *
*******************************************************************************/

int Professional::getAge() {
	return this->age;
}

/*******************************************************************************
* function name : getGender												       *
* input : nothing.														       *
* output : gender as int.												       *
* explanation : return the member of the gender as int (0 - for male,	       *
*		        1 - for female).										       *
*******************************************************************************/

string Professional::getGender() {
	return this->gender;
}

/*******************************************************************************
* function name : getMovies												       *
* input : nothing.														       *
* output : vector of movies as vector.									       *
* explanation : return the vector of all the movies that the professional is a *
*		        member in them.											       *
*******************************************************************************/

vector<Movie*>& Professional::getMovies() {
	return this->movies;
}

/*******************************************************************************
* function name : addMovie												       *
* input : a movie object.												       *
* output : nothing.														       *
* explanation : the function add the movie object to the movies vector.	       *
*******************************************************************************/

void Professional::addMovie(Movie* movieToAdd) {
	if (this->findMovie(movieToAdd->getId()) == NULL) {
		this->movies.push_back(movieToAdd);
	}
}

/*******************************************************************************
* function name : removeMovie											       *
* input : a movie id as int.											       *
* output : nothing.														       *
* explanation : the function remove the movie object from the movies vector.   *
*******************************************************************************/

void Professional::removeMovie (string movieToRemoveId) {
	for (vector<Movie*>::iterator it = this->movies.begin(); it != this->movies.end();) {
		if ((*it)->getId() == movieToRemoveId) {
			movies.erase(it);
		} else {
			++it;
		}
	}
}

/*******************************************************************************
* function name : findMovie												       *
* input : a movie id as string.											       *
* output : nothing.														       *
* explanation : the function find the movie with that id in the movies vector. *
*******************************************************************************/
Movie* Professional::findMovie (string movieToAddId) {
	for (vector<Movie*>::iterator it = this->movies.begin();
			it != this->movies.end(); ++it) {
		if ((*it)->getId() == movieToAddId) {
			return (*it);
		}
	}
	return NULL;
}

/*******************************************************************************
* function name : printProfessional										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : the function printing the proffesional details. this function  *
*				is pure virtual function and each Professional inheriting      *
*				object implement it in other way.						       *
*******************************************************************************/

string Professional::toString() { }
