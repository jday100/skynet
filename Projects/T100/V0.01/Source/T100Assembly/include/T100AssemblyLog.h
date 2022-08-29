#ifndef T100ASSEMBLYLOG_H
#define T100ASSEMBLYLOG_H

#include "T100Log.h"

enum T100LOG_HOTKEY{
    T100LOG_HOTKEY_NONE     = 0,
    T100LOG_HOTKEY_ADD,
    T100LOG_HOTKEY_LESSEN,
    T100LOG_HOTKEY_ON,
    T100LOG_HOTKEY_OFF,
    T100LOG_HOTKEY_CLEAR,
    T100LOG_HOTKEY_MAX
};


enum T100LOG_LEVEL{
    T100LOG_NONE            = 0,
    T100LOG_BYTE,
    T100LOG_CHAR,
    T100LOG_STRING,
    T100LOG_KEYWORD,
    T100LOG_SENTENCE,
    T100LOG_SEGMENT,
    T100LOG_FILE,
    T100LOG_ALL,
    T100LOG_MAX
};


class T100AssemblyLog : public T100Log
{
    public:
        T100AssemblyLog();
        virtual ~T100AssemblyLog();

        static T100VOID                 info(T100LOG_LEVEL, T100WSTRING);

        static T100LOG_LEVEL            m_level;

    protected:

    private:
};

#endif // T100ASSEMBLYLOG_H
