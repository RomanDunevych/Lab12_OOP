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
        throw TriangleException("������� ���������� �� ���� ���i������� ����.");
    }

    double c = sqrt(a * a + b * b);
    if (fabs(a * a + b * b - c * c) > 1e-9) {
        throw TriangleException("��������� �� � �����������.");
    }

    double sinA = a / c;
    double angleA = asin(sinA) * 180.0 / M_PI;
    double angleB = 90.0 - angleA;

    cout << "��� A: " << angleA << " ������i�" << endl;
    cout << "��� B: " << angleB << " ������i�" << endl;
}

void customTerminate() {
    cerr << "���i���� �������! ���������� �������� ����� terminate." << endl;
    abort();
}

void customUnexpected() {
    cerr << "����i������ �������! ���������� �������� ����� unexpected." << endl;
    throw;
}

int main() {
    setlocale(LC_ALL, "UKR");
    set_terminate(customTerminate);
    set_unexpected(customUnexpected);

    try {
        double a, b;
        cout << "����i�� ������� ������ a: ";
        cin >> a;
        cout << "����i�� ������� ������ b: ";
        cin >> b;

        calculateTriangleAngles(a, b);
    }
    catch (const TriangleException& e) {
        cerr << "��������� ������i�: " << e.what() << endl;
    }
    catch (...) {
        cerr << "������� ���i���� ��������� ������i�." << endl;
    }

    return 0;
}
