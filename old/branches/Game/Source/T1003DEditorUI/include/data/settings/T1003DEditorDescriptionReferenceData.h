#ifndef T1003DEDITORDESCRIPTIONREFERENCEDATA_H
#define T1003DEDITORDESCRIPTIONREFERENCEDATA_H

#include <vector>
#include "T100Common.h"
#include "common/T100EntityCommon.h"

#define     T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR                  std::vector<T100D3D12_INPUT_ELEMENT_DESC*>
#define     T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR          std::vector<T1003DEditorDescriptionReferenceData*>


class T1003DEditorDescriptionReferenceData
{
    public:
        T1003DEditorDescriptionReferenceData();
        virtual ~T1003DEditorDescriptionReferenceData();

        T100WSTRING                                         Name;
        T100UINT                                            Amount;

        T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR              m_descs;

    protected:

    private:
};

#endif // T1003DEDITORDESCRIPTIONREFERENCEDATA_H
