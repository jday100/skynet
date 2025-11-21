#ifndef AFXVER__H
#define AFXVER__H

#pragma once

/////////////////////////////////////////////////////////////////////////////
// Main version numbers

#define _AFX        1
#ifndef _MFC_VER
#define _MFC_VER    0x0E00
#endif // _MFC_VER

#ifndef _MFC_FILENAME_VER
#define _MFC_FILENAME_VER   "140"
#endif // _MFC_FILENAME_VER

#ifndef AFX_INLINE
    #define AFX_INLINE      inline
#endif // AFX_INLINE

#ifndef AFXAPI
#define AFXAPI          __stdcall
#endif // AFXAPI


#ifndef AFX_CDECL
#define AFX_CDECL       __cdecl
#endif // AFX_CDECL

#ifndef AFX_ALWAYS_VTABLE
#ifndef AFX_NOVTABLE
#if !defined(_DEBUG)
#define AFX_NOVTABLE        __declspec(novtable)
#else
#define AFX_NOVTABLE
#endif
#endif // AFX_NOVTABLE
#endif // AFX_ALWAYS_VTABLE


#ifndef AFX_COMDAT
#define AFX_COMDAT      __declspec(selectany)
#endif // AFX_COMDAT


#endif // AFXVER__H
