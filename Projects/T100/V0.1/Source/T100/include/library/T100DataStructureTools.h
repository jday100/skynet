#ifndef T100DATASTRUCTURETOOLS_H
#define T100DATASTRUCTURETOOLS_H

#include "T100Common.h"
#include "T100DataStructure.h"
#include "T100Class.h"

namespace T100Library{

class T100DataStructureTools : public T100Class
{
    public:
        T100DataStructureTools();
        virtual ~T100DataStructureTools();

        static T100BOOL         to_vector(T100WORD*, T100WORD, T100WORD_VECTOR&);

    protected:

    private:
};

}

#endif // T100DATASTRUCTURETOOLS_H
