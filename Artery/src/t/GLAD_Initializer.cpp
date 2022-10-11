#include "GLAD_Initializer.h"
//#include "winapi_error.h"
//#include "GlException.h"

namespace opengl {
    
    LRESULT CALLBACK FalseWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        default:
        {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        }

        return 0;
    }

    HGLRC CreateFalseRenderingContext(HDC hDC)
    {
        PIXELFORMATDESCRIPTOR pfd{};

        // Choose a stub pixel format in order to get access to wgl functions.
        ::SetPixelFormat(
            hDC,   // Device context.
            1,     // Index that identifies the pixel format to set. The various pixel formats supported by a device context are identified by one-based indexes.
            &pfd); // [out] Pointer to a PIXELFORMATDESCRIPTOR structure that contains the logical pixel format specification.

        // Create a fiction OpenGL rendering context.
        HGLRC hGLRC = ::wglCreateContext(hDC);

        // Throw exception if failed to create OpenGL rendering context.
        if (hGLRC == NULL)
            LOG("ERROR opengl::CreateFalseRenderingContext() -> wglCreateContext()");

        // Make just created OpenGL rendering context current.
        if (!::wglMakeCurrent(hDC, hGLRC))
            LOG("ERROR opengl::CreateFalseRenderingContext() -> wglMakeCurrent()");

        return hGLRC;
    }

    void Initialize_GLAD_Library()
    {
        static bool s_IsInitialized = false;

        if (s_IsInitialized)
            return;

        s_IsInitialized = true;

        const char* wndClassName = "FalseWindow";
        HINSTANCE hInst = ::GetModuleHandle(NULL); // get application handle

        // Create a struct describing window class.
        WNDCLASSEX wcex;
        wcex.cbSize = sizeof(WNDCLASSEX);                                 // struct size
        wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;                 // window style
        wcex.lpfnWndProc = FalseWndProc;                                       // pointer to window function WndProc
        wcex.cbClsExtra = 0;                                                  // shared memory
        wcex.cbWndExtra = 0;                                                  // number of additional bytes
        wcex.hInstance = hInst;                                              // current application's handle
        wcex.hIcon = ::LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));  // icon handle
        wcex.hCursor = ::LoadCursor(NULL, IDC_CROSS);                        // cursor handle
        wcex.hbrBackground = (HBRUSH)(COLOR_MENU + 1);                             // background brush's handle
        wcex.lpszMenuName = NULL;                                               // pointer to a string - menu name
        wcex.lpszClassName = wndClassName;                                       // pointer to a string - window class name
        wcex.hIconSm = ::LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));  // small icon's handle

        // Register window class for consequtive calls of CreateWindow or CreateWindowEx.
        if (!::RegisterClassEx(&wcex))
            LOG("ERROR opengl::Initialize_GLAD_Library() -> RegisterClassEx()");

        // Create a FICTION window based on the previously registered window class.
        HWND hWnd = ::CreateWindow(wndClassName,                  // window class name
            wndClassName,                  // window title
            WS_OVERLAPPEDWINDOW,           // window type
            CW_USEDEFAULT, CW_USEDEFAULT,  // window's start position (x, y)
            100,                           // window's  width in pixels
            100,                           // window's  height in pixels
            NULL,                          // parent window
            NULL,                          // menu handle
            hInst,                         // application handle
            NULL);                         // pointer to an object passed to the window with CREATESTRUCT struct (field lpCreateParams), pointer to which is contained in lParam parameter of WM_CREATE message

// Throw exception if CreateWindow() failed.
        if (!hWnd)
            LOG("ERROR opengl::Initialize_GLAD_Library() -> CreateWindow()");

        // Get device context for the window.
        HDC hDC = ::GetDC(hWnd);

        // Create a fiction rendering context.
        HGLRC tempOpenGLContext = CreateFalseRenderingContext(hDC);

        if (!gladLoadGL())
            std::cout << "opengl::Initialize_GLAD_Library() -> gladLoadGL()\n";

        ::DestroyWindow(hWnd);

        MSG msg = { 0 };
        while (msg.message != WM_QUIT)
        {
            while (GetMessage(&msg, NULL, 0, 0))
            {
                ::TranslateMessage(&msg);
                ::DispatchMessage(&msg);
            }
        }

        ::wglMakeCurrent(NULL, NULL);          // remove the temporary context from being active
        ::wglDeleteContext(tempOpenGLContext); // delete the temporary OpenGL context
    }

}