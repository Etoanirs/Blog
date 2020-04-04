// 此源文件在Windows平台上必须保存为Unicode格式（即UTF-16小尾）
// 因为包含的汉字“𪚥”，不能在简体中文版Windows默认的代码页936（即GBK）中表示
// 该汉字在UTF-16小尾序中用4个字节表示
// Windows操作系统能正确显示这样的在UTF-16需用4字节表示的字符
// 但是Windows API不能正确处理这样的在UTF-16需用4字节表示的字符，把它判定为2个UCS-2字符
#if 0
#include <windows.h>
#include <cstdio>
#include <wchar.h>
int main()
{
	const wchar_t lwc[] = L"𪚥";

	MessageBoxW(NULL, lwc, lwc, MB_OK);

	int i = wcslen(lwc);
	printf("%d\n", i);
	int j = lstrlenW(lwc);
	printf("%d\n", j);

	return 0;
}
#else
#include <windows.h>
#include <stdio.h>
int main() {
	char a1[128], a2[128] = { "Hello" };
	wchar_t w = L'页';
	int n1 = 0, n2= 5;
	wchar_t w1[128];
	int m1 = 0;

	n1 = WideCharToMultiByte(CP_UTF8, 0, &w, 1, a1, 128, NULL, NULL);
	m1 = MultiByteToWideChar(CP_UTF8, 0, a2, n2, w1, 128);
  printf("n1 =%d, m1 = %d\n",n1,m1 );

}

/*
源代码中字符串 "Hello 中国！"根据源代码的编码方式识别
w_char 在Window中定义为 16bit 但是在gcc中定义为32bit
*/
#endif
