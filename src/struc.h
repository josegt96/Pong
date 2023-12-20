#ifndef STRUC_H
#define STRUC_H

enum eDir
{
    STOP = 0,
    LEFT = 1,
    UPLEFT = 2,
    DOWNLEFT = 3,
    RIGHT = 4,
    UPRIGHT = 5,
    DOWNRIGHT = 6
};

struct Point2D
{
    int x;
    int y;
};

struct ColorRGB
{
    int red;
    int green;
    int blue;
};

struct PointWithColor
{
    Point2D point;
    ColorRGB color;
};

#endif