#include "Image.h"

class Image_process {
public:
    Image_process();
    void remove_noise(int filterSize, Image& image);
};