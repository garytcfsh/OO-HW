
class List
{
public:
    List();

    void append( char);
    void append( float);
    List* remove( List*);

    List *next, *back;

    void test();
    char c;//for hw1
    float f;//for hw2
    int count;
    int num;
};
