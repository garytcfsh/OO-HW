// list.h
//
// linked-list for hw1 and hw2
 
class List
{
public:
    List();

    void test();
    void append( char);
//    List* remove( List*);
    void remove( List*&);
    void append( float);

    List *next, *back;

    char c;//for hw1
    float f;//for hw2
    int count;
    int num;
};
