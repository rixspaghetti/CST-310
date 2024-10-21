#include <GL/glut.h>
#include <cstdlib>    // For exit function
#include <cmath>      // For mathematical functions
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"  // Include the stb_image library for texture loading


#define NUM_TEXTURES 3  // Number of textures you want to use

GLuint textureIDs[NUM_TEXTURES]; // Array to hold texture IDs

// Function to load a texture from an image file
void loadTexture(const char* filename, int textureIndex) {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data) {
        glGenTextures(1, &textureIDs[textureIndex]); // Generate a texture ID
        glBindTexture(GL_TEXTURE_2D, textureIDs[textureIndex]); // Bind the texture

        // Set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Load texture data into OpenGL
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D); // Generate Mipmaps for the texture

        stbi_image_free(data); // Free image memory after loading
    } else {
        printf("Failed to load texture: %s\n", filename);
    }
}



void checkOpenGLErrors(const char* context) {
    GLenum err;
    bool hasError = false;
    while((err = glGetError()) != GL_NO_ERROR) {  // Retrieve and clear errors
        std::cerr << "OpenGL error in " << context << ": " << err << std::endl;
        hasError = true;
    }
    if(hasError) {
        // Optionally, handle the error as needed
        // exit(-1);
    }
}

void convertRGBA(float& r, float& g, float& b, unsigned char R, unsigned char G, unsigned char B_val, unsigned char A) {

    r = R / 255.0f;      // Normalize red component
    g = G / 255.0f;      // Normalize green component
    b = B_val / 255.0f;  // Normalize blue component
    // Alpha is not used in this example, but can be handled similarly if needed
}

void drawLight(float cx, float cy, float rx, float ry, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);

    // Center of the oval
    glVertex2f(cx, cy); // This is the center vertex of the triangle fan

    for (int i = 0; i <= num_segments; i++) {  // <= to close the loop
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // current angle

        // Calculate x and y using different radii for x and y axes
        float x = rx * cosf(theta); // Horizontal radius (oval width)
        float y = ry * sinf(theta); // Vertical radius (oval height)

        // Vertex along the oval's circumference
        glVertex2f(x + cx, y + cy);
    }

    glEnd();
}

// Function to draw TV
void drawTV() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Blue color for the polygon rectangle
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(2110.0f, 2220.0f);  // Bottom-left vertex
        glVertex2f(3510.0f, 2220.0f);  // Bottom-right vertex
        glVertex2f(3537.0f, 1360.0f);  // Top-right vertex
        glVertex2f(2065.0f, 1360.0f);  // Top-left vertex
    glEnd();
}

// left chair
void leftChair()  {

                // back cushion //
glColor3f(0.0f, 1.0f, 0.0f);  // orange
glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1750.0f, 3490.0f);  // Bottom-left vertex
        glVertex2f(2500.0f, 3490.0f);  // Bottom-right vertex
        glVertex2f(2500.0f, 2850.0f);  // Top-right vertex
        glVertex2f(1725.0f, 2850.0f);  // Top-left vertex
    glEnd();
// ------------------------------------------------------------ //
 
// ------------------------------------------------------------ //
                // left side of chair //
    glColor3f(1.0f, 0.65f, 0.0f);  // orange
    // lower
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1175.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(1400.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(1400.0f, 3400.0f);  // Top-right vertex
        glVertex2f(1200.0f, 3400.0f);  // Top-left vertex
    glEnd();
    // upper
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1175.0f, 3400.0f);  // Bottom-left vertex
        glVertex2f(1400.0f, 3400.0f);  // Bottom-right vertex
        glVertex2f(1750.0f, 2975.0f);  // Top-right vertex
        glVertex2f(1610.0f, 2975.0f);  // Top-left vertex
    glEnd();
    // side
    glColor3f(0.0f, 0.0f, 255.0f);  // orange
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1385.0f, 3830.0f);  // Bottom-left vertex
        glVertex2f(1750.0f, 3490.0f);  // Bottom-right vertex
        glVertex2f(1750.0f, 2975.0f);  // Top-right vertex
        glVertex2f(1385.0f, 3400.0f);  // Top-left vertex
    glEnd();

    // --------------------------------------------------------- //

                    // right side of chair //
    // lower
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2300.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(2500.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(2500.0f, 3400.0f);  // Top-right vertex
        glVertex2f(2275.0f, 3400.0f);  // Top-left vertex
    glEnd();
    // upper
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2275.0f, 3395.0f);  // Bottom-left vertex
        glVertex2f(2500.0f, 3395.0f);  // Bottom-right vertex
        glVertex2f(2655.0f, 2950.0f);  // Top-right vertex
        glVertex2f(2455.0f, 2950.0f);  // Top-left vertex
    glEnd();
    // side
    glColor3f(1.0f, 1.f, 0.0f);  // yellow
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2500.0f, 4300.0f);  // Bottom-left vertex
        glVertex2f(2655.0f, 3650.0f);  // Bottom-right vertex
        glVertex2f(2655.0f, 2950.0f);  // Top-right vertex
        glVertex2f(2500.0f, 3395.0f);  // Top-left vertex
    glEnd();

    // --------------------------------------------------------- //

                        // butt cushion //
    glColor3f(0.0f, 1.5f, 0.0f);  // yellow
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1375.0f, 3860.0f);  // Bottom-left vertex
        glVertex2f(2280.0f, 3860.0f);  // Bottom-right vertex
        glVertex2f(2280.0f, 3490.0f);  // Top-right vertex
        glVertex2f(1780.0f, 3490.0f);  // Top-left vertex
    glEnd();
 
 // --------------------------------------------------------- //
                        // foot rest // 

    glColor3f(1.0f, 1.f, 0.0f);  // yellow                   
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1400.0f, 4150.0f);  // Bottom-left vertex
        glVertex2f(2280.0f, 4150.0f);  // Bottom-right vertex
        glVertex2f(2280.0f, 3810.0f);  // Top-right vertex
        glVertex2f(1400.0f, 3810.0f);  // Top-left vertex
    glEnd();  

   
}
void rightChair2() {
    
                // back cushion //
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3200.0f, 3520.0f);  // Bottom-left vertex
        glVertex2f(3955.0f, 3600.0f);  // Bottom-right vertex
        glVertex2f(4000.0f, 2950.0f);  // Top-right vertex
        glVertex2f(3175.0f, 2900.0f);  // Top-left vertex
    glEnd();
    // shadow
    glColor3f((198.0/255.0f) * 0.9f, (108.0/255.0f) * 0.9f, (71.0/255.0f) * 0.9f);
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3200.0f, 3520.0f);  // Bottom-left vertex
        glVertex2f(3555.0f, 3600.0f);  // Bottom-right vertex
        glVertex2f(3250.0f, 3045.0f);  // Top-right vertex
        glVertex2f(3175.0f, 3000.0f);  // Top-left vertex
    glEnd();
