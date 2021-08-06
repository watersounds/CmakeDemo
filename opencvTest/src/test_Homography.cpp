//单应矩阵完成图像对齐

#include <opencv2/core/async.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include <iostream>
 
 
using namespace std;
 
struct userData{
    cv::Mat im;
    vector<cv::Point2f> points;
};
 
 
void mouseHandler(int event, int x, int y, int flags, void* data_ptr){
    if(event == cv::EVENT_FLAG_LBUTTON)
    {
        userData *data = ((userData *) data_ptr);
        cv::circle(data->im, cv::Point(x,y), 3, cv::Scalar(0,0,255), 5, cv::LINE_AA);
        cv::imshow("Image", data->im);
 
        if(data->points.size() < 4)
        {
            data->points.push_back(cv::Point2f(x,y));
        }
    }
}
 
 
int main(int argc ,char** argv)
{
    userData data1,data2;
    cv::Mat im_src = cv::imread("1.jpg",1);
    cv::Mat im_dst = cv::imread("2.jpg",1);
 
    cv::Size dsize = cv::Size(im_src.cols*0.5, im_src.rows*0.5);
 
    cv::resize(im_src, im_src, dsize);
    cv::resize(im_dst, im_dst, dsize);
 
    data1.im = im_src;
    data2.im = im_dst;
 
    cout << "Click on the four corners of the book -- top left first and" << endl
         << "bottom left last -- and then hit ENTER" << endl;
 
    // 执行回调函数，通过鼠标点击，提取四个角点用于单应矩阵的计算
    cv::imshow("image_src", data1.im);
    cv::setMouseCallback("image_src", mouseHandler, &data1);
    cv::waitKey(0);
 
    cv::imshow("image_dst", data2.im);
    cv::setMouseCallback("image_dst", mouseHandler, &data2);
    cv::waitKey(0);
 
    // 通过人为的匹配上四个特征点，完成两个图像之间单应矩阵的计算
 
    cv::Mat H;
    H = cv::findHomography(data1.points, data2.points);
 
 
    cv::Mat outImage;
 
    // 通过单应矩阵H完成两个图像的对其
    cv::warpPerspective(im_src, outImage, H, im_dst.size());
 
    cv::imshow("Source image" ,im_src);
    cv::imshow("Destination Image", im_dst);
    cv::imshow("Warped Source Image", outImage);
    cv::waitKey(0);
 
    return 0;
}
// ————————————————
// 版权声明：本文为CSDN博主「ouyangzizhou」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/weixin_38213410/article/details/90054010