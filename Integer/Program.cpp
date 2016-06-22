#include "limits.h"
#include <iostream>
using namespace std;

#include "Integer.h"

void Demonstration01();
void Demonstration02();
void Demonstration03();

void TestingCtors();
void TestingArithmeticOperators();
void TestingArithmeticAssigmentOperators();
void TestingComparisonOperators();
void TestingIncrementOperators();
void TestingConversionOperator();
void TestingGetterSetter();
void TestingParseMethod();
void TestingBinaryStringMethod();
void TestingHexStringMethod();

void main()
{
	// for Web Site:
	 Demonstration01();
	 Demonstration02();
	 Demonstration03();

    // additional test routines
	TestingCtors ();
	TestingArithmeticOperators ();
	TestingArithmeticAssigmentOperators ();
	TestingComparisonOperators ();
	TestingIncrementOperators ();
	TestingConversionOperator ();
	TestingGetterSetter ();
	TestingParseMethod ();
	TestingBinaryStringMethod ();
	TestingHexStringMethod ();

	getchar();
}

void Demonstration01()
{
    Integer Fak, Max, j;

    // begin of demonstration
    Fak = 1;
    Max = 5;

    for (j = 1; j <= Max; j++)
        Fak *= j;

    cout << "Fak(" << Max << ") = " << Fak << endl;
}

void Demonstration02 ()
{
    Integer Fak = 1;
    Integer Max = 5;

    for (Integer j = 1; j <= Max; j++)
        Fak *= j;

    cout << "Fak(" << Max << ") = " << Fak << endl;
}

void Demonstration03 ()
{
    char buf[64];

    Integer i(0);
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = 1;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = -1;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = 127;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;
    
    i = -128;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = 32767;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;
    
    i = -32768;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = 2147483647;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = (-2147483647 - 1);    // minimum *signed* integer value !
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = 1;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = -1;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = 127;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;
    
    i = -128;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = 32767;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = -32768;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = 2147483647;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = (-2147483647 - 1);    // minimum *signed* integer value !
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;
}

void TestingCtors ()
{
    Integer a;
    cout << a << endl;

    Integer b (1);
    cout << b << endl;

    Integer c ("123");
    cout << c << endl;

    Integer d ("XYZ");
    cout << d << endl;
}

void TestingArithmeticOperators ()
{
    Integer a(2), b(3), c;

    c = a + b;
    cout << c << endl;
    c = a - b;
    cout << c << endl;
    c = a * b;
    cout << c << endl;
    c = a / b;
    cout << c << endl;
    c = a % b;
    cout << c << endl;
}

void TestingArithmeticAssigmentOperators ()
{
    Integer a(2), b(3);

    b += a;
    cout << b << endl;
    b -= a;
    cout << b << endl;
    b *= a;
    cout << b << endl;
    b /= a;
    cout << b << endl;
    b %= a;
    cout << b << endl;
}

void TestingIncrementOperators ()
{
    Integer a(1);
    Integer b;

    b = a ++;
    cout << b << endl;

    b = ++ a;
    cout << b << endl;

    b = a --;
    cout << b << endl;

    b = -- a;
    cout << b << endl;
}

void TestingComparisonOperators ()
{
    Integer a(2), b(3);

    cout << (a == b) << endl;
    cout << (a != b) << endl;
    cout << (a < b)  << endl;
    cout << (a <= b) << endl;
    cout << (a > b)  << endl;
    cout << (a >= b) << endl;
}

void TestingConversionOperator ()
{
    Integer a(5);
    int n = a;
    cout << n << endl;
}

void TestingGetterSetter ()
{
    Integer a(1);
    int n = a.GetValue ();
    cout << n << endl;
    a.SetValue (2);
    cout << a << endl;

    cout << "Min: " << Integer::MinValue() << endl;
    cout << "Max: " << Integer::MaxValue() << endl;
}

void TestingParseMethod ()
{
    Integer a;
    a.Parse ("12345");
    cout << a << endl;

    a.Parse ("123!!!");
    cout << a << endl;
}

void TestingBinaryStringMethod ()
{
    char buf[64];

    Integer i(0);
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = 1;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = -1;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = 127;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;
    
    i = -128;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = 32767;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;
    
    i = -32768;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = 2147483647;
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;

    i = (-2147483647 - 1); // minimum *signed* integer value !
    i.ToBinaryString (buf);
    cout << "|" << buf << "|" << endl;
}

void TestingHexStringMethod ()
{
    char buf[64];

    Integer i(0);
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = 1;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = -1;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = 127;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;
    
    i = -128;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = 32767;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = -32768;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = 2147483647;
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;

    i = (-2147483647 - 1); // minimum *signed* integer value !
    i.ToHexString (buf);
    cout << "|" << buf << "|" << endl;
}
