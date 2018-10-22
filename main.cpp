#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
        string filename;
        Bitmap image;
        int height;
        int width;

        if(argc!=2)
        {
                cout<<"Please specify one image file!\n";
        }
        else
        {
                
                filename = argv[1]; 
        }
        image.open(filename);

        if(image.isImage() != true)
        {
                "Image file must be a bitmap with a 24-bit color depth.\n";
        }
        else
        {
                
                vector <vector<Pixel>> imagePixels = image.toPixelMatrix();
                
                height = imagePixels.size();
                width = imagePixels[0].size();

                cout<<filename<< " is " << height << " pixels high and " << width << " pixels wide\n";
        }
        
        
  return 0;
}
