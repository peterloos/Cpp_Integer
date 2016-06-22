#include <iostream>
using namespace std;

#include "Integer.h"

#ifdef LONG_VERSION
// c'tors
Integer::Integer ()
{
    m_value = 0;
}

Integer::Integer (int n)
{
    m_value = n;
}

Integer::Integer (char* s)
{
    Parse (s);
}

// unary arithmetic operators
Integer operator+ (const Integer& i)
{
    return Integer (i.m_value);
}

Integer operator- (const Integer& i)
{
    return Integer (-i.m_value);
}

// binary arithmetic operators
Integer operator+ (const Integer& i1, const Integer& i2)
{
    return Integer (i1.m_value + i2.m_value);
}

Integer operator- (const Integer& i1, const Integer& i2)
{
    return Integer (i1.m_value - i2.m_value);
}

Integer operator* (const Integer& i1, const Integer& i2)
{
    return Integer (i1.m_value * i2.m_value);
}

Integer operator/ (const Integer& i1, const Integer& i2)
{
    return Integer (i1.m_value / i2.m_value);
}

Integer operator% (const Integer& i1, const Integer& i2)
{
    return Integer (i1.m_value % i2.m_value);
}

// arithmetic-assignment operators
Integer& operator+= (Integer& i1, const Integer& i2)
{
    i1.m_value += i2.m_value;
    return i1;
}

Integer& operator-= (Integer& i1, const Integer& i2)
{
    i1.m_value -= i2.m_value;
    return i1;
}

Integer& operator*= (Integer& i1, const Integer& i2)
{
    i1.m_value *= i2.m_value;
    return i1;
}

Integer& operator/= (Integer& i1, const Integer& i2)
{
    i1.m_value /= i2.m_value;
    return i1;
}

Integer& operator%= (Integer& i1, const Integer& i2)
{
    i1.m_value %= i2.m_value;
    return i1;
}

// comparison operators
bool operator== (const Integer& i1, const Integer& i2)
{
    return i1.m_value == i2.m_value;
}

bool operator!= (const Integer& i1, const Integer& i2)
{
    return !(i1 == i2);
}

bool operator<  (const Integer& i1, const Integer& i2)
{
    return i1.m_value < i2.m_value;
}

bool operator<= (const Integer& i1, const Integer& i2)
{
    return i1.m_value <= i2.m_value;
}

bool operator>  (const Integer& i1, const Integer& i2)
{
    return ! (i1 <= i2);
}

bool operator>= (const Integer& i1, const Integer& i2)
{
    return ! (i1 < i2);
}

// conversion operator
Integer::operator int ()
{
    return m_value;
}

// getter / setter
int Integer::GetValue ()
{
    return m_value;
}

void Integer::SetValue (int value)
{
    m_value = value;
}

int Integer::MaxValue ()
{
    return ~Integer::MinValue ();
}

int Integer::MinValue ()
{
    return 1 << (sizeof (int) * 8 - 1);
}
#endif

#ifdef SHORT_VERSION
#endif

// increment / decrement operators
Integer& operator++ (Integer& i)  // prefix version
{
    i += 1;
    return i;
}

Integer& operator-- (Integer& i)  // prefix version
{
    i -= 1;
    return i;
}

const Integer operator++ (Integer& i, int)  // postfix version
{
    Integer tmp(i);  // construct a copy
    ++ i;            // increment integer
    return tmp;      // return the copy
}

const Integer operator-- (Integer& i, int)  // postfix version
{
    Integer tmp(i);  // construct a copy
    -- i;            // decrement integer
    return tmp;      // return the copy
}

// public methods
void Integer::Parse (char* s)
{
    int len = 0;
    while (s[len] != '\0')
        len ++;

    m_value = 0;
    for (int i = 0; i < len; i ++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            m_value = 0;
            return;
        }

        m_value = 10 * m_value + (s[i] - '0');
    }
}

void Integer::ToHexString (char buf[])
{
    Integer::ToUnsignedString(buf, m_value, 4);
}

void Integer::ToBinaryString (char buf[])
{
    Integer::ToUnsignedString(buf, m_value, 1);
}

// convert an integer to an unsigned number
void Integer::ToUnsignedString (char buf[], int number, int shift)
{
    const int BufSize = 64;
    char tmp[BufSize];

    int mask = (1 << shift) - 1;
    int seperator = 0;

    const int NumDigits = 32 / shift;

    int pos = BufSize;
    for (int i = 0; i < NumDigits; i ++)
    {
        // calculate digit
        int rest = number & mask;
        char ch = (rest < 10) ? '0' + rest : 'A' + (rest - 10);
        pos --;
        tmp[pos] = ch;

        // insert blank
        seperator ++;
        if (seperator % 4 == 0 && i < NumDigits - 1)
        {
            pos --;
            tmp[pos] = ' ';
        }

        number >>= shift;
    }

    // copy result to callers buffer
    for (int i = 0; i < (BufSize - pos); i ++)
        buf[i] = tmp[pos + i];
    buf[BufSize - pos] = 0;
}

// output
ostream& operator<< (ostream& os, const Integer& i)
{
    os << i.m_value;
    return os;
}

