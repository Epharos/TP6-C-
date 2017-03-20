#include "Strings.h"
#include <iostream>
#include <string.h>

using namespace std;

Strings::Strings(int strings, int chars) : nbrOfStrings(strings), nbrOfChars(chars), T_chaine(new char[chars]), T_index(new char*[strings]), rnbrOfStrings(0), rnbrOfChars(0)
{
	cout << "Constructeur appelé (" << nbrOfChars << " lettres dans " << nbrOfStrings << " chaines)" << endl;
}

bool Strings::contains(const char* s)
{
	bool equals = true;
	int sindex = 0;

	for(int i = 0 ; i < rnbrOfChars ; i++)
	{
		if(T_chaine[i] == '\0' && equals && sindex == len(s))
		{
			cout << endl << endl;
			return true;
		}

		if(T_chaine[i] == '\0' && !equals)
		{
			sindex = 0;
			continue;
		}

		if(sindex > len(s) - 1)
		{
			equals = false;
			continue;
		}

		if(T_chaine[i] == s[sindex])
		{
			equals = true;
			sindex++;
		}
		else
		{
			equals = false;
			sindex++;
		}
	}

	return false;
}

bool Strings::add(const char* s)
{
	if(!contains(s))
	{
		int lenS = len(s);

		if((nbrOfChars - rnbrOfChars >= lenS + 1) && (rnbrOfStrings < nbrOfStrings))
		{
			T_index[rnbrOfStrings] = T_chaine + rnbrOfChars;

			for(int i = 0 ; i < lenS ; i++)
			{
				*(T_chaine + rnbrOfChars + i) = s[i];
			}

			*(T_chaine + rnbrOfChars + lenS) = '\0';

			rnbrOfStrings++;
			rnbrOfChars += lenS + 1;
			return true;
		}
	}

	return false;
}

int Strings::len(const char* s)
{
	int count = 0;

	while(s[count] != '\0')
	{
		count++;
	}

	return count;
}

void Strings::print()
{
	for(int i = 0 ; i < rnbrOfChars ; i++)
	{
		cout << T_chaine[i];

		if(T_chaine[i] == '\0')
		{
			cout << endl;
		}
	}
}

void Strings::extends(int factor)
{
	char* nT_chaine = new char[factor * nbrOfChars];
	char** nT_index = new char*[factor * nbrOfStrings];

	for(int i = 0 ; i < nbrOfChars ; i++)
	{
		nT_index[i] = T_chaine[i];
	}

	for(int i = 0 ; i < nT_index ; i++)
	{
		nT_index[i] = T_index[i];
	}

	delete [] T_chaine;
	delete [] T_index;

	nbrOfChars *= factor;
	nbrOfStrings *= factor;

	T_chaine = nT_chaine;
	T_index = nT_index;
}

Strings::~Strings()
{
	delete [] T_chaine;
	delete [] T_index;
	cout << "Appel du destructeur" << endl;
}