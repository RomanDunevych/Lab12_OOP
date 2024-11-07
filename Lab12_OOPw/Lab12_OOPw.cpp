#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

#define M_PI 3.14159265358979323846 

class TriangleException : public exception {
private:
    string message;
public:
    TriangleException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void calculateTriangleAngles(double a, double b) {
    if (a == 0 || b == 0) {
        throw TriangleException("Сторона трикутника не може дорiвнювати нулю.");
    }

    double c = sqrt(a * a + b * b);
    if (fabs(a * a + b * b - c * c) > 1e-9) {
        throw TriangleException("Трикутник не є прямокутним.");
    }

    double sinA = a / c;
    double angleA = asin(sinA) * 180.0 / M_PI;
    double angleB = 90.0 - angleA;

    cout << "Кут A: " << angleA << " градусiв" << endl;
    cout << "Кут B: " << angleB << " градусiв" << endl;
}

void customTerminate() {
    cerr << "Невiдома помилка! Завершення програми через terminate." << endl;
    abort();
}

void customUnexpected() {
    cerr << "Неочiкувана помилка! Завершення програми через unexpected." << endl;
    throw;
}

int main() {
    setlocale(LC_ALL, "UKR");
    set_terminate(customTerminate);
    set_unexpected(customUnexpected);

    try {
        double a, b;
        cout << "Введiть довжину катета a: ";
        cin >> a;
        cout << "Введiть довжину катета b: ";
        cin >> b;

        calculateTriangleAngles(a, b);
    }
    catch (const TriangleException& e) {
        cerr << "Виняткова ситуацiя: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Сталася невiдома виняткова ситуацiя." << endl;
    }

    return 0;
}
