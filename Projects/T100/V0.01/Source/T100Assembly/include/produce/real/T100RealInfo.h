#ifndef T100REALINFO_H
#define T100REALINFO_H

#include "T100SegmentCode.h"
#include "T100SegmentData.h"


class T100RealInfo
{
    public:
        T100RealInfo();
        virtual ~T100RealInfo();

        T100SegmentCode&            getCode();
        T100SegmentData&            getData();

    protected:
        T100SegmentCode             m_code;
        T100SegmentData             m_data;

    private:
};

#endif // T100REALINFO_H
