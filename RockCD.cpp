#include "RockCD.h"
#include "CD.h"
#include "Disc.h"
#include "TreeData.h"
#include <fstream>
#include <string>
using namespace std;


//-------------------------------Default Constructor-----------------------
// Creates a new RockCD object
RockCD::RockCD()
{
}

//------------------------------ create -----------------------------------
// Creates a new RockCD object from the file input
Item * RockCD::create (ifstream & line )
{
	RockCD *r = new RockCD();
	string s;
	getline(line, s, ',');
	r->setName(s);
	getline(line, s, ',');
	r->setTitle(s);
	getline(line, s, '\n');
	r->setYear(abs(atoi(s.c_str())));
	return r;
}

//------------------------------  <  --------------------------------------
// Determine if this TreeData object is smaller than the one passed in.
// Preconditions: two TreeData objects have a valid character value, and 
// can be compared by ASCII decimal value
// Postconditions: true is returned if this TreeData object's decimal value
// is smaller than of the one passed in as a parameter, and false if it is
// bigger.
 bool RockCD::operator<(const TreeData & otherRockCD ) const
{
	const RockCD & rockCD = static_cast<const RockCD &>(otherRockCD);
	int lastVal = this->artistOrDirectorName.compare(rockCD.artistOrDirectorName);
	int lastVal2 = this->getTitle().compare(rockCD.getTitle());
	if(lastVal < 0)
	{
		return true;
	}
	else if (lastVal == 0 && (this->getYear() < rockCD.getYear()))
	{
		return true;
	}
	else if (lastVal == 0 && (this->getYear() == rockCD.getYear()) && lastVal2 < 0)
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
 bool RockCD::operator>(const TreeData &otherRockCD) const
 { 
	const RockCD & rockCD = static_cast<const RockCD &>(otherRockCD);
	return rockCD < *this;
}

//------------------------------  ==  -------------------------------------
// Determine if two TreeData objects are equal.
// Preconditions: both TreeData objects have a valid character value ch and
// can be compared by ASCII decimal value.
// Postconditions:true is returned if the objects have the same character
// value ch, false otherwise.
 bool RockCD::operator==(const TreeData &otherRockCD) const
{
	const RockCD & rockCD = static_cast<const RockCD &>(otherRockCD);
	return ((this->artistOrDirectorName == rockCD.artistOrDirectorName) && (this->getYear() == rockCD.getYear()) 
	&& (this->getTitle() == rockCD.getTitle()));
}

//------------------------------  !=  -------------------------------------
// Determine if two TreeData objects are not equal.
// Preconditions: both TreeData objects have a valid character value ch and
// can be compared by ASCII decimal value.
// Postconditions:true is returned if the objects don't have the same 
// character value ch, false otherwise.
bool RockCD::operator!=(const TreeData &otherRockCD) const
{
	return !(*this == otherRockCD);
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class TreeData
// Preconditions: a TreeData object must have a valid character value ch
// Postconditions: the TreeData's value (char) is sent to the output w/o
// spaces.
 void RockCD::print(ostream& output) const
 {
	 output << artistOrDirectorName << ", "<< year << ", " << title;
 }

//-------------------------------Destructor ------------------------------
// Destructs a RockCD object
RockCD::~RockCD()
{
}