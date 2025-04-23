#include "functions.h"

using namespace std;

void fDebug(int code, int param1, int param2) 
{
	if (DEBUG == true)
	{
		switch (code)
		{
		case 0:
			cout << "DEBUG : Unknown" << endl;
			break;
		case 1:
			cout << "DEBUG : Player hit window border" << endl;
			break;
		case 2:
			cout << "DEBUG : Player position : " << param1 << "x " << param2 << "y" << endl;
			break;
		default:
			cout << "DEBUG : Default" << endl;
			break;
		}
	}
}

void fInitialize() 
{

}