#ifndef T100DEBUG_H
#define T100DEBUG_H

#include <stdarg.h>

namespace Utility
{
#ifdef _CONSOLE
    inline void Print( const char* msg ) { printf("%s", msg); }
    inline void Print( const wchar_t* msg ) { wprintf(L"%ws", msg); }
#else
    inline void Print( const char* msg ) { OutputDebugStringA(msg); }
    inline void Print( const wchar_t* msg ) { OutputDebugString(msg); }
#endif

    inline void Printf( const char* format, ... )
    {
        char buffer[256];
        va_list ap;
        va_start(ap, format);
        vsprintf_s(buffer, 256, format, ap);
        va_end(ap);
        Print(buffer);
    }

    inline void Printf( const wchar_t* format, ... )
    {
        wchar_t buffer[256];
        va_list ap;
        va_start(ap, format);
        vswprintf(buffer, 256, format, ap);
        va_end(ap);
        Print(buffer);
    }

#ifndef RELEASE
    inline void PrintSubMessage( const char* format, ... )
    {
        Print("--> ");
        char buffer[256];
        va_list ap;
        va_start(ap, format);
        vsprintf_s(buffer, 256, format, ap);
        va_end(ap);
        Print(buffer);
        Print("\n");
    }
    inline void PrintSubMessage( const wchar_t* format, ... )
    {
        Print("--> ");
        wchar_t buffer[256];
        va_list ap;
        va_start(ap, format);
        vswprintf(buffer, 256, format, ap);
        va_end(ap);
        Print(buffer);
        Print("\n");
    }
    inline void PrintSubMessage( void )
    {
    }
#endif

} // namespace Utility

#ifdef ERROR
#undef ERROR
#endif
#ifdef ASSERT
#undef ASSERT
#endif
#ifdef HALT
#undef HALT
#endif

#define HALT( ... ) ERROR( __VA_ARGS__ ) __debugbreak();

#ifdef RELEASE

    #define ASSERT( isTrue, ... ) (void)(isTrue)
    #define WARN_ONCE_IF( isTrue, ... ) (void)(isTrue)
    #define WARN_ONCE_IF_NOT( isTrue, ... ) (void)(isTrue)
    #define ERROR( msg, ... )
    #define DEBUGPRINT( msg, ... ) do {} while(0)
    #define ASSERT_SUCCEEDED( hr, ... ) (void)(hr)

    #define PRINTMATRIX( msg, m ) (void)(m)

#else	// !RELEASE

    #define STRINGIFY(x) #x
    #define STRINGIFY_BUILTIN(x) STRINGIFY(x)
    #define ASSERT( isFalse, ... ) \
        if (!(bool)(isFalse)) { \
            Utility::Print("\nAssertion failed in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            Utility::PrintSubMessage("\'" #isFalse "\' is false"); \
            Utility::PrintSubMessage(__VA_ARGS__); \
            Utility::Print("\n"); \
            __debugbreak(); \
        }

    #define ASSERT_SUCCEEDED( hr, ... ) \
        if (FAILED(hr)) { \
            Utility::Print("\nHRESULT failed in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            Utility::PrintSubMessage("hr = 0x%08X", hr); \
            Utility::PrintSubMessage(__VA_ARGS__); \
            Utility::Print("\n"); \
            __debugbreak(); \
        }


    #define WARN_ONCE_IF( isTrue, ... ) \
    { \
        static bool s_TriggeredWarning = false; \
        if ((bool)(isTrue) && !s_TriggeredWarning) { \
            s_TriggeredWarning = true; \
            Utility::Print("\nWarning issued in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
            Utility::PrintSubMessage("\'" #isTrue "\' is true"); \
            Utility::PrintSubMessage(__VA_ARGS__); \
            Utility::Print("\n"); \
        } \
    }

    #define WARN_ONCE_IF_NOT( isTrue, ... ) WARN_ONCE_IF(!(isTrue), __VA_ARGS__)

    #define ERROR( ... ) \
        Utility::Print("\nError reported in " STRINGIFY_BUILTIN(__FILE__) " @ " STRINGIFY_BUILTIN(__LINE__) "\n"); \
        Utility::PrintSubMessage(__VA_ARGS__); \
        Utility::Print("\n");

    #define DEBUGPRINT( msg, ... ) \
    Utility::Printf( msg "\n", ##__VA_ARGS__ );

    #define PRINTMATRIX( msg, m ) \
        Utility::Printf(msg "\n"); \
        Utility::Printf("%4.2f %4.2f %4.2f %4.2f\n", m._11, m._12, m._13, m._14); \
        Utility::Printf("%4.2f %4.2f %4.2f %4.2f\n", m._21, m._22, m._23, m._24); \
        Utility::Printf("%4.2f %4.2f %4.2f %4.2f\n", m._31, m._32, m._33, m._34); \
        Utility::Printf("%4.2f %4.2f %4.2f %4.2f\n\n", m._41, m._42, m._43, m._44);

#endif

#define BreakIfFailed( hr ) if (FAILED(hr)) __debugbreak()

#endif // T100DEBUG_H
