// winact.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <fstream>
using namespace std;

int main()
{
    system("title Windows Activation Fix");
    system("color 0b");
    system("echo.");
    system("echo This tool will fix your Windows Activation");
    system("echo.");
    system("echo.");
    system("echo.");
    system("echo Made by skidaim#0607"); //change this if you're gay
    system("echo.");
    system("echo.");
    system("echo.");
    system("pause");
    system("cls");
    system("cls");
    system("echo Starting...");
    string lol = getenv("windir");
    ofstream fl(lol + "\\IME\\permissions.bat");
    fl <<
          "@echo off\n"
          "takeown /F %windir%\\System32\\sppsvc.exe\n"
          "icacls %windir%\\System32 /grant administrators:F /T\n"
          "icacls %windir%\\System32\\spp /grant administrators:F /T\n"; //in case some dumbass has no permission to access to his system32 folder lmfao
    fl.close();
    system("%windir%\\IME\\permissions.bat");
    remove("C:\\Windows\\IME\\permissions.bat");
    remove("D:\\Windows\\IME\\permissions.bat");
    system("cls");
    system("echo Applying permissions...");
    //main part of the fix are these 4 cmd commands lmfao. It grants full access to Software Protection Platform to these registry keys, and the entire system32
    //fixes the 0xc00000022 error
    system("powershell.exe -c $acl = Get-Acl 'HKLM:\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SoftwareProtectionPlatform'; $rule = New-Object System.Security.AccessControl.RegistryAccessRule ('NT Service\\sppsvc','FullControl','ContainerInherit, ObjectInherit','None','Allow'); $acl.SetAccessRule($rule); Set-Acl -Path 'HKLM:\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SoftwareProtectionPlatform' -AclObject $acl");
    system("powershell.exe -c $acl = Get-Acl 'HKLM:\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SPP'; $rule = New-Object System.Security.AccessControl.RegistryAccessRule ('NT Service\\sppsvc','FullControl','ContainerInherit, ObjectInherit','None','Allow'); $acl.SetAccessRule($rule); Set-Acl -Path 'HKLM:\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SPP' -AclObject $acl");
    system("powershell.exe -c $acl = Get-Acl 'HKLM:\\SYSTEM\\CurrentControlSet\\Services\\SPPSVC'; $rule = New-Object System.Security.AccessControl.RegistryAccessRule ('NT Service\\sppsvc','FullControl','ContainerInherit, ObjectInherit','None','Allow'); $acl.SetAccessRule($rule); Set-Acl -Path 'HKLM:\\SYSTEM\\CurrentControlSet\\Services\\SPPSVC' -AclObject $acl");
    system("powershell.exe -c $acl = Get-Acl 'HKLM:\\SYSTEM\\WPA'; $rule = New-Object System.Security.AccessControl.RegistryAccessRule ('NT Service\\sppsvc','FullControl','ContainerInherit, ObjectInherit','None','Allow'); $acl.SetAccessRule($rule); Set-Acl -Path 'HKLM:\\SYSTEM\\WPA' -AclObject $acl");
    system("powershell.exe -c $acl = Get-Acl '%windir%\\System32'; $rule = New-Object System.Security.AccessControl.FileSystemAccessRule ('NT Service\\sppsvc','FullControl','ContainerInherit, ObjectInherit','None','Allow'); $acl.SetAccessRule($rule); Set-Acl -Path '%windir%\\System32' -AclObject $acl");
    system("powershell.exe -c $acl = Get-Acl '%windir%\\System32\\spp'; $rule = New-Object System.Security.AccessControl.FileSystemAccessRule ('NT Service\\sppsvc','FullControl','ContainerInherit, ObjectInherit','None','Allow'); $acl.SetAccessRule($rule); Set-Acl -Path '%windir%\\System32\\spp' -AclObject $acl");
    system("cls");
    ofstream al(lol + "\\IME\\reset.bat");
    al <<
          "@echo off\n"
          "echo. %blank%\n"
          "echo Clearing possibly corrupted licenses...\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "net stop sppsvc >nul 2>&1\n"
          "cd %windir%\\System32\\spp\\store\\2.0\n"
          "del tokens.dat >nul 2>&1\n"
          "net start sppsvc >nul 2>&1\n"
          "echo. %blank%\n"
          "echo Wait...\n"
          "echo. %blank%\n"
          "cscript.exe %windir%\\System32\\slmgr.vbs /rilc\n"; //resets activation tokens. Mainly for 0xc004f012, 0xc004f016 errors
    al.close();
    system("%windir%\\IME\\reset.bat");
    remove("C:\\Windows\\IME\\reset.bat");
    remove("D:\\Windows\\IME\\reset.bat");
    system("cls");
    ofstream bl(lol + "\\IME\\activator.bat");
    bl << 
          "@echo off\n"
          "color 0b\n"
          "echo. %blank%\n"
          "echo How to see what's your Windows version?\n"
          "echo Go to Settings, then System, then About\n"
          "echo It says your Windows version under 'Windows Specifications'\n"
          "echo If your version is different than these here, dm me\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo [1] Windows 10 Home\n"
          "echo [2] Windows 10 Home N\n"
          "echo [3] Windows 10 Pro\n"
          "echo [4] Windows 10 Pro N\n"
          "echo [5] Windows 10 Enterprise\n"
          "echo [6] Windows 10 Enterprise N\n"
          "echo [7] Windows 10 Education\n"
          "echo [8] Windows 10 Education N\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "set /p id=Select your Windows 10 version: \n"
          "if '%id%' EQU '1' goto win\n"
          "if '%id%' EQU '2' goto winn\n"
          "if '%id%' EQU '3' goto winpro\n"
          "if '%id%' EQU '4' goto winpron\n"
          "if '%id%' EQU '5' goto winen\n"
          "if '%id%' EQU '6' goto winenn\n"
          "if '%id%' EQU '7' goto wined\n"
          "if '%id%' EQU '8' goto winedn\n"
          "echo. %blank%\n"
          "echo Invalid number. Select 1-5\n"
          "echo Closing...\n"
          "echo. %blank%\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"
          "\n"
          ":win\n"
          "cls\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo Activating...\n"
          "slmgr //B /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99\n"
          "slmgr //B /skms kms8.msguides.com\n"
          "slmgr //B /ato\n"
          "echo. %blank%\n"
          "echo DONE!\n"
          "echo CHECK IF WINDOWS IS ACTIVATED\n"
          "echo. %blank%\n"
          "echo Closing...\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"
          "\n"
          ":winn\n"
          "cls\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo Activating...\n"
          "slmgr //B /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM\n"
          "slmgr //B /skms kms8.msguides.com\n"
          "slmgr //B /ato\n"
          "echo. %blank%\n"
          "echo DONE! \n"
          "echo CHECK IF WINDOWS IS ACTIVATED\n"
          "echo. %blank%\n"
          "echo Closing...\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"
          "\n"
          ":winpro\n"
          "cls\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo Activating...\n"
          "slmgr //B /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX\n"
          "slmgr //B /skms kms8.msguides.com\n"
          "slmgr //B /ato\n"
          "echo. %blank%\n"
          "echo DONE! \n"
          "echo CHECK IF WINDOWS IS ACTIVATED\n"
          "echo. %blank%\n"
          "echo Closing...\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"
          "\n"
          ":winpron\n"
          "cls\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo Activating...\n"
          "slmgr //B /ipk MH37W-N47XK-V7XM9-C7227-GCQG9\n"
          "slmgr //B /skms kms8.msguides.com\n"
          "slmgr //B /ato\n"
          "echo. %blank%\n"
          "echo DONE! \n"
          "echo CHECK IF WINDOWS IS ACTIVATED\n"
          "echo. %blank%\n"
          "echo Closing...\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"
          "\n"
          ":winen\n"
          "cls\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo Activating...\n"
          "slmgr //B /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43\n"
          "slmgr //B /skms kms8.msguides.com\n"
          "slmgr //B /ato\n"
          "echo. %blank%\n"
          "echo DONE! \n"
          "echo CHECK IF WINDOWS IS ACTIVATED\n"
          "echo. %blank%\n"
          "echo Closing...\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"
          "\n"
          ":winenn\n"
          "cls\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo Activating...\n"
          "slmgr //B /ipk DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4\n"
          "slmgr //B /skms kms8.msguides.com\n"
          "slmgr //B /ato\n"
          "echo. %blank%\n"
          "echo DONE! \n"
          "echo CHECK IF WINDOWS IS ACTIVATED\n"
          "echo. %blank%\n"
          "echo Closing...\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"
          "\n"
          ":wined\n"
          "cls\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo Activating...\n"
          "slmgr //B /ipk NW6C2-QMPVW-D7KKK-3GKT6-VCFB2\n"
          "slmgr //B /skms kms8.msguides.com\n"
          "slmgr //B /ato\n"
          "echo. %blank%\n"
          "echo DONE! \n"
          "echo CHECK IF WINDOWS IS ACTIVATED\n"
          "echo. %blank%\n"
          "echo Closing...\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"
          "\n"
          ":winedn\n"
          "cls\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo. %blank%\n"
          "echo Activating...\n"
          "slmgr //B /ipk 2WH4N-8QGBV-H22JP-CT43Q-MDWWJ\n"
          "slmgr //B /skms kms8.msguides.com\n"
          "slmgr //B /ato\n"
          "echo. %blank%\n"
          "echo DONE! \n"
          "echo CHECK IF WINDOWS IS ACTIVATED\n"
          "echo. %blank%\n"
          "echo Closing...\n"
          "timeout /T 3 /NOBREAK > nul\n"
          "exit\n"; //activator, uses msguides kms server because obviously
    bl.close();
    system("%windir%\\IME\\activator.bat");
    remove("C:\\Windows\\IME\\activator.bat");
    remove("D:\\Windows\\IME\\activator.bat");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