// ------------------------------------------------------------ //
 
// ------------------------------------------------------------ //
                // left side of chair //
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange
    // lower
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2845.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(3010.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(3010.0f, 3460.0f);  // Top-right vertex
        glVertex2f(2830.0f, 3440.0f);  // Top-left vertex
    glEnd();
    // upper
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2830.0f, 3445.0f);  // Bottom-left vertex
        glVertex2f(3010.0f, 3465.0f);  // Bottom-right vertex
        glVertex2f(3190.0f, 3015.0f);  // Top-right vertex
        glVertex2f(3075.0f, 2995.0f);  // Top-left vertex
    glEnd();
    // side
    glColor3f((198.0/255.0f) * 0.9f, (108.0/255.0f) * 0.9f, (71.0/255.0f) * 0.9f);  // orange
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3015.0f, 3880.0f);  // Bottom-left vertex
        glVertex2f(3200.0f, 3520.0f);  // Bottom-right vertex
        glVertex2f(3190.0f, 3005.0f);  // Top-right vertex
        glVertex2f(3010.0f, 3460.0f);  // Top-left vertex
    glEnd();

    // --------------------------------------------------------- //

                    // right side of chair //
    // lower
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3950.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(4220.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(4265.0f, 3600.0f);  // Top-right vertex
        glVertex2f(4055.0f, 3600.0f);  // Top-left vertex
    glEnd();
    // upper
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(4055.0f, 3600.0f);  // Bottom-left vertex
        glVertex2f(4265.0f, 3600.0f);  // Bottom-right vertex
        glVertex2f(4155.0f, 3075.0f);  // Top-right vertex
        glVertex2f(3995.0f, 3050.0f);  // Top-left vertex
    glEnd();

    // --------------------------------------------------------- //

                        // butt cushion //
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3020.0f, 3880.0f);  // Bottom-left vertex
        glVertex2f(4020.0f, 4030.0f);  // Bottom-right vertex
        glVertex2f(3955.0f, 3600.0f);  // Top-right vertex
        glVertex2f(3200.0f, 3520.0f);  // Top-left vertex
    glEnd();

    // shadows
    glColor3f((198.0/255.0f) * 0.9f, (108.0/255.0f) * 0.9f, (71.0/255.0f) * 0.9f);
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3770.0f, 3910.0f);  // Bottom-left vertex
        glVertex2f(4020.0f, 4030.0f);  // Bottom-right vertex
        glVertex2f(3955.0f, 3620.0f);  // Top-right vertex
        glVertex2f(3700.0f, 3600.0f);  // Top-left vertex
    glEnd();

 // --------------------------------------------------------- //
                        // foot rest // 

    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange                 
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3020.0f, 4170.0f);  // Bottom-left vertex
        glVertex2f(4010.0f, 4350.0f);  // Bottom-right vertex
        glVertex2f(4020.0f, 4030.0f);  // Top-right vertex
        glVertex2f(3020.0f, 3880.0f);  // Top-left vertex
    glEnd();  

// --------------------------------------------------------- //
                        // Inside right arm rest // 
    
    glColor3f((198.0/255.0f) * 0.9f, (108.0/255.0f) * 0.9f, (71.0/255.0f) * 0.9f);  // orange                 
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3956.0f, 3615.0f);  // Bottom-left vertex
        glVertex2f(4025.0f, 4030.0f);  // Bottom-right vertex
        glVertex2f(4055.0f, 3600.0f);  // Top-right vertex
        glVertex2f(3998.0f, 3040.0f);  // Top-left vertex

    glEnd();  
    
    // right side lines
    glLineWidth(2.0f);  // Set line width
    glBegin(GL_LINES);
    glColor3f((198.0/255.0f) * 0.80f, (108.0/255.0f) * 0.80f, (71.0/255.0f) * 0.80f);
        
        glVertex2f(3998.0, 3040.0);
        glVertex2f(3956.0, 3615.0);

        glVertex2f(3955.0, 3600.0);
        glVertex2f(4020.0, 4030.0);

        glVertex2f(3200.0, 3520.0);
        glVertex2f(3955.0, 3600.0);

        glVertex2f(3020.0, 3880.0);
        glVertex2f(3210.0, 3520.0);

        glVertex2f(3210.0, 3520.0);
        glVertex2f(3190.0, 3005.0);

        glVertex2f(4020.0, 4030.0);
        glVertex2f(4010.0, 4350.0);

        glVertex2f(3020.0, 4170.0);
        glVertex2f(3020.0, 3880.0);



    glEnd();
    
}

void leftChair2()  {

                // back cushion //
glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange
glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1750.0f, 3490.0f);  // Bottom-left vertex
        glVertex2f(2500.0f, 3490.0f);  // Bottom-right vertex
        glVertex2f(2500.0f, 2850.0f);  // Top-right vertex
        glVertex2f(1725.0f, 2850.0f);  // Top-left vertex
    glEnd();
// shadow
glColor3f((198.0/255.0f) * 0.9f, (108.0/255.0f) * 0.9f, (71.0/255.0f) * 0.9f);
glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1750.0f, 3490.0f);  // Bottom-left vertex
        glVertex2f(1940.0f, 3490.0f);  // Bottom-right vertex
        glVertex2f(1750.0f, 3000.0f);  // Top-right vertex
        glVertex2f(1725.0f, 3000.0f);  // Top-left vertex
    glEnd();
 
