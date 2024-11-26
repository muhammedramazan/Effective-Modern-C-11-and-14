#include <iostream>

// Orijinal fonksiyon
void f(int) {
    std::cout << "This is f()" << std::endl;
}

// fff için forward declaration
decltype(f) fff; // fff'nin imzası bildiriliyor



int main() {
    f(2);   // Orijinal f() çağrılır
    fff(2); // Yeni tanımlanan fff() çağrılır

    return 0;
}

// fff'nin tanımı
void fff() {
    std::cout << "This is fff()" << std::endl;
}


// fff'nin tanımı
void fff(int) {
    std::cout << "This is fff(int )" << std::endl;
}