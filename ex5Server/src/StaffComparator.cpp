/*
 * StaffComparator.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: roi
 */

#include "StaffComparator.h"
using namespace std;

/*******************************************************************************
 * function name : StaffComparator										       *
 * input : nothing.														       *
 * output : nothing.													       *
 * explanation : constructor of a StaffComparator.							   *
 *******************************************************************************/
StaffComparator::StaffComparator(int sortingType) {
	this->sortingTypeNum = sortingType;
	switch (this->sortingTypeNum) {
	case 1: {
		SortStaffById* sortStaffById = new SortStaffById();
		this->sortingType = (SortingStaffType*) sortStaffById;
	}
		break;
	case 2: {
		SortStaffByAge* sortStaffByAge = new SortStaffByAge();
		this->sortingType = (SortingStaffType*) sortStaffByAge;
	}
		break;
	case 3: {
		SortStaffByMoviesQuantity* sortStaffByMoviesQuantity =
				new SortStaffByMoviesQuantity();
		this->sortingType = (SortingStaffType*) sortStaffByMoviesQuantity;
	}
		break;
	default:
		break;
	}
}

StaffComparator::StaffComparator() {
}
/*******************************************************************************
 * function name : ~StaffComparator										       *
 * input : nothing														       *
 * output : nothing.													       *
 * explanation : destructor of a StaffComparator.							   *
 *******************************************************************************/
StaffComparator::~StaffComparator() {
	//delete this->sortingType;
}

/*******************************************************************************
 * function name : operator()												   *
 * input : two objects of const Professional.							       *
 * output : bool.														       *
 * explanation : pure virtual function that return true if the				   *
 * 				first professional is "smaller" (the compeerator decide the	   *
 *				implementation) than the seccond professional and 0 if it is   *
 *				"bigger".												       *
 *******************************************************************************/
bool StaffComparator::operator ()(Professional* firstPro,
		Professional* seccondPro) {
	return this->sortingType->compare(firstPro, seccondPro);
}

/*******************************************************************************
 * function name : setSortingType										       *
 * input : set the type of how the staff vector will be sorted as int.	   	   *
 * output : nothing.													       *
 * explanation : set the type of how the staff vector will be sort:	 	       *
 *				1 - for sorting by id.									       *
 *				2 - for sorting by age.									       *
 *				3 - for sorting by the movies quantity of the professional.    *
 *******************************************************************************/
void StaffComparator::setSortingType(int sortingType) {
	this->sortingTypeNum = sortingType;
	switch (this->sortingTypeNum) {
	case 1: {
		delete this->sortingType;
		SortStaffById* sortStaffById = new SortStaffById();
		this->sortingType = (SortingStaffType*) sortStaffById;
	}
		break;
	case 2: {
		delete this->sortingType;
		SortStaffByAge* sortStaffByAge = new SortStaffByAge();
		this->sortingType = (SortingStaffType*) sortStaffByAge;
	}
		break;
	case 3: {
		delete this->sortingType;
		SortStaffByMoviesQuantity* sortStaffByMoviesQuantity =
				new SortStaffByMoviesQuantity();
		this->sortingType = (SortingStaffType*) sortStaffByMoviesQuantity;
	}
		break;
	default:
		break;
	}
}

/*******************************************************************************
 * function name : setSortingType										       *
 * input : nothing.														       *
 * output : the type of how the staff vector will be sorted as int.		       *
 * explanation : return the member of type of how the staff vector will be sort*
 *				1 - for sorting by id.									       *
 *				2 - for sorting by age.									       *
 *				3 - for sorting by the movies quantity of the professional.    *
 *******************************************************************************/
int StaffComparator::getSortingType() {
	return this->sortingTypeNum;
}
