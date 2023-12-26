#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "Image.h"

#include "stb_image.h"
#include "stb_image_write.h"

Image::Image()
{
}

Image::Image(const char* filename)
{
    image_data = stbi_load(filename, &m_width, &m_height, &m_nChannel, 0);
        if (!image_data) {
            std::cerr << "Failed to load the image." << std::endl;
            exit(1);
        }
}

Image::Image(int width, int height, int nChannels)
{
    m_width = width;
    m_height = height;
    m_nChannel = nChannels;
    m_size = width * height * nChannels;
    unsigned char* image_data = new unsigned char[m_width * m_height * m_nChannel];
}

Image::Image(const Image &image)
{
    m_width = image.m_width;
    m_height = image.m_height;
    m_nChannel = image.m_nChannel;
    m_size = m_width * m_height * m_nChannel;
    image_data = image.image_data;
}

Image::~Image()
{
    if (image_data) {
        stbi_image_free(image_data);
    }
}

unsigned char * Image::get_image_data()
{
    return image_data;
}
int Image::get_m_width()
{
    return m_width;
}
int Image::get_m_height()
{
    return m_height;
}
int Image::get_m_nChannel()
{
    return m_nChannel;
}


