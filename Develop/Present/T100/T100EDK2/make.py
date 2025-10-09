import os
import sys
import subprocess

import ctypes
from ctypes import wintypes

kernel32 = ctypes.windll.kernel32
user32 = ctypes.windll.user32

EnumWindowsProc     = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)

g_project_path      = ""
g_compiler_path     = ""

g_project_build             = ""
g_project_code              = ""
g_project_include           = ""
g_project_source            = ""
g_project_build_filename    = ""

g_edk2_path                 = "C:\\zmsys2\\msys2\\home\\user\\edk2"

def args():
    print("Run args...")
    count = len(sys.argv)

    if(count != 9):
        return

    global g_project_path
    global g_compiler_path

    global g_project_build
    global g_project_code
    global g_project_include
    global g_project_source
    global g_project_build_filename

    value               = sys.argv[1]
    g_project_path      = sys.argv[2]
    g_compiler_path     = sys.argv[3]

    g_project_build             = sys.argv[4]
    g_project_code              = sys.argv[5]
    g_project_include           = sys.argv[6]
    g_project_source            = sys.argv[7]
    g_project_build_filename    = sys.argv[8]

    match value:
        case 'build':
            build_test()
            return
            build()
            edk2_build()
        case 'clean':
            clean()
        case 'rebuild':
            rebuild()   
        case 'run':
            run()


def build():
    print("Run project build...")

    global g_project_path
    global g_compiler_path

    global g_project_build
    global g_project_code
    global g_project_include
    global g_project_source
    global g_project_build_filename

    bin     = "%s\\g++ -I%s\\%s\\%s" % (g_compiler_path, g_project_path, g_project_code, g_project_include)

    line    = "%s\\%s\\%s\\" % (g_project_path, g_project_code, g_project_source)

    cmd     = "%s %s%s -o %s\\%s\\%s" % (bin, line, "main.cpp", g_project_path, g_project_build, g_project_build_filename)

    print(cmd)

    subprocess.call(cmd)

    print("Success")

def clean():
    print("Run project clean...")
    global g_project_path
    global g_project_build
    global g_project_build_filename

    """
    cmd 	= "cmd.exe /c del /q %s\\%s\\%s" % (g_project_path, g_project_build, g_project_build_filename)

    print(cmd)

    subprocess.call(cmd)
    """

    edk2_build()

    print("Success")

def rebuild():
    print("Run project rebuild...")
    clean()
    build()

def run():
    print("Run project target...")
    global g_project_path
    global g_project_build
    global g_project_build_filename

    cmd 	= "%s\\%s\\%s" % (g_project_path, g_project_build, g_project_build_filename)

    print(cmd)

    subprocess.call(cmd)

    print("Success")

def edk2_build():
    print("EDK2...")

    global g_edk2_path

    #cmd     = "cmd.exe /c %s\\%s\\%s" % (g_edk2_path, "BaseTools", "make")
    #C:\zmsys2\msys2\mingw64.exe

    cmd     = "cmd.exe /c %s" % ("C:\\zmsys2\\msys2\\mingw64.exe")

    print(cmd)

    subprocess.call(cmd)

def find_windows_by_pid(pid):
    def callback(hwnd, lparam):
        #if ctypes.cast(lparam, ctypes.POINTER(wintypes.DWORD)).contents.value == pid:
        print("{hwnd}")
        return True
    print(user32)

    ctypes.windll.user32.EnumWindows(EnumWindowsProc(callback), 0)

def build_test():
    cmd     = "C:\\zmsys2\\msys2\\mingw64.exe"

    class STARTUPINFO(ctypes.Structure):
        _fields_ = [
                ("cb", wintypes.DWORD),
                ("lpReserved", wintypes.LPSTR),
                ("lpDesktop", wintypes.LPSTR),
                ("lpTitle", wintypes.LPSTR),
                ("dwX", wintypes.DWORD),
                ("dwY", wintypes.DWORD),
                ("dwXSize", wintypes.DWORD),
                ("dwYSize", wintypes.DWORD),
                ("dwXCountChars", wintypes.DWORD),
                ("dwYCountChars", wintypes.DWORD),
                ("dwFillAttribute", wintypes.DWORD),
                ("dwFlags", wintypes.DWORD),
                ("wShowWindow", wintypes.WORD),
                ("cbReserved2", wintypes.WORD),
                ("lpReserved2", ctypes.c_void_p),
                ("hStdInput", wintypes.HANDLE),
                ("hStdOutput", wintypes.HANDLE),
                ("hStdError", wintypes.HANDLE)
            ]

    class PROCESS_INFORMATION(ctypes.Structure):
        _fields_ = [
            ("hProcess", wintypes.HANDLE),
            ("hThread", wintypes.HANDLE),
            ("dwProcessId", wintypes.DWORD),
            ("dwThreadId", wintypes.DWORD)
        ]

    startupinfo = STARTUPINFO()
    process_information = PROCESS_INFORMATION()

    creation_flags  = 0x00000010
    startupinfo.cb = ctypes.sizeof(STARTUPINFO)

    success = kernel32.CreateProcessA(
            b"C:\\zmsys2\\msys2\\mingw64.exe",
            None,
            None,
            None,
            False,
            creation_flags,
            None,
            None,
            ctypes.byref(startupinfo),
            ctypes.byref(process_information)
        )

    if success:
        print("Success")
    else:
        error_code = kernel32.GetLastError()
        print("Error")



    find_windows_by_pid(process_information.dwProcessId)

    return

if __name__ == "__main__":
    print("Run project build...")
    args()
