#include "list.h"
#include <iostream>
#include <fstream>
using namespace std;

int readList( List*);
void avgs( List*, List*, float &, float &, float &, int);
float large( List*, int);
void display( float, float, float, float);

int main ()
{
	List *head=NULL, *now=NULL;
	int i=0, N=0;

	now = new List();
	head = now;
	N = readList( now);
	head = head->next;
	now = head;
	float avg, avgP, avgN;
	avgs( head, now, avg, avgP, avgN, N);
	now = head;
	float max = large( now, N);
	display( avg, avgP, avgN, max);
	return 0;
}

int readList( List *now)
{
	fstream fileIn;
	fileIn.open( "A.txt", ios::in);
	int i=0;
	float in;
	if (!fileIn)
		cout << "error" << endl;
	else
	{	
		while (fileIn >> in)
		{
			i++;
		        now->append( (float)in);	
			now = now->next;
		}
	}
	return i;
}

void avgs( List* head, List* now, float &avg, float &avgP, float &avgN, int N)
{
	float sum=0;
	
	now = head;
	for (int i=0; i<N; i++)
	{
		sum = sum + now->f;
		now = now->next;
	}
	avg = sum/N;

	int sumN=0;
	sum = 0;
	now = head;
	for (int i=0; i<N; i++)
	{
		if (now->f > 0)
		{
			sum = sum + now->f;
			sumN++;
		}
		now = now->next;
	}
	avgP = sum/sumN;

	sum = 0;
	sumN=0;
	now = head;
	for (int i=0; i<N; i++)
	{
		if (now->f < 0)
		{
			sum = sum + now->f;
			sumN++;
		}
		now = now->next;
	}
	avgN = sum/sumN;
}

float large( List* now, int N)
{
	float max = now->f;
	for (int i=0; i<N; i++)
	{
		if (now->f > max)
			max = now->f;
		now = now->next;
	}

	return max;
}
	
void display( float avg, float avgP, float avgN, float max)
{
	cout << "avg = " << avg << endl
		<< "avgP = " << avgP << endl
		<< "avgN = " << avgN << endl
		<< "max = " << max << endl;
}
