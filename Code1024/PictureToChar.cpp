#include "PictureToChar.h"
#include <opencv.hpp>
#include <iostream>
#include <Windows.h>
using namespace cv;
using namespace std;
const char* aclik_char = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\\\"^`'.";

PictureToChar::PictureToChar()
{
}
char get_char(int gray) {
	//int gray_number = gray;
	double untiy = (256.0 + 1) / (double)strlen(aclik_char);
	double gray_number = (gray - 127) * 2.0 + 127;

	//gray_number = (gray_number - 127) * 1.4 + 127;
		if (gray_number > 255){
			gray_number = 255;
		}
		if (gray_number < 0){
			gray_number = 0;
		}
		int index = gray_number / untiy;
		//cout << "index->" << index << endl;
		//cout << "untiy->" << untiy << endl;
		//cout << "gray_number->" << gray_number << endl;


		return aclik_char[index];
}
	
void PictureToChar::show_VideoToChar(char* path, int width, int height) {
	VideoCapture cap;
	cap.open(path);
	if (!cap.isOpened()) {
		cout << "can't open file" << endl;
		return;
	}
	Mat frame, frame_resize, frame_gray;
	while (true)
	{
		cap >> frame;
		if (frame.empty())	break;
		resize(frame, frame_resize, Size(width, height));
		cvtColor(frame_resize, frame_gray, COLOR_BGR2GRAY);
		String txt = "";

		int height1 = frame_gray.rows;
		int width1 = frame_gray.cols;

		for (int j = 0; j < height1; j++) {
			txt = "";
			for (int i = 0; i < width1; i++)
			{
				int pdata = frame_gray.ptr<uchar>(j)[i];
				txt += get_char(pdata);
			}
			cout << txt << endl;
			

		}

		//将光标移动到（0，0）处
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = 0;
		pos.Y = 0;
		SetConsoleCursorPosition(hConsoleOutput, pos);
		
	}
}

void PictureToChar::show_Over()
{
	VideoCapture a,b,c,d,e;
	a.open("C:\\Users\\29799\\Desktop\\codefrom1024\\c\\10.mp4");
	b.open("C:\\Users\\29799\\Desktop\\codefrom1024\\c\\11.mp4");
	c.open("C:\\Users\\29799\\Desktop\\codefrom1024\\c\\12.mp4");
	d.open("C:\\Users\\29799\\Desktop\\codefrom1024\\c\\13.mp4");
	e.open("C:\\Users\\29799\\Desktop\\codefrom1024\\c\\14.mp4");
	Mat frame1, frame2, frame3, frame4, frame5;
	a >> frame1;
	b >> frame2;
	c >> frame3;
	d >> frame4;
	e >> frame5;
	resize(frame1, frame1, Size(400, 300));
	resize(frame2, frame2, Size(400, 300));
	resize(frame3, frame3, Size(400, 300));
	resize(frame4, frame4, Size(400, 300));
	resize(frame5, frame5, Size(400, 300));
	imshow("no.1", frame1);
	imshow("no.2", frame2);
	imshow("no.3", frame3);
	imshow("no.4", frame4);
	imshow("no.5", frame5);
	moveWindow("no.1", 0, 0);
	moveWindow("no.2", 0, 490);
	moveWindow("no.3", 1130, 0);
	moveWindow("no.4", 1130, 490);
	moveWindow("no.5", 565, 245);

	while (1)
	{

		a >> frame1;
		b >> frame2;
		c >> frame3;
		d >> frame4;
		e >> frame5;
		resize(frame1, frame1, Size(400, 300));
		resize(frame2, frame2, Size(400, 300));
		resize(frame3, frame3, Size(400, 300));
		resize(frame4, frame4, Size(400, 300));
		resize(frame5, frame5, Size(400, 300));
		imshow("no.1", frame1);
		imshow("no.2", frame2);
		imshow("no.3", frame3);
		imshow("no.4", frame4);
		imshow("no.5", frame5);
		
		// y-max = 490 
		
		waitKey(1);

	}
}
void PictureToChar::show_PhotoToChar(char* path,int width,int hight) {
	char from[] = "1024节日创业编码作品------后端一班吕权峰";

	Mat frame = imread(path); 
	Mat frame_resize, frame_gray;
		resize(frame, frame_resize, Size(width, hight));
		cvtColor(frame_resize, frame_gray, COLOR_BGR2GRAY);
		String txt = "";
		int height1 = frame_gray.rows;
		int width1 = frame_gray.cols;
		for (int j = 0; j < height1; j++) {
			txt = "";
			for (int i = 0; i < width1; i++)
			{
				int pdata = frame_gray.ptr<uchar>(j)[i];
				txt += get_char(pdata);
				
			}
			cout << txt << endl;
			
		}
		for (int i = 0; i < width; i++) {
			if (i == (int)(((double)width / 2.0) - (double)strlen(aclik_char) / 2.0)) {
				i += strlen(aclik_char);
				for (char k : from)
				{
					cout << k;
					
				}
			}
			cout << "-";
		}
		cout << endl;

	
}







