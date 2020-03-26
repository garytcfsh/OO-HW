#include "list.h"
#include <iostream>

using namespace std;

int main( int argc, char **argv)
{
    int i=0;//loop count
    int count=0;
    List *head, *temp, *now;
    now = new List();
    head = now;

    i = 1;
    if (!argc > 1)
    {
        cout << "input error" << endl;
        exit(1);
    }
    for (int ii=1; ii<argc; ii++)
    {
        i = 0;
        while (argv[ii][i] != '\0')
        {
            now->append( argv[ii][i]);
            now = now->next;
            i++;
            count++;
        }
    }
    head = head->next;
    now = head;
    int j=0, k=0;
    int newCount = count;
    for ( j=0; j<count; j++)
    {
	    temp = now->next;
	    count = newCount;
	    for ( k=j+1; k<count; k++)
	    {
		if (now->c == temp->c)
		{
			now->count = now->count + 1;
			temp = temp->remove( temp);
			newCount--;
		}
		else
		{
			temp = temp->next;
		}
	    }
	    now = now->next;
    }

    now = head;

    for (int ii=0; ii<newCount; ii++)
    {
//        cout << now->c << " list num: " << now->num << endl;
        cout << now->c << "-" << now->count << endl;
        now = now->next;
    }


    return 0;
}
