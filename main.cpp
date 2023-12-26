#include "Image.h"
#include "Image_process.h"

#include "stb_image.h"
#include "stb_image_write.h"

using namespace std;

int main()
{
    Image image1 = Image("image_gauss.jpg");
    Image image2 = Image("image_uniform.jpg");
    Image_process image_process = Image_process();

    int filterSize = 3;
    image_process.remove_noise(filterSize, image1);
    image_process.remove_noise(filterSize, image2);

    stbi_write_jpg("image_gauss_processed.jpg", image1.get_m_width(), image1.get_m_height(), image1.get_m_nChannel(), image1.get_image_data(), 100);
    stbi_write_jpg("image_uniform_processed.jpg", image2.get_m_width(), image2.get_m_height(), image2.get_m_nChannel(), image2.get_image_data(), 100);

    return 0;
}