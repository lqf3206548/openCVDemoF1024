#pragma once
#ifndef openCV_PictureTOChar
#define openCV_PictureTOChar
#define HAVE_STRUCT_TIMESPEC
class PictureToChar
{
public:
	PictureToChar();
	void show_PhotoToChar(char* path, int width, int hight);
	void show_VideoToChar(char* path, int width, int hight);
	void show_Over();

private:

				};



#endif // openCV_PictureTOChar