// ------------------------------------------------------------ //
                // left side of chair //
    // lower
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1200.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(1390.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(1390.0f, 3400.0f);  // Top-right vertex
        glVertex2f(1195.0f, 3400.0f);  // Top-left vertex
    glEnd();
    // upper
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1175.0f, 3400.0f);  // Bottom-left vertex
        glVertex2f(1400.0f, 3400.0f);  // Bottom-right vertex
        glVertex2f(1750.0f, 2970.0f);  // Top-right vertex
        glVertex2f(1610.0f, 2975.0f);  // Top-left vertex
    glEnd();
    // side
    glColor3f((198.0/255.0f) * 0.9f, (108.0/255.0f) * 0.9f, (71.0/255.0f) * 0.9f);
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1385.0f, 3830.0f);  // Bottom-left vertex
        glVertex2f(1750.0f, 3500.0f);  // Bottom-right vertex
        glVertex2f(1750.0f, 2975.0f);  // Top-right vertex
        glVertex2f(1385.0f, 3400.0f);  // Top-left vertex
    glEnd();

    // --------------------------------------------------------- //

                    // right side of chair //
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange
    // lower
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2290.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(2500.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(2500.0f, 3400.0f);  // Top-right vertex
        glVertex2f(2275.0f, 3400.0f);  // Top-left vertex
    glEnd();
    // upper
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2275.0f, 3395.0f);  // Bottom-left vertex
        glVertex2f(2500.0f, 3395.0f);  // Bottom-right vertex
        glVertex2f(2655.0f, 2950.0f);  // Top-right vertex
        glVertex2f(2455.0f, 2950.0f);  // Top-left vertex
    glEnd();
    // side
    glColor3f((198.0/255.0f) * 0.95f, (108.0/255.0f) * 0.95f, (71.0/255.0f) * 0.95f);
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2500.0f, 4300.0f);  // Bottom-left vertex
        glVertex2f(2655.0f, 3650.0f);  // Bottom-right vertex
        glVertex2f(2655.0f, 2950.0f);  // Top-right vertex
        glVertex2f(2500.0f, 3395.0f);  // Top-left vertex
    glEnd();

    // shadow for side
    glColor3f((198.0/255.0f) * 0.920f, (108.0/255.0f) * 0.920f, (71.0/255.0f) * 0.920f);
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2500.0f, 4300.0f);  // Bottom-left vertex
        glVertex2f(2655.0f, 3650.0f);  // Bottom-right vertex
        glVertex2f(2655.0f, 3200.0f);  // Top-right vertex
        glVertex2f(2500.0f, 3645.0f);  // Top-left vertex
    glEnd();

    // --------------------------------------------------------- //

                        // butt cushion //
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1375.0f, 3860.0f);  // Bottom-left vertex
        glVertex2f(2280.0f, 3860.0f);  // Bottom-right vertex
        glVertex2f(2280.0f, 3490.0f);  // Top-right vertex
        glVertex2f(1760.0f, 3490.0f);  // Top-left vertex
    glEnd();
    // shadow
    glColor3f((198.0/255.0f) * 0.9f, (108.0/255.0f) * 0.9f, (71.0/255.0f) * 0.9f);
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1370.0f, 3850.0f);  // Bottom-left vertex
        glVertex2f(1640.0f, 3850.0f);  // Bottom-right vertex
        glVertex2f(1940.0f, 3490.0f);  // Top-right vertex
        glVertex2f(1760.0f, 3490.0f);  // Top-left vertex
    glEnd();
 
 // --------------------------------------------------------- //
                        // foot rest // 
    glColor3f(198.0/255.0f, 108.0/255.0f, 71.0/255.0f);  // orange               
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1400.0f, 4150.0f);  // Bottom-left vertex
        glVertex2f(2280.0f, 4150.0f);  // Bottom-right vertex
        glVertex2f(2280.0f, 3850.0f);  // Top-right vertex
        glVertex2f(1400.0f, 3850.0f);  // Top-left vertex
    glEnd(); 
    // black space under the foot rest
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(1390.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(2280.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(2280.0f, 4150.0f);  // Top-right vertex
        glVertex2f(1390.0f, 4150.0f);  // Top-left vertex
    glEnd();

    // left chair - left side - side
    glLineWidth(2.0f);  // Set line width
    glColor3f((198.0/255.0f) * 0.80f, (108.0/255.0f) * 0.80f, (71.0/255.0f) * 0.80f);
    glBegin(GL_LINES);
        // l-/r+       u-/d+
    glVertex2f(1390.0, 3850.0);
    glVertex2f(1750.0, 3500.0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0f);  // Set line width
    glVertex2f(1740.0, 2975.0);
    glVertex2f(1740.0, 3500.0);

    glVertex2f(1740.0, 3500.0);
    glVertex2f(2275.0, 3500.0);

    glVertex2f(1395.0, 3850.0);
    glVertex2f(1395.0, 4150.0);

    glVertex2f(2275.0, 3850.0);
    glVertex2f(2275.0, 4150.0);

    glEnd();   

}
// right chair
void rightChair() {

                // back cushion //
glColor3f(0.0f, 1.0f, 0.0f);  // orange
glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3200.0f, 3520.0f);  // Bottom-left vertex
        glVertex2f(3955.0f, 3600.0f);  // Bottom-right vertex
        glVertex2f(4000.0f, 2950.0f);  // Top-right vertex
        glVertex2f(3175.0f, 2900.0f);  // Top-left vertex
    glEnd();
// ------------------------------------------------------------ //
 
// ------------------------------------------------------------ //
                // left side of chair //
    glColor3f(1.0f, 0.65f, 0.0f);  // orange
    // lower
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2845.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(3010.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(3010.0f, 3460.0f);  // Top-right vertex
        glVertex2f(2830.0f, 3440.0f);  // Top-left vertex
    glEnd();
    // upper
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(2830.0f, 3440.0f);  // Bottom-left vertex
        glVertex2f(3010.0f, 3460.0f);  // Bottom-right vertex
        glVertex2f(3185.0f, 3020.0f);  // Top-right vertex
        glVertex2f(3075.0f, 2975.0f);  // Top-left vertex
    glEnd();
    // side
    glColor3f(0.0f, 0.0f, 255.0f);  // orange
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3020.0f, 3880.0f);  // Bottom-left vertex
        glVertex2f(3190.0f, 3495.0f);  // Bottom-right vertex
        glVertex2f(3190.0f, 3005.0f);  // Top-right vertex
        glVertex2f(3010.0f, 3460.0f);  // Top-left vertex
    glEnd();

    // --------------------------------------------------------- //

                    // right side of chair //
    // lower
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3950.0f, 5000.0f);  // Bottom-left vertex
        glVertex2f(4220.0f, 5000.0f);  // Bottom-right vertex
        glVertex2f(4265.0f, 3600.0f);  // Top-right vertex
        glVertex2f(4055.0f, 3600.0f);  // Top-left vertex
    glEnd();
    // upper
    glColor3f(0.0f, 1.5f, 0.0f);  // green
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(4055.0f, 3600.0f);  // Bottom-left vertex
        glVertex2f(4265.0f, 3600.0f);  // Bottom-right vertex
        glVertex2f(4155.0f, 3075.0f);  // Top-right vertex
        glVertex2f(4000.0f, 3050.0f);  // Top-left vertex
    glEnd();

    // --------------------------------------------------------- //

                        // butt cushion //
    glColor3f(0.0f, 1.5f, 0.0f);  // yellow
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3020.0f, 3880.0f);  // Bottom-left vertex
        glVertex2f(4020.0f, 4030.0f);  // Bottom-right vertex
        glVertex2f(3955.0f, 3600.0f);  // Top-right vertex
        glVertex2f(3200.0f, 3520.0f);  // Top-left vertex
    glEnd();
 
 // --------------------------------------------------------- //
                        // foot rest // 

    glColor3f(1.0f, 1.f, 0.0f);  // yellow                   
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3020.0f, 4170.0f);  // Bottom-left vertex
        glVertex2f(4010.0f, 4350.0f);  // Bottom-right vertex
        glVertex2f(4020.0f, 4030.0f);  // Top-right vertex
        glVertex2f(3020.0f, 3880.0f);  // Top-left vertex
    glEnd();  

