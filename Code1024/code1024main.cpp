#include <iostream>
#include <windows.h>
#include "PictureToChar.h"
#include "pthread.h"

PictureToChar p;

void loading() {
	int max = 1024;
	int counter = 0;
	char a[4] = { '|','/','-','\\' };	//�洢��ص��ַ�
	for (int i = 0; i <= max; i+=8) {	//�������ܽ��ȿ���
		counter++;
		std::cout << " [";	//��������߿�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY|BACKGROUND_GREEN);	//���ü�������ʽ����
		for (int j = 0; j < (((double)i / (double)max)) *80.0; j++) {	//���Ƽ��ؽ��ȵ���ʾ
			std::cout << "_";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);	//�ָ�ԭ����
		for (int j = 0; j < (double)(max -i)/ (double)max * 80.0; j++) {
			std::cout << ".";
		}	//δ���ؽ�����ʾ
		std::cout << "] "<< a[counter % 4] << "-";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);	//�ָ�ԭ����
		std::cout << i;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);	//�ָ�ԭ����

		std::cout << "-" << "���ڼ�����";	//��ʾ�ͳ����������ʾ�͡����ڼ��ء�������ʾ
		for (int j = 0; j < (counter % 4); j++) { std::cout << "."; }	//ʵ�ֶ�̬��ʾ
		Sleep(60);	//���Ƴ��������ٶ�
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
	cfi.dwFontSize.X = 0; //�ֿ�
	cfi.dwFontSize.Y = 15;//�ָ�
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;//��ϸ
	wcscpy_s(cfi.FaceName, L"Raster"); //�������壬�˴���Ϊ��������
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("mode con cols=121 lines=50");
	p.show_PhotoToChar(photoPath,120,30);
	loading();
	cfi.dwFontSize.Y = 6;//�ָ�
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
