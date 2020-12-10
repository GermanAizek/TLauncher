#include <windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int __stdcall sub_4013B0(HINSTANCE hInstance, int, char *, int nCmdShow); // idb
BOOL __stdcall EnumFunc(HWND, LPARAM); // idb
void __stdcall TimerFunc(HWND, UINT, UINT, DWORD); // idb
FILE *sub_401C10();
int __cdecl sub_401C30(char *, char *, size_t); // idb
FILE *sub_401ED0();
signed int __cdecl sub_4020C0(int a1, uint8_t *a2);
int __cdecl sub_4021A0(int a1);
int __cdecl sub_4023B0(char *, LPBYTE lpData, DWORD cbData); // idb
int __cdecl sub_402690(char *); // idb
int __cdecl sub_4027A0(LPCSTR lpSubKey, int); // idb
LONG __cdecl sub_402920(LPCSTR lpSubKey, int a2);
int __cdecl sub_402CB0(LPCSTR lpSubKey, int); // idb
char *__cdecl sub_403100(char *a1, char *a2, char *a3, int a4);
int __cdecl sub_4033F0(char *, int, int, int, int, char *); // idb
int __cdecl sub_403790(char *, char *); // idb
int __cdecl sub_403D20(char *, size_t); // idb
void sub_4042B0();
int __cdecl sub_404740(char *, int); // idb
char *__cdecl sub_4051E0(char *a1, int a2);
size_t __cdecl sub_405390(char *a1, int a2);
void __cdecl sub_405B60(char *a1);
int __cdecl sub_405D30(char *); // idb
BOOL sub_406830();
int __cdecl sub_406860(int, LPDWORD lpExitCode); // idb
void __cdecl sub_406B70(); // idb
int sub_406C00();


int dword_407070[] = { 4294967295 }; // weak
int dword_407074[] = { 0 }; // weak
int dword_408000 = 60; // weak
int (*off_408030)[97] = &dword_40707C; // weak
const CHAR WindowName = '\0'; // idb
int dword_40A010; // weak
int dword_40A014; // weak
int dword_40A018; // weak
DWORD ExitCode; // idb
int dword_40A020; // weak
int dword_40A024; // weak
int dword_40A028; // weak
int dword_40A040; // weak
int dword_40A060; // weak
HWND hWnd; // idb
int dword_40A080; // weak
FILE *dword_40A090; // idb
char byte_40A0A0; // idb
char byte_40A1A3[]; // weak
char word_40A1A4[]; // idb
char byte_40A2A7[]; // weak
char dword_40A2A8[]; // idb
int dword_40A2AC; // weak
int dword_40A2B0; // weak
char byte_40A2B4[]; // weak
HANDLE hProcess; // idb
HANDLE hObject; // idb
int dword_4122B8; // weak
DWORD dwCreationFlags; // idb
int dword_4122D0; // weak
int dword_4122D4; // weak
int dword_4122D8; // weak
int dword_4122DC; // weak
char byte_4122E0; // idb
char byte_412360; // idb
char word_4123E0[]; // idb
char word_412460[]; // idb
char byte_4124E0[128]; // idb
char byte_412560[260]; // idb
char byte_412664[268]; // idb
char Buffer[272]; // idb
HMODULE hModule; // idb
CHAR Caption[]; // idb
int dword_412894; // weak
char byte_412898; // weak
char Text[]; // idb
const CHAR File; // idb


//----- (004013B0) --------------------------------------------------------
int __stdcall sub_4013B0(HINSTANCE hInstance, int a2, char *a3, int nCmdShow)
{
  int v4; // eax@1
  signed int v6; // edi@5
  signed int v7; // edi@8
  int v8; // eax@10
  int v9; // eax@34
  signed int v10; // esi@36
  HANDLE v11; // eax@39
  int v12; // ebx@40
  int v13; // eax@40
  HWND v14; // ebx@48
  MSG Msg; // [sp+30h] [bp-158h]@19
  struct tagRECT Rect; // [sp+50h] [bp-138h]@40
  char v17; // [sp+60h] [bp-128h]@33
  __int16 v18; // [sp+68h] [bp-120h]@33
  char v19; // [sp+70h] [bp-118h]@47
  CHAR String; // [sp+F0h] [bp-98h]@51

  v4 = sub_405D30(a3);
  if ( v4 == 183 )
  {
    memset(&v19, 0, 0x80u);
    if ( sub_4020C0(24, &v19) && (v14 = FindWindowExA(0, 0, 0, 0)) != 0 )
    {
      while ( 1 )
      {
        GetWindowTextA(v14, &String, 127);
        if ( strstr(&String, &v19) )
          break;
        v14 = FindWindowExA(0, v14, 0, 0);
        if ( !v14 )
          goto LABEL_48;
      }
    }
    else
    {
LABEL_48:
      v14 = 0;
    }
    ShowWindow(v14, 5);
    SetForegroundWindow(v14);
    sub_401C10();
    return 2;
  }
  if ( v4 != 1 )
  {
LABEL_3:
    sub_401ED0();
    return 1;
  }
  v6 = 0;
  if ( sub_4021A0(4) && !strstr(a3, "--l4j-no-splash") )
    v6 = 1;
  dword_40A014 = v6;
  v7 = 0;
  dword_40A010 = sub_4021A0(31);
  if ( dword_40A010 || sub_4021A0(11) && !strstr(a3, "--l4j-dont-wait") )
    v7 = 1;
  dword_40A018 = v7;
  v8 = dword_40A014;
  if ( !dword_40A014 && !v7 )
    goto LABEL_42;
  hWnd = CreateWindowExA(0x80u, "STATIC", &WindowName, 0x8000000E, 0, 0, 2147483648, 2147483648, 0, 0, hInstance, 0);
  if ( dword_40A014 )
  {
    memset(&v17, 0, 8u);
    v18 = 0;
    if ( sub_4020C0(6, &v17) )
    {
      v9 = atoi(&v17);
      if ( (unsigned int)(v9 - 1) <= 0x383 )
        dword_408000 = v9;
      else
        dword_408000 = 60;
    }
    v10 = 0;
    dword_408000 *= 1000;
    if ( sub_4021A0(7) && !strstr(a3, "--l4j-no-splash-err") )
      v10 = 1;
    dword_40A080 = v10;
    dword_40A060 = sub_4021A0(5);
    v11 = LoadImageA(hInstance, (LPCSTR)1, 0, 0, 0, 0x40u);
    if ( v11 )
    {
      SendMessageA(hWnd, 0x172u, 0, (LPARAM)v11);
      GetWindowRect(hWnd, &Rect);
      v12 = (GetSystemMetrics(0) - (Rect.right - Rect.left)) / 2;
      v13 = GetSystemMetrics(1);
      SetWindowPos(hWnd, 0, v12, (v13 - (Rect.bottom - Rect.top)) / 2, 0, 0, 1u);
      ShowWindow(hWnd, nCmdShow);
      UpdateWindow(hWnd);
      goto LABEL_41;
    }
    goto LABEL_3;
  }
LABEL_13:
  if ( !dword_40A018 )
    goto LABEL_15;
  while ( 1 )
  {
    if ( !SetTimer(hWnd, 1u, 0x64u, TimerFunc) )
      goto LABEL_3;
LABEL_15:
    if ( !sub_406860(0, &ExitCode) )
      goto LABEL_3;
    if ( !dword_40A014 && !dword_40A018 )
      break;
    while ( GetMessageA(&Msg, 0, 0, 0) )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }
    if ( dword_40A010 && ExitCode && dword_40A090 )
      fprintf(dword_40A090, "Exit code:\t%d, restarting the application!\n", ExitCode);
    sub_406830();
    if ( !dword_40A010 || !ExitCode )
    {
      if ( dword_40A090 )
        fprintf(dword_40A090, "Exit code:\t%d\n", ExitCode);
      sub_401C10();
      return ExitCode;
    }
LABEL_41:
    v8 = dword_40A014;
LABEL_42:
    if ( !v8 )
      goto LABEL_13;
  }
  if ( dword_40A090 )
    fwrite("Exit code:\t0\n", 1u, 0xDu, dword_40A090);
  sub_406830();
  sub_401C10();
  return 0;
}
// 408000: using guessed type int dword_408000;
// 40A010: using guessed type int dword_40A010;
// 40A014: using guessed type int dword_40A014;
// 40A018: using guessed type int dword_40A018;
// 40A060: using guessed type int dword_40A060;
// 40A080: using guessed type int dword_40A080;

/*
BOOL CALLBACK MyEnumProc(HWND hWnd, LPARAM lParam)
{
    DWORD dwProcessId;
    LPWNDINFO pInfo = (LPWNDINFO)lParam;
    GetWindowThreadProcessId(hWnd, &dwProcessId);

    if( dwProcessId == pInfo->dwProcessId )
    {
        pInfo->hWnd = hWnd;
        return FALSE;
    }
    return TRUE;
}
*/
// https://github.com/wswm2009/DLLSrc_MFC/blob/ef37d8bd549baacbb4201e9d20590fdc059353dd/MfcDLLHook/MfcDLLHook/MainDlg.cpp
BOOL CALLBACK EnumFunc(HWND hWnd, LPARAM a2)
{
    DWORD dwProcessId;
    GetWindowThreadProcessId(hWnd, &dwProcessId);
    if ( dword_4122B8 == dwProcessId && (GetWindowLongA(hWnd, GWL_STYLE) & WS_VISIBLE))
    {
        dword_40A014 = 0; // pInfo->hWnd
        ShowWindow(hWnd, 0);
        return FALSE;
    }
    return TRUE;
}
// 40A014: using guessed type int dword_40A014;
// 4122B8: using guessed type int dword_4122B8;

//----- (004019E0) --------------------------------------------------------
void __stdcall TimerFunc(HWND hWnd, UINT a2, UINT a3, DWORD a4)
{
  if ( dword_40A014 )
  {
    if ( dword_408000 )
    {
      dword_408000 -= 100;
      if ( dword_40A060 )
        EnumWindows(EnumFunc, 0);
    }
    else
    {
      dword_40A014 = 0;
      ShowWindow(::hWnd, 0);
      if ( dword_40A060 && dword_40A080 )
      {
        KillTimer(hWnd, 1u);
        sub_401ED0();
        PostQuitMessage(0);
      }
    }
  }
  GetExitCodeProcess(hProcess, &ExitCode);
  if ( ExitCode != 259 || !dword_40A014 && !dword_40A018 )
  {
    KillTimer(::hWnd, 1u);
    PostQuitMessage(0);
  }
}
// 408000: using guessed type int dword_408000;
// 40A014: using guessed type int dword_40A014;
// 40A018: using guessed type int dword_40A018;
// 40A060: using guessed type int dword_40A060;
// 40A080: using guessed type int dword_40A080;

