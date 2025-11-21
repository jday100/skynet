#ifndef T100FILE_H
#define T100FILE_H

#include <vector>

#define         T100FILE_VECTOR             std::vector<char>


class T100File
{
    public:
        T100File();
        virtual ~T100File();

        void            Read(T100FILE_VECTOR&);

    protected:

    private:
};

#endif // T100FILE_H
