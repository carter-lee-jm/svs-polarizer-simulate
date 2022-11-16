#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"
int main()
{
	//read image
	cv::Mat mat_arr[8];
	mat_arr[0] = cv::imread("g.png", cv::IMREAD_GRAYSCALE);
	mat_arr[1] = cv::imread("k.png", cv::IMREAD_GRAYSCALE);
	mat_arr[2] = cv::imread("r.png", cv::IMREAD_GRAYSCALE);
	mat_arr[3] = cv::imread("n.png", cv::IMREAD_GRAYSCALE);

	cv::Mat big(mat_arr[0].rows*2, mat_arr[0].cols * 2,CV_8U);

	int sizeY= mat_arr[0].rows * 2;
	int sizeX= mat_arr[0].cols * 2;
	int k = 0;
	uint8_t* ImageData_I0 = mat_arr[0].data;
	uint8_t* ImageData_I90 = mat_arr[1].data;
	uint8_t* ImageData_I45 = mat_arr[2].data;
	uint8_t* ImageData_I135 = mat_arr[3].data;
	uint8_t* sr_data = big.data;
	for (unsigned int y = 0; y < sizeY; y += 2)
	{
		for (unsigned int x = 0; x < sizeX; x += 2)
		{

			sr_data[1 + sizeX] = ImageData_I0[k];
			sr_data[0] = ImageData_I90[k];
			sr_data[1] = ImageData_I45[k];
			sr_data[sizeX] = ImageData_I135[k];
			sr_data += 2;
			k++;
		}
		sr_data += sizeX;
	}

	cv::imshow("win", big);
	cv::waitKey(0);

	mat_arr[4] =cv::Mat(mat_arr[0].rows, mat_arr[0].cols, CV_8U);
	mat_arr[5] = cv::Mat(mat_arr[0].rows, mat_arr[0].cols, CV_8U);
	mat_arr[6] = cv::Mat(mat_arr[0].rows, mat_arr[0].cols, CV_8U);
	mat_arr[7] = cv::Mat(mat_arr[0].rows, mat_arr[0].cols, CV_8U);

	cv::imshow("4", mat_arr[4]);
	cv::imshow("5", mat_arr[5]);
	cv::imshow("6", mat_arr[6]);
	cv::imshow("7", mat_arr[7]);
	cv::waitKey(0);

	ImageData_I0 = mat_arr[4].data;
	ImageData_I90 = mat_arr[5].data;
	ImageData_I45 = mat_arr[6].data;
	ImageData_I135 = mat_arr[7].data;
	sr_data = big.data;

	k = 0;
	for (unsigned int y = 0; y < sizeY; y += 2)
	{
		for (unsigned int x = 0; x < sizeX; x += 2)
		{

			ImageData_I0[k] = sr_data[1 + sizeX];
			ImageData_I90[k] = sr_data[0];
			ImageData_I45[k] = sr_data[1];
			ImageData_I135[k] = sr_data[sizeX];
			sr_data += 2;
			k++;
		}
		sr_data += sizeX;
	}

	cv::imshow("4", mat_arr[4]);
	cv::imshow("5", mat_arr[5]);
	cv::imshow("6", mat_arr[6]);
	cv::imshow("7", mat_arr[7]);
	cv::waitKey(0);

}