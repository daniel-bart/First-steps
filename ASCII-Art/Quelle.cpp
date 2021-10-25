#include <Magick++.h>
#include <iostream> 

using namespace std;
using namespace Magick;

int main(int argc, char** argv)
{
    InitializeMagick(*argv);
    Image image;
    try {
        image.read("E:/Projects/ASCII-Art/pineapple.jpg");
        Geometry newSize = Geometry(175, 115);
        image.resize(newSize);
        cout << "Successfully loaded image!" << endl;
        int x = image.columns();
        int y = image.rows();
        cout << "Image Size: " << x << " x " << y << endl;
        image.modifyImage();
        char pixel_matrix[4000][4000]; // Max. 4000*4000 Pixel
        int signs[] = {96,94,92,34,44,58,59,73,108,33,105,126,43,95,45,63,93,91,125,123,49,41,40,124,92,92,47,116,102,106,114,120,110,117,118,99,122,88,89,85,74,67,76,81,48,79,90,109,119,113,112,100,98,107,104,97,111,42,35,77,87,38,56,37,66,64,36,32};      cout << "Iterating through pixel brightness" << endl;
        for (int j = 0; j < y; j++) {
            cout << endl;
            for (int i = 0; i < x; i++) {

                Color c = image.pixelColor(i, j);
                int r = c.quantumRed() * 255 / QuantumRange;
                int g = c.quantumGreen() * 255 / QuantumRange;
                int b = c.quantumBlue() * 255 / QuantumRange;
                int brightness = ((r + g + b) / 3)/3.8;
                pixel_matrix[i][j] = char(signs[brightness]);
                cout << pixel_matrix[i][j]<< pixel_matrix[i][j];
                //cout <<"R: "<< r <<" G: " << g << " B: " << b << endl;
            }
        }

    }
    catch (Exception& error_)
    {
        cout << "Caught exception: " << error_.what() << endl;
        return 1;
    }
    
    return 0;
}