#include <Magick++.h>
#include <iostream> 
#include <fstream>
#include <filesystem>
#include <algorithm>


using namespace std;
using namespace Magick;

int bright(int a, int b, int c, int f) {
    int calc_bright;
    try {
        if (f == 1) {
            calc_bright = (a + b + c) / 3;
            return calc_bright;
        }
        else if (f == 2) {
            calc_bright = (max({ a, b, c }) + min({ a, b, c })) / 2;
            return calc_bright;
        }
        else if (f == 3) {
            calc_bright = (0.21 * a + 0.72 * b + 0.07 * c);
            return calc_bright;
        }
        else {
            throw invalid_argument("Choice out of range");
        }
    }
    catch (const invalid_argument& error) {
        cout << "Invalid Argument: " << error.what() << endl;
        exit(EXIT_FAILURE);
    }
};
int main(int argc, char** argv)
{
    InitializeMagick(*argv);
    Image image;
    try {
        int Choice;
        image.read("pineapple.jpg");
        Geometry newSize = Geometry(180, 160);
        image.resize(newSize);
        cout << "Successfully loaded image!" << endl;
        int x = image.columns();
        int y = image.rows();
        cout << "Image Size: " << x << " x " << y << endl;
        image.modifyImage();
        //char pixel_matrix[4000][4000]; // Max. 4000*4000 Pixel
        int signs[] = {96,94,92,34,44,58,59,73,108,33,105,126,43,95,45,63,93,91,125,123,49,41,40,124,92,92,47,116,102,106,114,120,110,117,118,99,122,88,89,85,74,67,76,81,48,79,90,109,119,113,112,100,98,107,104,97,111,42,35,77,87,38,56,37,66,64,36,32};      cout << "Iterating through pixel brightness" << endl;
        reverse(begin(signs), end(signs)); // Switching Contrast
        cout << "Choose type of brightness calculation: (1) average, (2) min_max, (3) luminosity." << endl;
        cin >> Choice;
        ofstream art("art.txt", ios_base::app);
        for (int j = 0; j < y; j++) {
            art << endl;
            for (int i = 0; i < x; i++) {

                Color c = image.pixelColor(i, j);
                int r = c.quantumRed() * 255 / QuantumRange;
                int g = c.quantumGreen() * 255 / QuantumRange;
                int b = c.quantumBlue() * 255 / QuantumRange;
                int brightness = bright(r,g,b,Choice)/3.8;
                //pixel_matrix[i][j] = char(signs[brightness]);
                art << char(signs[brightness]) << char(signs[brightness]) << char(signs[brightness]);
                //cout <<"R: "<< r <<" G: " << g << " B: " << b << endl;
            }
        }
        art.close();
    }
    catch (Exception& error_)
    {
        cout << "Caught exception: " << error_.what() << endl;
        return 1;
    }
    
    return 0;
}