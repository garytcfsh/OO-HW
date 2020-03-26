#include <iostream>
#include <fstream>
using namespace std;

void readList( float*);
int main ()
{
	float fb[100];
	int i=0;

	readList( fb);
	for (i=0; i<100; i++)
	{
		cout << fb[i] << endl;
	}
	return 0;
}

void readList( float* fb)
{
	fstream fileIn;
	fileIn.open( "test.txt", ios::in);
	int i=0;
	if (!fileIn)
		cout << "error" << endl;
	else
	{
		while (!fileIn.eof())
		{
		//	fileIn.getline( buffer, sizeof( buffer));
		//	cout << buffer << endl;
			fileIn >> fb[i];
			i++;
		}
	}
}


	
