#include "CD.h"
#include "ClassicalCD.h"
#include "TreeData.h"
#include "Disc.h"
#include <fstream>
#include <string>
using namespace std;
	//-------------------------------Default Constructor-----------------------
	// Creates a new ClassicalCD object
ClassicalCD::ClassicalCD()
{
}

	//------------------------------- Constructor-----------------------------
	// Creates a new ClassicalCD object with the composer's name
ClassicalCD::ClassicalCD (string cmpsr)
{
	this->composer = cmpsr;
}

	//------------------------------- setComposer ----------------------------
	// Sets ClassicalCD's composer
void ClassicalCD::setComposer(string s)
{
	this->composer = s;
}

	//------------------------------- getComposer ----------------------------
	// returns ClassicalCD's composer's name
string ClassicalCD::getComposer() const
{
	return this->composer;
}



				//------------------------------  <  --------------------------------------
	// Determine if this TreeData object is smaller than the one passed in.
	// Preconditions: two TreeData objects have a valid character value, and 
	// can be compared by ASCII decimal value
	// Postconditions: true is returned if this TreeData object's decimal value
	// is smaller than of the one passed in as a parameter, and false if it is
	// bigger.
 bool ClassicalCD::operator<(const TreeData&  otherClassicalCD) const
	{
		const ClassicalCD & clCD = static_cast<const ClassicalCD &>(otherClassicalCD);
		int lastVal = this->artistOrDirectorName.compare(clCD.artistOrDirectorName);
		int lastVal2 = this->getTitle().compare(clCD.getTitle());
				int lastVal3 = this->composer.compare(clCD.composer);
		if(lastVal3 < 0)
		{
			return true;
		}
		else if (lastVal3 == 0 && (lastVal < 0))
		{
			return true;
		}
		else if (lastVal3 == 0 && (lastVal == 0) && (this->getYear() < clCD.getYear()))
		{
			return true;
		}
		else if (lastVal3 == 0  && (lastVal == 0) && (this->getYear() == clCD.getYear()) && lastVal2 < 0)
		{
		return true;
		}
		else
		return false;
		
	}

	//------------------------------  >  --------------------------------------
	// Determine if this TreeData object is bigger than the one passed in.
	// Preconditions: two TreeData objects have a valid character value, and 
	// can be compared by ASCII decimal value
	// Postconditions: true is returned if this TreeData object's decimal value
	// is bigger than of the one passed in as a parameter, and false if it's 
	// otherwise.
 bool ClassicalCD::operator>(const TreeData& otherClassicalCD) const
	 {
		
		 
		const ClassicalCD & clCD = static_cast<const ClassicalCD &>(otherClassicalCD);
		return clCD < *this;
	 }

	//------------------------------  ==  -------------------------------------
	// Determine if two TreeData objects are equal.
	// Preconditions: both TreeData objects have a valid character value ch and
	// can be compared by ASCII decimal value.
	// Postconditions:true is returned if the objects have the same character
	// value ch, false otherwise.
	 bool ClassicalCD::operator==(const TreeData& otherClassicalCD) const
	{
		
		const ClassicalCD & clCD = static_cast<const ClassicalCD &>(otherClassicalCD);
		int lastVal = this->artistOrDirectorName.compare(clCD.artistOrDirectorName);
		int lastVal2 = this->getTitle().compare(clCD.getTitle());
		int lastVal3 = this->composer.compare(clCD.composer);
		return ((lastVal == 0) && (lastVal2 ==0 )&& (lastVal3 ==0) && (this->getYear() == clCD.getYear()));
	}

	//------------------------------  !=  -------------------------------------
	// Determine if two TreeData objects are not equal.
	// Preconditions: both TreeData objects have a valid character value ch and
	// can be compared by ASCII decimal value.
	// Postconditions:true is returned if the objects don't have the same 
	// character value ch, false otherwise.
	 bool ClassicalCD::operator!=(const TreeData& otherClassicalCD) const
	{
		
		const ClassicalCD & clCD = static_cast<const ClassicalCD &>(otherClassicalCD);
		return !(*this == clCD);
	}
	//------------------------------ create -----------------------------------
	// Creates a new ClassicalCD object from the file input
Item * ClassicalCD::create (ifstream &line )
{
	ClassicalCD *c = new ClassicalCD();
		//char ch;
		//line.get(ch);
		//this->setType(ch);
		string s;
		//getline(line, s, '\,');
		//this->setQuantity(atoi(s.c_str()));
		getline(line, s, ',');
		c->setName(s);
		getline(line, s, ',');
		c->setTitle(s);
		getline(line, s, ',');
		c->setYear(abs(atoi(s.c_str())));
		getline(line, s, '\n');
		//line.ignore();
		c->setComposer(s);
		return c;
}


		//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class TreeData
// Preconditions: a TreeData object must have a valid character value ch
// Postconditions: the TreeData's value (char) is sent to the output w/o
// spaces.
  void ClassicalCD::print(ostream& output) const
 {
	 //const ClassicalCD & clCD = static_cast<const ClassicalCD &>(otherClassicalCD);
	 output << composer << ", " << artistOrDirectorName <<  ", " << year << ", " << title;
 }
	//-------------------------------Destructor ------------------------------
	// Destructs a ClassicalCD object
ClassicalCD::~ClassicalCD()
{
}
