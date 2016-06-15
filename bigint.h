#ifndef BIGINT_H
#define BIGINT_H
#include <vector>
#include <iostream>

using namespace std;

class BigInt
{

public:

    BigInt();
    BigInt(long long int DecNum);
    BigInt(BigInt *another);
    ~BigInt();
    void print();
    vector<int> & myNumber() {return number;}
    BigInt &operator +(BigInt& toPlus);
    vector<int>number;
private:

    static const int base = 1000000;


};

#endif // BIGINT_H
