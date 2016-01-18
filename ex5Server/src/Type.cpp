/*
 * Type.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: roi
 */

#include "Type.h"
#include "Movie.h"

/*******************************************************************************
 * function name : type													       *
 * input : type as string												       *
 * output : nothing.													       *
 * explanation : constructor of a Type, fill the members with the input.	   *
 *******************************************************************************/
Type::Type(string type) {
	this->type = type;
	this->movies = vector<Movie*>();
}
Type::Type(){}
/*******************************************************************************
 * function name : getMovies											       *
 * input : nothing.														       *
 * output : vector of movies as vector.									       *
 * explanation : return the vector of all the movies that the Type is a		   *
 *		         member in them.										       *
 *******************************************************************************/
vector<Movie*>& Type::getMovies() {
	return this->movies;
}

/*******************************************************************************
 * function name : getType												       *
 * input : nothing.														       *
 * output : type as string.												       *
 * explanation : return the member of the type as string.				       *
 *******************************************************************************/
string Type::getType() {
	return this->type;
}

/*******************************************************************************
 * function name : addMovie												       *
 * input : a movie object.												       *
 * output : nothing.													       *
 * explanation : the function add the movie object to the movies vector.       *
 *******************************************************************************/
void Type::addMovie(Movie* movieToAdd) {
	this->movies.push_back(movieToAdd);
}

/*******************************************************************************
 * function name : removeMovie											       *
 * input : a movie id as string.										       *
 * output : nothing.														   *
 * explanation : the function remove the movie object from the movies vector.  *
 *******************************************************************************/
void Type::removeMovie(string movieToRemoveId) {
	for (vector<Movie*>::iterator it = this->movies.begin();
			it != this->movies.end();) {
		if ((*it)->getId() == movieToRemoveId) {
			movies.erase(it);
		} else {
			++it;
		}
	}
}

/*******************************************************************************
 * function name : findMovie											       *
 * input : a movie id as string.										       *
 * output : nothing.													       *
 * explanation : the function find the movie with that id in the movies vector.*
 *******************************************************************************/
Movie* Type::findMovie(string movieToFindId) {
	for (vector<Movie*>::iterator it = this->movies.begin();
			it != this->movies.end(); ++it) {
		if ((*it)->getId() == movieToFindId) {
			return (*it);
		}
	}
	return NULL;
}

/*******************************************************************************
 * function name : ~Type												       *
 * input : nothing														       *
 * output : nothing.													       *
 * explanation : destructor of a Type.										   *
 *******************************************************************************/
Type::~Type() {
}
