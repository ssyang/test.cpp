// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ct1.h"
#include "ct2.h"
#include "ct3.h"

#include <atltrace.h>
#include <windows.h>

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
    switch (fdwCtrlType)
    {
        // Handle the CTRL-C signal.
    case CTRL_C_EVENT:
        ATLTRACE(L"Ctrl-C event\n\n");
        Beep(750, 300);
        return TRUE;
        // CTRL-CLOSE: confirm that the user wants to exit.
    case CTRL_CLOSE_EVENT:
        Beep(600, 200);
        ATLTRACE(L"Ctrl-Close event\n\n");
        return TRUE;
        // Pass other signals to the next handler.
    case CTRL_BREAK_EVENT:
        Beep(900, 200);
        ATLTRACE(L"Ctrl-Break event\n\n");
        return FALSE;

    case CTRL_LOGOFF_EVENT:
        Beep(1000, 200);
        ATLTRACE(L"Ctrl-Logoff event\n\n");
        return FALSE;

    case CTRL_SHUTDOWN_EVENT:
        Beep(750, 500);
        ATLTRACE(L"Ctrl-Shutdown event\n\n");
        return FALSE;

    default:
        return FALSE;
    }
}

int main()
{
    std::wcout << L"Hello World!\n";
    
    //ct1::get_instance().info();
    ct2::get_instance().info();
    //ct3::get_instance().info();

    if (SetConsoleCtrlHandler(CtrlHandler, TRUE)) {
        ATLTRACE(L"\nThe Control Handler is installed.\n");
        ATLTRACE(L"\n -- Now try pressing Ctrl+C or Ctrl+Break, or");
        ATLTRACE(L"\n    try logging off or closing the console...\n");
        ATLTRACE(L"\n(...waiting in a loop for events...)\n\n");

        while (true) {}
    }
    else {
        ATLTRACE(L"\nERROR: Could not set control handler");
        return 1;
    }

    std::wcout << L"Good bye!\n";
}
