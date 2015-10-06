//
// CST 136 - Assignment #6
//
// Kendra Ash 
//
//
// File: Assignment6.cpp
//
// This file contains the definitions for the Crypto, Caeser and Vigenere classes.
//
#include <iostream>

#include  <string.h>
#include  <math.h>
#include "Assignment6.h"

// Crypto 
Crypto::Crypto(string phrase, Range range) : m_phrase(phrase), m_range(range)
{
	m_encryptionLevel = 0;
	m_numConversions = 0;
}
string Crypto::phrase()
{
	return m_phrase;
}
void Crypto::encrypt()
{
}
void Crypto::decrypt() 
{
}
//------------------------------- Caesar ---------------------------------
// Caesar constructor 
Caesar::Caesar(string phrase, int key, Range range): Crypto(phrase, range)
{
	m_key = key;
}
//
// Encryption
//
void Caesar::encrypt()
{
	Crypto::encrypt();
	// incrementing encryption level
	m_encryptionLevel++;

	m_key = normalizeKey(m_key);

	/// get the range
	int len = m_phrase.length();

	
	//
	// Process each character
	//
	for (int idx = 0; idx < len; ++idx)
	{

		//
		// Out of range characters are just transfered to
		// the ciphertext
		//
		if (m_range.in(m_phrase.at(idx))!=true)
		{
			//phrase().at(idx) = m_range[idx]; ///src[idx]
			continue;
		}

		// incrementing conversions 
		m_numConversions++;
		//
		// Determine the alphabet index of the plaintext character
		//
		char  c = m_phrase[idx] - m_range.min();


		//
		// Add the key to the alphabet index to get the ciphertext
		// character. Handle the wrap-around past the last valid
		// character.
		//
		c += m_key % m_range.numCharacters();
		c %= m_range.numCharacters();

		m_phrase[idx] = c + m_range.min();
	}

}
//
// Decryption 
//
void Caesar::decrypt()
{
	Crypto::decrypt();
	// Decryption is accomplished with encryption using a negated key.
	m_key = -m_key;
	m_numConversions = 0;
	m_encryptionLevel--;
	encrypt();
}
//
//Helper Function
//
int Caesar:: normalizeKey(int  origKey)
{
	int  normKey = abs(origKey);

		normKey %= m_range.numCharacters();

		if (origKey < 0)
			normKey = m_range.numCharacters() - normKey;
		
		return  normKey;
}

//------------------------------- Vigenere ---------------------------------
Vigenere::Vigenere(string phrase, string key, Range range) : Crypto(phrase, range)
{
	mv_key = key;
}
//
// Encryption
//
void Vigenere::encrypt()
{
	Crypto::encrypt();

	m_encryptionLevel++;

	int  keyIdx = 0;  // index into key string

	int idx;
	int len = m_phrase.length();

	// Process each character
	//
	for (idx = 0; idx < len; ++idx, ++keyIdx)
	{
		//
		// Handle running out of characters in the index string
		//
		if (!mv_key[keyIdx])
			keyIdx = 0;


		//
		// Skip out of range characters
		//
		if (m_range.in(m_phrase.at(idx)) != true)
		{
			continue;
		}

		m_numConversions++;

		//
		// Determine the ascii offset value of the key character
		//
		int  asciiOffset = mv_key[keyIdx] - m_range.min();


		//
		// Add the ascii offset to the plaintext value to determine
		// the cipher character
		//
		int  newChar = m_phrase[idx] + asciiOffset;


		//
		// Handle wrap-around of the cipher character if needed
		//
		if (newChar > m_range.max())
			newChar = m_range.min() + (newChar - m_range.max() - 1);

		m_phrase[idx] = newChar;
	}
}
void Vigenere::decrypt()
{
	Crypto::decrypt();
	m_numConversions = 0;
	//
	// Decryption
	//
	
	m_encryptionLevel--;

	int  keyIdx = 0;  // index into key string

	int idx;
	int len = m_phrase.length();

	// Process each character
	//
	for (idx = 0; idx < len; ++idx, ++keyIdx)
	{
		//
		// Handle running out of characters in the index string
		//
		if (!mv_key[keyIdx])
			keyIdx = 0;


		//
		// Skip out of range characters
		//
		if (m_range.in(m_phrase.at(idx)) != true)
		{
			continue;
		}

		m_numConversions++;

		//
		// Determine the ascii offset value from the cipher
		// character and the key character
		//
		int  asciiOffset = m_phrase[idx] - mv_key[keyIdx];

		//
		// Convert the ascii offset to a plaintext character
		//
		char  newChar = m_range.min() + asciiOffset;


		//
		// Handle wrap-around of the plaintext character if needed
		//
		if (asciiOffset < 0)
			newChar += m_range.numCharacters();

		m_phrase[idx] = newChar;
		}
}