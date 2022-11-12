#include <iostream>

using std::cout;

double f(double x)
{
    return (x * x); // f(x)
}

int main() {
    double S, S1, h, y, y1, eps = pow(10, -6), N = 10; // Точность eps и N
    int a = 0, b = 10; // границы интегрирования

    S1 = 0;
    do {
        S = S1;
        S1 = 0;
        h = (b - a) / N;
        for (double x = a; x < b; x+=h) { // треугольниками
            y = f(x);
            S1 += h * y;
        }
        N++;
    } while (fabs(S1 - S) > eps);
    cout << S1 << " - Triangles" << "\n";

    S1 = 0;
    do {
        S = S1;
        S1 = 0;
        h = (b - a) / N;
        for (double x = a; x < b; x += h) { // трапециями
            if (x == a) {
                y = f(x);
                continue;
            }
            y1 = f(x);
            S1 += (y + y1) / 2 * h; 
            y = y1;
        }
        N++;
    } while (fabs(S1 - S) > eps);
    cout << S1 << " - Trapezoids" << "\n";

    S1 = 0;
    do {
        S = S1;
        h = (b - a) / N;
        y = 0, y1 = 0;
        for (int i = 1; i < N; i += 2) { // симпсоном
            y += f(a + i * h); 
            y1 += f(a + (i + 1) * h);
        }
        S1 = h / 3 * (f(a) + 4 * y + 2 * y1);
        N *= 2;
    } while (fabs(S1 - S) > eps);
    cout << S1 << " - Simpson" << "\n";
}