//----- (00401C10) --------------------------------------------------------
FILE *sub_401C10()
{
  FILE *result; // eax@1

  result = dword_40A090;
  if ( dword_40A090 )
    result = (FILE *)fclose(dword_40A090);
  return result;
}

//----- (00401C30) --------------------------------------------------------
int __cdecl sub_401C30(char *a1, char *a2, size_t a3)
{
  size_t v3; // eax@2
  FILE *v4; // eax@2
  FILE *v5; // ebx@2
  int result; // eax@2
  signed int v7; // esi@3
  char v8[272]; // [sp+10h] [bp-8128h]@2
  CHAR Buffer; // [sp+120h] [bp-8018h]@1

  memset(&Buffer, 0, 0x7FFFu);
  GetEnvironmentVariableA("Launch4j", &Buffer, 0x7FFFu);
  if ( strstr(a1, "--l4j-debug") || strstr(&Buffer, "debug") )
  {
    memset(v8, 0, 0x104u);
    strncpy(v8, a2, a3);
    v3 = strlen(v8);
    *(uint32_t *)&v8[v3] = 1969319004;
    *(uint32_t *)&v8[v3 + 4] = 879256430;
    *(uint32_t *)&v8[v3 + 8] = 1869360746;
    *(uint16_t *)&v8[v3 + 12] = 103;
    v4 = fopen(v8, "a");
    dword_40A090 = v4;
    v5 = v4;
    result = 0;
    if ( !v5 )
      return result;
    v7 = 0;
    if ( strstr(a1, "--l4j-debug-all") || strstr(&Buffer, "debug-all") )
      v7 = 1;
    dword_40A028 = v7;
  }
  else
  {
    v5 = dword_40A090;
  }
  if ( v5 )
  {
    fprintf(v5, "\n\nVersion:\t%s\n", "3.9");
    if ( dword_40A090 )
      fprintf(dword_40A090, "CmdLine:\t%s %s\n", a2, a1);
  }
  return 1;
}
// 40A028: using guessed type int dword_40A028;
// 401C30: using guessed type char var_8128[272];

//----- (00401ED0) --------------------------------------------------------
FILE *sub_401ED0()
{
  DWORD v0; // ebx@1
  FILE *result; // eax@11
  size_t v2; // eax@18
  CHAR Buffer[4]; // [sp+20h] [bp-8h]@16

  v0 = GetLastError();
  if ( dword_40A090 )
    fprintf(dword_40A090, "Error msg:\t%s\n", Text);
  if ( v0 )
  {
    FormatMessageA(0x1300u, 0, v0, 0x400u, Buffer, 0, 0);
    if ( dword_40A090 )
      fprintf(dword_40A090, "Error:\t\t%s\n", *(uint32_t *)Buffer);
    v2 = strlen(Text);
    *(uint16_t *)&Text[v2] = 2570;
    Text[v2 + 2] = 0;
    strcat(Text, *(const char **)Buffer);
    LocalFree(*(HLOCAL *)Buffer);
  }
  if ( dword_40A024 )
  {
    if ( Caption[0] )
      printf("%s: %s\n", Caption, Text);
    else
      puts(Text);
  }
  else
  {
    MessageBoxA(0, Text, Caption, 0);
  }
  if ( File )
  {
    if ( dword_40A090 )
      fprintf(dword_40A090, "Open URL:\t%s\n", &File);
    ShellExecuteA(0, "open", &File, 0, 0, 1);
  }
  result = dword_40A090;
  if ( dword_40A090 )
    result = (FILE *)fclose(dword_40A090);
  return result;
}
// 40A024: using guessed type int dword_40A024;

//----- (004020C0) --------------------------------------------------------
signed int __cdecl sub_4020C0(int a1, uint8_t *a2)
{
  HRSRC v2; // eax@1
  HGLOBAL v3; // eax@2
  uint8_t *v4; // ecx@3
  int v5; // edx@4
  char v6; // al@5
  signed int result; // eax@8

  v2 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)(unsigned __int16)a1, 0x400u);
  if ( !v2 )
  {
    SetLastError(0);
    *a2 = 0;
    return 0;
  }
  v3 = LoadResource(hModule, v2);
  if ( !v3 )
    return 0;
  v4 = LockResource(v3);
  if ( !v4 )
    return 0;
  v5 = 0;
  do
  {
    v6 = v4[v5];
    a2[v5++] = v6;
  }
  while ( v6 );
  if ( dword_40A028 && dword_40A090 )
  {
    fprintf(dword_40A090, "Resource %d:\t%s\n", a1, a2);
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}
// 40A028: using guessed type int dword_40A028;

//----- (004021A0) --------------------------------------------------------
int __cdecl sub_4021A0(int a1)
{
  HRSRC v1; // eax@1
  HGLOBAL v2; // eax@2
  bool v3; // zf@2
  uint8_t *v4; // eax@3
  uint8_t *v5; // ecx@3
  int v6; // edx@4
  char v7; // al@5
  char *v8; // esi@9
  const char *v9; // edi@9
  signed int v10; // ecx@9
  int result; // eax@12
  char *v12; // esi@13
  const char *v13; // edi@13
  signed int v14; // ecx@13
  bool v15; // zf@13
  int v16; // [sp+4h] [bp-54h]@13
  int v17; // [sp+8h] [bp-50h]@8
  char *v18; // [sp+Ch] [bp-4Ch]@8
  char v19[56]; // [sp+20h] [bp-38h]@1

  memset(v19, 0, 0x14u);
  v1 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)(unsigned __int16)a1, 0x400u);
  if ( v1 )
  {
    v2 = LoadResource(hModule, v1);
    v3 = v2 == 0;
    if ( v2 )
    {
      v4 = LockResource(v2);
      v3 = v4 == 0;
      v5 = v4;
      if ( v4 )
      {
        v6 = 0;
        do
        {
          v7 = v5[v6];
          v19[v6++] = v7;
        }
        while ( v7 );
        v3 = dword_40A028 == 0;
        if ( dword_40A028 )
        {
          v3 = dword_40A090 == 0;
          if ( dword_40A090 )
          {
            v17 = a1;
            v18 = v19;
            fprintf(dword_40A090, "Resource %d:\t%s\n", a1, v19);
          }
        }
      }
    }
    v8 = v19;
    v9 = "true";
    v10 = 5;
    do
    {
      if ( !v10 )
        break;
      v3 = *v8++ == *v9++;
      --v10;
    }
    while ( v3 );
    result = v3;
  }
  else
  {
    v12 = v19;
    v13 = "true";
    SetLastError(0);
    v19[0] = 0;
    v14 = 5;
    v15 = &v16 == 0;
    do
    {
      if ( !v14 )
        break;
      v15 = *v12++ == *v13++;
      --v14;
    }
    while ( v15 );
    result = v15;
  }
  return result;
}
// 40A028: using guessed type int dword_40A028;
// 4021A0: using guessed type char var_38[56];

//----- (004023B0) --------------------------------------------------------
int __cdecl sub_4023B0(char *a1, LPBYTE lpData, DWORD cbData)
{
  HKEY v3; // esi@1
  int result; // eax@6
  const CHAR *v5; // edi@7
  char *v6; // eax@7
  const CHAR *v7; // ebx@7
  int v8; // [sp+20h] [bp-18h]@7
  DWORD Type; // [sp+24h] [bp-14h]@9
  HKEY phkResult; // [sp+28h] [bp-10h]@8

  v3 = HKEY_CLASSES_ROOT;
  if ( strstr(a1, "HKEY_CLASSES_ROOT") == a1
    || (v3 = HKEY_CURRENT_USER, strstr(a1, "HKEY_CURRENT_USER") == a1)
    || (v3 = HKEY_LOCAL_MACHINE, strstr(a1, "HKEY_LOCAL_MACHINE") == a1)
    || (v3 = HKEY_USERS, strstr(a1, "HKEY_USERS") == a1)
    || (v3 = HKEY_CURRENT_CONFIG, strstr(a1, "HKEY_CURRENT_CONFIG") == a1) )
  {
    v5 = strchr(a1, 92) + 1;
    v6 = strrchr(a1, 92);
    v7 = v6 + 1;
    *v6 = 0;
    v8 = 0;
    if ( dword_40A020 && !RegOpenKeyExA(v3, v5, 0, 0x20119u, &phkResult)
      || !RegOpenKeyExA(v3, v5, 0, 0x20019u, &phkResult) )
    {
      v8 = RegQueryValueExA(phkResult, v7, 0, &Type, lpData, &cbData) == 0;
      RegCloseKey(phkResult);
    }
    *((uint8_t *)v7 - 1) = 92;
    result = v8;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 40A020: using guessed type int dword_40A020;

//----- (00402690) --------------------------------------------------------
int __cdecl sub_402690(char *a1)
{
  int v1; // ebx@1
  const char *v2; // edx@3
  size_t v4; // eax@8
  size_t v5; // eax@13
  const char *v6; // [sp+Ch] [bp-15Ch]@5
  char v7[272]; // [sp+10h] [bp-158h]@1
  struct stat v8; // [sp+120h] [bp-48h]@11

  v1 = 0;
  memset(v7, 0, 0x104u);
  if ( *a1 )
  {
    strcpy(v7, a1);
    if ( dword_40A024 )
    {
      v5 = strlen(v7);
      if ( v7[v5 - 1] != 92 )
        *(uint16_t *)&v7[v5] = 92;
      strcat(v7, "bin\\java.exe");
    }
    else
    {
      v4 = strlen(v7);
      if ( v7[v4 - 1] != 92 )
        *(uint16_t *)&v7[v4] = 92;
      strcat(v7, "bin\\javaw.exe");
    }
    v1 = stat(v7, &v8) == 0;
    if ( !v1 )
      SetLastError(0);
  }
  if ( dword_40A090 )
  {
    v2 = "(OK)";
    if ( !v1 )
      v2 = "(not found)";
    v6 = v2;
    fprintf(dword_40A090, "Check launcher:\t%s %s\n", v7, v2);
  }
  return v1;
}
// 40A024: using guessed type int dword_40A024;
// 402690: using guessed type char var_158[272];

//----- (004027A0) --------------------------------------------------------
int __cdecl sub_4027A0(LPCSTR lpSubKey, int a2)
{
  int v2; // edi@1
  int v4; // edx@5
  char v5; // bl@6
  size_t v6; // eax@8
  DWORD Type; // [sp+24h] [bp-244h]@4
  DWORD cbData; // [sp+28h] [bp-240h]@4
  HKEY phkResult; // [sp+2Ch] [bp-23Ch]@1
  char Data[272]; // [sp+30h] [bp-238h]@4
  char v11[296]; // [sp+140h] [bp-128h]@1

  v2 = 0;
  memset(v11, 0, 0x104u);
  if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, lpSubKey, 0, a2 & 0x100 | 0x20019, &phkResult) )
    goto LABEL_16;
  memset(Data, 0, 0x104u);
  cbData = 260;
  if ( !RegQueryValueExA(phkResult, "JavaHome", 0, &Type, (LPBYTE)Data, &cbData) )
  {
    v4 = 0;
    do
    {
      v5 = Data[v4];
      v11[v4++] = v5;
    }
    while ( v5 );
    if ( a2 & 2 )
    {
      v6 = strlen(v11);
      if ( v11[v6 - 1] != 92 )
        *(uint16_t *)&v11[v6] = 92;
      strcat(v11, "jre");
    }
    v2 = sub_402690(v11);
  }
  RegCloseKey(phkResult);
  if ( !v2 )
LABEL_16:
    dword_4122DC = 1;
  else
    strcpy(byte_412664, v11);
  return v2;
}
// 4122DC: using guessed type int dword_4122DC;
// 4027A0: using guessed type char var_128[296];
// 4027A0: using guessed type BYTE Data[272];

