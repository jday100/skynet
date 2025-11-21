#ifndef AFXSTAT__H
#define AFXSTAT__H

#include <afxtls_.h>

class AFX_MODULE_STATE : public CNoTrackObject
{
public:
    explicit AFX_MODULE_STATE(BOOL bDLL);
    ~AFX_MODULE_STATE();

};

class _AFX_THREAD_STATE : public CNoTrackObject
{
public :
    _AFX_THREAD_STATE();
    ~_AFX_THREAD_STATE();

};


AFX_MODULE_STATE* AFXAPI AfxGetModuleState();


#endif // AFXSTAT__H
