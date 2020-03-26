// list.h
//
// linked-list for hw1 and hw2
//
#include <iostream>

using namespace std;
 
template <class T>
class List
{
public:
    List<T>();

    void test();
//    void append( char);
//    List* remove( List*);
    void remove( List<T>*&);
    void append( T);

    List *next, *back;

    T data;
    char c;//for hw1
    float f;//for hw2
    int count;
    int num;
};


template<class T>
List<T>::List()
{
        count = 1;
        num = 0;
        next = NULL;
        back = NULL;
}

template<class T>
void List<T>::test()
{
    cout << "test" << endl;
}
template<class T>
void List<T>::append( T data)
{
        next = new List<T>();
        next->back = this;
        next->data = data;
        next->num = this->num + 1;
}
template<class T>
void List<T>::remove( List *&rm)
{
        if (rm->back != NULL)
                rm->back->next = rm->next;
        if (rm->next != NULL)
        {
                rm->next->back = rm->back;
                rm = rm->next;
        }
}

