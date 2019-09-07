#ifndef CONSOLE_H_
#define CONSOLE_H_

#include<stdio.h>
#include<windows.h>

#define BLACK        0
#define BLUE         1
#define GREEN        2
#define CYAN         (GREEN | BLUE)
#define RED          4
#define MAGENTA      (RED | BLUE)
#define BROWN        (RED | GREEN)
#define DARKGRAY     (RED | GREEN | BLUE)
#define LIGHT        8
#define LIGHTGRAY    (LIGHT | BLACK)
#define LIGHTBLUE    (LIGHT | BLUE)
#define LIGHTRED     (LIGHT | RED)
#define LIGHTMAGENTA (LIGHT | MAGENTA)
#define YELLOW       (LIGHT | BROWN)
#define WHITE        (LIGHT | RED | GREEN | BLUE)
#define BACKGROUND(color) (color<<4)

#define gotoxy(x, y) { COORD d={x,y}; \
            SetConsoleCursorPosition  \
               (GetStdHandle(STD_OUTPUT_HANDLE), d);}

#define textattr(color) { \
            SetConsoleTextAttribute \
            (GetStdHandle(STD_OUTPUT_HANDLE), (WORD)color);}

#define TextXY(x, y, text, color) { \
             gotoxy(x, y); \
                textattr(color); \
                   printf("%s", text); }

#define RTextXY(x, y, text, color){ \
             gotoxy(x, y); \
                textattr(color); \
                  printf("%S", text);}


#define CursorVisible(isVisible){\
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);\
            CONSOLE_CURSOR_INFO i; \
            GetConsoleCursorInfo(h, &i); \
            i.bVisible = isVisible; \
            SetConsoleCursorInfo(h, &i);}

#endif // CONSOLE_H_
