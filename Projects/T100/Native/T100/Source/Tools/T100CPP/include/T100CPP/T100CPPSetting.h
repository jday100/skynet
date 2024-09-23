#ifndef T100CPPSETTING_H
#define T100CPPSETTING_H

#include "T100Setting.h"

class T100CPPSetting : public T100Setting
{
    public:
        T100CPPSetting();
        virtual ~T100CPPSetting();

        T100WString         TEST_PATH       = L"test";

    protected:

    private:
};

#endif // T100CPPSETTING_H
