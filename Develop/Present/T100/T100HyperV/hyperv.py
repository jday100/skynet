import os
import sys
import ctypes
import subprocess

g_hyperv_path       = ""

def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False

def admin():
    if not is_admin():
        ctypes.windll.shell32.ShellExecuteW(None, "runas", sys.executable, " ".join(sys.argv), None, 1)
        sys.exit()

    print("admin")


def args():
    print("Run args...")
    count = len(sys.argv)

    if(count != 2):
        return 
    
    value   = sys.argv[1]
    
    match value:
        case 'create':
            create()

def create():
    print("Run hyperv create...")

    cmd     = "PowerShell New-VM -Name \"WinVM\" -MemoryStartupBytes 1GB -NewVHDPath \"C:\\vm\\WinVM.vhdx\" -NewVHDSizeBytes 2GB"
    
    print(cmd)

    subprocess.call(cmd)

    print("Success")

def start():
    print("Run hyperv start...")

    print("Success")


if __name__ == "__main__":
    print("Run hyperv...")
    args()