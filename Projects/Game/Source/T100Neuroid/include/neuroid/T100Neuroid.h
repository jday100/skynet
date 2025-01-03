#ifndef T100NEUROID_H
#define T100NEUROID_H

#include "T100Input.h"
#include "T100Output.h"
#include "T100Layer.h"
#include "T100Neuron.h"

class T100Neuroid
{
    public:
        T100Neuroid();
        virtual ~T100Neuroid();

        void            run();
        void            training();

    protected:

    private:
};

#endif // T100NEUROID_H
