#ifndef T1003DEDITORCONFIGFILE_H
#define T1003DEDITORCONFIGFILE_H

#include <fstream>
#include "game/file/T100JSON.h"

class T1003DEditorConfigFile
{
    public:
        T1003DEditorConfigFile();
        virtual ~T1003DEditorConfigFile();

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorConfigFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorConfigFile&);

    protected:
        JSON                                        m_json;

    private:
        T100VOID                                    encode();
        T100VOID                                    decode();
};

#endif // T1003DEDITORCONFIGFILE_H
