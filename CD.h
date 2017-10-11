#pragma once
#include "Disc.h"
class CD: public Disc
{
public:
	//-------------------------------Default Constructor-----------------------
	// Creates a new CD object
	CD();

	//------------------------------ create -----------------------------------
	// Creates a new CD object from the file input
	//virtual void create(ifstream ) = 0;


	//-------------------------------Destructor ------------------------------
	// Destructs a CD object
	virtual ~CD();
private:
};

