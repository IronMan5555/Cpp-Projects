#include <windows.h>
#include "helper.h"

#define SHUTDOWN 1
#define RESTART 2
#define LOGOFF 3
#define CANCEL 4

void AddControls(HWND);

HINSTANCE hInstance;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    MSG m;

    InitInstance(hInstance, nCmdShow, "Power Options");

    while(GetMessage(&m, 0, 0, 0))
    {
        TranslateMessage(&m);
        DispatchMessage(&m);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_COMMAND:
        switch(wParam)
        {
        case SHUTDOWN:
            system("start PowerOff.bat");
            PostQuitMessage(2);
            break;

        case RESTART:
            system("start restart.bat");
            PostQuitMessage(3);
            break;

        case LOGOFF:
            system("start logoff.bat");
            PostQuitMessage(4);
            break;

        case CANCEL:
            PostQuitMessage(1);
            break;
        }
        break;

    case WM_CREATE:
        AddControls(hWnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}

void AddControls(HWND hWnd)
{
    CreateWindow("BUTTON", "Shutdown", WS_VISIBLE | WS_CHILD, 5, 80, 270, 38,
		hWnd, (HMENU)SHUTDOWN, NULL, NULL);

    CreateWindow("BUTTON", "Restart", WS_VISIBLE | WS_CHILD, 5, 125, 270, 38,
		hWnd, (HMENU)RESTART, NULL, NULL);

    CreateWindow("BUTTON", "Log off", WS_VISIBLE | WS_CHILD, 5, 170, 270, 38,
		hWnd, (HMENU)LOGOFF, NULL, NULL);

    CreateWindow("BUTTON", "Cancel", WS_VISIBLE | WS_CHILD, 5, 215, 270, 38,
		hWnd, (HMENU)CANCEL, NULL, NULL);
}
