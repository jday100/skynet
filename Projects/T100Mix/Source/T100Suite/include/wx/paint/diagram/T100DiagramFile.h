#ifndef T100DIAGRAMFILE_H
#define T100DIAGRAMFILE_H

#include "T100DiagramFileSource.h"
#include "T100DiagramFileTarget.h"

class T100DiagramFile
{
    public:
        T100DiagramFile();
        virtual ~T100DiagramFile();

        virtual T100BOOL        serialize(T100DiagramFileSource&, T100DiagramFileTarget&);

        virtual T100BOOL        deserialize(T100DiagramFileSource&, T100DiagramFileTarget&);

    protected:

    private:
};

#endif // T100DIAGRAMFILE_H
