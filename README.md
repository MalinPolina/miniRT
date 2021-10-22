# miniRT
Very basic RayTracer

## Specifics

Uses the miniLibX
Allows window management

Can render these simple geometric objects: plane, sphere, cylinder, square, triangle

Can have multiple cameras: use left and right arrow keys to switch between them
Has a zoom option: use up and down arrow keys

## Usage

```c
./miniRT filename.rt
```
To save as .bmp:

```c
./miniRT filename.rt --save
```

## Exit

Press ESC or click on the red cross on the window’s frame

## Input file template

```c

R           x,y                                              //resolituon

A	ratio	r,g,b 					// ambient light

c	x,y,z	x,y,z 		                        // camera

sp	x,y,z	diameter  r,g,b                         // sphere - center
pl	x,y,z	x,y,z	r,g,b                           // plane - coordinates - orientation vector
sq	x,y,z	x,y,z	diameter	r,g,b           // square - center - orientation vector
cy	x,y,z	x,y,z	diameter	height	r,g,b   // cylinder - coordinates - orientation vector
tr	x,y,z	x,y,z	x,y,z		r,g,b           // triangle - edges

```

