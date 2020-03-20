#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat lableMat;
	Mat statsMat;
	Mat centerMat;
	Mat dstMat;
	Mat outMat;
	int a = 0;
	Mat srcMat = imread("D:\\a\\clip.png", 0);
	threshold(srcMat, dstMat, 100, 255, THRESH_BINARY_INV);
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));		//¾ØÐÎ 9*9
	morphologyEx(dstMat, outMat, MORPH_ERODE, element);		//¸¯Ê´
	int nComp = cv::connectedComponentsWithStats(outMat,
		lableMat,
		statsMat,
		centerMat,
		8,
		CV_32S);
	for (int i = 1; i < nComp; i++)
	{
		if (statsMat.at<int>(i, 4) > 4000)
			a++;
	}
	cout << a << endl;
	imshow("erode", outMat);
	waitKey(0);
	return 0;
}