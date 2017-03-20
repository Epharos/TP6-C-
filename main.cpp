#include <iostream>
#include <string.h>
#include "Strings.h"

using namespace std;

int main()
{
	Strings s(10, 200);

	char s1[10] = "Bonjour";
	char s2[10] = "Au revoir";
	char s3[10] = "Hehe";

	s.add(s1);
	s.add(s3);
	s.add(s2);

	s.print();
}