// --------------------------------------------------------- //
                        // Inside right arm rest // 
    
    glColor3f(1.0f, 1.0f, 0.0f);  // yellow                   
    glBegin(GL_POLYGON);  // Start drawing the polygon
                // l-/r+       u-/d+
        glVertex2f(3956.0f, 3615.0f);  // Bottom-left vertex
        glVertex2f(4020.0f, 4030.0f);  // Bottom-right vertex
        glVertex2f(4055.0f, 3600.0f);  // Top-right vertex
        glVertex2f(3998.0f, 3040.0f);  // Top-left vertex
        
    glEnd();  
   
}
void drawWall() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIDs[4]);  // Floor texture ID

    glDisable(GL_DEPTH_TEST);  // Disable depth testing for 2D overlay

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);  // Use white to display texture as-is

    // Scale factors to fit the window size (750x500)
    float scaleX = 750.0f / 5484.0f;
    float scaleY = 500.0f / 4279.0f;

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 4279.0f );   // Top-left
        glTexCoord2f(1.0f, 1.0f); glVertex2f(5484.0f , 4279.0f );  // Top-right
        glTexCoord2f(1.0f, 0.0f); glVertex2f(5484.0f , 0.0f);   // Bottom-right
        glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);  // Bottom-left
    glEnd();

    glEnable(GL_DEPTH_TEST);  // Re-enable depth testing

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void patchWall()
{
    glEnable(GL_TEXTURE_2D);
    // Set the color to white to avoid altering the texture color
    glColor3f(1.0f, 1.0f, 1.0f);  // White color

    // Bind the texture you want to use
    glBindTexture(GL_TEXTURE_2D, textureIDs[4]); // Assuming textureIDs[0] is your desired texture
    glBegin(GL_POLYGON);
        glVertex2f(4257.0f, 3676.0f);
        glVertex2f(4435.0f, 3682.0f);
        glVertex2f(4435.0f, 3150.0f);
        glVertex2f(4257.0f, 3150.0f);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}


// right wall socket
void rightWallSocket() {
    /*glColor3f(1.0f, 0.0f, 0.0f);  // red color
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(4500.0f, 3380.0f);  // Bottom-left vertex
        glVertex2f(4600.0f, 3400.0f);  // Bottom-right vertex
        glVertex2f(4620.0f, 3200.0f);  // Top-right vertex
        glVertex2f(4520.0f, 3180.0f);  // Top-left vertex
    glEnd();*/

    // Set the color to white to avoid altering the texture color
    glColor3f(183/255.0f, 173/255.0f, 171/255.0f);  // White color

    // Bind the texture you want to use
    //glBindTexture(GL_TEXTURE_2D, textureIDs[1]); // Assuming textureIDs[0] is your desired texture


    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(4500.0f, 3380.0f);  // Bottom-left vertex
        glVertex2f(4600.0f, 3400.0f);  // Bottom-right vertex
        glVertex2f(4620.0f, 3200.0f);  // Top-right vertex
        glVertex2f(4520.0f, 3180.0f);  // Top-left vertex
    glEnd();

    glColor3f(0,0,0);  // Set color to brown

    // 9.5 thickness
    glLineWidth(0.5f);  // Set line width

    glBegin(GL_LINES);
    //socket plug top
    glVertex2f(4562, 3236);glVertex2f(4557,3256);
    glVertex2f(4579, 3239);glVertex2f(4574, 3258);
    glVertex2f(4557, 3262);glVertex2f(4574, 3272);

    //socket plug bottom
    glVertex2f(4557, 3296);glVertex2f(4552,3326);
    glVertex2f(4574, 3299);glVertex2f(4569, 3328);
    glVertex2f(4552, 3332);glVertex2f(4569, 3339);
    //glVertex2f();glVertex2f();

    glEnd();



    // Disable texturing after drawing if it's not needed elsewhere
    //glBindTexture(GL_TEXTURE_2D, 0);

}

// floor
void drawFloor() {
    glEnable(GL_TEXTURE_2D);

    // black  column
    glColor3f(0.0f, 0.0f, 0.0f);
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(5484, 3720); glVertex2f(5484, 3944);
        glVertex2f(5484, 3944); glVertex2f(1157, 3780);
        glVertex2f(1157, 3780); glVertex2f(1149, 3581);
        glVertex2f(1149, 3581); glVertex2f(5484, 3720);
    glEnd();

    //grey floor
    /*glColor3f(0.5f, 0.5f, 0.5f);
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0, 4279); glVertex2f(0, 3979);
        glVertex2f(0, 3979); glVertex2f(371, 3667);
        glVertex2f(371, 3667); glVertex2f(1157, 3780);
        glVertex2f(1157, 3780); glVertex2f(5484, 3944);
        glVertex2f(5484, 3944); glVertex2f(5484, 4279);
        glVertex2f(5484, 4279); glVertex2f(0, 4279);

    glEnd();*/

    //glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glColor3f(0.5f, 0.5f, 0.5f); // Set color to gray

    glBindTexture(GL_TEXTURE_2D, textureIDs[0]); // Bind the first texture

    // Draw the polygon with the texture
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(0, 4279);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(0, 3979);
        glTexCoord2f(0.5f, 0.0f); glVertex2f(371, 3667);
        glTexCoord2f(0.5f, 1.0f); glVertex2f(1157, 3780);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(5484, 3944);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(5484, 4279);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture

}

void drawHorizontalLines() {
    // Define the points for the quadrilateral
    float topLeftX = 1359, topLeftY = 164;
    float bottomLeftX = 1752, bottomLeftY = 483;
    float topRightX = 333, topRightY = 213;
    float bottomRightX = 936, bottomRightY = 520;

    // Number of lines
    int numLines = 10;

    // Interpolation for each step
    for (int i = 0; i <= numLines; i++) {
        // Interpolation ratio
        float t = (float)i / numLines;

        // Interpolate left side (topLeft to bottomLeft)
        float leftX = topLeftX + t * (bottomLeftX - topLeftX);
        float leftY = topLeftY + t * (bottomLeftY - topLeftY);

        // Interpolate right side (topRight to bottomRight)
        float rightX = topRightX + t * (bottomRightX - topRightX);
        float rightY = topRightY + t * (bottomRightY - topRightY);

        // Draw the horizontal line
        glBegin(GL_LINES);
        glVertex2f(leftX, leftY);
        glVertex2f(rightX, rightY);
        glEnd();
    }
}