//----- (00402920) --------------------------------------------------------
LONG __cdecl sub_402920(LPCSTR lpSubKey, int a2)
{
  const char *v2; // edx@2
  LONG result; // eax@5
  DWORD v4; // ST04_4@10
  size_t v5; // eax@11
  char *v6; // eax@15
  const char *v7; // esi@16
  DWORD dwIndex; // [sp+24h] [bp-364h]@6
  DWORD cbName; // [sp+2Ch] [bp-35Ch]@6
  struct _FILETIME ftLastWriteTime; // [sp+30h] [bp-358h]@10
  HKEY phkResult; // [sp+3Ch] [bp-34Ch]@5
  char v12[272]; // [sp+40h] [bp-348h]@6
  CHAR Name; // [sp+150h] [bp-238h]@6
  char SubKey[296]; // [sp+260h] [bp-128h]@6

  if ( dword_40A090 )
  {
    v2 = "64";
    if ( !(a2 & 0x100) )
      v2 = "32";
    fprintf(dword_40A090, "%s-bit search:\t%s...\n", v2, lpSubKey);
  }
  result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, lpSubKey, 0, a2 & 0x100 | 0x20019, &phkResult);
  if ( !result )
  {
    cbName = 260;
    dwIndex = 0;
    memset(SubKey, 0, 0x104u);
    memset(&Name, 0, 0x104u);
    memset(v12, 0, 0x104u);
    while ( 1 )
    {
      v4 = dwIndex++;
      if ( RegEnumKeyExA(phkResult, v4, &Name, &cbName, 0, 0, 0, &ftLastWriteTime) )
        break;
      strcpy(SubKey, lpSubKey);
      v5 = strlen(SubKey);
      if ( SubKey[v5 - 1] != 92 )
        *(uint16_t *)&SubKey[v5] = 92;
      strcat(SubKey, &Name);
      if ( dword_40A090 )
        fprintf(dword_40A090, "Check:\t\t%s\n", SubKey);
      v6 = strchr(&Name, 95);
      if ( v6 && (v7 = v6 + 1, strlen(v6 + 1) <= 2) )
      {
        strncpy(v12, &Name, v7 - &Name);
        v12[v7 - &Name] = 0;
        *(uint16_t *)&v12[strlen(v12)] = 48;
        strcat(v12, v7);
      }
      else
      {
        strcpy(v12, &Name);
      }
      if ( strcmp(v12, word_4123E0) < 0
        || word_412460[0] && strcmp(v12, word_412460) > 0
        || strcmp(v12, byte_4124E0) <= 0
        || !sub_4027A0(SubKey, a2) )
      {
        if ( dword_40A090 )
          fprintf(dword_40A090, "Ignore:\t\t%s\n", v12);
      }
      else
      {
        strcpy(byte_4124E0, v12);
        strcpy(byte_412560, SubKey);
        dword_4122D4 = a2;
        if ( dword_40A090 )
          fprintf(dword_40A090, "Match:\t\t%s\n", v12);
      }
      cbName = 260;
    }
    result = RegCloseKey(phkResult);
  }
  return result;
}
// 4122D4: using guessed type int dword_4122D4;
// 402920: using guessed type CHAR SubKey[296];
// 402920: using guessed type char var_348[272];

//----- (00402CB0) --------------------------------------------------------
int __cdecl sub_402CB0(LPCSTR lpSubKey, int a2)
{
  int result; // eax@1
  bool v3; // zf@5
  HRSRC v4; // eax@15
  HGLOBAL v5; // eax@16
  uint8_t *v6; // ecx@17
  int v7; // edx@18
  char v8; // al@19
  char v9[44]; // [sp+20h] [bp-38h]@15

  result = dword_4122D0;
  if ( dword_4122D0 == 9 )
  {
    memset(v9, 0, 0x14u);
    v4 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x1E, 0x400u);
    if ( v4 )
    {
      v5 = LoadResource(hModule, v4);
      if ( v5 )
      {
        v6 = LockResource(v5);
        if ( v6 )
        {
          v7 = 0;
          do
          {
            v8 = v6[v7];
            v9[v7++] = v8;
          }
          while ( v8 );
          if ( dword_40A028 && dword_40A090 )
            fprintf(dword_40A090, "Resource %d:\t%s\n", 30, v9);
        }
      }
    }
    else
    {
      SetLastError(0);
      v9[0] = 0;
    }
    result = atoi(v9);
    dword_4122D0 = result;
  }
  if ( result == 2 )
  {
    if ( !dword_40A020 )
      return sub_402920(lpSubKey, a2);
    result = sub_402920(lpSubKey, a2 | 0x100);
    v3 = (BYTE1(dword_4122D4) & 1) == 0;
LABEL_6:
    if ( !v3 )
      return result;
    return sub_402920(lpSubKey, a2);
  }
  if ( result <= 2 )
  {
    if ( --result )
      return result;
LABEL_9:
    if ( dword_40A020 )
      result = sub_402920(lpSubKey, a2 | 0x100);
    return result;
  }
  if ( result != 3 )
  {
    v3 = result == 4;
    goto LABEL_6;
  }
  sub_402920(lpSubKey, a2);
  result = dword_4122D4;
  if ( !dword_4122D4 || BYTE1(result) & 1 )
    goto LABEL_9;
  return result;
}
// 40A020: using guessed type int dword_40A020;
// 40A028: using guessed type int dword_40A028;
// 4122D0: using guessed type int dword_4122D0;
// 4122D4: using guessed type int dword_4122D4;
// 402CB0: using guessed type char var_38[44];

//----- (00403100) --------------------------------------------------------
char *__cdecl sub_403100(char *a1, char *a2, char *a3, int a4)
{
  char *v4; // edi@1
  char *v5; // eax@2
  char *v6; // esi@2
  const char *v7; // ebx@3
  char *result; // eax@3
  const char *v9; // edi@4
  CHAR *v10; // esi@4
  size_t v11; // eax@4
  bool v12; // zf@4
  signed int v13; // ecx@4
  const char *v14; // edi@8
  CHAR *v15; // esi@8
  signed int v16; // ecx@8
  const char *v17; // edi@12
  CHAR *v18; // esi@12
  signed int v19; // ecx@12
  const char *v20; // edi@16
  CHAR *v21; // esi@16
  signed int v22; // ecx@16
  const char *v23; // edi@20
  CHAR *v24; // esi@20
  signed int v25; // ecx@20
  CHAR *lpBuffer; // [sp+34h] [bp-80A4h]@4
  int v27; // [sp+38h] [bp-80A0h]@3
  CHAR Buffer; // [sp+40h] [bp-8098h]@1
  CHAR Name; // [sp+8040h] [bp-98h]@1

  v4 = a2;
  memset(&Name, 0, 0x80u);
  memset(&Buffer, 0, 0x7FFFu);
  if ( *a2 )
  {
    while ( 1 )
    {
      v5 = strchr(v4, 37);
      v6 = v5;
      if ( !v5 )
        break;
      v7 = v5 + 1;
      result = strchr(v5 + 1, 37);
      v27 = (int)result;
      if ( !result )
        return result;
      strncat(a1, v4, v6 - v4);
      Name = 0;
      strncat(&Name, v7, v27 - (uint32_t)v6 - 1);
      v9 = "EXEDIR";
      v10 = &Name;
      v11 = strlen(a1);
      v12 = &a1[v11] == 0;
      lpBuffer = &a1[v11];
      v13 = 7;
      do
      {
        if ( !v13 )
          break;
        v12 = *v10++ == *v9++;
        --v13;
      }
      while ( v12 );
      if ( v12 )
      {
        strncat(a1, a3, a4);
      }
      else
      {
        v14 = "EXEFILE";
        v15 = &Name;
        v16 = 8;
        do
        {
          if ( !v16 )
            break;
          v12 = *v15++ == *v14++;
          --v16;
        }
        while ( v12 );
        if ( v12 )
        {
          strcat(a1, a3);
        }
        else
        {
          v17 = "PWD";
          v18 = &Name;
          v19 = 4;
          do
          {
            if ( !v19 )
              break;
            v12 = *v18++ == *v17++;
            --v19;
          }
          while ( v12 );
          if ( v12 )
          {
            GetCurrentDirectoryA(0x104u, lpBuffer);
          }
          else
          {
            v20 = "OLDPWD";
            v21 = &Name;
            v22 = 7;
            do
            {
              if ( !v22 )
                break;
              v12 = *v21++ == *v20++;
              --v22;
            }
            while ( v12 );
            if ( v12 )
            {
              strcat(a1, ::Buffer);
            }
            else
            {
              v23 = "JREHOMEDIR";
              v24 = &Name;
              v25 = 11;
              do
              {
                if ( !v25 )
                  break;
                v12 = *v24++ == *v23++;
                --v25;
              }
              while ( v12 );
              if ( v12 )
              {
                strcat(a1, byte_412664);
              }
              else if ( strstr(&Name, "HKEY") == &Name )
              {
                sub_4023B0(&Name, (LPBYTE)lpBuffer, 0x400u);
              }
              else if ( GetEnvironmentVariableA(&Name, &Buffer, 0x7FFFu) )
              {
                strcat(a1, &Buffer);
              }
            }
          }
        }
      }
      if ( dword_40A090 )
        fprintf(dword_40A090, "Substitute:\t%s = %s\n", &Name, lpBuffer);
      v4 = (char *)(v27 + 1);
      if ( !*(uint8_t *)(v27 + 1) )
        goto LABEL_30;
    }
    strcat(a1, v4);
    result = (char *)1;
  }
  else
  {
LABEL_30:
    result = (char *)1;
  }
  return result;
}

