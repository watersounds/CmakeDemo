#include "nanodet.h"


bool NanoDet::hasGPU = false;
NanoDet::NanoDet(const char* param, const char* bin, bool useGPU)
{
    this->Net = new ncnn::Net();
    // opt 
#if NCNN_VULKAN
    this->hasGPU = ncnn::get_gpu_count() > 0;
#endif
    this->Net->opt.use_vulkan_compute = this->hasGPU && useGPU;
    this->Net->opt.use_fp16_arithmetic = true;
    this->Net->load_param(param);
    this->Net->load_model(bin);
}

NanoDet::~NanoDet()
{
    delete this->Net;
}

void NanoDet::preprocess(cv::Mat& image, ncnn::Mat& in, int target_size)
{
    int width = image.cols;
    int height = image.rows;

    


}