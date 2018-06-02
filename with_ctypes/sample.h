#ifndef __SAMPLE_H__
#define __SAMPLE_H__
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

int gcd(int x, int y);
int in_mandel(double x0, double y0, int n);
int divide(int a, int b, int *remainder);
double avg(double *a, int n);
    
/* A C data structure */
typedef struct Point {
    double x,y;
} Point;
    
double distance(Point *p1, Point *p2);

#ifdef __cplusplus
}
#endif
#endif
