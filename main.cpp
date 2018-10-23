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
        Pixel color;
        vector <vector<Pixel>> imagePixels;

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
                
                imagePixels = image.toPixelMatrix();
                
                height = imagePixels.size();
                width = imagePixels[0].size();

                cout<<filename<< " is " << height << " pixels high and " << width << " pixels wide\n";
        }
        for(int columns = 0; columns < imagePixels.size(); columns++)
        {
                for(int rows = 0; rows < imagePixels[0].size(); rows++)
                {
                        color = imagePixels[rows][columns];
                        color.green=0;
                        color.blue=0;
                        imagePixels[rows][columns] = color;
                       // image.fromPixelMatrix(imagePixels);
                       // image.save("redness.bmp");
                }
        }
       
        image.fromPixelMatrix( imagePixels );
                image.save("redness.bmp");
        
        
  return 0;
}
