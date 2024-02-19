
# Initial goal：
  A system to enable children to design smartwatch holders 
  Two of my PhD students are investigating how smartwatches can help children self-manage long term health conditions. Sometimes children do not like the feeling of the straps on their wrist. We want to design an interface to enable children to creatively design holders for the smartwatches that they could then attach to their clothes. The interface could be screen-based but it could be more hands on e.g. it could be a deformable physical interface. The created designs must be viable smartwatch housings and the system will then translate them into a file format that can be read by a 3D printer (e.g. .OBJ or .STL). This project will have some support from my PhD student Sydney Charitos.

# My goal:
  I want to create an application using openFrameworks, which is a simple modeling software that allows children to build their own smartphone stands. It will have a menu with various molds such as cubes, circles, cylinders, etc., as well as basic molds, like a circular holder to ensure a smartwatch doesn't fall out. Users can add patterns, like little rabbits and cats, that can be added to the holder or module. Users will be able to click on these molds to display them at the center of the screen, and then the children can use these molds to assemble them just like LEGO bricks, and they can change the molds' length, width, height, rotation, and position to achieve the shape they want. Finally, there will be a button to export the model as an STL file. After implementing the basic functionalities, I want to explore more challenging or interesting features, such as controlling the screen and moving modules or other functionalities through camera gesture recognition.

# What I have done so far:
  Currently, I have implemented a simple menu that can create cubes. Then, based on mouse clicks, it selects the cube, and the direction of the cube can be controlled with the keyboard. Additionally, it is possible to export the entire scene with the modified positions.

# Difficulties 
The difficulties I've met

## Using Processing to export STL file

  I attempted various methods to export STL files, including but not limited to using the ModelBuilderMk2 library, netfabb, HE_Mesh, and writing my own code for printing STL files. However, all attempts were unsuccessful. The issues ranged from the libraries being too outdated and incompatible, to the printed files having significant flaws. Consequently, following the advice of my supervisor, Jon, I switched to using openFrameworks.

## Using openFrameworks to export STL file(sloved)

  I'm using ofxSTL lib to import and export STL files, it's work. However, I am unable to export my model without loading an STL file, meaning if I don't load a file， just directly create or modify a model, I can't export the model.
  However, I tried writing some utility methods myself to import the model's vertices, faces, and normals into the ofxSTL exporter, and then I was able to successfully export the correct STL file.

...