// ceiling vent
void drawCeilingVent() {
    //  whitish color)
    glColor3f(155.0/255.0f, 135/255.0f, 126/255.0f);
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(333, 213); glVertex2f(1359, 164);
        glVertex2f(1359, 164); glVertex2f(1752, 483);
        glVertex2f(1752, 483); glVertex2f(936, 520);
        glVertex2f(936, 520); glVertex2f(333, 213);

    glEnd();


    glColor3f(090.0/255.0f, 80.0/255.0f, 79.0/255.0f);
    glLineWidth(0.05f);  // Set line width

    // Draw the horizontal lines
    drawHorizontalLines();

    glColor3f(155.0/255.0f, 135/255.0f, 126/255.0f);

    //set eh color to white
    //glColor3f(1.0f, 1.0f, 1.0f);  // White color

    glLineWidth(9.5f);  // Set line width

    // drw teh border
    glBegin(GL_LINES);

    glVertex2f(333, 213); glVertex2f(1359, 164);
    glVertex2f(1359, 164); glVertex2f(1752, 483);
    glVertex2f(1752, 483); glVertex2f(936, 520);
    glVertex2f(936, 520); glVertex2f(333, 213);

    glEnd();


}


//  Ceiling
void drawCeiling() {
    //  color RGB (129,60,48)
    glColor3f(129.0 / 255.0, 60.0 / 255.0, 48.0 / 255.0);
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0, 603); glVertex2f(247, 697);
        glVertex2f(247, 697); glVertex2f(5484, 508);
        glVertex2f(5484, 448); glVertex2f(5484, 0);
        glVertex2f(5484, 0); glVertex2f(0, 0);
        glVertex2f(0, 0); glVertex2f(0, 583);

    glEnd();

    drawCeilingVent();
}



// left panel
void drawPanel() {
    glEnable(GL_TEXTURE_2D);
    
    glColor3f(1.0f, 1.0f, 1.0f);  // White color
    
    // Bind the texture for texture 1
    glBindTexture(GL_TEXTURE_2D, textureIDs[2]); // Assuming textureIDs[0] is the texture you want to use

    // Enable texturing before drawing
    glEnable(GL_TEXTURE_2D);

    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glTexCoord2f(0.0f, 0.0f); glVertex2f(1700.0f, 2170.0f);  // Bottom-left vertex
        glTexCoord2f(1, 0.0f); glVertex2f(1900.0f, 2170.0f);  // Bottom-right vertex
        glTexCoord2f(0.25, 1); glVertex2f(1900.0f, 2000.0f);  // Top-right vertex
        glTexCoord2f(10.0f, 1); glVertex2f(1700.0f, 2000.0f);  // Top-left vertex
    glEnd();

    // Disable texturing after drawing if it's not needed elsewhere
    glDisable(GL_TEXTURE_2D);

}

void drawtopFrame() {

     // Set the color to white to avoid altering the texture color
    glColor3f(250/255.0, 239/255.0, 194/255.0);  // Set color to whiteish

    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0.0f, 1145.0f);  // Bottom-left vertex
        glVertex2f(295.0f, 1171.0f);  // Bottom-right vertex
        glVertex2f(328.0f, 1559.0f);  // Top-right vertex
        glVertex2f(0.0f, 1560.0f);  // Top-left vertex
    glEnd();
    
    glColor3f(144/255.0, 102/255.0, 60/255.0);  // Set color to brown

    // 9.5 thickness
    glLineWidth(9.5f);  // Set line width

    glBegin(GL_LINES);
    glVertex2f(0.0f, 1145.0f);glVertex2f(295.0f, 1171.0f);
    glVertex2f(295.0f, 1145.0f);glVertex2f(328.0f, 1589.0f);
    glVertex2f(328.0f, 1559.0f);glVertex2f(0.0f, 1560.0f);

    glEnd();


}

void drawBottomFrame() {

    glColor3f(250/255.0f, 239/255.0f, 194/255.0f);  // Set color to white-ish

    // Draw the quad with counter-clockwise winding order
    glBegin(GL_QUADS);
        glVertex2f(609.0f, 2225.0f);  // Top-left
        glVertex2f(858.0f, 2211.0f);  // Top-right
        glVertex2f(864.0f, 2371.0f);  // Bottom-right
        glVertex2f(606.0f, 2387.0f);  // Bottom-left
    glEnd();

    // Set color for the lines
    glColor3f(180/255.0f, 136/255.0f, 101/255.0f);  // Set color to brown
    glLineWidth(10.5f);  // Set line width

    // Draw the outline lines
    glBegin(GL_LINES);
        glVertex2f(590, 2387); glVertex2f(884, 2371);
        glVertex2f(864, 2371); glVertex2f(858, 2211);
        glVertex2f(878, 2211); glVertex2f(589, 2225);
        glVertex2f(609, 2225); glVertex2f(606, 2387);
    glEnd();

}


