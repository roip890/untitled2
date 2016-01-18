/*
 * MoviesSystem.h
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#ifndef MOVIESSYSTEM_H_
#define MOVIESSYSTEM_H_
#include "Actor.h"
#include "Director.h"
#include "Producer.h"
#include "ScreenWriter.h"
#include "Movie.h"
#include <string>
#include "vector"
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <pthread.h>
#include "Server.h"
#include <fstream>
// include headers that implement a archive in simple text format
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>
using namespace std;

/*******************************************************************************
 * class name : MoviesSystem												       *
 * explanation : MoviesSystem is menu of the application.					   *
 *******************************************************************************/
class MoviesSystem {
private:
	vector<Movie*> movies;
	vector<Professional*> professionals;
	vector<Type*> types;
	Server* server;
	static MoviesSystem* instance;
	static pthread_mutex_t lock;
	static bool isConstruct;
	bool inUse;
	friend class boost::serialization::access;
	//friend std::ostream & operator<<(std::ostream &os, const MoviesSystem &ms);




	/*******************************************************************************
	 * function name : getCommand											       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : getting and operating the next command					       *
	 *******************************************************************************/
	int getCommand(int sock);

	/*******************************************************************************
	 * function name : split												       *
	 * input : string and delimiters.										       *
	 * output : vector of string after the split.							       *
	 * explanation : split the string to the vector by the delimiters.		       *
	 *******************************************************************************/
	vector<string> split(string str, string delim);

	/*******************************************************************************
	 * function name : isMovieInputValid									       *
	 * input : length and year as int, rank as float.						       *
	 * output : true if the input valid and false otherwise.				       *
	 * explanation : check if the input of the movie is valid.				       *
	 *******************************************************************************/
	bool isMovieInputValid(int length, int year, float rank);

	/*******************************************************************************
	 * function name : isProfessionalInputValid								       *
	 * input : professional type, id and age  as int, gender as string.		       *
	 * output : true if the input valid and false otherwise.				       *
	 * explanation : check if the input of the professional is valid.		       *
	 *******************************************************************************/
	bool isProfessionalInputValid(int professionalType, int id, int age, string gender);

