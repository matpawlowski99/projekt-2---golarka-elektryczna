#include <iostream>

#include "Interfejs.h"
#include "Golarka elektryczna.h"

using namespace std;

/*void testujKlasy();
void testujOperatory();*/

int main()
{
	/*testujKlasy();
#ifdef _DEBUG	
	testujOperatory();
#endif*/

	Interfejs aplikacja;

	while (1)
	{
		if (!(aplikacja.menuGlowne()))
		{
			return 0;
		}
	}
}