void drawBookshelf() {
    
    // back part
    
    // Enable 2D texturing
    glEnable(GL_TEXTURE_2D);

    // Set the color to white, so the texture is displayed without tint
    glColor3f(1.0f, 1.0f, 1.0f);

    // Bind the texture you want to apply (assuming textureIDs[2] is the correct texture)
    glBindTexture(GL_TEXTURE_2D, textureIDs[6]);

    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);

    // Define texture coordinates and corresponding vertices

    // Bottom-left corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(90.0f, 3860.0f);

    // Bottom-right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1050.0f, 3620.0f);

    // Top-right corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(950.0f, 1645.0f);

    // Top-left corner
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(-125.0f, 1645.0f);

    glEnd();

    // Disable texturing if it's not needed elsewhere
    glDisable(GL_TEXTURE_2D);

    /*glColor3f(1.0f, 0.0f, 0.0f);  // red color
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(090.0f, 3860.0f);  // Bottom-left vertex
        glVertex2f(1050.0f, 3620.0f);  // Bottom-right vertex
        glVertex2f(950.0f, 1645.0f);  // Top-right vertex
        glVertex2f(-0125.0f, 1645.0f);  // Top-left vertex
    glEnd();*/


 
 // ------------------------------------------------------------------ //

    // side panel 

    // Enable 2D texturing
    glEnable(GL_TEXTURE_2D);

    // Set the color to white so the texture is displayed without tint
    glColor3f(0.7f, 0.7f, 0.7f);

    // Bind the texture you want to apply (assuming textureIDs[2] is the correct texture)
    glBindTexture(GL_TEXTURE_2D, textureIDs[6]);

    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);

    // Define texture coordinates and corresponding vertices

    // Bottom-left corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(1050.0f, 3750.0f);

    // Bottom-right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1110.0f, 3750.0f);

    // Top-right corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(1020.0f, 1640.0f);

    // Top-left corner
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(950.0f, 1645.0f);

    glEnd();

    // Disable texturing after drawing if it's not needed elsewhere
    glDisable(GL_TEXTURE_2D);

    /*glColor3f(0.0f, 1.0f, 1.0f);  // light blue color
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(1050.0f, 3750.0f);  // Bottom-left vertex
        glVertex2f(1110.0f, 3750.0f);  // Bottom-right vertex
        glVertex2f(1020.0f, 1640.0f);  // Top-right vertex
        glVertex2f(950.0f, 1645.0f);  // Top-left vertex
    glEnd();*/



  // ------------------------------------------------------------------ //

    // shelf 1 - from the top
    // Enable 2D texturing
    glEnable(GL_TEXTURE_2D);

    // Set the color to white so the texture is displayed without tint
    glColor3f(0.8f, 0.8f, 0.8f);

    // Bind the texture you want to apply (assuming textureIDs[2] is the correct texture)
    glBindTexture(GL_TEXTURE_2D, textureIDs[6]);

    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);

    // Define texture coordinates and corresponding vertices

    // Bottom-left corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 2075.0f);

    // Bottom-right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1050.0f, 2025.0f);

    // Top-right corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(950.0f, 1950.0f);

    // Top-left corner
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, 2000.0f);

    glEnd();

    // Disable texturing after drawing if it's not needed elsewhere
    /*glDisable(GL_TEXTURE_2D);


    glColor3f(0.0f, 0.0f, 1.0f);  // blue color
    //    l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0000.0f, 2075.0f);  // Bottom-left vertex
        glVertex2f(1050.0f, 2025.0f);  // Bottom-right vertex
        glVertex2f(950.0f, 1950.0f);  // Top-right vertex
        glVertex2f(0000.0f, 2000.0f);  // Top-left vertex
    glEnd();*/

    // shelf 2 

    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);

    // Define texture coordinates and corresponding vertices

    // Bottom-left corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 2525.0f);

    // Bottom-right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1075.0f, 2425.0f);

    // Top-right corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(950.0f, 2325.0f);

    // Top-left corner
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, 2400.0f);

    glEnd();

    /*glColor3f(0.0f, 0.0f, 1.0f);  // blue color
    //    l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0000.0f, 2525.0f);  // Bottom-left vertex
        glVertex2f(1075.0f, 2425.0f);  // Bottom-right vertex
        glVertex2f(950.0f, 2325.0f);  // Top-right vertex
        glVertex2f(0000.0f, 2400.0f);  // Top-left vertex
    glEnd();*/

    // shelf 3

    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);

    // Define texture coordinates and corresponding vertices

    // Bottom-left corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 3100.0f);

    // Bottom-right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1100.0f, 2900.0f);

    // Top-right corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(995.0f, 2790.0f);

    // Top-left corner
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, 2950.0f);

    glEnd();

    /*glColor3f(0.0f, 0.0f, 1.0f);  // blue color
    //    l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0000.0f, 3100.0f);  // Bottom-left vertex
        glVertex2f(1100.0f, 2900.0f);  // Bottom-right vertex
        glVertex2f(995.0f, 2790.0f);  // Top-right vertex
        glVertex2f(0000.0f, 2950.0f);  // Top-left vertex
    glEnd();*/

    // shelf 4
    
    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);

    // Define texture coordinates and corresponding vertices

    // Bottom-left corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(50.0f, 3590.0f);

    // Bottom-right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1125.0f, 3350.0f);

    // Top-right corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(1020.0f, 3225.0f);

    // Top-left corner
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(50.0f, 3400.0f);

    glEnd();    
    
    /*glColor3f(0.0f, 0.0f, 1.0f);  // blue color
    //    l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0050.0f, 3590.0f);  // Bottom-left vertex
        glVertex2f(1125.0f, 3350.0f);  // Bottom-right vertex
        glVertex2f(1020.0f, 3225.0f);  // Top-right vertex
        glVertex2f(0050.0f, 3400.0f);  // Top-left vertex
    glEnd();*/

    // bottom shelf

    // Begin drawing the textured polygon
    glBegin(GL_POLYGON);

    // Define texture coordinates and corresponding vertices

    // Bottom-left corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(100.0f, 4050.0f);

    // Bottom-right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1125.0f, 3750.0f);

    // Top-right corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(1040.0f, 3615.0f);

    // Top-left corner
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(80.0f, 3860.0f);

    glEnd();


    /*glColor3f(0.0f, 0.0f, 1.0f);  // blue color
    //    l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0100.0f, 4050.0f);  // Bottom-left vertex
        glVertex2f(1125.0f, 3750.0f);  // Bottom-right vertex
        glVertex2f(1040.0f, 3615.0f);  // Top-right vertex
        glVertex2f(0080.0f, 3860.0f);  // Top-left vertex
    glEnd();*/


    // Disable texturing after drawing if it's not needed elsewhere
    glDisable(GL_TEXTURE_2D);
     // ------------------------------------------------------------------ //

     // outer border - right 
    glColor3f(167/255.0f, 129/255.0f, 90/255.0f);  // brown color
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(1110.0f, 3830.0f);  // Bottom-left vertex
        glVertex2f(1180.0f, 3830.0f);  // Bottom-right vertex
        glVertex2f(1090.0f, 1600.0f);  // Top-right vertex
        glVertex2f(1020.0f, 1600.0f);  // Top-left vertex
    glEnd();

    // outer border - top
    //glColor3f(1.0f, 0.0f, 1.0f);  // red color
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0000.0f, 1650.0f);  // Bottom-left vertex
        glVertex2f(1100.0f, 1650.0f);  // Bottom-right vertex
        glVertex2f(1100.0f, 1550.0f);  // Top-right vertex
        glVertex2f(0000.0f, 1550.0f);  // Top-left vertex
    glEnd();

     // outer border - bottom
    //glColor3f(1.0f, 0.0f, 1.0f);  // red color
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(0100.0f, 4100.0f);  // Bottom-left vertex
        glVertex2f(1110.0f, 3800.0f);  // Bottom-right vertex
        glVertex2f(1100.0f, 3750.0f);  // Top-right vertex
        glVertex2f(0100.0f, 4050.0f);  // Top-left vertex
    glEnd();

    // outer border - left
     //glColor3f(1.0f, 0.0f, 1.0f);  // red color
             // l-/r+       u-/d+
    glBegin(GL_POLYGON);  // Start drawing the polygon
        glVertex2f(60.0f, 4150.0f);  // Bottom-left vertex
        glVertex2f(130.0f, 4130.0f);  // Bottom-right vertex
        glVertex2f(020.0f, 3100.0f);  // Top-right vertex
        glVertex2f(-0030.0f, 3250.0f);  // Top-left vertex
    glEnd();



}

void RightSpotlight() {
    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Set spotlight position at (4552, 291) and a Z-value
    GLfloat lightPosition[] = { 4552.0f, 291.0f, 100.0f, 1.0f };  // Spotlight position
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // Set the direction of the spotlight (pointing downward in this example)
    GLfloat spotlightDirection[] = { 0.0f, -1.0f, 0.0f };  // Pointing downward
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotlightDirection);

    // Set spotlight properties
    GLfloat spotlightCutoff = 25.0f;  // Angle of the cone
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spotlightCutoff);

    GLfloat spotlightExponent = 2.0f;  // Focus the light
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spotlightExponent);

    // Set light color components (ambient, diffuse, and specular)
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
}


