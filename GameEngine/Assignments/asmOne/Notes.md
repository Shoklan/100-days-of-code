# Assignment 1

## Requirements
- Only Submit main.cpp file. // So bulid from a single file.
- Comment with full names of project users. // So, notate my name and such

## Program Specification:
In the assignment, you will be writing a C++/SMFL program which will be reading descriptions of shapes from a config file and then drawing those shapes to the screen.
These will have a set of attributes which you will need to implement after reading them from a configuration file; the position will be the upper left of the shape being drawn.

These shapes must bounce off the once they've reached the edge of the screen.
This should be true even when the shape size changes.
Text must be in the center of the object drawn.


The User Interface must:
1. List all the shapes and their properties.
2. Toggle the shape being drawn or not.
3. Change the scale of the shape: 0-4.
4. Change the x,y velocity of the shape: -8 - 8.
5. Change the color of the shape.
6. Change the name of the shape.

## Hints:
1. Should probably use a `std::vector` for storing arbitrary length set of objects.
2. Consider your own custom class/struct for storing the properties of the objects.
3. The bounding box is a useful way to test for window collisions: `shape.getLocalBounds()`
4. A text elements `.getLocalBounds()` is a way to center the text.
5. 