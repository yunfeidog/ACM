#include "stdio.h"
#include "math.h"
//设计函数实现平面坐标系中某点直角坐标(x, y)到极坐标(r, theta)的转换
//其中r = sqrt(x*x + y*y) theta = atan(y/x)
//其中atan()函数返回值的范围为(-pi/2, pi/2)

//返回给定x,y的极坐标r
double getRadius(double x, double y) {
    double r = 0;
    r = sqrt(x * x + y * y);
    return r;
}

//返回给定x,y的极坐标theta
double getTheta(double x, double y) {
    double theta = 0;
    theta = atan(y / x);
    return theta;
}

int main() {
    double x, y;
    printf("请输入直角坐标系中的点的坐标:");
    scanf("%lf%lf", &x, &y);
    printf("x=%lf,y=%lf,r=%lf,theta=%lf", x, y, getRadius(x, y), getTheta(x, y));
    return 0;
}

