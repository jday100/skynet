#ifndef T100CPPSCANNER_H
#define T100CPPSCANNER_H

#include "T100Common.h"
#include "T100WString.h"
#include "T100CPPKeywordScanner.h"
#include "T100CPPElementScanner.h"
#include "T100CPPSentenceScanner.h"
#include "T100CPPPartScanner.h"
#include "T100CPPProjectScanner.h"

class T100CPPScanner
{
    public:
        T100CPPScanner();
        virtual ~T100CPPScanner();

        T100BOOL            done(T100WString);

    protected:
        T100BOOL            create(T100WString);
        T100BOOL            destroy();

        T100BOOL            execute();

    private:
        T100CPPKeywordScanner*          m_keyword_scanner           = T100NULL;
        T100CPPElementScanner*          m_element_scanner           = T100NULL;
        T100CPPSentenceScanner*         m_sentence_scanner          = T100NULL;
        T100CPPPartScanner*             m_part_scanner              = T100NULL;
        T100CPPProjectScanner*          m_project_scanner           = T100NULL;
};

#endif // T100CPPSCANNER_H
