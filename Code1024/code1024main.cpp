#include <iostream>
#include <windows.h>
#include "PictureToChar.h"
#include "pthread.h"

PictureToChar p;

void loading() {
	int max = 1024;
	int counter = 0;
	char a[4] = { '|','/','-','\\' };	//存储相关的字符
	for (int i = 0; i <= max; i+=8) {	//进度条总进度控制
		counter++;
		std::cout << " [";	//进度条左边框
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY|BACKGROUND_GREEN);	//设置加载条样式配置
		for (int j = 0; j < (((double)i / (double)max)) *80.0; j++) {	//控制加载进度的显示
			std::cout << "_";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);	//恢复原配置
		for (int j = 0; j < (double)(max -i)/ (double)max * 80.0; j++) {
			std::cout << ".";
		}	//未加载进度显示
		std::cout << "] "<< a[counter % 4] << "-";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);	//恢复原配置
		std::cout << i;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);	//恢复原配置

		std::cout << "-" << "正在加载中";	//显示和程序进行中提示和“正在加载”字样提示
		for (int j = 0; j < (counter % 4); j++) { std::cout << "."; }	//实现动态显示
		Sleep(60);	//控制程序运行速度
		printf("\r"); 
		
	}
}

void showBoom() {

}
void starat() {

	char photoPath[] = "C:\\Users\\29799\\Desktop\\codefrom1024\\photo.png";
	char videoPath[] = "C:\\Users\\29799\\Desktop\\codefrom1024\\video.mp4";

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0; //字宽
	cfi.dwFontSize.Y = 15;//字高
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;//粗细
	wcscpy_s(cfi.FaceName, L"Raster"); //设置字体，此处设为点阵字体
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("mode con cols=121 lines=50");
	p.show_PhotoToChar(photoPath,120,30);
	loading();
	cfi.dwFontSize.Y = 6;//字高
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("mode con cols=320 lines=135");
	p.show_VideoToChar(videoPath, 300, 120);

}
int main(int argc, char* argv[])
{
	starat();
	p.show_Over();
	
    return 0;
}
