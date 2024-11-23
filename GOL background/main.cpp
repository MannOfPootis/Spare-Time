#include <cairo/cairo.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include <thread>

const std::string IMAGE_PATH = "/home/doominik/Downloads/image.psd(1).jpg";
const int width = 1920;
const int height = 1080;
const int margin =1 ;
const int size=5;
const int sizex=width*0.75/(margin*size);
const int sizey=height*0.75/(margin*size);
bool spacepl[sizex][sizey] = {{false}};
bool spaceTemppl[sizex][sizey] = {{true}};
bool (*space)[sizey] = spacepl;
bool (*spaceTemp)[sizey] = spaceTemppl;
void createImage(const std::string& filepath) {
    // Dimensions of the image


    // Get the current time
 //   std::time_t now = std::time(nullptr);
   // std::string timestamp = std::ctime(&now);

    // Create a Cairo surface and context
    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cairo_t* cr = cairo_create(surface);

    // Draw background
    cairo_set_source_rgb(cr, 1, 0.18, 0.20); // Dark gray
    cairo_paint(cr);
    cairo_set_source_rgb(cr,1,1,1);
    for(int i =0;i<sizex;i++){
           for(int j=0;j<sizey;j++){
            if(space[i][j]){
                cairo_rectangle(cr,0.05*width+(size+margin)*i,0.05*height+(size+margin)*j,size,size);

                cairo_fill(cr);

            }


           }
       }
    // Draw text



  //  cairo_move_to(cr, 100, 200);

    cairo_surface_write_to_png(surface, filepath.c_str());

    // Clean up
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}

void setBackground(const std::string& filepath) {
    // Use gsettings to set the background
    std::string command = "gsettings set org.gnome.desktop.background picture-uri 'file://" + filepath + "'";
    std::system(command.c_str());
}
void GOLplane()
{
    for(int i=0;i<sizex;i++){
        for(int j =0;j<sizey;j++){
            int box=0;
            for(int k=-1;k<=1;k++){
                for(int u=-1;u<=1;u++){
                    box+=(int)space[(i+k)%sizex][(j+u)%sizey];
                }
            }
            spaceTemp[i][j]= (box==3)||(box==4)&&(space[i][j]);
        }
    }

    std::swap(space, spaceTemp);
}



int main() {
    const int sleep_interval = 5; // Time interval in seconds
    int i =0;
    for(int i =0;i<sizex;i++){
        for(int j=0;j<sizey;j++){
            //if(space[i][j]){
            space[i][j]=(rand()%10)==0;

            //}


        }
    }
    while (i<10000) {
       // std::cout<<"next";
        createImage(IMAGE_PATH);      // Create a new image
        setBackground(IMAGE_PATH);   // Set it as the background
        GOLplane();

        std::this_thread::sleep_for(std::chrono::seconds(sleep_interval));
        i++;
    }

    return 0;
}
