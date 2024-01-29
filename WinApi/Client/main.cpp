// Client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "pch.h"
#include "framework.h"
#include "Client.h"
#include "CCore.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND      g_hWND;
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


// 지역
// 전역
// 정적 ( 데이터 영역)
// 1. 함수 안에
// 2. 파일
// 3. 클래스 안에

class CClass
{
private:
    int m_i;

    static int m_iStatic;

public:
    void func()
    {
        m_i = 0;
    }

    // 정적 멤버함수, 객체없이 호출 가능, this가 없다(멤버 접근 불가), 정적 멤버 접근가능
    static void FUNC()
    {

    }
};

int CClass::m_iStatic = 0;


/// SAL 주석
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,        /*실행 된 프로세스의 시작 주소*/
                     _In_opt_ HINSTANCE hPrevInstance, /*먼저 실행된 프로세스의 시작 주소 (초창기의 윈도우)*/
                                        /*가상 메모리로 인해 메모리 할당을 유연하게 할 수 있게되며 쓸모가 없어짐*/
                     _In_ LPWSTR    lpCmdLine,  // cmd 창에서 부가 명령어 같은 용도
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);

    // 윈도우 정보 등록
    MyRegisterClass(hInstance);

    // 윈도우 생성
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // Core 초기화
    if (FAILED(CCore::GetInst()->init(g_hWND, POINT{1280, 768})))
    {
        MessageBox(nullptr, L"Core 객체 초기화 실패", L"ERROR", MB_OK);
         
        return FALSE;
    }

    // 단축기 테이블 정보 로딩
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

    MSG msg;

    // GetMessage
    // 메세지 큐에서 메세지 확인 될 때 까지 대기
    // msg.message = WM_QUIT 인 경우 false 를 반환 -> 프로그램 종료

    // PeekMessage
    // 메시지 유무와 관계없이 반환
    // 메시지큐에서 메시지를 확인한 경우 true, 메시지큐에 메시지가 없는 경우 false를 반환한다.

    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            int iTime = GetTickCount();

            if (WM_QUIT == msg.message)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
   
        }
        // 메세지가 발생하지 않는 대부분의 시간
        else
        {
           
            // Game 코드 수행
            // 디자인 패턴 (설계 유형)
            // 싱클톤 패턴

            CCore::GetInst()->progress();
        }
        
    }



    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CLIENT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   g_hWND = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!g_hWND)
   {
      return FALSE;
   }

   ShowWindow(g_hWND, nCmdShow);
   UpdateWindow(g_hWND);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT: // 무효화 영역(invalidate)이 발생한 경우
        {
            PAINTSTRUCT ps;
            
            // Device Context 만들어서 ID를 반환
            HDC hdc = BeginPaint(hWnd, &ps); // Device Context (그리기)
            // DC의 목적지는 hWnd
            // DC의 펜은 기본 펜(BLACK)
            // DC의 브러쉬는 기본 브러쉬(WHITE)
            // HDC는 ID 값 가진 어떤 구조체를 만드는것으로 전처리 되어있다.
            // Device Context? 그리기 작업 수행, 필요한 Data 집합체
            /*
            // 직접 펜과 브러쉴르 만들어서 DC에 적용
            HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255,0,0));
            HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

            // 기본 펜과 브러쉬 ID 값을 받아 둠
            HPEN hDefaultPen = (HPEN)SelectObject(hdc, hRedPen);
            HBRUSH hDefaultBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);
            */
            // void 포인터를 캐스팅해줘야함. 왜? SelectObject()함수는 범용적인 함수임
            // HPEN 만 반환하는게 아니라 HBRUSH를 반환할 수도  있고 여러가지 object를 반환할 수 있음. void*를 반환하고
            // 사용자가 직접 타입 캐스팅해줘야함.
  
            // 윈도우 핸들
            // 윈도우 좌표 단위는 픽셀
            // HDC?
            
            //Rectangle(hdc, 1180, 668, 1280, 768);
    

      

            EndPaint(hWnd, &ps);
        }
        break;
    
    case WM_LBUTTONDOWN:
        break;
    case WM_MOUSEMOVE:
        break;
    case WM_LBUTTONUP: 
        break;
    case WM_TIMER:
        break;

 
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
