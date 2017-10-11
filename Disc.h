#pragma once
#include "Item.h"
#include "string.h" 
using namespace std;
class Disc: public Item
{
public:

	//-------------------------------Default Constructor-----------------------
	// Creates a new Disc object
	Disc();

	//------------------------------- Constructor-----------------------------
	// Creates a new Disc object with the year, artistOrDirectorName and title
	Disc (string,  string, int );

	//------------------------------- setYear -------------------------------
	// Sets Disc's year
	void setYear(int );

	//------------------------------- getYear -------------------------------
	// returns Disc's year
	int getYear() const;

	//------------------------------- setTitle -------------------------------
	// Sets Disc's title
	void setTitle(string );

	//------------------------------- getTitle -------------------------------
	// returns Disc's title
	string getTitle() const;

	//------------------------------- setName -------------------------------
	// Sets Dis's artist's or director's name
	void setName (string );

	//------------------------------- getName -------------------------------
	// returns Disc's artist's or director's name
	string getName() const;

	//-------------------------------Destructor ------------------------------
	// Destructs a Disc object
	virtual ~Disc(void);

protected:
	int year;
	string title;
	string artistOrDirectorName;
};
 
