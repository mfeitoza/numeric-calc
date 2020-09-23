#include <stdio.h>
#include <math.h>

double equation1 (double x) {
    return pow(x, 2.0);
}

double equation2 (double x) {
    return  pow(x, 2.0) - x - 1;
}

double two_point (double (*fn) (double), double x, double h) {
    return (fn(x + h) - fn(x)) / h;
}

double three_point (double (*fn) (double), double x, double h) {
    return (1/(2*h))*(-3*fn(x) + 4 * fn(x + h) - fn(x + 2*h));
}

double five_point (double (*fn) (double), double x, double h) {
    return (1/(12*h))*(fn(x - 2*h) - 8*fn(x - h) + 8*fn(x + h) - fn(x + 2*h));
}

int main () {
    double h = 0.0001;

    printf("f(x) = x^2; x = 3\n");
    printf("Two point: %lf\n", two_point(equation1, 3, h));
    printf("Three point: %lf\n", three_point(equation1, 3, h));
    printf("Five point: %lf\n", five_point(equation1, 3, h));

    printf("\n");
    printf("f(x) = x^2-x-1; x = 7\n");
    printf("Two point: %lf\n", two_point(equation2, 7, h));
    printf("Three point: %lf\n", three_point(equation2, 7, h));
    printf("Five point: %lf\n", five_point(equation2, 7, h));
}