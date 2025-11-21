#ifndef T100EXTENSIONFRAME_H
#define T100EXTENSIONFRAME_H

#include "T100Extension.h"

class wxFrame;

class T100ExtensionFrame : public T100Extension
{
    public:
        T100ExtensionFrame();
        virtual ~T100ExtensionFrame();

        T100VOID            SetFrame(wxFrame*);
        wxFrame*            GetFrame();

    protected:
        wxFrame*            m_frame     = T100NULL;

    private:
};

#endif // T100EXTENSIONFRAME_H
