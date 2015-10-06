
//
// This file contains the declaration for a Range class that maintains
// the minimum and maximum values for a charcter range and provides
// related to the range.
//

#ifndef  range_H
#define  range_H


class  Range
{
public:

	//
	// Constructor
	//
	// Parameters:  the minimum and maximum charcter values for the range.

	Range(char  minChar, char  maxChar) : m_minChar(minChar),
		m_maxChar(maxChar) {}

	//
	// Min/Max character accessor functions
	//
	char  min() const { return  m_minChar; }
	char  max() const { return  m_maxChar; }

	//
	// Returns the number of characters in the range.
	//
	unsigned  numCharacters() const { return  m_maxChar - m_minChar + 1; }

	//
	// Returns true if the character passed as a parameter is
	// in the range.  Otherwise, false is returned.
	//
	bool  in(char  c)  const { return  c >= m_minChar &&  c <= m_maxChar; }

private:

	const char  m_minChar;
	const char  m_maxChar;
};


#endif