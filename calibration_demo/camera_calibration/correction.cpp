#include <opencv2/calib3d.hpp>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

/**
 * @主函数
 */
int main( int argc, char** argv ) {

  /// 读取一副图片，不改变图片本身的颜色类型（该读取方式为DOS运行模式）
  Mat src = imread(argv[1], 1);
  Mat distortion = src.clone();
  Mat camera_matrix = Mat(3, 3, CV_32FC1);
  Mat distortion_coefficients;
  printf("read image\n");

  //导入相机内参和畸变系数矩阵
  FileStorage file_storage("../build/out_camera_data1.xml", FileStorage::READ);
  file_storage["camera_matrix"] >> camera_matrix;
  file_storage["distortion_coefficients"] >> distortion_coefficients;
  file_storage.release();

  //矫正
  undistort(src, distortion, camera_matrix, distortion_coefficients);

  imshow("img", src);
  imshow("undistort", distortion);
  imwrite("undistort.jpg", distortion);
  printf("save image\n");

  waitKey(0);
  return 0;
}
// ————————————————
// 版权声明：本文为CSDN博主「yuchiwang」的原创文章，遵循CC 4.0
// BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/u013498583/article/details/71404323