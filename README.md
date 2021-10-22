# miniRT
Simple RayTracer


## Input file template

```c

R   x,y                                   //resolituon

A	ratio	r,g,b 								            // ambient light

c	x,y,z	x,y,z 								            // camera

sp	x,y,z	diameter  r,g,b                     // sphere - center
pl	x,y,z	x,y,z	r,g,b                         // plane - coordinates - orientation vector
sq	x,y,z	x,y,z	diameter	r,g,b           // square - center - orientation vector
cy	x,y,z	x,y,z	diameter	height	r,g,b   // cylinder - coordinates - orientation vector
tr	x,y,z	x,y,z	x,y,z		r,g,b           // triangle - edges

```

