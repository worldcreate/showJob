#include "JobTable.h"
#include <stdio.h>
#include "windows.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

static JobTable jt;

inline blankRead(){
	while(getchar() != '\n');
}

// 関数のプロトタイプ宣言
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// エントリポイント
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	WNDCLASSEX wcex; // ウインドウクラス構造体
	HWND hWnd;	// ウインドウハンドル
	MSG msg;	// メッセージ構造体

	// ウィンドウクラス構造体を設定します。
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "ModelApp";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// ウインドウクラスを登録します。
	RegisterClassEx(&wcex);

	// ウインドウを作成します。
	hWnd = CreateWindow(wcex.lpszClassName, // ウインドウクラス名
		"Cursor", // キャプション文字列
		WS_OVERLAPPEDWINDOW,	// ウインドウのスタイル
		CW_USEDEFAULT,	// 水平位置
		CW_USEDEFAULT,	// 垂直位置
		WINDOW_WIDTH,	// 幅
		WINDOW_HEIGHT,	// 高さ
		NULL,	// 親ウインドウ
		NULL,	// ウインドウメニュー
		hInstance,	// インスタンスハンドル
		NULL
	);	// WM_CREATE情報

	// ウインドウを表示します。
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// メッセージループ
	while(GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// 戻り値を返します。
	return msg.wParam;
}

// ウインドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam){
// メッセージの種類に応じて処理を分岐します。
	static HDC hdcMem;
	static HBITMAP hBitmap;
	static int BufferWidth;
	static int BufferHeight;
	static RECT rc;
	static int srcX=0;
	static int srcY=0;
	switch (message) {
		case WM_CREATE:{
			int m,j;
			char delm;
			scanf("%d%c%d",&j,&delm,&m);
			blankRead();
			for(int i=0;i<m;i++){
				char temp[256];
				gets(temp);
				jt.addMachine(temp);
			}
			HDC hdc;
			hdc=GetDC(hWnd);
			hBitmap=CreateCompatibleBitmap(hdc,BufferWidth=jt.getMaxTime()+30,BufferHeight=JobTable::jobHeight*m+30);
			hdcMem=CreateCompatibleDC(NULL);
			SelectObject(hdcMem,hBitmap);
			PatBlt(hdcMem,0,0,BufferWidth,BufferHeight,WHITENESS);
			jt.draw(hdcMem);
			GetClientRect(hWnd,&rc);
		}
		return 0;
		case WM_PAINT:{
			PAINTSTRUCT ps;
			HDC hdc=BeginPaint(hWnd,&ps);
			BitBlt(hdc,0,0,rc.right,rc.bottom,hdcMem,srcX,srcY,SRCCOPY);
			EndPaint(hWnd,&ps);
		}
		return 0;
		case WM_KEYDOWN:
			if(GetKeyState(VK_LEFT)&0x80){
				srcX-=10;
			}else if(GetKeyState(VK_RIGHT)&0x80){
				srcX+=10;
			}else if(GetKeyState(VK_UP)&0x80){
				srcY-=10;
			}else if(GetKeyState(VK_DOWN)&0x80){
				srcY+=10;
			}
			if(srcX<0)
				srcX=0;
			if(srcY<0)
				srcY=0;
			InvalidateRect(hWnd,NULL,TRUE);
		return 0;
		case WM_DESTROY:
			// ウインドウが破棄されたときの処理
			PostQuitMessage(0);
		return 0;
		default:
		// デフォルトの処理
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}