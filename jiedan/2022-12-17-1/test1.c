#include "stdio.h"

//返回给定c的圆的半径r,已知周长
double getRadius(double c) {
    double r = 0;
    double pi = 3.1415926;
    r = c / (2 * pi);
    return r;
}

//返回给定c的圆的面积s,已知周长
double getArea(double c) {
    double s = 0;
    double pi = 3.1415926;
    s = pi * getRadius(c) * getRadius(c);
    return s;
}


int main() {
    getRadius(10);
    return 0;
}
