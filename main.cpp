#include <iostream>
#include <vector>
#include <bigint.h>

using namespace std;

int main(int argc, char *argv[])
{
    BigInt var(123456789123);
    BigInt var1(2);
    BigInt p = &(var+var1);
    p.print();
    return 0;
}
