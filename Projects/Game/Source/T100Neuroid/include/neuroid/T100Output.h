#ifndef T100OUTPUT_H
#define T100OUTPUT_H

#include <vector>
#include "T100Input.h"

#define     T100NEUROID_OUTPUT_VECTOR           std::vector<T100Output*>


class T100Output
{
    public:
        T100Output();
        virtual ~T100Output();

        void            output(float);

        float           value;

        void            connect(T100Input&);

    protected:

    private:
};

#endif // T100OUTPUT_H