//----- (004033F0) --------------------------------------------------------
int __cdecl sub_4033F0(char *a1, int a2, int a3, int a4, int a5, char *a6)
{
  HRSRC v6; // eax@1
  HGLOBAL v7; // eax@2
  uint8_t *v8; // ecx@3
  int v9; // edx@4
  char v10; // al@5
  HRSRC v11; // eax@9
  HGLOBAL v12; // eax@10
  uint8_t *v13; // ecx@11
  int v14; // edx@12
  char v15; // al@13
  __int64 v16; // rax@17
  int v17; // ST28_4@17
  __int64 v18; // kr00_8@17
  unsigned __int64 v19; // rax@17
  unsigned __int64 v20; // rax@17
  int v21; // esi@17
  FILE *v22; // ecx@21
  size_t v23; // eax@24
  unsigned __int64 v25; // [sp+0h] [bp-A8h]@17
  int v26; // [sp+44h] [bp-64h]@9
  char v27[32]; // [sp+50h] [bp-58h]@9
  char v28[56]; // [sp+70h] [bp-38h]@1

  memset(v28, 0, 0x14u);
  v6 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)(unsigned __int16)a2, 0x400u);
  if ( v6 )
  {
    v7 = LoadResource(hModule, v6);
    if ( v7 )
    {
      v8 = LockResource(v7);
      if ( v8 )
      {
        v9 = 0;
        do
        {
          v10 = v8[v9];
          v28[v9++] = v10;
        }
        while ( v10 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", a2, v28);
      }
    }
  }
  else
  {
    SetLastError(0);
    v28[0] = 0;
  }
  v26 = atoi(v28);
  memset(v27, 0, 0x14u);
  v11 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)(unsigned __int16)a3, 0x400u);
  if ( v11 )
  {
    v12 = LoadResource(hModule, v11);
    if ( v12 )
    {
      v13 = LockResource(v12);
      if ( v13 )
      {
        v14 = 0;
        do
        {
          v15 = v13[v14];
          v27[v14++] = v15;
        }
        while ( v15 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", a3, v27);
      }
    }
  }
  else
  {
    SetLastError(0);
    v27[0] = 0;
  }
  LODWORD(v16) = atoi(v27);
  v17 = v16;
  v16 = (signed int)v16;
  v18 = v16;
  v19 = (unsigned int)v16 * (unsigned __int64)(unsigned int)a4;
  LODWORD(v25) = v19;
  HIDWORD(v25) = v17 * a5 + HIDWORD(v19) + HIDWORD(v18) * a4;
  v20 = v25 / 0x6400000;
  v21 = v26;
  if ( v26 < (signed int)(v25 / 0x6400000) )
    v21 = v25 / 0x6400000;
  if ( v21 > 0 )
  {
    if ( (((unsigned int)dword_4122D4 >> 8) ^ 1) & (v21 > 1024) )
    {
      v22 = dword_40A090;
      if ( dword_40A090 )
      {
        fprintf(dword_40A090, "Heap limit:\tReduced %d MB heap size to 32-bit maximum %d MB\n", v21, 1024);
        v22 = dword_40A090;
      }
      v21 = 1024;
      if ( !v22 )
        goto LABEL_24;
    }
    else
    {
      v22 = dword_40A090;
      if ( !dword_40A090 )
      {
LABEL_24:
        strcat(a1, a6);
        v23 = strlen(a1);
        itoa(v21, &a1[v23], 10);
        LODWORD(v20) = strlen(a1);
        *(uint16_t *)&a1[v20] = 8301;
        a1[(uint32_t)v20 + 2] = 0;
        return v20;
      }
    }
    fprintf(
      v22,
      "Heap %s:\tRequested %d MB / %d%%, Available: %d MB, Heap size: %d MB\n",
      a6,
      v26,
      (uint32_t)v18,
      (unsigned int)(__PAIR__((unsigned int)a5, a4) >> 20),
      v21);
    goto LABEL_24;
  }
  return v20;
}
// 40A028: using guessed type int dword_40A028;
// 4122D4: using guessed type int dword_4122D4;
// 4033F0: using guessed type char var_38[56];
// 4033F0: using guessed type char var_58[32];

//----- (00403790) --------------------------------------------------------
int __cdecl sub_403790(char *a1, char *a2)
{
  HRSRC v2; // eax@1
  HGLOBAL v3; // eax@2
  uint8_t *v4; // ecx@3
  int v5; // edx@4
  char v6; // al@5
  size_t v7; // eax@10
  size_t v8; // eax@10
  int v9; // eax@10
  int result; // eax@10
  size_t v11; // eax@13
  char *v12; // esi@13
  char *v13; // edi@13
  int v14; // eax@13
  int v15; // ebx@14
  char v16; // cl@15
  signed int v17; // [sp+14h] [bp-134h]@13
  int v18; // [sp+1Ch] [bp-12Ch]@10
  char v19[296]; // [sp+20h] [bp-128h]@10

  v2 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0xC, 0x400u);
  if ( v2 )
  {
    v3 = LoadResource(hModule, v2);
    if ( v3 )
    {
      v4 = LockResource(v3);
      if ( v4 )
      {
        v5 = 0;
        do
        {
          v6 = v4[v5];
          a1[v5++] = v6;
        }
        while ( v6 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", 12, a1);
        *(uint16_t *)&a1[strlen(a1)] = 32;
      }
    }
  }
  else
  {
    SetLastError(0);
    *a1 = 0;
  }
  memset(v19, 0, 0x104u);
  v7 = strlen(a2);
  strncpy(v19, a2, v7 - 3);
  v8 = strlen(v19);
  *(uint32_t *)&v19[v8] = 778712172;
  *(uint32_t *)&v19[v8 + 4] = 6909545;
  v9 = open(v19, 0);
  v18 = v9;
  result = v9 + 1;
  if ( result )
  {
    if ( dword_40A090 )
      fprintf(dword_40A090, "Loading:\t%s\n", v19);
    v11 = strlen(a1);
    v12 = &a1[v11];
    v13 = &a1[v11];
    v14 = read(v18, &a1[v11], 31744 - v11);
    v17 = 1;
    if ( v14 > 0 )
    {
      v15 = v14;
      do
      {
        v16 = *v12;
        if ( *v12 == 35 )
        {
          v17 = 0;
          goto LABEL_21;
        }
        if ( v16 == 10 || v16 == 13 )
        {
          v17 = 1;
          if ( v13 <= a1 || *(v13 - 1) == 32 )
            goto LABEL_21;
          *v13 = 32;
        }
        else
        {
          if ( !v17 )
            goto LABEL_21;
          *v13 = v16;
        }
        ++v13;
LABEL_21:
        ++v12;
        --v15;
      }
      while ( v15 );
    }
    *v13 = 0;
    if ( v14 > 0 && *(v13 - 1) != 32 )
      *(uint16_t *)&a1[strlen(a1)] = 32;
    result = close(v18);
  }
  return result;
}
// 40A028: using guessed type int dword_40A028;
// 403790: using guessed type char var_128[296];

//----- (00403D20) --------------------------------------------------------
int __cdecl sub_403D20(char *a1, size_t a2)
{
  HRSRC v2; // eax@1
  HGLOBAL v3; // eax@2
  uint8_t *v4; // ecx@3
  int v5; // edx@4
  char v6; // al@5
  signed int v7; // ecx@16
  HRSRC v9; // eax@20
  HGLOBAL v10; // eax@21
  bool v11; // cf@21
  bool v12; // zf@21
  uint8_t *v13; // eax@22
  uint8_t *v14; // ecx@22
  int v15; // edx@23
  char v16; // al@24
  signed int v17; // ecx@28
  char *v18; // esi@28
  const char *v19; // edi@28
  size_t v20; // eax@33
  int v21; // [sp+4h] [bp-8164h]@36
  char *v22; // [sp+8h] [bp-8160h]@8
  char *v23; // [sp+Ch] [bp-815Ch]@8
  char v24[32]; // [sp+20h] [bp-8148h]@20
  char v25; // [sp+40h] [bp-8128h]@9
  char v26; // [sp+41h] [bp-8127h]@12
  char v27[296]; // [sp+8040h] [bp-128h]@1

  memset(v27, 0, 0x104u);
  v2 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)1, 0x400u);
  if ( !v2 )
  {
    SetLastError(0);
    v27[0] = 0;
    return 0;
  }
  v3 = LoadResource(hModule, v2);
  if ( !v3 )
    return 0;
  v4 = LockResource(v3);
  if ( !v4 )
    return 0;
  v5 = 0;
  do
  {
    v6 = v4[v5];
    v27[v5++] = v6;
  }
  while ( v6 );
  if ( dword_40A028 && dword_40A090 )
  {
    v23 = v27;
    v22 = (char *)1;
    fprintf(dword_40A090, "Resource %d:\t%s\n", 1, v27);
  }
  memset(&v25, 0, 0x8000u);
  sub_403100(&v25, v27, a1, a2);
  if ( dword_40A090 )
  {
    v22 = &v25;
    fprintf(dword_40A090, "Bundled JRE:\t%s\n", &v25);
  }
  if ( v25 != 92 && v26 != 58 )
  {
    strncpy(word_40A1A4, a1, a2);
    v20 = strlen(word_40A1A4);
    if ( byte_40A1A3[v20] != 92 )
      *(uint16_t *)&word_40A1A4[v20] = 92;
    strcat(word_40A1A4, &v25);
  }
  else
  {
    strcpy(word_40A1A4, &v25);
  }
  if ( !sub_402690(word_40A1A4) )
    return 0;
  if ( !dword_40A020 )
    goto LABEL_39;
  memset(v24, 0, 0x14u);
  v9 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x1D, 0x400u);
  if ( v9 )
  {
    v10 = LoadResource(hModule, v9);
    v11 = 0;
    v12 = v10 == 0;
    if ( v10 )
    {
      v13 = LockResource(v10);
      v11 = 0;
      v12 = v13 == 0;
      v14 = v13;
      if ( v13 )
      {
        v15 = 0;
        do
        {
          v16 = v14[v15];
          v24[v15++] = v16;
        }
        while ( v16 );
        v11 = 0;
        v12 = dword_40A028 == 0;
        if ( dword_40A028 )
        {
          v11 = 0;
          v12 = dword_40A090 == 0;
          if ( dword_40A090 )
          {
            v23 = v24;
            v22 = (char *)29;
            fprintf(dword_40A090, "Resource %d:\t%s\n", 29, v24);
          }
        }
      }
    }
  }
  else
  {
    SetLastError(0);
    v24[0] = 0;
    v11 = (unsigned int)&v21 < 4;
    v12 = &v21 == 0;
  }
  v17 = 5;
  v18 = v24;
  v19 = "true";
  do
  {
    if ( !v17 )
      break;
    v11 = (unsigned __int8)*v18 < *v19;
    v12 = *v18++ == *v19++;
    --v17;
  }
  while ( v12 );
  v7 = 260;
  if ( (!v11 && !v12) != v11 )
LABEL_39:
    v7 = 4;
  dword_4122D4 = v7;
  strcpy(byte_412664, word_40A1A4);
  return 1;
}
// 40A020: using guessed type int dword_40A020;
// 40A028: using guessed type int dword_40A028;
// 4122D4: using guessed type int dword_4122D4;
// 403D20: using guessed type char var_128[296];
// 403D20: using guessed type char var_8148[32];

