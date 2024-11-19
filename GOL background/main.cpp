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
void createImage(const std::string& filepath) {
    // Dimensions of the image


    // Get the current time
    std::time_t now = std::time(nullptr);
    std::string timestamp = std::ctime(&now);

    // Create a Cairo surface and context
    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cairo_t* cr = cairo_create(surface);

    // Draw background
    cairo_set_source_rgb(cr, 1, 0.18, 0.20); // Dark gray
    cairo_paint(cr);

    // Draw text
    cairo_set_source_rgb(cr,1,1,1);

    cairo_rectangle(cr,100,100,10,10);
    cairo_fill(cr);
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

int main() {
    const int sleep_interval = 1; // Time interval in seconds
    int i =0;
    while (i<10) {
        createImage(IMAGE_PATH);      // Create a new image
        setBackground(IMAGE_PATH);   // Set it as the background
        std::this_thread::sleep_for(std::chrono::seconds(sleep_interval));
        i++;
    }

    return 0;
}
