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
    int newCount = count;//calculated how many list is removed
    for ( j=0; j<count; j++)
    {
	    temp = now->next;
	    for ( k=j+1; k<count; k++)
	    {
		if (now->c == temp->c)//hit
		{
			now->count = now->count + 1;
			temp->remove( temp);//remove hit list and set next list as current list
			newCount--;
		}
		else//miss
		{
			temp = temp->next;
		}
	    }
	    now = now->next;//prepare to start next comparing
	    count = newCount;//set list new number before new comparing start
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