//----- (004042B0) --------------------------------------------------------
void sub_4042B0()
{
  HRSRC v0; // eax@2
  HGLOBAL v1; // eax@3
  uint8_t *v2; // eax@4
  int v3; // edx@5
  char v4; // bl@6
  int v5; // ebx@12
  size_t v6; // eax@13
  const char *v7; // eax@13
  size_t v8; // eax@15
  HRSRC v9; // eax@17
  HGLOBAL v10; // eax@18
  uint8_t *v11; // ecx@19
  int v12; // edx@20
  char v13; // al@21
  HRSRC v14; // eax@25
  HGLOBAL v15; // eax@26
  uint8_t *v16; // eax@27
  int v17; // edx@28
  char v18; // bl@29
  HRSRC v19; // eax@36
  HGLOBAL v20; // eax@37
  uint8_t *v21; // ecx@38
  int v22; // edx@39
  char v23; // al@40
  char v24[1028]; // [sp+10h] [bp-408h]@36

  if ( word_4123E0[0] )
  {
    v0 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x67, 0x400u);
    if ( v0 )
    {
      v1 = LoadResource(hModule, v0);
      if ( v1 )
      {
        v2 = LockResource(v1);
        if ( v2 )
        {
          v3 = 0;
          do
          {
            v4 = v2[v3];
            Text[v3++] = v4;
          }
          while ( v4 );
          if ( dword_40A028 && dword_40A090 )
            fprintf(dword_40A090, "Resource %d:\t%s\n", 103, Text);
        }
      }
    }
    else
    {
      SetLastError(0);
      Text[0] = 0;
    }
    *(uint16_t *)&Text[strlen(Text)] = 32;
    strcat(Text, &byte_4122E0);
    if ( word_412460[0] )
    {
      *(uint32_t *)&Text[strlen(Text)] = 2108704;
      strcat(Text, &byte_412360);
    }
    v5 = dword_4122D0;
    if ( dword_4122D0 == 4 || dword_4122D0 == 1 )
    {
      v6 = strlen(Text);
      *(uint16_t *)&Text[v6] = 10272;
      Text[v6 + 2] = 0;
      v7 = "64";
      if ( v5 != 1 )
        v7 = "32";
      strcat(Text, v7);
      v8 = strlen(Text);
      *(uint32_t *)&Text[v8] = 1953063469;
      *(uint16_t *)&Text[v8 + 4] = 41;
    }
    if ( dword_4122DC )
    {
      memset(v24, 0, 0x400u);
      v19 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x68, 0x400u);
      if ( v19 )
      {
        v20 = LoadResource(hModule, v19);
        if ( v20 )
        {
          v21 = LockResource(v20);
          if ( v21 )
          {
            v22 = 0;
            do
            {
              v23 = v21[v22];
              v24[v22++] = v23;
            }
            while ( v23 );
            if ( dword_40A028 && dword_40A090 )
              fprintf(dword_40A090, "Resource %d:\t%s\n", 104, v24);
            *(uint16_t *)&Text[strlen(Text)] = 10;
            strcat(Text, v24);
          }
        }
      }
      else
      {
        SetLastError(0);
        v24[0] = 0;
      }
    }
    v9 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x15, 0x400u);
    if ( v9 )
    {
      v10 = LoadResource(hModule, v9);
      if ( v10 )
      {
        v11 = LockResource(v10);
        if ( v11 )
        {
          v12 = 0;
          do
          {
            v13 = v11[v12];
            *((uint8_t *)&File + v12++) = v13;
          }
          while ( v13 );
          if ( dword_40A028 )
          {
            if ( dword_40A090 )
              fprintf(dword_40A090, "Resource %d:\t%s\n", 21, &File);
          }
        }
      }
    }
    else
    {
      SetLastError(0);
      File = 0;
    }
  }
  else
  {
    v14 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x66, 0x400u);
    if ( v14 )
    {
      v15 = LoadResource(hModule, v14);
      if ( v15 )
      {
        v16 = LockResource(v15);
        if ( v16 )
        {
          v17 = 0;
          do
          {
            v18 = v16[v17];
            Text[v17++] = v18;
          }
          while ( v18 );
          if ( dword_40A028 && dword_40A090 )
            fprintf(dword_40A090, "Resource %d:\t%s\n", 102, Text);
        }
      }
    }
    else
    {
      SetLastError(0);
      Text[0] = 0;
    }
  }
}
// 40A028: using guessed type int dword_40A028;
// 4122D0: using guessed type int dword_4122D0;
// 4122DC: using guessed type int dword_4122DC;
// 4042B0: using guessed type char var_408[1028];

//----- (00404740) --------------------------------------------------------
int __cdecl sub_404740(char *a1, int a2)
{
  HRSRC v2; // eax@1
  HGLOBAL v3; // eax@2
  bool v4; // zf@2
  uint8_t *v5; // eax@3
  uint8_t *v6; // ecx@3
  int v7; // edx@4
  char v8; // al@5
  char *v9; // esi@9
  signed int v10; // ecx@9
  const char *v11; // edi@9
  HRSRC v12; // eax@12
  HGLOBAL v13; // eax@13
  uint8_t *v14; // ecx@14
  int v15; // edx@15
  char v16; // al@16
  char *v17; // eax@20
  const char *v18; // esi@21
  HRSRC v19; // eax@23
  HGLOBAL v20; // eax@24
  uint8_t *v21; // eax@25
  int v22; // edx@26
  char v23; // bl@27
  char *v24; // eax@31
  const char *v25; // esi@32
  signed int v27; // eax@40
  HRSRC v28; // eax@45
  HGLOBAL v29; // eax@46
  uint8_t *v30; // ecx@47
  int v31; // edx@48
  char v32; // al@49
  int v33; // eax@51
  unsigned int v34; // esi@51
  int v35; // ebx@51
  const char *v36; // edx@65
  HRSRC v37; // eax@70
  HGLOBAL v38; // eax@71
  uint8_t *v39; // ecx@72
  int v40; // edx@73
  char v41; // al@74
  int v42; // eax@78
  unsigned int v43; // esi@78
  int v44; // ebx@78
  const char *v45; // edx@87
  const char *v46; // [sp+4h] [bp-84h]@43
  char *v47; // [sp+8h] [bp-80h]@8
  char *v48; // [sp+Ch] [bp-7Ch]@8
  int v49; // [sp+24h] [bp-64h]@39
  int v50; // [sp+28h] [bp-60h]@1
  size_t v51; // [sp+2Ch] [bp-5Ch]@1
  char v52[32]; // [sp+30h] [bp-58h]@45
  char v53[56]; // [sp+50h] [bp-38h]@1

  v50 = 1;
  memset(v53, 0, 0x14u);
  v51 = a2;
  v2 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x20, 0x400u);
  if ( v2 )
  {
    v3 = LoadResource(hModule, v2);
    v4 = v3 == 0;
    if ( v3 )
    {
      v5 = LockResource(v3);
      v4 = v5 == 0;
      v6 = v5;
      if ( v5 )
      {
        v7 = 0;
        do
        {
          v8 = v6[v7];
          v53[v7++] = v8;
        }
        while ( v8 );
        v4 = dword_40A028 == 0;
        if ( dword_40A028 )
        {
          v4 = dword_40A090 == 0;
          if ( dword_40A090 )
          {
            v48 = v53;
            v47 = (char *)32;
            fprintf(dword_40A090, "Resource %d:\t%s\n", 32, v53);
          }
        }
      }
    }
  }
  else
  {
    SetLastError(0);
    v53[0] = 0;
    v4 = &v46 == 0;
  }
  v9 = v53;
  v10 = 5;
  v11 = "true";
  do
  {
    if ( !v10 )
      break;
    v4 = *v9++ == *v11++;
    --v10;
  }
  while ( v4 );
  dword_4122D8 = v4;
  v12 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)2, 0x400u);
  if ( v12 )
  {
    v13 = LoadResource(hModule, v12);
    if ( v13 )
    {
      v14 = LockResource(v13);
      if ( v14 )
      {
        v15 = 0;
        do
        {
          v16 = v14[v15];
          *(&byte_4122E0 + v15++) = v16;
        }
        while ( v16 );
        if ( dword_40A028 && dword_40A090 )
        {
          v48 = &byte_4122E0;
          v47 = (char *)2;
          fprintf(dword_40A090, "Resource %d:\t%s\n", 2, &byte_4122E0);
        }
      }
    }
  }
  else
  {
    SetLastError(0);
    byte_4122E0 = 0;
  }
  v17 = strchr(&byte_4122E0, 95);
  if ( v17 && (v18 = v17 + 1, strlen(v17 + 1) <= 2) )
  {
    strncpy(word_4123E0, &byte_4122E0, v18 - &byte_4122E0);
    word_4123E0[v18 - &byte_4122E0] = 0;
    *(uint16_t *)&word_4123E0[strlen(word_4123E0)] = 48;
    v46 = v18;
    strcat(word_4123E0, v18);
  }
  else
  {
    strcpy(word_4123E0, &byte_4122E0);
  }
  v19 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)3, 0x400u);
  if ( v19 )
  {
    v20 = LoadResource(hModule, v19);
    if ( v20 )
    {
      v21 = LockResource(v20);
      if ( v21 )
      {
        v22 = 0;
        do
        {
          v23 = v21[v22];
          *(&byte_412360 + v22++) = v23;
        }
        while ( v23 );
        if ( dword_40A028 && dword_40A090 )
        {
          v48 = &byte_412360;
          v47 = (char *)3;
          fprintf(dword_40A090, "Resource %d:\t%s\n", 3, &byte_412360);
        }
      }
    }
  }
  else
  {
    SetLastError(0);
    byte_412360 = 0;
  }
  v24 = strchr(&byte_412360, 95);
  if ( v24 && (v25 = v24 + 1, strlen(v24 + 1) <= 2) )
  {
    strncpy(word_412460, &byte_412360, v25 - &byte_412360);
    word_412460[v25 - &byte_412360] = 0;
    *(uint16_t *)&word_412460[strlen(word_412460)] = 48;
    v46 = v25;
    strcat(word_412460, v25);
  }
  else
  {
    strcpy(word_412460, &byte_412360);
  }
  if ( dword_4122D8 )
  {
    if ( word_4123E0[0] )
    {
      memset(v52, 0, 0x14u);
      v28 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x12, 0x400u);
      if ( v28 )
      {
        v29 = LoadResource(hModule, v28);
        if ( v29 )
        {
          v30 = LockResource(v29);
          if ( v30 )
          {
            v31 = 0;
            do
            {
              v32 = v30[v31];
              v52[v31++] = v32;
            }
            while ( v32 );
            if ( dword_40A028 && dword_40A090 )
            {
              v48 = v52;
              v47 = (char *)18;
              fprintf(dword_40A090, "Resource %d:\t%s\n", 18, v52);
            }
          }
        }
      }
      else
      {
        SetLastError(0);
        v52[0] = 0;
      }
      v33 = atoi(v52);
      v34 = v33 - 2;
      v35 = v33;
      if ( (unsigned int)(v33 - 2) > 1 )
      {
        sub_402CB0("SOFTWARE\\JavaSoft\\Java Runtime Environment", 1);
        if ( v35 )
          sub_402CB0("SOFTWARE\\JavaSoft\\Java Development Kit", 2);
      }
      else
      {
        sub_402CB0("SOFTWARE\\JavaSoft\\Java Development Kit", 2);
        if ( v35 != 3 )
          sub_402CB0("SOFTWARE\\JavaSoft\\Java Runtime Environment", 1);
      }
      if ( dword_4122D4 )
        goto LABEL_101;
      if ( v34 > 1 )
      {
        sub_402CB0("SOFTWARE\\IBM\\Java2 Runtime Environment", 1);
        if ( v35 )
          sub_402CB0("SOFTWARE\\IBM\\Java Development Kit", 2);
      }
      else
      {
        sub_402CB0("SOFTWARE\\IBM\\Java Development Kit", 2);
        if ( v35 != 3 )
          sub_402CB0("SOFTWARE\\IBM\\Java2 Runtime Environment", 1);
      }
      if ( dword_4122D4 )
      {
LABEL_101:
        strcpy(word_40A1A4, byte_412664);
        if ( dword_40A090 )
        {
          v36 = "64";
          if ( !(BYTE1(dword_4122D4) & 1) )
            v36 = "32";
          v48 = (char *)v36;
          v47 = byte_4124E0;
          fprintf(dword_40A090, "Runtime used:\t%s (%s-bit)\n", byte_4124E0, v36);
        }
        return v50;
      }
    }
    v50 = sub_403D20(a1, v51);
    if ( v50 )
      return v50;
  }
  else
  {
    if ( sub_403D20(a1, v51) )
      return v50;
    v49 = 0;
    if ( !word_4123E0[0] )
      goto LABEL_102;
    memset(v52, 0, 0x14u);
    v37 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x12, 0x400u);
    if ( v37 )
    {
      v38 = LoadResource(hModule, v37);
      if ( v38 )
      {
        v39 = LockResource(v38);
        if ( v39 )
        {
          v40 = 0;
          do
          {
            v41 = v39[v40];
            v52[v40++] = v41;
          }
          while ( v41 );
          if ( dword_40A028 && dword_40A090 )
          {
            v48 = v52;
            v47 = (char *)18;
            fprintf(dword_40A090, "Resource %d:\t%s\n", 18, v52);
          }
        }
      }
    }
    else
    {
      SetLastError(0);
      v52[0] = 0;
    }
    v42 = atoi(v52);
    v43 = v42 - 2;
    v44 = v42;
    if ( (unsigned int)(v42 - 2) > 1 )
    {
      sub_402CB0("SOFTWARE\\JavaSoft\\Java Runtime Environment", 1);
      if ( v44 )
        sub_402CB0("SOFTWARE\\JavaSoft\\Java Development Kit", 2);
    }
    else
    {
      sub_402CB0("SOFTWARE\\JavaSoft\\Java Development Kit", 2);
      if ( v44 != 3 )
        sub_402CB0("SOFTWARE\\JavaSoft\\Java Runtime Environment", 1);
    }
    if ( dword_4122D4 )
      goto LABEL_103;
    if ( v43 > 1 )
    {
      sub_402CB0("SOFTWARE\\IBM\\Java2 Runtime Environment", 1);
      if ( v44 )
        sub_402CB0("SOFTWARE\\IBM\\Java Development Kit", 2);
    }
    else
    {
      sub_402CB0("SOFTWARE\\IBM\\Java Development Kit", 2);
      if ( v44 != 3 )
        sub_402CB0("SOFTWARE\\IBM\\Java2 Runtime Environment", 1);
    }
    if ( dword_4122D4 )
    {
LABEL_103:
      strcpy(word_40A1A4, byte_412664);
      if ( dword_40A090 )
      {
        v45 = "64";
        if ( !(BYTE1(dword_4122D4) & 1) )
          v45 = "32";
        v48 = (char *)v45;
        v47 = byte_4124E0;
        fprintf(dword_40A090, "Runtime used:\t%s (%s-bit)\n", byte_4124E0, v45);
      }
      v49 = 1;
      v27 = 1;
    }
    else
    {
LABEL_102:
      v27 = v49;
    }
    v50 = v27;
    if ( v27 )
      return v50;
  }
  sub_4042B0();
  return v50;
}
// 40A028: using guessed type int dword_40A028;
// 4122D4: using guessed type int dword_4122D4;
// 4122D8: using guessed type int dword_4122D8;
// 404740: using guessed type char var_38[56];
// 404740: using guessed type char var_58[32];

