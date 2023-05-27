#include <windows.h>
#include <CommCtrl.h>
#include <windowsx.h>
#include "resource.h"


INT_PTR CALLBACK DlgProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
) 
{
	// 获取当前实例句柄
	HINSTANCE hInstance = GetModuleHandleW(0);

	// 获取下拉框句柄
	HWND hCombox1 = GetDlgItem(hwnd, IDC_COMBO1);

	switch (uMsg)
	{
	case WM_INITDIALOG:

	{	
		ComboBox_AddString(hCombox1, L"选项1");
		ComboBox_AddString(hCombox1, L"选项2");
		ComboBox_SetCurSel(hCombox1, 0);
		break;
	}
	case WM_CLOSE:
	{
		EndDialog(hwnd, 0);
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_COMBO1:
		{
			// 下拉框改变
			if (HIWORD(wParam) == CBN_SELCHANGE) {
				int index = ComboBox_GetCurSel(hCombox1);
				HBITMAP hBitmap = LoadBitmapW(hInstance, MAKEINTRESOURCEW(IDB_BITMAP1 + index));
				SendDlgItemMessageW(hwnd, IDC_STATIC1, STM_SETIMAGE, IMAGE_BITMAP, (LONG)hBitmap);
			}
			break;
		}
		case IDCANCEL:
		{
			SendMessageW(hwnd, WM_CLOSE, wParam, lParam);
			break;
		}
		case IDOK:
		{

			break;
		}
		default:
			break;
		}
	}
	default:
		return FALSE;
		break;
	}

	return TRUE;
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE preInstance,
	LPSTR lpCmdLine,
	int nShowCmd
) 
{
	DialogBoxW(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	return 0;
}