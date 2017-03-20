#ifndef Strings_h
#define Strings_h

class Strings
{
	int nbrOfStrings, nbrOfChars, rnbrOfStrings, rnbrOfChars;
	char* T_chaine;
	char** T_index;

	private :

	public :
		Strings(int, int);
		~Strings();
		bool contains(const char*);
		bool add(const char*);
		int len(const char*);
		void print(int);
		void print();
		void extend(int);
};

#endif