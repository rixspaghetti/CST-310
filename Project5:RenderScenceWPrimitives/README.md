# Project 5: Render Your Scene with Primitives

### Authors: Atuhaire Ambala and Ricardo Escarcega  
**Professor:** Ricardo Citro  
**Course:** CST 310  
**Date:** 10/20/24

## Project Description

The goal of this project is to develop 3D graphical renderings using OpenGL by capturing real-world environments and recreating them in a digital format. The project involves using photographic images to capture various scenes and develop them using primitives and OpenGL techniques. This includes scene selection, texture mapping, lighting, shading, and optimization techniques.

## Getting Started

To run this project, you need to have OpenGL installed on your system. All the necessary code files are provided, including the Makefile to help compile and link the project. 

The project also includes several texture images that have been used for enhancing realism in the scene. These texture files are included in the "Textures" folder.

### Prerequisites
- OpenGL
- GCC or any C++ compiler that supports OpenGL
- Linux or macOS (recommended for easier compilation with Makefile)

### File Structure
- `lobby.cpp`: Main source code containing the rendering logic.
- `Makefile`: Used to compile the project.
- `Textures` folder: Contains the textures used for rendering, including:
  - `floor.jpg`
  - `control.jpg`
  - `wall.jpg`
  - `wood.jpg`

## Running the Project

To compile and run the project, follow these steps:

1. Open a terminal in the directory containing the files.
2. Make sure that all texture images are in the `Textures` folder.
3. Use the command:

   ```sh
   make run
   ```
   This command will use the Makefile to compile all necessary files and create the executable.

4. Once the compilation is successful, you can run the program using:

   ```sh
   ./lobby
   ```

## Textures

The texture images are crucial for adding realism to the 3D renderings. Make sure the `Textures` folder contains the following files:
- `floor.jpg`: Texture for the floor in the scene.
- `control.jpg`: Texture for the control panel.
- `wall.jpg`: Texture for the walls.
- `wood.jpg`: Texture for wooden objects like bookshelves.

These texture images will be loaded at runtime and applied to the respective objects in the 3D scene to make the renderings look more lifelike.

## Notes
- Ensure that all textures are present in the correct directory before running the program, otherwise the scene will render without proper textures.
- The Makefile handles the compilation and linking process, simplifying running the program.

## License
This project is intended for educational purposes, as part of CST 310 coursework.

Feel free to contact us for any questions regarding the project.

## Certification Statement
"We certify that all images submitted for this project were taken personally using our phones. They were not downloaded from the internet, ensuring authenticity and originality in capturing the chosen environments."
