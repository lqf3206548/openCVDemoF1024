#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;
int smain()
{
    // ��ȡͼƬ��ʹ��ͼƬ�ľ���·�����ο��Լ���ͼ����Ŀ¼��
    Mat srcImg = imread("C:\\Users\\29799\\Pictures\\QQͼƬ20211019193838.png");
    if (srcImg.empty()) {
        cout << "could not load image..." << endl;
        return -1;
    }

    imshow("Test opencv setup", srcImg);
    // ��ʾ�Ҷ�ͼ
    Mat Gray;
    cvtColor(srcImg, Gray, 6);
    imshow("Gray", Gray);
    // �ȴ����ⰴ�����£�����Ӵ����ͼƬ��һ������
    waitKey(0);

    cout << "Hello,world." << endl;
    return 0;
}