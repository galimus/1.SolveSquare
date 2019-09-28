include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF 3
#define EPS 1e-4 /* диапазон  */

void UnitTests(void);

int SolveLinear( double b, double c, double *x1) { /* решает линейное уравнение когда a=0 */
    assert (b!=0);
    assert (c);
    assert (x1 != nullptr);
    *x1= -c / b;
     return 1;

}
int SolveSquare(double a, double b, double c, double *x1, double *x2) { /* функция , которая решает квадратное уравнение */
    assert (a);/* Проверяют входные данные на ошибку */
    assert (b);
    assert (c);

    assert (x1 != nullptr);
    assert (x2 != nullptr);
    assert (x1 != x2);
     if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return INF;
            }
        } else {
           return SolveLinear(b,c,x1);

        }
     }
     double d = b * b - 4 * a * c;
        if (d < 0 && abs(d) > EPS) {
            return 0;
        }
        if (abs(d) < EPS) {
            *x1 = *x2 = -b / (2 * a);
            return 1;
        } else {
            d = sqrt(d);
            *x1 = (-b - d) / (2 * a);
            *x2 = (-b + d) / (2 * a);
            return 2;
        }
    }

    void UnitTests() {
    double x1 = NAN,x2 = NAN;
    assert(SolveSquare(1,-4,4,&x1,&x2)==1);
    assert(x1== 2.0);
    printf("Test 1 Completed\n");
}

int main() {
    UnitTests();

    printf(" Welcome to my program\n");
    printf(" Enter a,b,c:\n");
    
    double a = NAN, b = NAN, c = NAN;
    scanf(" %lg%lg%lg", &a, &b, &c);
    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    switch (nRoots) {
        case 0 :
            printf(" No roots\n");
            break;
        case 1 :
            printf("x=%lg\n", x1);
            break;
        case 2 :
            printf("x1= %lg, x2=%lg\n", x1, x2);
            break;
        case INF :
            printf(" Any number");
            break;
        default: printf ( " main(): ERROR : nRoots = %d\n,nRoots");
    }
    printf( "Thank you for using my program\n ");
    return 0;
}

