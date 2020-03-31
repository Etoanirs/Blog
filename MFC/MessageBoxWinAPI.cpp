#include <windows.h>
/*
  windows.h 是最终要的一个头文件，几乎包含了所有重要的 Windows头文件
  windef.h 基本数据类型定义
  winnt.h 支持Unicode的类型定义
  winbase.h 内核函数
  winuser.h 用户界面函数
  wingdi.h  图形设备接口函数
*/
int
WINAPI        //#define WINAPI __stdcall    函数调用约定
WinMain       //Windows程序的入口函数
(
  HINSTANCE hInstance,
  HINSTANCE prevInstance,
  LPSTR lpCmdLine,    //Long Pointer 是16位Windows的产物
  int iShowCmd
)
{
  int ret = MessageBox(nullptr,TEXT("Hello Windows98!"),TEXT("SayHello"),MB_YESNO|MB_ICONINFORMATION|MB_DEFBUTTON2);
  switch (ret) {
    case IDYES:
    MessageBox(nullptr,TEXT("您点击了YES!"),TEXT("YES"),MB_OK);
    break;
    case IDNO:
    MessageBox(nullptr,TEXT("您点击了NO!"),TEXT("NO"),MB_OK);
    break;
  }
  return 0;
}
