#include <iostream>

#include "T100Thread.h"

using namespace std;

class T100Test : public T100Thread
{
public:
    T100Test() {}
    virtual ~T100Test() {}

    T100VOID        Run()
    {
        cout << "Hello world!" << endl;
    }
};



int main()
{
    //cout << "Hello world!" << endl;

    T100Test    test;

    test.Start();

    test.Waiting();

    return 0;
}
