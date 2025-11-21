#ifndef T1003DEDITORPIPELINESTATESETTINGFILE_H
#define T1003DEDITORPIPELINESTATESETTINGFILE_H

#include <fstream>
#include "game/file/T100JSON.h"

class T1003DEditorPipelineStateSettingFile
{
    public:
        T1003DEditorPipelineStateSettingFile();
        virtual ~T1003DEditorPipelineStateSettingFile();

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorPipelineStateSettingFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorPipelineStateSettingFile&);

    protected:
        JSON                                        m_json;

    private:
        T100VOID                                    encode();
        T100VOID                                    decode();
};

#endif // T1003DEDITORPIPELINESTATESETTINGFILE_H