	/*******************************************************************************
	 * function name : isSortingTypeValid									       *
	 * input : sortingType as int.											       *
	 * output : true if the input valid and false otherwise.				       *
	 * explanation : check if the input of the sortingType is valid.		       *
	 *******************************************************************************/
	bool isSortingTypeValid(int sortingType);
	/*******************************************************************************
	 * function name : MoviesSystem											       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : constructor of moviesSystem object. creating vector of	       *
	 *				movies and vector of professionals.						       *
	 *******************************************************************************/
	MoviesSystem();
public:
	void save(MoviesSystem* ms);
	void load(MoviesSystem* ms);
	static MoviesSystem* getInstance();
	bool occupy();
	void setServer(Server* serv);
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(movies);
		ar & BOOST_SERIALIZATION_NVP(professionals);
		ar & BOOST_SERIALIZATION_NVP(types);
		//ar & BOOST_SERIALIZATION_NVP(server);
		ar & BOOST_SERIALIZATION_NVP(instance);
		ar & BOOST_SERIALIZATION_NVP(isConstruct);
		ar & BOOST_SERIALIZATION_NVP(inUse);
	}

	/*******************************************************************************
	 * function name : ~MoviesSystem										       *
	 * input : nothing														       *
	 * output : nothing.													       *
	 * explanation : destructor of a MoviesSystem.								   *
	 *******************************************************************************/
	virtual ~MoviesSystem();

	/*******************************************************************************
	 * function name : start												       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : starting the operation of the movies system		  		   *
	 *				(starting the manu).									       *
	 *******************************************************************************/
	static void* start(void* var);

	/*******************************************************************************
	 * function name : setNewMovie											       *
	 * input : all movie parameters: code, length, year and rank as int,	   	   *
	 *	  types as vector of string and summary as string.					       *
	 * output : nothing.													       *
	 * explanation : setting new movie object using Movie constructor.		       *
	 *******************************************************************************/
	string setNewMovie(string id, string name, int length, int year, float rank,
			string summary);

	/*******************************************************************************
	 * function name : setNewProfessional									       *
	 * input : all the professional parameters: id, age and gender as int,	       *
	 *	  name as string.													       *
	 * output : nothing.													       *
	 * explanation : setting new professional object using Professional constructor.*
	 *************************m******************************************************/
	string setNewProfessional(int professionalType, int id, int age,
			string specificDesc, string gender, string name);

	/*******************************************************************************
	 * function name : addProfessionalToMovie								       *
	 * input : professional id and movie id as int.							       *
	 * output : nothing.													       *
	 * explanation : searching the professional by id and adding it to		       *
	 *				the movie staff and the movie to the professional movie vector.*
	 *******************************************************************************/
	string addProfessionalToMovie(int professionalToAddId, string movieId);
	/*******************************************************************************
	 * function name : addTypeToMovie										       *
	 * input : movie type as string  and movie id as int.					       *
	 * output : nothing.														   *
	 * explanation : adding type of movie to it's types vector.				       *
	 *******************************************************************************/
	string addTypeToMovie(string movieId, string typeToAdd);

	/*******************************************************************************
	 * function name : setSortingTypeMovie									       *
	 * input : sorting type as int.											       *
	 * output : nothing.													       *
	 * explanation : setting the sorting type of a movie.					       *
	 *******************************************************************************/
	string setSortingTypeMovie(string movieId, int sortingTypeToAdd);

	/*******************************************************************************
	 * function name : printAllProfessionalsOfMovie							       *
	 * input : movie id as int.												       *
	 * output : nothing.													       *
	 * explanation : searching the movie by it's id and printing all the	       *
	 *				professionals of the movie.								       *
	 *******************************************************************************/
	string printAllProfessionalsOfMovie(string movieId);

	/*******************************************************************************
	 * function name : printAllMovieDetails									       *
	 * input : movie id as int.												       *
	 * output : nothing.													       *
	 * explanation : searching the movie by it's id and printing all the	       *
	 *				the movie details.										       *
	 *******************************************************************************/
	string printAllMovieDetails(string movieId);

	/*******************************************************************************
	 * function name : mergeMovies											       *
	 * input : vector of Movie objects.										       *
	 * output : nothing.													       *
	 * explanation : searching the movies by their id, merging all the movies to   *
	 one movie and adding it to movies vector.								       *
	 *******************************************************************************/
	string mergeMovies(vector<string> moviesId);

	/*******************************************************************************
	 * function name : printAllMoviesOfProfessional							       *
	 * input : movie id as int.												       *
	 * output : nothing.													       *
	 * explanation : searching the movie by it's id and printing all the		   *
	 *				professionals of the movie.								       *
	 *******************************************************************************/
	string printAllMoviesOfProfessional(int professionalId);

	/*******************************************************************************
	 * function name : printAllMoviesOfType									       *
	 * input : type as string.												       *
	 * output : nothing.													       *
	 * explanation : searching the type by it's id and printing all the			   *
	 *				movies of the type.											   *
	 *																		       *
	 *******************************************************************************/
	string printAllMoviesOfType(string typeStr);

	/*******************************************************************************
	 * function name : deleteType											       *
	 * input : movie id as string.											       *
	 * output : nothing.													       *
	 * explanation : searching the type by it's id and remove it from the types	   *
	 *				vector and from each types vector of the movie types vector.   *
	 *******************************************************************************/
	string deleteType(string type);

	/*******************************************************************************
	 * function name : deleteMovie											       *
	 * input : movie id as int.												       *
	 * output : nothing.													       *
	 * explanation : searching the movie by it's id and remove it from the movies  *
	 *				vector and from each movies vector of the movie staff vector.  *
	 *******************************************************************************/
	string deleteMovie(string movieId);

	/*******************************************************************************
	 * function name : deleteProfessional									       *
	 * input : professional id as int.										       *
	 * output : nothing.													       *
	 * explanation : searching the professional by it's id and remove it from the   *
	 *				professional vector and from each staff vector of the	       *
	 *				professional movies vector.								       *
	 *******************************************************************************/
	string deleteProfessional(int professionalId);

	/*******************************************************************************
	 * function name : removeProfessionalFromMovie							       *
	 * input : professional id and movie id as int.							       *
	 * output : nothing.													       *
	 * explanation : searching the movie by it's id and remove the professional    *
	 *				from the staff vector and removing the movie from the	       *
	 *				professional movies vector.								       *
	 *******************************************************************************/
	string removeProfessionalFromMovie(int professionalId, string movieId);

	/*******************************************************************************
	 * function name : printAllMovies										       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : printing all the details of each movie in the movies vector.  *
	 *******************************************************************************/
	string printAllMovies();

	/*******************************************************************************
	 * function name : printAllProfessionals								       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : printing all the professional details of each professional	   *
	 *				in the professionals vector.							       *
	 *******************************************************************************/
	string printAllProfessionals();

	/*******************************************************************************
	 * function name : getMovies											       *
	 * input : nothing.														       *
	 * output : vector of Movie objects.									       *
	 * explanation : return the vector of all the movies of the movies system as   *
	 * 				 vector of Movie objects.								       *
	 *******************************************************************************/
	vector<Movie*>& getMovies();

	/*******************************************************************************
	 * function name : getProfessionals										       *
	 * input : nothing.														       *
	 * output : vector of Professional objects.								       *
	 * explanation : return the vector of all the professionals of the			   *
	 * 				 movies system as vector of Professional objects.		       *
	 *******************************************************************************/
	vector<Professional*>& getProfessionals();

	/*******************************************************************************
	 * function name : getTypes												       *
	 * input : nothing.														       *
	 * output : vector of Type objects.										       *
	 * explanation : return the vector of all the types of the					   *
	 * 				 movies system as vector of types objects.				       *
	 *******************************************************************************/
	vector<Type*>& getTypes();

	/*******************************************************************************
	 * function name : findMovie											       *
	 * input : movie id as int.												       *
	 * output : movie with that id.											       *
	 * explanation : finding professional with that id.						       *
	 *******************************************************************************/
	Movie* findMovie(string MovieId);

	/*******************************************************************************
	 * function name : findProfessional										       *
	 * input : professional id as int.										       *
	 * output : professional with that id.									       *
	 * explanation : finding professional with that id.						       *
	 *******************************************************************************/
	Professional* findProfessional(int ProfessionalId);

	/*******************************************************************************
	 * function name : findType												       *
	 * input : Type as string.												       *
	 * output : Type with that string.										       *
	 * explanation : finding professional with that id.						       *
	 *******************************************************************************/
	Type* findType(string type);
};

#endif /* MOVIESSYSTEM_H_ */
