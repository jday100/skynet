#include "T100Console.h"

int main()
{
    print("hello world!");

    char* value = (char*)"hello";

    if(strlen(value) == 5)return 0;

    return strlen(value);
}
