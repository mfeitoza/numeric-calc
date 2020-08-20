#include <stdio.h>
#include <math.h>

double equation1 (double x) {
    return  pow(x, 2.0) - x - 1;
}

double equation2 (double x) {
    return  exp(x) - 1;
}

double equation3 (double x) {
    return  exp(x) - sin(x) * cos(x);
}

double bisect_method (double (*fn) (double), double a, double b, double epsilon) {
    double fa, fb, mid, fmid;

    do {
        mid = (b + a) / 2;
        fmid = fn(mid);
        fa = fn(a);
        fb = fn(b);

        printf("a: %lf | b: %lf | mid: %lf | fa: %lf | fmid: %lf | fb: %lf\n", a, b, mid, fa, fmid, fb);

        if ((fa < 0.0 && fmid < 0.0) || (fa > 0.0 && fmid > 0.0)) {
            a = mid;
        } else {
            b = mid;
        }

    } while (fabs(fmid) > epsilon);

    return mid;
}

int main () {
    printf("x^2-x-1; a = 0; b = 2; epsilon = 0.01\n");
    printf("Resultado: %lf\n", bisect_method(equation1, 0, 2, 0.01));
    printf("--\n");

    printf("e^x-1; a = -1; b = 2; epsilon = 0.001\n");
    printf("Resultado: %lf\n", bisect_method(equation2, -1, 2, 0.001));
    printf("--\n");

    printf("e^x - sen(x) * cos(x); a = -2; b = -1; epsilon = 0.001\n");
    printf("Resultado: %lf\n", bisect_method(equation3, -2, -1, 0.001));
    printf("--\n");
}

