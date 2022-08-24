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

double secant_method (double (*fn) (double), double a, double b, double epsilon) {
  double fa, fb, c, fc;
  int i = 0;

  do {
    i++;
    fa = fn(a);
    fb = fn(b);
    c = b - (b - a) * fb / (fb-fa);
    fc = fn(c);

    printf("I: %-3d | a: %-10lf | fa: %-10lf | b: %-10lf | fb: %-10lf | c: %-10lf | fc: %-10lf |\n", i, a, fa, b, fb, c, fc);

    a = b;
    b = c;
  } while (fabs(fc) > epsilon);

  return c;
}

int main () {
    printf("x^2-x-1; a = 0; b = 2; epsilon = 0.01\n");
    printf("Resultado: %lf\n", secant_method(equation1, 0, 2, 0.01));
    printf("--\n");

    printf("e^x-1; a = -1; b = 2; epsilon = 0.01\n");
    printf("Resultado: %lf\n", secant_method(equation2, -1, 2, 0.01));
    printf("--\n");

    printf("e^x - sen(x) * cos(x); a = -2; b = -1; epsilon = 0.01\n");
    printf("Resultado: %lf\n", secant_method(equation3, -2, -1, 0.01));
    printf("--\n");
}