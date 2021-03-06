#ifndef CCONSIX_H_GAMEPLATFORM
#define CCONSIX_H_GAMEPLATFORM

#include "..\include\CChess.h"


#define EMPTY 2//空


struct Step{
	Point first, second;
	BOOL side;
};
#define InitStep(step) { step.first.x=step.first.y=step.second.x=step.second.y=-1; }
#define IsChess(point) if(point.x!=-1&&point.y!=-1)

class CConSix : public CChess
{
public:

	CConSix(HINSTANCE hInst,HWND hWnd,char *LibPath);
	~CConSix();

	//设置棋盘大小
	virtual VOID SetBoard(RECT rtBoard);
	//绘制棋盘
	virtual VOID DrawBoard(HDC hDC);
	//初始化棋局
	virtual VOID InitGame();
	//处理引擎行棋命令  返回值：  -1：行棋违规  0：未找到关键字  1：获取成功  2：胜负手
	virtual INT ProcessMove(char *moveCmd, char *curCmd, char *denCmd);
	//响应鼠标单击消息
	virtual BOOL OnLButtonDown(int x, int y);
	//确认着法
	virtual INT OkMove(char *denCmd);
	//取消着法
	virtual INT CancelMove();

private:

	BYTE board[19][19];//棋盘信息结构
	stack<Step> stepStack;//着法栈

	bool first_hand;//第一手标志(由于六子棋第一手落一子，以后每手落两子，故需要标记)

	HPEN hPen;//棋盘刻线画笔句柄
	HFONT hFont;//刻度字体句柄
	HDC hBlcDC, hWhtDC, hMarkDC;//棋子元素DC

	int d;//棋盘刻线间距
	int pWidth;//刻线画笔宽
	int fWidth, fHeight;//刻度字体宽、高

	//绘制棋子
	VOID DrawChess();
	//播放音效
	bool PlaySnd(int tag);
	//初始化棋盘状态
	VOID InitBoard();
	//双方对弈
	BOOL SToS(Point point);
	//判断棋步合法性
	bool FitRules();
	//判断胜负
	bool WinOrLose();

};

#endif