#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//棋盘大小
#define ROW 9
#define COL 9
//防止越界访问用
#define ROWS ROW+2
#define COLS COL+2
//雷的数量
#define EASY_COUNT 10

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int  cols, char set);

//打印棋盘，用q变量判断打印0的时候是正常打印还是打印空格
void DisplayBoard(char board[ROWS][COLS], int row, int  col);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int  col);

//排查雷
void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], char newmine[ROWS][COLS], int row, int col);

//找对应坐标附近有几个雷
int  GetMine(char mine[ROWS][COLS], int x, int y);

//判断周围有多少雷
//因为要延申打印，并且第一次碰到非空非雷时仍然打印，这里用flag判断，
void MakeBoard(char mine[ROWS][COLS], char show[ROWS][COLS], char newmine[ROWS][COLS], int x, int y, int row, int col, int flag);

//复制棋盘
void CopyBoard(char mine[ROWS][COLS], char newmine[ROWS][COLS], int row, int col);