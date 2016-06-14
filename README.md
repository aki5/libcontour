# Libcontour - fast multicolor contouring

Libcontour implements fast and robust moore contour tracing from 7-bit images. The images are 7-bit, because libcontour uses the most significant bit to mark a pixel as already part of a contour. A distinguishing feature of libcontour is that it contours all colors in a single pass.

The stopping criteria for the moore contour is "arrived at the same pixel again from the same direction", the complications of which are discussed for example [here](http://www.imageprocessingplace.com/downloads_V3/root_downloads/tutorials/contour_tracing_Abeer_George_Ghuneim/moore.html).

A very simple polygon fitting algorithm is also provided, which does a polygon fit by iterative refinement instead of the perhaps more obvious way of iterative simplification. This polygon fitting strategy trades quality for improved performance and a simpler algorithm.

## Contouring API

The first step is to initialize the contourer by calling `initcontour` with a description of the memory mapped bitmap in separate parameters. Stride must currently match width, or nextcontour will fail.

```
void initcontour(Contour *cp, uchar *img, int width, int height, int stride);
```

After the contourer has been initialized, contours can be extracted one at a time by repeatedly calling nextcontour. `Apt` indicates for how many points there is room in the `pt` array, while `idp` is used to return color of the returned contour. The return value tells how many points the contour has. The `fillrule` flag is an attempt at an opengl rasterizer like fill-rules for the different colors. The implementation is not really ready, so this flag is best left as 0.

When there are no more contours to be found, nextcontour returns -1.

Each point in the `pt` array consists of two values, the x-coordinate and the y-coordinate, but `apt` and the return value from `nextcontour` are in number of points, not elements of the array. X-coordinate of the i'th point is at `pt[2*i+0]` and the y-coordinate would be at `pt[2*i+1]`.

```
int nextcontour(Contour *cp, short *pt, int apt, int fillrule, int *idp);
```

Fitpoly will fit a polyline approximating the polyline given as input. The format for both, `poly` and `pt` is the same as discussed above for `nextcontour`, and `dstthr` is a refinement termination threshold. Fitpoly will return the number of points in the returned polyline.

```
int fitpoly(int *poly, int apoly, short *pt, int npt, int dstthr);
```
