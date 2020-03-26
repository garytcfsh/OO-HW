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
    for (int ii=0; ii<count; ii++)
    {
        cout << now->c << endl;
        now = now->next;
    }


    return 0;
}