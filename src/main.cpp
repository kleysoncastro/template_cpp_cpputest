#include <iostream>

int main(int argc, char const *argv[])
{

    int c = 8;

    auto soma = [c](int a, int b) -> int
    {
        return a + b - c;
    };

    std::cout << "hello cpp " << soma(10, 10) << '\n';
    return 0;
}