void RightLightdisplay() {
    //glClear(GL_COLOR_BUFFER_BIT);
    
    // Enable blending for transparency (glow effect)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw the outer glow (larger, semi-transparent oval)
    //glColor4f(1.0f, 1.0f, 0.8f, 0.3f);  // Light yellowish glow with transparency
    //drawLight(4552.0f, 291.0f, 200.0f, 100.0f, 100);  // Larger oval for glow

    // Draw the inner glow (smaller, more opaque oval)
    glColor4f(1.0f, 1.0f, 0.8f, 0.6f);  // Brighter inner glow
    drawLight(4552.0f, 291.0f, 120.0f, 75.0f, 100);  // Smaller oval for stronger glow

    // Draw the spotlight itself (smallest, nearly fully opaque oval)
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);  // Very bright spotlight
    drawLight(4552.0f, 291.0f, 80.0f, 50.0f, 100);  // Smallest oval for spotlight

    // Disable blending after drawing
    glDisable(GL_BLEND);

    glutSwapBuffers();  // Swap buffers for smooth drawing (if using double buffering)

}


void LeftLightdisplay() {
    //glClear(GL_COLOR_BUFFER_BIT);
    
    // Enable blending for transparency (glow effect)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw the outer glow (larger, semi-transparent oval)
    //glColor4f(1.0f, 1.0f, 0.8f, 0.3f);  // Light yellowish glow with transparency
    //drawLight(4552.0f, 291.0f, 200.0f, 100.0f, 100);  // Larger oval for glow

    // Draw the inner glow (smaller, more opaque oval)
    glColor4f(1.0f, 1.0f, 0.8f, 0.6f);  // Brighter inner glow
    drawLight(224.0f, 445.0f, 120.0f, 75.0f, 100);  // Smaller oval for stronger glow

    // Draw the spotlight itself (smallest, nearly fully opaque oval)
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);  // Very bright spotlight
    drawLight(224.0f, 445.0f, 80.0f, 50.0f, 100);  // Smallest oval for spotlight

    // Disable blending after drawing
    glDisable(GL_BLEND);

    glutSwapBuffers();  // Swap buffers for smooth drawing (if using double buffering)

}





// }
// all the lines
void renderLines() {
    
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

    
    // 0.5 thickness
    glLineWidth(0.5f);  // Set line width

    glBegin(GL_LINES);


    //TV
    glVertex2f(2067, 1394); glVertex2f(2116, 2206); 
    glVertex2f(2116, 2206); glVertex2f(3300, 2211);
    glVertex2f(3300, 2211); glVertex2f(3308, 1373);
    glVertex2f(3308, 1373); glVertex2f(2067, 1394);

    //control panel
    /*glVertex2f(1708, 2006); glVertex2f(1716, 2139);
    glVertex2f(1716, 2139); glVertex2f(1894, 2138);
    glVertex2f(1894, 2138); glVertex2f(1894, 2006);
    glVertex2f(1894, 2006); glVertex2f(1708, 2006);*/

    //Ceiling
    glVertex2f(0, 583); glVertex2f(247, 677);
    glVertex2f(247, 677); glVertex2f(5484, 448);

    //ceiling vent
    glVertex2f(333, 213); glVertex2f(1359, 164);
    glVertex2f(1359, 164); glVertex2f(1752, 483);
    glVertex2f(1752, 483); glVertex2f(936, 520);
    glVertex2f(936, 520); glVertex2f(333, 213);

    //picture frame
    glVertex2f(0, 1145); glVertex2f(295, 1171);
    glVertex2f(295, 1171); glVertex2f(328, 1559);
    glVertex2f(328, 1559); glVertex2f(0, 1560);

    //right wall socket
    glVertex2f(1133, 3266); glVertex2f(1202, 3266);
    glVertex2f(1202, 3266); glVertex2f(1199, 3133);
    glVertex2f(1199, 3133); glVertex2f(1128, 3127);
    glVertex2f(1128, 3127); glVertex2f(1133, 3266);

    //floor wall
    glVertex2f(1149, 3581); glVertex2f(5443, 3712);
    glVertex2f(5443, 3712); glVertex2f(5484, 3753);

    // right wall socket
    glVertex2f(4523, 3197); glVertex2f(4623, 3204);
    glVertex2f(4623, 3204); glVertex2f(4610, 3344);
    glVertex2f(4610, 3344); glVertex2f(4510, 3338);
    glVertex2f(4510, 3338); glVertex2f(4523, 3197);

    //shelves
    glVertex2f(944, 1611); glVertex2f(1048, 3621);
    
    glVertex2f(0, 2009); glVertex2f(963, 1967);
    glVertex2f(963, 1967); glVertex2f(1063, 1994);

    glVertex2f(0, 2442); glVertex2f(984, 2346);
    glVertex2f(984, 2346); glVertex2f(1080, 2403);

    glVertex2f(0, 2960); glVertex2f(1007, 2800);
    glVertex2f(1007, 2800); glVertex2f(1106, 2888);
    
    glVertex2f(32, 3423); glVertex2f(1030, 3230);
    glVertex2f(1030, 3230); glVertex2f(1118, 3344);

    glVertex2f(73, 3881); glVertex2f(1048, 3621);
    glVertex2f(1048, 3621); glVertex2f(1145, 3766);


    //left chair
    glVertex2f(1225, 4275); glVertex2f(1393, 4279);
    glVertex2f(1393, 4279); glVertex2f(1338, 3411);
    glVertex2f(1338, 3411); glVertex2f(1731, 3050); 
    glVertex2f(1731, 3050); glVertex2f(1752, 3506);
    glVertex2f(1752, 3506); glVertex2f(1365, 3858);

    glVertex2f(1378, 4140); glVertex2f(2286, 4146);
    glVertex2f(2286, 4146); glVertex2f(2287, 3874);
    glVertex2f(2287, 3874); glVertex2f(1365, 3858);
    glVertex2f(1365, 3858); glVertex2f(1378, 4140);

    glVertex2f(1752, 3506); glVertex2f(2272, 3496);

    glVertex2f(1728, 2971); glVertex2f(1651, 2990);
    glVertex2f(1651, 2990); glVertex2f(1186, 3406);
    glVertex2f(1186, 3406); glVertex2f(1225, 4275);

    glVertex2f(2289, 4279); glVertex2f(2267, 3439);
    glVertex2f(2267, 3439); glVertex2f(2459, 3040);
    glVertex2f(2459, 3040); glVertex2f(2443, 2868);
    glVertex2f(2443, 2868); glVertex2f(1731, 2860);
    glVertex2f(1731, 2860); glVertex2f(1731, 3050);

    glVertex2f(2453, 2985); glVertex2f(2650, 2990);
    glVertex2f(2650, 2990); glVertex2f(2470, 3438);
    glVertex2f(2470, 3438); glVertex2f(2467, 4279);

    glVertex2f(2650, 2990); glVertex2f(2648, 3692);
    glVertex2f(2648, 3692); glVertex2f(2489, 4279);


    //right chair
    glVertex2f(3192, 3542); glVertex2f(3957, 3612);
    glVertex2f(3957, 3612); glVertex2f(3925, 4048);
    glVertex2f(3925, 4048); glVertex2f(3018, 3912);
    glVertex2f(3018, 3912); glVertex2f(3192, 3542);


    //glVertex2f(3192, 3542); glVertex2f(3016, 4180);
    glVertex2f(3016, 4180); glVertex2f(3700, 4279);

    glVertex2f(3016, 4279); glVertex2f(3012, 3453);
    glVertex2f(3012, 3453); glVertex2f(3174, 3070);
    glVertex2f(3192, 3542); glVertex2f(3171, 2910);

    glVertex2f(2841, 4279); glVertex2f(2825, 3432);
    glVertex2f(2825, 3432); glVertex2f(3059, 2993);
    glVertex2f(3059, 2993); glVertex2f(3169, 3008);
    
    glVertex2f(3169, 3008); glVertex2f(3182, 2991);

    glVertex2f(3171, 2910); glVertex2f(3980, 2939);
    glVertex2f(3980, 2939); glVertex2f(3957, 3612);

    glVertex2f(3975, 3046); glVertex2f(4163, 3072);
    glVertex2f(4163, 3072); glVertex2f(4161, 3568);
    glVertex2f(4161, 3568); glVertex2f(4124, 4279);

    glVertex2f(3925, 4048); glVertex2f(3924, 4279);

    //glVertex2f(3963, 3129); glVertex2f(4047, 3550);
    //glVertex2f(4047, 3550); glVertex2f(4031, 4279);

    glEnd();

    // 2.5 thickness
    glLineWidth(2.5f);

    glBegin(GL_LINES);

    //TV Stand
    glVertex2f(2693, 2315); glVertex2f(2691, 2211);

    //ceiling vent
    glVertex2f(333, 213); glVertex2f(1359, 164);
    glVertex2f(1359, 164); glVertex2f(1752, 483);
    glVertex2f(1752, 483); glVertex2f(936, 520);
    glVertex2f(936, 520); glVertex2f(333, 213);

    //picture frame
    glVertex2f(0, 1145); glVertex2f(295, 1171);
    glVertex2f(295, 1171); glVertex2f(328, 1559);
    glVertex2f(328, 1559); glVertex2f(0, 1560);

    //shelves
    glVertex2f(0, 2049); glVertex2f(1063, 1994);
    glVertex2f(0, 2511); glVertex2f(1080, 2403);
    glVertex2f(0, 3075); glVertex2f(1106, 2888);
    glVertex2f(56, 3580); glVertex2f(1118, 3344);
    glVertex2f(96, 4055); glVertex2f(1145, 3766);

    glEnd();


     // 6.5 thickness
    glLineWidth(6.5f);

    glBegin(GL_LINES);

    //shelves
    glVertex2f(0,1595); glVertex2f(1046, 1596);
    glVertex2f(1046, 1596); glVertex2f(1146, 3835);
    glVertex2f(0, 3275); glVertex2f(84, 4145);

    glEnd();

     // 9.5 thickness
    glLineWidth(9.5f);

    glBegin(GL_LINES);

    //shelves
    glVertex2f(607,2227); glVertex2f(854, 2211);
    glVertex2f(854, 2211); glVertex2f(862, 2365);
    glVertex2f(862, 2365); glVertex2f(603, 2384);
    glVertex2f(603, 2384); glVertex2f(607, 2227);

    glEnd();

    
    drawWall();
    drawCeiling();
    drawFloor();
    drawTV();
    leftChair2();
    rightChair2();
    rightWallSocket();
    drawPanel();
    drawBookshelf();
    drawtopFrame();
    drawBottomFrame();
    //patchWall();

  

    glLineWidth(1.0f);
    // Set color for the circle (blue)
    glColor3f(215/255.0f, 196/255.0f, 154/255.0f);
    // Draw a circle at (3000, 3000) with radius 500 and 100 segments for smoothness
    drawLight(223.0f, 437.0f, 160.0f, 80.0f, 100);

    drawLight(4561.0f, 283.0f, 160.0f, 80.0f, 100);

    RightLightdisplay();
    LeftLightdisplay();
    
    //RightSpotlight();

    glFlush();  // Render the lines
    
}



