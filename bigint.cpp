#include "bigint.h"

BigInt::BigInt()
{
    number.push_back(0);
}

BigInt::BigInt(long long int DecNum)
{
    if(DecNum >= base)
    {
        while(DecNum != 0)
        {
            number.push_back(DecNum % base);
            DecNum /= base;
        }
    }
    else{
        number.push_back(DecNum);
    }
}

BigInt::BigInt(BigInt* another)
{
    /*for(int i = 0; i < another->number.size(); i++)
        cout << another->number[i];
    cout<< endl << "-----------------"<<endl;*/
    this->number = another->number;
}

BigInt::~BigInt()
{

}

void BigInt::print()
{
    for(int i = number.size() - 1; i >= 0; i--)
        cout << number[i];
    return;
}

BigInt& BigInt::operator +(BigInt &toPlus)
{
    static BigInt max =  this->myNumber().size() >= toPlus.myNumber().size() ? *this : toPlus; // костыль
    BigInt min = this->myNumber().size() >= toPlus.myNumber().size() ? toPlus : *this;
    long long int lend = 0;

    for(int i = 0; i < max.myNumber().size(); i++)
    {
        if( (min.myNumber().size() - 1) < i)
            break;
        long long int temp = min.myNumber()[i] + max.myNumber()[i] ;
        if(temp + lend >= this->base){
            max.myNumber()[i] = (temp+lend) % base;
            lend = (temp+lend) / base;
        }
        else{
            max.myNumber()[i] = temp + lend;
            lend = 0;
        }
    }
    return max;
}
