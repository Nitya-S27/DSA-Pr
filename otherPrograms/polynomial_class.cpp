// 3x1 + 4x2 + 5x3
#include <iostream>
using namespace std;

class Polynomial
{
    int *coefficients;
    int size;
    int degree;

public:
    Polynomial()
    {
        coefficients = new int[5];
        size = 5;
        for (int i = 0; i < size; i++)
        {
            coefficients[i] = 0;
        }
        degree = 0;
    }

    Polynomial(Polynomial const &p)
    {
        this->coefficients = new int[p.size];
        for (int i = 0; i < size; i++)
        {
            this->coefficients[i] = p.coefficients[i];
        }
        this->size = p.size;
        this->degree = p.degree;
    }

    Polynomial operator=(Polynomial const &p)
    {
        this->coefficients = new int[p.size];
        for (int i = 0; i < size; i++)
        {
            this->coefficients[i] = p.coefficients[i];
        }
        this->size = p.size;
    }

    void setCoefficient(int deg, int coeff)
    {
        if (deg > size)
        {
            int *newCoefficientArray = new int[size * 2];
            for (int i = 0; i < size * 2; i++)
            {
                newCoefficientArray[i] = 0;
            }
            for (int i = 0; i < size; i++)
            {
                newCoefficientArray[i] = coefficients[i];
            }
            delete[] coefficients;
            coefficients = newCoefficientArray;
            size *= 2;
        }
        coefficients[deg] = coeff;
        if (deg > degree)
        {
            degree = deg;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (coefficients[i])
            {
                cout << coefficients[i] << "x" << i;
                if (i < degree)
                {
                    cout << " + ";
                }
            }
        }
    }

    void add(Polynomial const &p)
    {
        int maxDegree = max(this->degree, p.degree);
        int capacity = size;
        int *newPolynomial = new int[size];
        for (int i = 0; i < size; i++)
        {
            newPolynomial[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            newPolynomial[i] = this->coefficients[i] + p.coefficients[i];
            degree = i;
        }
        delete[] this->coefficients;
        this->coefficients = newPolynomial;
    }

    Polynomial operator+(Polynomial const &p)
    {
        int maxDegree = max(this->degree, p.degree);
        int capacity = size;
        Polynomial newP;
        newP.size = size;
        newP.degree = maxDegree;
        for (int i = 0; i < size; i++)
        {
            newP.coefficients[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            newP.coefficients[i] = this->coefficients[i] + p.coefficients[i];
        }
        return newP;
    }
};

int main()
{
    Polynomial p1;
    p1.setCoefficient(3, 16);
    p1.setCoefficient(2, 36);
    p1.setCoefficient(1, 43);
    p1.setCoefficient(7, 45);
    p1.setCoefficient(5, 17);
    p1.setCoefficient(8, 76);
    cout << "Polynomial 1 : ";
    p1.display();
    cout << endl;
    Polynomial p2;
    p2.setCoefficient(0, 27);
    p2.setCoefficient(4, 32);
    p2.setCoefficient(1, 20);
    p2.setCoefficient(8, 30);
    p2.setCoefficient(5, 17);
    p2.setCoefficient(9, 10);
    p2.setCoefficient(11, 31);
    cout << "Polynomial 2 : ";
    p2.display();
    p1.add(p2);
    cout << endl
         << "Polynomial after addition : ";
    p1.display();
    Polynomial p3 = p1 + p2;
    cout << endl
         << "Polynomial after addition : ";
    p3.display();
    return 0;
}