//----- (004051E0) --------------------------------------------------------
char *__cdecl sub_4051E0(char *a1, int a2)
{
  HRSRC v2; // eax@1
  HGLOBAL v3; // eax@2
  uint8_t *v4; // ecx@3
  int v5; // edx@4
  char v6; // al@5
  char *result; // eax@9
  const CHAR *v8; // ebx@11
  char *v9; // eax@12
  char v10[32768]; // [sp+10h] [bp-10018h]@1
  CHAR Value; // [sp+8010h] [bp-8018h]@1

  memset(&Value, 0, 0x8000u);
  memset(v10, 0, 0x7FFFu);
  v2 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x13, 0x400u);
  if ( v2 )
  {
    v3 = LoadResource(hModule, v2);
    if ( v3 )
    {
      v4 = LockResource(v3);
      if ( v4 )
      {
        v5 = 0;
        do
        {
          v6 = v4[v5];
          v10[v5++] = v6;
        }
        while ( v6 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", 19, v10);
      }
    }
  }
  else
  {
    SetLastError(0);
    v10[0] = 0;
  }
  for ( result = strtok(v10, "\t"); ; result = strtok(0, "\t") )
  {
    v8 = result;
    if ( !result )
      break;
    v9 = strchr(result, 61);
    *v9 = 0;
    Value = 0;
    sub_403100(&Value, v9 + 1, a1, a2);
    if ( dword_40A090 )
      fprintf(dword_40A090, "Set var:\t%s = %s\n", v8, &Value);
    SetEnvironmentVariableA(v8, &Value);
  }
  return result;
}
// 40A028: using guessed type int dword_40A028;
// 4051E0: using guessed type char var_10018[32768];

//----- (00405390) --------------------------------------------------------
size_t __cdecl sub_405390(char *a1, int a2)
{
  HRSRC v2; // eax@1
  HGLOBAL v3; // eax@2
  bool v4; // cf@2
  bool v5; // zf@2
  uint8_t *v6; // eax@3
  uint8_t *v7; // ecx@3
  int v8; // edx@4
  char v9; // al@5
  char *v10; // esi@9
  signed int v11; // ecx@9
  const char *v12; // edi@9
  int v13; // ebx@12
  HRSRC v14; // eax@12
  HGLOBAL v15; // eax@13
  uint8_t *v16; // ecx@14
  int v17; // edx@15
  char v18; // al@16
  HRSRC v19; // eax@20
  HGLOBAL v20; // eax@21
  uint8_t *v21; // ecx@22
  int v22; // edx@23
  char v23; // al@24
  HRSRC v24; // eax@28
  HGLOBAL v25; // eax@29
  uint8_t *v26; // ecx@30
  int v27; // edx@31
  char v28; // al@32
  size_t v29; // eax@36
  char *i; // ebx@38
  int v31; // esi@41
  char *v32; // eax@41
  char *v33; // esi@43
  __int32 v34; // ebx@43
  size_t v35; // eax@50
  size_t result; // eax@50
  size_t v37; // eax@53
  size_t v38; // eax@55
  size_t v39; // edi@55
  size_t v40; // eax@55
  size_t v41; // eax@65
  char *v42; // [sp+4h] [bp-10394h]@53
  char *v43; // [sp+8h] [bp-10390h]@8
  char *v44; // [sp+Ch] [bp-1038Ch]@8
  size_t v45; // [sp+1Ch] [bp-1037Ch]@1
  struct _finddata_t v46; // [sp+20h] [bp-10378h]@43
  char v47[32]; // [sp+140h] [bp-10258h]@1
  char v48[272]; // [sp+160h] [bp-10238h]@1
  char v49[272]; // [sp+270h] [bp-10128h]@1
  char v50; // [sp+380h] [bp-10018h]@1
  char v51[32792]; // [sp+8380h] [bp-8018h]@1

  v45 = a2;
  memset(v51, 0, 0x8000u);
  memset(&v50, 0, 0x8000u);
  memset(v49, 0, 0x104u);
  memset(v48, 0, 0x104u);
  memset(v47, 0, 0x14u);
  v2 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x11, 0x400u);
  if ( v2 )
  {
    v3 = LoadResource(hModule, v2);
    v4 = 0;
    v5 = v3 == 0;
    if ( v3 )
    {
      v6 = LockResource(v3);
      v4 = 0;
      v5 = v6 == 0;
      v7 = v6;
      if ( v6 )
      {
        v8 = 0;
        do
        {
          v9 = v7[v8];
          v47[v8++] = v9;
        }
        while ( v9 );
        v4 = 0;
        v5 = dword_40A028 == 0;
        if ( dword_40A028 )
        {
          v4 = 0;
          v5 = dword_40A090 == 0;
          if ( dword_40A090 )
          {
            v44 = v47;
            v43 = (char *)17;
            fprintf(dword_40A090, "Resource %d:\t%s\n", 17, v47);
          }
        }
      }
    }
  }
  else
  {
    SetLastError(0);
    v47[0] = 0;
    v4 = (unsigned int)&v42 < 4;
    v5 = &v42 == 0;
  }
  v10 = v47;
  v11 = 5;
  v12 = "true";
  do
  {
    if ( !v11 )
      break;
    v4 = (unsigned __int8)*v10 < *v12;
    v5 = *v10++ == *v12++;
    --v11;
  }
  while ( v5 );
  v13 = (!v4 && !v5) == v4;
  v14 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0xE, 0x400u);
  if ( v14 )
  {
    v15 = LoadResource(hModule, v14);
    if ( v15 )
    {
      v16 = LockResource(v15);
      if ( v16 )
      {
        v17 = 0;
        do
        {
          v18 = v16[v17];
          v49[v17++] = v18;
        }
        while ( v18 );
        if ( dword_40A028 && dword_40A090 )
        {
          v44 = v49;
          v43 = (char *)14;
          fprintf(dword_40A090, "Resource %d:\t%s\n", 14, v49);
        }
      }
    }
  }
  else
  {
    SetLastError(0);
    v49[0] = 0;
  }
  v19 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0xF, 0x400u);
  if ( !v19 )
  {
    SetLastError(0);
    byte_40A0A0 = 0;
LABEL_52:
    if ( v13 )
    {
      v37 = strlen(dword_40A2A8);
      *(uint32_t *)&dword_40A2A8[v37] = 1918986797;
      *(uint16_t *)&dword_40A2A8[v37 + 4] = 8736;
      dword_40A2A8[v37 + 6] = 0;
      v42 = a1;
      strcat(dword_40A2A8, a1);
      result = strlen(dword_40A2A8);
    }
    else
    {
      v38 = strlen(dword_40A2A8);
      v39 = v45;
      *(uint32_t *)&dword_40A2A8[v38] = 1918986797;
      *(uint16_t *)&dword_40A2A8[v38 + 4] = 8736;
      dword_40A2A8[v38 + 6] = 0;
      strncat(dword_40A2A8, a1, v39);
      v40 = strlen(dword_40A2A8);
      if ( dword_40A2A8[v40 - 1] != 92 )
        *(uint16_t *)&dword_40A2A8[v40] = 92;
      strcat(dword_40A2A8, v49);
      result = strlen(dword_40A2A8);
    }
    *(uint16_t *)&dword_40A2A8[result] = 34;
    return result;
  }
  v20 = LoadResource(hModule, v19);
  if ( !v20 )
    goto LABEL_52;
  v21 = LockResource(v20);
  if ( !v21 )
    goto LABEL_52;
  v22 = 0;
  do
  {
    v23 = v21[v22];
    *(&byte_40A0A0 + v22++) = v23;
  }
  while ( v23 );
  if ( dword_40A028 && dword_40A090 )
  {
    v44 = &byte_40A0A0;
    v43 = (char *)15;
    fprintf(dword_40A090, "Resource %d:\t%s\n", 15, &byte_40A0A0);
  }
  v24 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x10, 0x400u);
  if ( v24 )
  {
    v25 = LoadResource(hModule, v24);
    if ( v25 )
    {
      v26 = LockResource(v25);
      if ( v26 )
      {
        v27 = 0;
        do
        {
          v28 = v26[v27];
          v51[v27++] = v28;
        }
        while ( v28 );
        if ( dword_40A028 && dword_40A090 )
        {
          v44 = v51;
          v43 = (char *)16;
          fprintf(dword_40A090, "Resource %d:\t%s\n", 16, v51);
        }
        goto LABEL_36;
      }
    }
  }
  else
  {
    SetLastError(0);
    v51[0] = 0;
  }
  if ( dword_40A090 )
    fwrite("Info:\t\tClasspath not defined.\n", 1u, 0x1Eu, dword_40A090);
