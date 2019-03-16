#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");

    float a, x, y, x0 = 1.3, xk = 54.4, h = 2.2;
    printf("Введите a: ");
    scanf("%f", &a);
    x = x0;
    printf("      X      |      Y      \n"
           "-------------+-------------\n");
    while (x <= xk)
    {
        y = pow((x - 2), 2) / (a - 1.5) + pow(x * x + 1, 1. / 3);
        printf("%12f | %12f\n", x, y);
        x += h;
    }
    printf("\nкoнец");
    return 0;
}