// Initialization function
void init() {

    glEnable(GL_TEXTURE_2D); // Enable 2D texturing

    // Load multiple textures
    /*
    loadTexture("/Users/atu/Library/CloudStorage/OneDrive-Personal/Documents/Atu/GCU/F24/CST-310/week6/Textures/floor.jpg", 0);  // Load the first texture
    loadTexture("/Users/atu/Library/CloudStorage/OneDrive-Personal/Documents/Atu/GCU/F24/CST-310/week6/Textures/socket.jpg", 1);  // Load the first texture
    loadTexture("/Users/atu/Library/CloudStorage/OneDrive-Personal/Documents/Atu/GCU/F24/CST-310/week6/Textures/control.jpg", 2);  // Load the first texture
    loadTexture("/Users/atu/Library/CloudStorage/OneDrive-Personal/Documents/Atu/GCU/F24/CST-310/week6/Textures/Control.png", 3);  // Load the first texture
    loadTexture("/Users/atu/Library/CloudStorage/OneDrive-Personal/Documents/Atu/GCU/F24/CST-310/week6/Textures/wall.jpg", 4);  // Load the first texture
    loadTexture("/Users/atu/Library/CloudStorage/OneDrive-Personal/Documents/Atu/GCU/F24/CST-310/week6/Textures/topFrame.jpg", 5);  // Load the first texture
    loadTexture("/Users/atu/Library/CloudStorage/OneDrive-Personal/Documents/Atu/GCU/F24/CST-310/week6/Textures/wood.jpg", 6);  // Load the first texture
    */
    loadTexture("Textures/floor.jpg", 0);       // Load texture 0
    loadTexture("Textures/control.jpg", 2);     // Load texture 2
    loadTexture("Textures/wall.jpg", 4);        // Load texture 4
    loadTexture("Textures/wood.jpg", 6);        // Load texture 6

    // Set background color to the specified RGB value
    //glClearColor(0.745f, 0.694f, 0.671f, 1.0f);


    // Set up 2D orthographic projection to match the given dimensions
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Swap the y-axis by setting (0, 2141) at the bottom-left and (2855, 0) at the top-right
    gluOrtho2D(0, 5484, 4279, 0);  // Adjusted projection for the given coordinate system

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Main function
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //glutInitWindowSize(2855, 2141);  // Set window size based on the coordinate system
    glutInitWindowSize(5484, 4279);
    glutCreateWindow("OpenGL 2D Line Rendering with GLUT");

    // Initialize OpenGL
    init();

    // Set the display function
    glutDisplayFunc(renderLines);
    
    // Enter the main loop
    glutMainLoop();

    return 0;
}