LABEL_36:
  sub_403100(&v50, v51, a1, v45);
  v29 = strlen(dword_40A2A8);
  *(int *)((char *)&dword_40A2AC + v29) = 1634759539;
  *(uint32_t *)&dword_40A2A8[v29] = 1634493229;
  *(int *)((char *)&dword_40A2B0 + v29) = 572549236;
  byte_40A2B4[v29] = 0;
  if ( v13 )
  {
    v42 = a1;
    strcat(dword_40A2A8, a1);
    v41 = strlen(dword_40A2A8);
LABEL_66:
    *(uint16_t *)&dword_40A2A8[v41] = 59;
    goto LABEL_38;
  }
  if ( v49[0] )
  {
    strcat(dword_40A2A8, v49);
    v41 = strlen(dword_40A2A8);
    goto LABEL_66;
  }
LABEL_38:
  for ( i = strtok(&v50, ";"); i; i = strtok(0, ";") )
  {
    if ( dword_40A090 )
    {
      v43 = i;
      fprintf(dword_40A090, "Add classpath:\t%s\n", i, v44);
      if ( strpbrk(i, "*?") )
      {
LABEL_41:
        v31 = 0;
        v32 = strrchr(i, 92);
        if ( v32 )
          v31 = v32 - i + 1;
        v48[0] = 0;
        v43 = (char *)v31;
        v33 = &v48[v31];
        strncpy(v48, i, (size_t)v43);
        *v33 = 0;
        v34 = findfirst(i, &v46);
        if ( v34 != -1 )
        {
          do
          {
            while ( 1 )
            {
              strcpy(v33, v46.name);
              strcat(dword_40A2A8, v48);
              *(uint16_t *)&dword_40A2A8[strlen(dword_40A2A8)] = 59;
              if ( dword_40A090 )
                break;
              if ( findnext(v34, &v46) )
                goto LABEL_48;
            }
            v43 = v48;
            fprintf(dword_40A090, "      \"      :\t%s\n", v48, v44);
          }
          while ( !findnext(v34, &v46) );
        }
LABEL_48:
        findclose(v34);
        continue;
      }
    }
    else if ( strpbrk(i, "*?") )
    {
      goto LABEL_41;
    }
    v42 = i;
    strcat(dword_40A2A8, i);
    *(uint16_t *)&dword_40A2A8[strlen(dword_40A2A8)] = 59;
  }
  byte_40A2A7[strlen(dword_40A2A8)] = 0;
  v35 = strlen(dword_40A2A8);
  *(uint8_t *)(v35 + 4235946) = 0;
  *(uint16_t *)&dword_40A2A8[v35] = 8226;
  return (size_t)strcat(dword_40A2A8, &byte_40A0A0);
}
// 40A028: using guessed type int dword_40A028;
// 40A2AC: using guessed type int dword_40A2AC;
// 40A2B0: using guessed type int dword_40A2B0;
// 405390: using guessed type char var_8018[32792];
// 405390: using guessed type char var_10238[272];
// 405390: using guessed type char var_10128[272];
// 405390: using guessed type char var_10258[32];

//----- (00405B60) --------------------------------------------------------
void __cdecl sub_405B60(char *a1)
{
  HRSRC v1; // eax@1
  HGLOBAL v2; // eax@2
  uint8_t *v3; // ecx@3
  int v4; // edx@4
  char v5; // al@5
  char *v6; // ebx@13
  char *v7; // eax@14
  char v8[32776]; // [sp+10h] [bp-8008h]@1

  memset(v8, 0, 0x8000u);
  v1 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0xD, 0x400u);
  if ( v1 )
  {
    v2 = LoadResource(hModule, v1);
    if ( v2 )
    {
      v3 = LockResource(v2);
      if ( v3 )
      {
        v4 = 0;
        do
        {
          v5 = v3[v4];
          v8[v4++] = v5;
        }
        while ( v5 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", 13, v8);
        *(uint16_t *)&dword_40A2A8[strlen(dword_40A2A8)] = 32;
        strcat(dword_40A2A8, v8);
      }
    }
  }
  else
  {
    SetLastError(0);
    v8[0] = 0;
  }
  if ( *a1 )
  {
    strcpy(v8, a1);
    while ( 1 )
    {
      v6 = strstr(v8, "--l4j-");
      if ( !v6 )
        break;
      while ( 1 )
      {
        v7 = strchr(v6, 32);
        if ( v7 )
        {
          if ( v7[1] )
            break;
        }
        *v6 = 0;
        v6 = strstr(v8, "--l4j-");
        if ( !v6 )
          goto LABEL_17;
      }
      strcpy(v6, v7 + 1);
    }
LABEL_17:
    if ( v8[0] )
    {
      *(uint16_t *)&dword_40A2A8[strlen(dword_40A2A8)] = 32;
      strcat(dword_40A2A8, v8);
    }
  }
}
// 40A028: using guessed type int dword_40A028;
// 405B60: using guessed type char var_8008[32776];

