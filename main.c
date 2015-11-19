
#include "windows.h"

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
		CW_USEDEFAULT,	// 幅
		CW_USEDEFAULT,	// 高さ
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
	switch (message) {
		case WM_DESTROY:
		// ウインドウが破棄されたときの処理
		PostQuitMessage(0);
		return 0;
		default:
		// デフォルトの処理
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}