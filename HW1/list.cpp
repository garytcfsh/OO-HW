#include "list.h"
#include <iostream>

using namespace std;

List::List()
{

}

void List::test()
{
    cout << "test" << endl;
}

void List ::append( char c)
{
	next = new List();
	next->back = this;
	next->c = c;
}
