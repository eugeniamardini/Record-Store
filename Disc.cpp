#include "Disc.h"
#include "CD.h"
#include "DVD.h"
#include "Item.h"
#include "string.h"
using namespace std;

	//-------------------------------Default Constructor-----------------------
	// Creates a new Disc object
	Disc::Disc()
	{
	}

	//------------------------------- Constructor-----------------------------
	// Creates a new Disc object with the year, artistOrDirectorName and title
	Disc::Disc (string ttl,  string name, int yr)
	{
		this->artistOrDirectorName = name;
		this->title = ttl;
		this->year = yr;
	}

	//------------------------------- setYear -------------------------------
	// Sets Disc's year
	void Disc::setYear(int yr)
	{
		this->year = yr;
	}

	//------------------------------- getYear -------------------------------
	// returns Disc's year
	int Disc::getYear() const
	{
		return this->year;
	}

	//------------------------------- setTitle -------------------------------
	// Sets Disc's title
	void Disc::setTitle(string ttl)
	{
		this->title = ttl;
	}

	//------------------------------- getTitle -------------------------------
	// returns Disc's title
	string Disc::getTitle() const
	{ 
		return this->title;
	}

	//------------------------------- setName -------------------------------
	// Sets Dis's artist's or director's name
	void Disc::setName (string name)
	{
		this->artistOrDirectorName = name;
	}

	//------------------------------- getName -------------------------------
	// returns Disc's artist's or director's name
	string Disc::getName() const
	{
		return this->artistOrDirectorName;
	}



	//-------------------------------Destructor ------------------------------
	// Destructs a Disc object
	 Disc::~Disc()
	 {
	 }

