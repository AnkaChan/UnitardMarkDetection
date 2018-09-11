#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"

int main(int argc, char ** argv) {
	std::string fileName = "corner1.png";
	cv::Mat img = cv::imread(fileName);
	cv::Mat imgG;
	cv::cvtColor(img, imgG, CV_RGB2GRAY);

	cv::imshow("Before Filter", imgG);
	cv::waitKey(0);

	cv::Mat imgFiltered;
	cv::bilateralFilter(imgG, imgFiltered, 10, 75, 75);

	cv::imshow("After Filter", imgFiltered);
	cv::waitKey(0);

	std::vector<cv::Point2f> corners;
	cv::goodFeaturesToTrack(imgFiltered, corners, 0, 0.01, 20, cv::Mat(), 3, true);

	for (const cv::Point2f & p : corners)
	{
		cv::circle(img, p, 3, cv::Scalar(0, 0, 255), -1);
	}

	cv::imshow("Corners", img);
	cv::waitKey(0);
}