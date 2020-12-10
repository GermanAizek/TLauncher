#include <windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int CALLBACK sub_4013B0(HINSTANCE hInstance, int, char*, int nCmdShow); // idb
BOOL CALLBACK EnumFunc(HWND, LPARAM); // idb
void CALLBACK TimerFunc(HWND, UINT, UINT, DWORD); // idb
FILE* sub_401C10();
int __cdecl sub_401C30(char*, char*, size_t); // idb
FILE* sub_401ED0();
signed int __cdecl sub_4020C0(int a1, uint8_t* a2);
int __cdecl sub_4021A0(int a1);
int __cdecl sub_4023B0(char*, LPBYTE lpData, DWORD cbData); // idb
int __cdecl sub_402690(char*); // idb
int __cdecl sub_4027A0(LPCSTR lpSubKey, int); // idb
LONG __cdecl sub_402920(LPCSTR lpSubKey, int a2);
int __cdecl sub_402CB0(LPCSTR lpSubKey, int); // idb
char* __cdecl sub_403100(char* a1, char* a2, char* a3, int a4);
int __cdecl sub_4033F0(char*, int, int, int, int, char*); // idb
int __cdecl sub_403790(char*, char*); // idb
int __cdecl sub_403D20(char*, size_t); // idb
void sub_4042B0();
int __cdecl sub_404740(char*, int); // idb
char* __cdecl sub_4051E0(char* a1, int a2);
size_t __cdecl sub_405390(char* a1, int a2);
void __cdecl sub_405B60(char* a1);
int __cdecl sub_405D30(char*); // idb
BOOL sub_406830();
int __cdecl sub_406860(int, LPDWORD lpExitCode); // idb
void __cdecl sub_406B70(); // idb
int sub_406C00();