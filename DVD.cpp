#include "DVD.h"
#include "Disc.h"
#include <fstream>
#include <string>
using namespace std;

//-------------------------------Default Constructor-----------------------
// Creates a new DVD object
DVD::DVD(){}


//------------------------------  <  --------------------------------------
// Determine if this TreeData object is smaller than the one passed in.
// Preconditions: two TreeData objects have a valid character value, and 
// can be compared by ASCII decimal value
// Postconditions: true is returned if this TreeData object's decimal value
// is smaller than of the one passed in as a parameter, and false if it is
// bigger.
 bool DVD::operator<(const TreeData & otherDVD) const
{
	const DVD & dvd = static_cast<const DVD &>(otherDVD);
	int lastVal = this->artistOrDirectorName.compare(dvd.artistOrDirectorName);
	int lastVal2 = this->getTitle().compare(dvd.getTitle());
	if(lastVal2 < 0)
	{
		return true;
	}
	else if (lastVal2 == 0 && (this->getYear() < dvd.getYear()))
	{
		return true;
	}
	else if (lastVal2 == 0 && (this->getYear() == dvd.getYear()) && lastVal < 0)
	{
		return true;
	}
	else
	{
	return false;
	}
}

//------------------------------  >  --------------------------------------
// Determine if this TreeData object is bigger than the one passed in.
// Preconditions: two TreeData objects have a valid character value, and 
// can be compared by ASCII decimal value
// Postconditions: true is returned if this TreeData object's decimal value
// is bigger than of the one passed in as a parameter, and false if it's 
// otherwise.
 bool DVD::operator>(const TreeData & otherDVD) const
 {
	 const DVD & dvd = static_cast<const DVD &>(otherDVD);
	 return dvd < *this;
 }

//------------------------------  ==  -------------------------------------
// Determine if two TreeData objects are equal.
// Preconditions: both TreeData objects have a valid character value ch and
// can be compared by ASCII decimal value.
// Postconditions:true is returned if the objects have the same character
// value ch, false otherwise.
 bool DVD::operator==(const TreeData& otherDVD) const
{
	const DVD & dvd = static_cast<const DVD &>(otherDVD);
	return ((this->artistOrDirectorName == dvd.artistOrDirectorName) && (this->getYear() == dvd.getYear()) 
		&& (this->getTitle() == dvd.getTitle()));
}

//------------------------------  !=  -------------------------------------
// Determine if two TreeData objects are not equal.
// Preconditions: both TreeData objects have a valid character value ch and
// can be compared by ASCII decimal value.
// Postconditions:true is returned if the objects don't have the same 
// character value ch, false otherwise.
 bool DVD::operator!=(const TreeData & otherDVD) const
{
	const DVD & dvd = static_cast<const DVD &>(otherDVD);
	return !(*this == dvd);
}

//------------------------------ create -----------------------------------
// Creates a new DVD object from the file input
Item *DVD::create (ifstream &line )
{
	DVD *d = new DVD();
		string s;
	
		getline(line, s, ',');
		d->setName(s);
		getline(line, s, ',');
		d->setTitle(s);
		getline(line, s, '\n');
		//line.ignore();
		d->setYear(abs(atoi(s.c_str())));
		return d;
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class TreeData
// Preconditions: a TreeData object must have a valid character value ch
// Postconditions: the TreeData's value (char) is sent to the output w/o
// spaces.
void DVD::print(ostream& output) const
 {
	 output << title << ", "<< year << ", " << artistOrDirectorName;
 }
	//-------------------------------Destructor ------------------------------
	// Destructs a DVD object
DVD::~DVD(){}