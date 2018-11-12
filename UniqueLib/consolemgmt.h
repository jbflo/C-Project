#ifndef CONSOLEMGMT_H_INCLUDED
#define CONSOLEMGMT_H_INCLUDED
#include<windows.h>

#define MAX_W 100
#define MAX_H 40


/******************************************************************************/

void setcolor(unsigned short color)  	//begining of set color funtion
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);  	//gets std handle
    SetConsoleTextAttribute(hCon,color); 	//Sets Console Text Attribute HCon color.
}



void gotoxy(int x, int y)
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}



BOOL SetConsoleSizeXY(HANDLE hStdout, int iWidth, int iHeight)
{
 CONSOLE_SCREEN_BUFFER_INFO info;
 COORD      coordMax;

 coordMax = GetLargestConsoleWindowSize(hStdout);

 if (iHeight > coordMax.Y) iHeight = coordMax.Y;

 if (iWidth > coordMax.X) iWidth = coordMax.X;

 if (!GetConsoleScreenBufferInfo(hStdout, &info)) return FALSE;

/* - hauteur - */
    info.srWindow.Left = 0;
    info.srWindow.Right = info.dwSize.X - 1;
    info.srWindow.Top = 0;
    info.srWindow.Bottom = iHeight - 1;

 if (iHeight < info.dwSize.Y)
 {
  if (!SetConsoleWindowInfo(hStdout, TRUE, &info.srWindow))
   return FALSE;

  info.dwSize.Y = iHeight;

  if (!SetConsoleScreenBufferSize(hStdout, info.dwSize))
   return FALSE;
    }
    else if (iHeight > info.dwSize.Y)
    {
  info.dwSize.Y = iHeight;

  if (!SetConsoleScreenBufferSize(hStdout, info.dwSize))
   return FALSE;

  if (!SetConsoleWindowInfo(hStdout, TRUE, &info.srWindow))
   return FALSE;
    }

 if (!GetConsoleScreenBufferInfo(hStdout, &info))
  return FALSE;

/* --- largeur - */
 info.srWindow.Left = 0;
 info.srWindow.Right = iWidth - 1;
 info.srWindow.Top = 0;
 info.srWindow.Bottom = info.dwSize.Y - 1;

 if (iWidth < info.dwSize.X)
 {
  if (!SetConsoleWindowInfo(hStdout, TRUE, &info.srWindow))
   return FALSE;

  info.dwSize.X = iWidth;

  if (!SetConsoleScreenBufferSize(hStdout, info.dwSize))
   return FALSE;
 }
 else if (iWidth > info.dwSize.X)
 {
  info.dwSize.X = iWidth;

  if (!SetConsoleScreenBufferSize(hStdout, info.dwSize))
   return FALSE;

  if (!SetConsoleWindowInfo(hStdout, TRUE, &info.srWindow))
   return FALSE;
 }

 return TRUE;
}


void Maximize()
{
    //CONSOLE_SCREEN_BUFFER_INFO info;
    HANDLE hStdout=GetStdHandle (STD_OUTPUT_HANDLE);

    SetConsoleSizeXY(hStdout, MAX_W, MAX_H);

}
void drw_line(int length, int assci_code)
{int i;
for(i=0;i<length;i++) printf("%c", assci_code);

}



#endif // CONSOLEMGMT_H_INCLUDED
