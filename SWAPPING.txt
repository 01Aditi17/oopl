#include <iostream>
using namespace std;

template <class T>
void swap_value(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    float p, q;
    char a, b;
    
    
    cout << "Enter two integers: ";
    cin >> x >> y;
    swap_value(x, y);
    cout << "Swapped int values: " << x << " " << y << endl;

    
    cout << "Enter two float numbers: ";
    cin >> p >> q;
    swap_value(p, q);
    cout << "Swapped float values: " << p << " " << q << endl;

    
    cout << "Enter two characters: ";
    cin >> a >> b;
    swap_value(a, b);
    cout << "Swapped char values: " << a << " " << b << endl;

    return 0;
}
