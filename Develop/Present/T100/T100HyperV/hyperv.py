import sys
import subprocess

g_hyperv_path       = ""

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


if __name__ == "__main__":
    print("Run hyperv...")
    args()