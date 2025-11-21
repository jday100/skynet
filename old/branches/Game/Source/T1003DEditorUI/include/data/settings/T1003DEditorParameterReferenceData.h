#ifndef T1003DEDITORPARAMETERREFERENCEDATA_H
#define T1003DEDITORPARAMETERREFERENCEDATA_H

#include <vector>
#include "T100Common.h"

#define     T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR            std::vector<T1003DEditorParameterReferenceData*>

class T1003DEditorParameterReferenceData
{
    public:
        T1003DEditorParameterReferenceData();
        virtual ~T1003DEditorParameterReferenceData();

        T100WSTRING             Name;

    protected:

    private:
};

#endif // T1003DEDITORPARAMETERREFERENCEDATA_H
