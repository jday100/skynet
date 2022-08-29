#ifndef ICOMPUTER_H
#define ICOMPUTER_H
#include "ICU.h"
#include "IAU.h"
#include "IMemory.h"
#include "IManager.h"
#include "IInterrupt.h"
#include "IExecutor.h"


class IComputer
{
    public:
        IComputer();
        virtual ~IComputer();

        virtual ICU*            getCU()=0;
        virtual IAU*            getAU()=0;
        virtual IMemory*        getMemory()=0;
        virtual IManager*       getManager()=0;
        virtual IInterrupt*     getInterrupt()=0;
        virtual IExecutor*      getExecutor()=0;

    protected:

    private:
};

#endif // ICOMPUTER_H
