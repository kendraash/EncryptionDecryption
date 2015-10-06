//
// CST 136 - Assignment #6
//
// Kendra Ash 
//
//
// File: Assignment6.h
//
// This file contains the declartions for the Crypto, Caeser and Vigenere classes.
//

#include <iostream>
#include <string>
#include "range.h"

using namespace std;

class Crypto
{
	public:
		Crypto(string phrase, Range range);
		string phrase();
		virtual void encrypt() =0;
		virtual void decrypt() =0;
		int encryptionLevel() { return m_encryptionLevel; }
		int numConversions() { return m_numConversions; }

	protected:
		Range m_range;
		string m_phrase;
		int m_numConversions;
		int m_encryptionLevel;

};
class Caesar : public Crypto
{
	public:  
		Caesar(string phrase, int key, Range range);
		virtual void encrypt();
		virtual void decrypt();
	
	private:
		int m_key;
		int normalizeKey(int  origKey);
};
class Vigenere : public Crypto
{
	public:
		Vigenere(string phrase, string key, Range range);
		void encrypt();
		void decrypt();

	private:
		string mv_key;
};

