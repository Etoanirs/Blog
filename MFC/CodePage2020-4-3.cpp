#include <windows.h>
#include <stdio.h>
#if 0
int main( void )
{
  SetConsoleOutputCP(65001);  //ConsoleApi2.h (via Wincon.h, include Windows.h)
  /*
  To determine a console's current output code page, use the GetConsoleOutputCP function. To set and retrieve a console's input code page, use the SetConsoleCP and GetConsoleCP functions.
  注册表信息
  \HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage
  ACP 65001
  MACCP 65001
  OEMCP 65001

  */
  printf("简体中文\n");
  return 0;
}
#elif 2
/*
BOOL EnumSystemCodePagesA(
  CODEPAGE_ENUMPROCA lpCodePageEnumProc,
  DWORD              dwFlags
);
*/
BOOL CALLBACK EnumCodePagesProc(LPTSTR lpCodePageString)    //Winnls.h (include Windows.h)
{
  printf("%s\n", lpCodePageString);
  return FALSE;
}
int main(int argc, char const *argv[])
{
  //winnls.h (include Windows.h)
  EnumSystemCodePages(EnumCodePagesProc,CP_INSTALLED);    //CP_SUPPORTED

  return 0;
}
#else
int main(int argc, char const *argv[])
{
  CPINFO info;
  UINT iCP = 936; //GBK
  GetCPInfo(iCP, &info);    //winnls.h (include Windows.h)
  /*
  BOOL GetCPInfo(
  UINT CodePage,      // code page identifier
  LPCPINFO lpCPInfo   // information buffer);
  Parameters
  CP_ACP Use the system default–ANSI code page.
  CP_MACCP Windows NT/2000/XP: Use the system default–Macintosh code page.
  CP_OEMCP Use the system default–OEM code page.
  */
  printf("Code page %d's default char is [%c]\n", iCP, info.DefaultChar[0]);
  printf("Max size of a char: %d\n", info.MaxCharSize);
  int i;
  const int iMaxLeadBytePairNum = 5;
  for (i = 0; i < iMaxLeadBytePairNum; i++)
  {
    if (info.LeadByte[i * 2] == 0 && info.LeadByte[i * 2 + 1] == 0)
        break;
    printf("Lead byte pair %d: 0x%02X-0x%02X\n", i, info.LeadByte[i * 2], info.LeadByte[i * 2 + 1]);
  }
  return 0;
}
#endif
