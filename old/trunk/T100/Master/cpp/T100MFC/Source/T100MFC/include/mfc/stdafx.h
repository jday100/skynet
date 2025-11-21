#ifndef STDAFX_H
#define STDAFX_H

#include <tchar.h>

#define _CRT_RAND_S

#include <winsdkver.h>

#undef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_MAXVER

#undef NTDDI_VERSION

#include <sdkddkver.h>

#include <afx.h>

#include <afxwin.h>

#include <afxstat_.h>


#include <afxtls_.h>

#include <afximpl.h>


#define AFX_COMDAT __declspec(selectany)

#endif // STDAFX_H
