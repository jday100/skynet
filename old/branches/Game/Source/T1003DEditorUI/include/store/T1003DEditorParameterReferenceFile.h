#ifndef T1003DEDITORPARAMETERREFERENCEFILE_H
#define T1003DEDITORPARAMETERREFERENCEFILE_H

#include <fstream>
#include "game/file/T100JSON.h"
#include "T1003DEditorParameterReferenceData.h"

class T1003DEditorParameterReferenceFile
{
    public:
        T1003DEditorParameterReferenceFile();
        virtual ~T1003DEditorParameterReferenceFile();

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorParameterReferenceFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorParameterReferenceFile&);

    protected:
        JSON                                        m_json;

    private:
        T100VOID                                    encode();
        T100VOID                                    decode();
};

#endif // T1003DEDITORPARAMETERREFERENCEFILE_H
