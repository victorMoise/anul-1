#include <stdio.h>

struct Nr_complex {
    int re;
    int im;
};

typedef struct Nr_complex NR_CPX;

NR_CPX sum_cpx(NR_CPX x, NR_CPX y) {
    NR_CPX z;
    z.re = x.re + y.re;
    z.im = x.im + y.im;
    return z;
}

NR_CPX sub_cpx(NR_CPX x, NR_CPX y) {
    NR_CPX z;
    z.re = x.re - y.re;
    z.im = x.im - y.im;
    return z;
}


int main() {
    NR_CPX nr1, nr2, sum, diff;
    
    printf("Realul lui x: ");
    scanf("%d", &nr1.re);
    printf("Imaginarul lui x: ");
    scanf("%d", &nr1.im);
    printf("Realul lui y: ");
    scanf("%d", &nr2.re);
    printf("Imaginarul lui y: ");
    scanf("%d", &nr2.im);

    sum = sum_cpx(nr1, nr2);
    printf("x + y = %d + (%di)\n", sum.re, sum.im);
    diff = sub_cpx(nr1, nr2);
    printf("x - y = %d + (%di)\n", diff.re, diff.im);
    diff = sub_cpx(nr2, nr1);
    printf("y - x = %d + (%di)\n", diff.re, diff.im);
    return 0;
}