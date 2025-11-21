#ifndef T1003DEDITORDESCRIPTIONREFERENCEFILE_H
#define T1003DEDITORDESCRIPTIONREFERENCEFILE_H

#include <vector>
#include <fstream>
#include "game/file/T100JSON.h"
#include "T1003DEditorDescriptionReferenceData.h"

class T1003DEditorDescriptionReferenceFile
{
    public:
        T1003DEditorDescriptionReferenceFile(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&);
        virtual ~T1003DEditorDescriptionReferenceFile();

        T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&     GetDescriptionReferences();

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorDescriptionReferenceFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorDescriptionReferenceFile&);

    protected:
        JSON                                                m_json;

    private:
        T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&     m_descriptionReferences;

        T100VOID                                            encode();
        //T100VOID                                    EncodeDesc(T100D3D12_INPUT_ELEMENT_DESC*, JSON&);

        T100VOID                                            decode();
        //T100VOID                                    DecodeDesc(JSON&);

};

#endif // T1003DEDITORDESCRIPTIONREFERENCEFILE_H
