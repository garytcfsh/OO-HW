#include "list.h"
#include <iostream>

using namespace std;

List::List()
{
	count = 1;
	num = 0;
	next = NULL;
	back = NULL;
}

void List::test()
{
    cout << "test" << endl;
}

void List::append( char c)
{
	next = new List();
	next->back = this;
	next->c = c;
	next->num = this->num + 1;
}

List* List::remove( List *rm)
{
	if (rm->back != NULL)
		rm->back->next = rm->next;
	if (rm->next != NULL)
	{
		rm->next->back = rm->back;
		rm = rm->next;
	}
	return rm;
}
