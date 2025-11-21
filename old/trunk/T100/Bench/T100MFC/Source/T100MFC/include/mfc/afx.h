#ifndef AFX_H
#define AFX_H

#include <tchar.h>
#include <windows.h>
#include <afxver_.h>

/*============================================================================*/
// Classes declared in this file

struct CRuntimeClass;

class CObject;

    class CException;
        class CArchiveException;
        class CFileException;
        class CSimpleException;
            class CMemoryException;
            class CNotSupportedException;
            class CInvalidArgException;

    class CFile;
        class CStdioFile;
        class CMemFile;

struct CFileStatus;
struct CMemoryState;

class CArchive;
class CDumpContext;

void AFXAPI AfxClassInit(CRuntimeClass* pNewClass);
struct AFX_CLASSINIT
{
    AFX_CLASSINIT(CRuntimeClass* pNewClass)
        {
            AfxClassInit(pNewClass);
        }
};


struct CRuntimeClass
{
    LPCSTR          m_lpszClassName;
    int             m_nObjectSize;
    UINT            m_wSchema;
    CObject* (PASCAL* m_pfnCreateObject)();

    CRuntimeClass*  m_pBaseClass;

    CObject*        CreateObject();
    BOOL            IsDerivedFrom(const CRuntimeClass* pBaseClass) const;

    static CRuntimeClass* PASCAL FromName(LPCSTR lpszClassName);
    static CRuntimeClass* PASCAL FromName(LPCWSTR lpszClassName);
    static CObject* PASCAL CreateObject(LPCSTR lpszClassName);
    static CObject* PASCAL CreateObject(LPCWSTR lpszClassName);

    void            Store(CArchive& ar) const;
    static          CRuntimeClass* PASCAL Load(CArchive& ar, UINT* pwSchemaNum);

    CRuntimeClass*  m_pNextClass;
    const AFX_CLASSINIT* m_pClassInit;
};

/*============================================================================*/
// class CObject is the root of all compliant objects

class CObject
{
public:
    virtual CRuntimeClass* GetRuntimeClass() const;
    virtual ~CObject() = 0;

    void* PASCAL operator new(size_t nSize);
    void* PASCAL operator new(size_t, void* p);
    void PASCAL operator delete(void* p);
    void PASCAL operator delete(void* p, void* pPlace);

protected:
    CObject();
private:
    CObject(const CObject& objectSrc);
    void operator=(const CObject& objectSrc);

public:
    BOOL        IsSerializable() const;
    BOOL        IsKindOf(const CRuntimeClass* pClass) const;

    virtual void Serialize(CArchive& ar);

public:
    static const CRuntimeClass classCObject;
};


// Helper macros
#define _RUNTIME_CLASS(class_name) ((CRuntimeClass*)(&class_name::class##class_name))
#ifdef _AFXDLL
#define RUNTIME_CLASS(class_name) (class_name::GetThisClass())
#else
#define RUNTIME_CLASS(class_name) _RUNTIME_CLASS(class_name)
#endif // _AFXDLL
#define ASSERT_KINDOF(class_name, object) \
    ASSERT((object)->IsKindOf(RUNTIME_CLASS(class_name)))

// RTTI helper macros/functions
const CObject* AFX_CDECL AfxDynamicDownCast(CRuntimeClass* pClass, const CObject* pObject);
CObject* AFX_CDECL AfxDynamicDownCast(CRuntimeClass* pClass, CObject* pObject);
#define DYNAMIC_DOWNCAST(class_name, object) \
    (class_name*)AfxDynamicDownCast(RUNTIME_CLASS(class_name), object)

#ifdef _DEBUG
const CObject* AFX_CDECL AfxStaticDownCast(CRuntimeClass* pClass, const CObject* pObject);
CObject* AFX_CDECL AfxStaticDownCast(CRuntimeClass* pClass, CObject* pObject);
#define STATIC_DOWNCAST(class_name, object) \
    (static_cast<class_name*>(AfxStaticDownCast(RUNTIME_CLASS(class_name), object)))
#else
#define STATIC_DOWNCAST(class_name, object)(static_cast<class_name*>(object))
#endif // _DEBUG


/*============================================================================*/
// Helper macros for declaring CRuntimeClass compatible classes

#ifdef _AFXDLL
#define DECLARE_DYNAMIC(class_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static const CRuntimeClass class##class_name; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	/*__pragma(warning(suppress:26433))*/ \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC(class_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static CRuntimeClass class##class_name; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	/*__pragma(warning(suppress:26433))*/ \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#else
#define DECLARE_DYNAMIC(class_name) \
public: \
	static const CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC(class_name) \
public: \
	static CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#endif

// not serializable, but dynamically constructable
#define DECLARE_DYNCREATE(class_name) \
	DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();

#define _DECLARE_DYNCREATE(class_name) \
	_DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();

#define DECLARE_SERIAL(class_name) \
	_DECLARE_DYNCREATE(class_name) \
	AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb);

#ifdef _AFXDLL
#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL, class_init }; \
	CRuntimeClass* PASCAL class_name::GetThisClass() \
		{ return _RUNTIME_CLASS(class_name); } \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS(class_name); }

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL, class_init }; \
	CRuntimeClass* PASCAL class_name::GetThisClass() \
		{ return _RUNTIME_CLASS(class_name); } \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS(class_name); }

#else
#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }

#endif

#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
	IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL, NULL)

#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
		class_name::CreateObject, NULL)

#define IMPLEMENT_SERIAL(class_name, base_class_name, wSchema) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	extern AFX_CLASSINIT _init_##class_name; \
	_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, \
		class_name::CreateObject, &_init_##class_name) \
	AFX_CLASSINIT _init_##class_name(RUNTIME_CLASS(class_name)); \
	CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb) \
		{ pOb = (class_name*) ar.ReadObject(RUNTIME_CLASS(class_name)); \
			return ar; }

// optional bit for schema number that enables object versioning
#define VERSIONABLE_SCHEMA  (0x80000000)

/*============================================================================*/
// Exceptions

class CException : public CObject
{

};

#endif // AFX_H
