#pragma once
#include <iostream>
using namespace std;

class Image {
public:
    Image();
    Image(const char* filename);
    Image(int width, int height, int nChannels);
    Image(const Image& image);
    ~Image();

    unsigned char* get_image_data(); 
    int get_m_width();
    int get_m_height();
    int get_m_nChannel(); 

private:
    int m_width;
    int m_height;

    int m_nChannel;

    int m_size;
    unsigned char* image_data;

};