//----- (00405D30) --------------------------------------------------------
int __cdecl sub_405D30(char *a1)
{
  signed int v1; // edx@1
  char *v3; // eax@4
  int v4; // esi@4
  int v5; // eax@5
  HMODULE v6; // eax@6
  FARPROC v7; // ebx@6
  HANDLE v8; // eax@7
  const char *v9; // edx@9
  HRSRC v10; // eax@12
  HGLOBAL v11; // eax@13
  uint8_t *v12; // ecx@14
  int v13; // edx@15
  CHAR v14; // al@16
  HRSRC v15; // eax@20
  HGLOBAL v16; // eax@21
  uint8_t *v17; // ecx@22
  int v18; // edx@23
  char v19; // al@24
  HRSRC v20; // eax@28
  HGLOBAL v21; // eax@29
  uint8_t *v22; // ecx@30
  int v23; // edx@31
  char v24; // al@32
  HRSRC v25; // eax@36
  HGLOBAL v26; // eax@37
  uint8_t *v27; // ecx@38
  int v28; // edx@39
  char v29; // al@40
  HRSRC v30; // eax@46
  HGLOBAL v31; // eax@47
  uint8_t *v32; // ecx@48
  int v33; // edx@49
  char v34; // al@50
  size_t v35; // eax@54
  int v36; // eax@58
  size_t v37; // eax@59
  size_t v38; // ebx@59
  FILE *v39; // eax@60
  HRSRC v40; // eax@75
  HGLOBAL v41; // eax@76
  uint8_t *v42; // ecx@77
  int v43; // edx@78
  char v44; // al@79
  size_t v45; // eax@84
  FILE *v46; // ebx@90
  size_t v47; // eax@91
  size_t v48; // eax@92
  const char *v49; // [sp+8h] [bp-10460h]@61
  char v50; // [sp+30h] [bp-10438h]@87
  int v51; // [sp+8030h] [bp-8438h]@87
  int v52; // [sp+8040h] [bp-8428h]@87
  int v53; // [sp+8044h] [bp-8424h]@87
  char v54[32]; // [sp+8070h] [bp-83F8h]@75
  char Buffer[32768]; // [sp+8090h] [bp-83D8h]@59
  char v56[272]; // [sp+10090h] [bp-3D8h]@46
  char v57[272]; // [sp+101A0h] [bp-2C8h]@46
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [sp+102B0h] [bp-1B8h]@45
  char Name[128]; // [sp+102C0h] [bp-1A8h]@36
  CHAR Filename; // [sp+10340h] [bp-128h]@3

  hModule = GetModuleHandleA(0);
  v1 = 0;
  if ( !hModule )
    return v1;
  byte_412898 = 0;
  *(uint32_t *)Caption = 1853186380;
  dword_412894 = 1781819491;
  dword_4122D0 = 9;
  dword_4122D4 = 0;
  dword_4122D8 = 0;
  dword_4122DC = 0;
  memset(&Filename, 0, 0x104u);
  if ( !GetModuleFileNameA(hModule, &Filename, 0x104u) )
    return 0;
  v3 = strrchr(&Filename, 92);
  v4 = v3 - &Filename;
  if ( v3 - &Filename == -1 )
    return 0;
  v5 = sub_401C30(a1, &Filename, v3 - &Filename);
  v1 = 0;
  if ( !v5 )
    return v1;
  v6 = GetModuleHandleA("kernel32");
  v7 = GetProcAddress(v6, "IsWow64Process");
  if ( v7 )
  {
    v8 = GetCurrentProcess();
    ((void (__stdcall *)(HANDLE, int *))v7)(v8, &dword_40A020);
  }
  if ( dword_40A090 )
  {
    v9 = "yes";
    if ( !dword_40A020 )
      v9 = "no";
    fprintf(dword_40A090, "WOW64:\t\t%s\n", v9);
  }
  v10 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0xA, 0x400u);
  if ( v10 )
  {
    v11 = LoadResource(hModule, v10);
    if ( v11 )
    {
      v12 = LockResource(v11);
      if ( v12 )
      {
        v13 = 0;
        do
        {
          v14 = v12[v13];
          Caption[v13++] = v14;
        }
        while ( v14 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", 10, Caption);
      }
    }
  }
  else
  {
    SetLastError(0);
    Caption[0] = 0;
  }
  v15 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x16, 0x400u);
  if ( v15 )
  {
    v16 = LoadResource(hModule, v15);
    if ( v16 )
    {
      v17 = LockResource(v16);
      if ( v17 )
      {
        v18 = 0;
        do
        {
          v19 = v17[v18];
          *((uint8_t *)&File + v18++) = v19;
        }
        while ( v19 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", 22, &File);
      }
    }
  }
  else
  {
    SetLastError(0);
    File = 0;
  }
  v20 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x65, 0x400u);
  if ( !v20 )
  {
    SetLastError(0);
    Text[0] = 0;
LABEL_65:
    v39 = dword_40A090;
    if ( !dword_40A090 )
      return 0;
    v49 = "Startup error message not defined.";
    goto LABEL_62;
  }
  v21 = LoadResource(hModule, v20);
  if ( !v21 )
    goto LABEL_65;
  v22 = LockResource(v21);
  if ( !v22 )
    goto LABEL_65;
  v23 = 0;
  do
  {
    v24 = v22[v23];
    Text[v23++] = v24;
  }
  while ( v24 );
  if ( dword_40A028 && dword_40A090 )
    fprintf(dword_40A090, "Resource %d:\t%s\n", 101, Text);
  memset(Name, 0, 0x80u);
  v25 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x17, 0x400u);
  if ( v25 )
  {
    v26 = LoadResource(hModule, v25);
    if ( v26 )
    {
      v27 = LockResource(v26);
      if ( v27 )
      {
        v28 = 0;
        do
        {
          v29 = v27[v28];
          Name[v28++] = v29;
        }
        while ( v29 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", 23, Name);
      }
    }
  }
  else
  {
    SetLastError(0);
    Name[0] = 0;
  }
  if ( Name[0] )
  {
    MutexAttributes.nLength = 12;
    MutexAttributes.bInheritHandle = 1;
    MutexAttributes.lpSecurityDescriptor = 0;
    CreateMutexA(&MutexAttributes, 0, Name);
    if ( GetLastError() == 183 )
    {
      if ( dword_40A090 )
      {
        fprintf(dword_40A090, "Error:\t\t%s\n", "Instance already exists.");
        v1 = 183;
      }
      else
      {
        v1 = 183;
      }
      return v1;
    }
  }
  memset(v57, 0, 0x104u);
  memset(v56, 0, 0x104u);
  GetCurrentDirectoryA(0x104u, ::Buffer);
  v30 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)8, 0x400u);
  if ( v30 )
  {
    v31 = LoadResource(hModule, v30);
    if ( v31 )
    {
      v32 = LockResource(v31);
      if ( v32 )
      {
        v33 = 0;
        do
        {
          v34 = v32[v33];
          v56[v33++] = v34;
        }
        while ( v34 );
        if ( dword_40A028 && dword_40A090 )
          fprintf(dword_40A090, "Resource %d:\t%s\n", 8, v56);
        strncpy(v57, &Filename, v4);
        v35 = strlen(v57);
        if ( v57[v35 - 1] != 92 )
          *(uint16_t *)&v57[v35] = 92;
        strcat(v57, v56);
        chdir(v57);
        if ( dword_40A090 )
          fprintf(dword_40A090, "Working dir:\t%s\n", v57);
      }
    }
  }
  else
  {
    SetLastError(0);
    v56[0] = 0;
  }
  v36 = sub_404740(&Filename, v4);
  v1 = 0;
  if ( !v36 )
    return v1;
  memset(v56, 0, 0x104u);
  strcpy(v56, word_40A1A4);
  v37 = strlen(v56);
  v56[v37 + 4] = 0;
  *(uint32_t *)&v56[v37] = 1852400220;
  memset(Buffer, 0, 0x7FFFu);
  v38 = 32766 - GetEnvironmentVariableA("Path", Buffer, 0x7FFFu);
  if ( v38 >= strlen(v56) )
  {
    *(uint16_t *)&Buffer[strlen(Buffer)] = 59;
    strcat(Buffer, v56);
    if ( SetEnvironmentVariableA("Path", Buffer) )
    {
      sub_4051E0(&Filename, v4);
      memset(v54, 0, 0x14u);
      v40 = FindResourceExA(hModule, (LPCSTR)0xA, (LPCSTR)0x14, 0x400u);
      if ( v40 )
      {
        v41 = LoadResource(hModule, v40);
        if ( v41 )
        {
          v42 = LockResource(v41);
          if ( v42 )
          {
            v43 = 0;
            do
            {
              v44 = v42[v43];
              v54[v43++] = v44;
            }
            while ( v44 );
            if ( dword_40A028 && dword_40A090 )
              fprintf(dword_40A090, "Resource %d:\t%s\n", 20, v54);
          }
        }
      }
      else
      {
        SetLastError(0);
        v54[0] = 0;
      }
      dwCreationFlags = atoi(v54);
      if ( dword_40A024 )
      {
        v45 = strlen(word_40A1A4);
        if ( byte_40A1A3[v45] != 92 )
          *(uint16_t *)&word_40A1A4[v45] = 92;
        strcat(word_40A1A4, "bin\\java.exe");
      }
      else
      {
        v48 = strlen(word_40A1A4);
        if ( byte_40A1A3[v48] != 92 )
          *(uint16_t *)&word_40A1A4[v48] = 92;
        strcat(word_40A1A4, "bin\\javaw.exe");
      }
      v51 = 64;
      GlobalMemoryStatusEx(&v51);
      sub_4033F0(dword_40A2A8, 25, 26, v52, v53, "-Xms");
      sub_4033F0(dword_40A2A8, 27, 28, v52, v53, "-Xmx");
      memset(&v50, 0, 0x8000u);
      sub_403790(&v50, &Filename);
      sub_403100(dword_40A2A8, &v50, &Filename, v4);
      sub_405390(&Filename, v4);
      sub_405B60(a1);
      if ( dword_40A090
        && (fprintf(dword_40A090, "Launcher:\t%s\n", word_40A1A4), dword_40A090)
        && (fprintf(dword_40A090, "Launcher args:\t%s\n", dword_40A2A8), (v46 = dword_40A090) != 0) )
      {
        v47 = strlen(dword_40A2A8);
        fprintf(v46, "Args length:\t%d/32768 chars\n", v47);
        v1 = 1;
      }
      else
      {
        v1 = 1;
      }
      return v1;
    }
  }
  v39 = dword_40A090;
  if ( dword_40A090 )
  {
    v49 = "appendToPathVar failed.";
LABEL_62:
    fprintf(v39, "Error:\t\t%s\n", v49);
  }
  return 0;
}
// 406F60: using guessed type int __stdcall GlobalMemoryStatusEx(uint32_t);
// 40A020: using guessed type int dword_40A020;
// 40A024: using guessed type int dword_40A024;
// 40A028: using guessed type int dword_40A028;
// 4122D0: using guessed type int dword_4122D0;
// 4122D4: using guessed type int dword_4122D4;
// 4122D8: using guessed type int dword_4122D8;
// 4122DC: using guessed type int dword_4122DC;
// 412894: using guessed type int dword_412894;
// 412898: using guessed type char byte_412898;
// 405D30: using guessed type CHAR Name[128];
// 405D30: using guessed type char var_3D8[272];
// 405D30: using guessed type char var_83F8[32];
// 405D30: using guessed type char var_2C8[272];
// 405D30: using guessed type CHAR Buffer[32768];

//----- (00406830) --------------------------------------------------------
BOOL sub_406830()
{
  CloseHandle(hObject);
  return CloseHandle(hProcess);
}

//----- (00406860) --------------------------------------------------------
int __cdecl sub_406860(int a1, LPDWORD lpExitCode)
{
  size_t v2; // eax@1
  int result; // eax@3
  CHAR CommandLine[2]; // [sp+30h] [bp-8068h]@1
  struct _STARTUPINFOA StartupInfo; // [sp+8030h] [bp-68h]@1

  memset(&hProcess, 0, 0x10u);
  memset(&StartupInfo, 0, 0x44u);
  StartupInfo.cb = 68;
  memset(CommandLine, 0, 0x8000u);
  strcpy(CommandLine, "\"");
  strcat(CommandLine, word_40A1A4);
  v2 = strlen(CommandLine);
  *(uint16_t *)&CommandLine[v2] = 8226;
  CommandLine[v2 + 2] = 0;
  strcat(CommandLine, dword_40A2A8);
  if ( CreateProcessA(0, CommandLine, 0, 0, 1, dwCreationFlags, 0, 0, &StartupInfo, (LPPROCESS_INFORMATION)&hProcess) )
  {
    if ( a1 )
    {
      WaitForSingleObject(hProcess, 0xFFFFFFFF);
      GetExitCodeProcess(hProcess, lpExitCode);
      CloseHandle(hObject);
      CloseHandle(hProcess);
      result = 1;
    }
    else
    {
      result = 1;
      *lpExitCode = 0;
    }
  }
  else
  {
    result = 0;
    *lpExitCode = -1;
  }
  return result;
}

//----- (00406B70) --------------------------------------------------------
void __cdecl sub_406B70()
{
  void (**v0)(void); // eax@1
  int v1; // edx@2

  v0 = (void (**)(void))off_408030;
  if ( (*off_408030)[0] )
  {
    do
    {
      (*v0)();
      v1 = (*off_408030)[1];
      v0 = (void (**)(void))&(*off_408030)[1];
      off_408030 = (int (*)[97])((char *)off_408030 + 4);
    }
    while ( v1 );
  }
}
// 408030: using guessed type int (*off_408030)[97];

//----- (00406C00) --------------------------------------------------------
int sub_406C00()
{
  int j; // ebx@3
  int v2; // eax@2
  bool i; // zf@2
  int v4; // [sp+0h] [bp-8h]@0

  if ( !dword_40A040 )
  {
    dword_40A040 = 1;
    v2 = 0;
    for ( i = 1; !i; i = dword_407074[v2] == 0 )
      ++v2;
    for ( j = v2; j; --j )
      ((void (*)(void))dword_407070[j])();
    atexit(sub_406B70);
  }
  return v4;
}
// 407070: using guessed type int dword_407070[];
// 407074: using guessed type int dword_407074[];
// 40A040: using guessed type int dword_40A040;
