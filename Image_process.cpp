#include "Image_process.h"

Image_process::Image_process()
{
}

void Image_process::remove_noise(int filterSize, Image& image)
{
        int halfFilterSize = filterSize / 2;

    unsigned char* tempImage = new unsigned char[image.get_m_width() * image.get_m_height() * image.get_m_nChannel()];
    cout << tempImage[10];

    for (int y = 0; y < image.get_m_width(); y++) {
        for (int x = 0; x < image.get_m_width(); x++) {
            for (int c = 0; c < image.get_m_nChannel(); c++) {
                unsigned char* pixelValues = new unsigned char[filterSize * filterSize];

                int index = 0;
                for (int j = -1 * halfFilterSize; j <= halfFilterSize; j++) {
                    for (int i = -1 * halfFilterSize; i <= halfFilterSize; i++) {
                        int posX = x + i;
                        int posY = y + j;

                        if (posX >= 0 && posX < image.get_m_width() && posY >= 0 && posY < image.get_m_height()) {
                            pixelValues[index] = image.get_image_data()[(posY * image.get_m_width() + posX) * image.get_m_nChannel() + c];
                        }
                        else {
                            pixelValues[index] = 0;
                        }

                        index++;
                    }
                }

                for (int i = 0; i < filterSize * filterSize - 1; i++) {
                    for (int j = 0; j < filterSize * filterSize - i - 1; j++) {
                        if (pixelValues[j] > pixelValues[j + 1]) {
                            swap(pixelValues[j], pixelValues[j + 1]);
                        }
                    }
                }

                tempImage[(y * image.get_m_width() + x) * image.get_m_nChannel() + c] = pixelValues[filterSize * filterSize / 2];

            }
        }
    }

    memcpy(image.get_image_data(), tempImage, image.get_m_width() * image.get_m_height() * image.get_m_nChannel());
}