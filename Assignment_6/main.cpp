#include "Assignment6.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;



//
// This function makes a polymorphic call to both the encryption
// and decryption functions, displaying the phrase both before
// and after each.
//
void  encryptAndDecrypt(Crypto  &msg)
{
	cout << "Original - " << msg.phrase() << endl;
	cout << "           Level = " << msg.encryptionLevel() << endl;
	cout << "   # Conversions = " << msg.numConversions() << endl;

	//
	// Encrypt
	//
	msg.encrypt();
	cout << " Encrypt - " << msg.phrase() << endl;
	cout << "           Level = " << msg.encryptionLevel() << endl;
	cout << "   # Conversions = " << msg.numConversions() << endl;

	//
	// Decyrpt
	//
	msg.decrypt();
	cout << " Decrypt - " << msg.phrase() << endl;
	cout << "           Level = " << msg.encryptionLevel() << endl;
	cout << "   # Conversions = " << msg.numConversions() << endl;
}


//
// Main program
//
int  main()
{
	//
	// Caesar example
	//
	// Uses a valid character range of 'a' to 'z' and
	// a key of 5.
	//
	Caesar  msg1("kendra thinks shes a smart fella' but shes really a fart smeller!", 12345678, Range('a', 'z'));

	//
	// Encrypt the message, then decrypt it
	//
	encryptAndDecrypt(msg1);


	//
	// Vigenere example
	//
	// Uses a valid character range of 'A' to 'Z' and
	// a key of "COWBOY".
	//
	Range  vigRange('a', 'z');

	Vigenere  msg2("ThIs SeNtEnCe Is SeCrEt.", "totalitarianism", vigRange);


	//
	// Encrypt the message, then decrypt it
	//
	encryptAndDecrypt(msg2);

	return  0;
}