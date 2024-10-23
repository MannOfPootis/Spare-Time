from PIL import Image

# Load the image
image_path = 'Coloring buk/rak.jpeg'  # Replace with your image path
img = Image.open(image_path)

# Convert the image to RGB (to ensure it's in the right format)
img = img.convert('RGB')

# Load the pixel data
pixels = img.load()

# Get the image dimensions
width, height = img.size

# Loop through all pixels
for x in range(width):
    for y in range(height):
        r, g, b = pixels[x, y]
        bar=80

        # Check if the pixel is black (RGB all equal to 0)
        if not (r < bar and g < bar and b <bar):
            # Replace non-black pixels with white
            pixels[x, y] = (255, 255, 255)

# Save the modified image
img.save('output_image.jpg')
img.show()  # Optional: Display the image
