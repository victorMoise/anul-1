#include <stdio.h>

struct Timp {
    int ora;
    int minut;
    int secunda;
};

typedef struct Timp TIMP;

TIMP add_time(TIMP x, TIMP y) {
    TIMP z;
    z.secunda = x.secunda + y.secunda;
    z.minut = x.minut + y.minut;
    z.ora = x.ora + y.ora;
    z.minut += z.secunda / 60;
    z.ora += z.minut / 60;
    z.secunda = z.secunda % 60;
    z.minut = z.minut % 60;
    z.ora = z.ora % 24;
    return z;
}

int main() {
    TIMP data1, data2, res;

    printf("Pentru data1:\n");
    printf("Ora: ");
    scanf("%d", &data1.ora);
    printf("Minut: ");
    scanf("%d", &data1.minut);
    printf("Secunda: ");
    scanf("%d", &data1.secunda);
    printf("Pentru data2:\n");
    printf("Ora: ");
    scanf("%d", &data2.ora);
    printf("Minut: ");
    scanf("%d", &data2.minut);
    printf("Secunda: ");
    scanf("%d", &data2.secunda);

    res = add_time(data1, data2);

    printf("Ora rezultata dupa adunare: %d:%d:%d\n", res.ora, res.minut, res.secunda);
    return 0;
}