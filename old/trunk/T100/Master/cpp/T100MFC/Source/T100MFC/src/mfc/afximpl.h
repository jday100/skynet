#ifndef AFXIMPL_H
#define AFXIMPL_H

#ifdef _MT
void AFXAPI AfxLockGlobals(int nLockType);
void AFXAPI AfxUnlockGlobals(int nLockType);
BOOL AFXAPI AfxCriticalInit();
void AFXAPI AfxCriticalTerm();
#else
#define AfxLockGlobals(nLockType)
#define AfxUnlockGlobals(nLockType)
#define AfxCriticalInit() (TRUE)
#define AfxCriticalTerm()
#endif // _MT





extern CNotSupportedException _simpleNotSupportedException;
extern CMemoryException _simpleMemoryException;
extern CUserException _simpleUserException;
extern CResourceException _simpleResourceException;




#endif // AFXIMPL_H
