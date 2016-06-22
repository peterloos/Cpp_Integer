#define SHORT_VERSION
// #define LONG_VERSION

#ifdef SHORT_VERSION

class Integer
{
private:
    int m_value;

public:
    // c'tors
    Integer ()          { m_value = 0; }
    Integer (int value) { m_value = value; }
    Integer (char* s)   { Parse (s); }

    // unary arithmetic operators
    friend Integer operator+ (const Integer& i)
        { return Integer (i.m_value) ;}
    friend Integer operator- (const Integer& i)
        { return Integer (-i.m_value); }

    // binary arithmetic operators
    friend Integer operator+ (const Integer& i1, const Integer& i2)
        { return Integer (i1.m_value + i2.m_value); }
    friend Integer operator- (const Integer& i1, const Integer& i2)
        { return Integer (i1.m_value - i2.m_value); }
    friend Integer operator* (const Integer& i1, const Integer& i2)
        { return Integer (i1.m_value * i2.m_value);}
    friend Integer operator/ (const Integer& i1, const Integer& i2)
        { return Integer (i1.m_value / i2.m_value); }
    friend Integer operator% (const Integer& i1, const Integer& i2)
        { return Integer (i1.m_value % i2.m_value); }

    // arithmetic-assignment operators
    friend Integer& operator+= (Integer& i1, const Integer& i2)
        { i1.m_value += i2.m_value; return i1; }
    friend Integer& operator-= (Integer& i1, const Integer& i2)
        { i1.m_value -= i2.m_value; return i1; }
    friend Integer& operator*= (Integer& i1, const Integer& i2)
        { i1.m_value *= i2.m_value; return i1; }
    friend Integer& operator/= (Integer& i1, const Integer& i2)
        { i1.m_value /= i2.m_value; return i1; }
    friend Integer& operator%= (Integer& i1, const Integer& i2)
        { i1.m_value %= i2.m_value; return i1; }

    // increment / decrement operators
    friend Integer& operator++ (Integer&);           // prefix increment
    friend const Integer operator++ (Integer&, int); // postfix increment
    friend Integer& operator-- (Integer&);           // prefix decrement
    friend const Integer operator-- (Integer&, int); // postfix decrement

    // comparison operators
    friend bool operator== (const Integer& i1, const Integer& i2)
        { return i1.m_value == i2.m_value; }
    friend bool operator!= (const Integer& i1, const Integer& i2)
        { return i1.m_value != i2.m_value; }
    friend bool operator<  (const Integer& i1, const Integer& i2)
        { return i1.m_value < i2.m_value; }
    friend bool operator<= (const Integer& i1, const Integer& i2)
        { return i1.m_value <= i2.m_value; }
    friend bool operator>  (const Integer& i1, const Integer& i2)
        { return i1.m_value > i2.m_value; }
    friend bool operator>= (const Integer& i1, const Integer& i2)
        { return i1.m_value >= i2.m_value; }

    // conversion operator
    operator int () { return m_value; }
    
    // getter / setter
    int GetValue () { return m_value; }
    void SetValue (int value) { m_value = value; }
    static int MaxValue () { return ~Integer::MinValue (); }
    static int MinValue () { return 1 << (sizeof (int) * 8 - 1); }

    // public methods
    void Parse (char*);
    void ToHexString (char[]);
    void ToBinaryString (char[]);

    // private helper methods
private:
    static void ToUnsignedString (char[], int, int);

    // output
    friend ostream& operator<< (ostream&, const Integer&);
};

#endif


#ifdef LONG_VERSION

class Integer
{
private:
    int m_value;

public:
    // c'tors
    Integer ();
    Integer (int);
    Integer (char*);

    // unary arithmetic operators
    friend Integer operator+ (const Integer&);
    friend Integer operator- (const Integer&);

    // binary arithmetic operators
    friend Integer operator+ (const Integer&, const Integer&);
    friend Integer operator- (const Integer&, const Integer&);
    friend Integer operator* (const Integer&, const Integer&);
    friend Integer operator/ (const Integer&, const Integer&);
    friend Integer operator% (const Integer&, const Integer&);

    // arithmetic-assignment operators
    friend Integer& operator+= (Integer&, const Integer&);
    friend Integer& operator-= (Integer&, const Integer&);
    friend Integer& operator*= (Integer&, const Integer&);
    friend Integer& operator/= (Integer&, const Integer&);
    friend Integer& operator%= (Integer&, const Integer&);

    // increment / decrement operators
    friend Integer& operator++ (Integer&);           // prefix increment
    friend const Integer operator++ (Integer&, int); // postfix increment
    friend Integer& operator-- (Integer&);           // prefix decrement
    friend const Integer operator-- (Integer&, int); // postfix decrement

    // comparison operators
    friend bool operator== (const Integer&, const Integer&);
    friend bool operator!= (const Integer&, const Integer&);
    friend bool operator<  (const Integer&, const Integer&);
    friend bool operator<= (const Integer&, const Integer&);
    friend bool operator>  (const Integer&, const Integer&);
    friend bool operator>= (const Integer&, const Integer&);

    // conversion operator
    operator int ();
    
    // getter / setter
    int GetValue ();
    void SetValue (int);
    static int MaxValue ();
    static int MinValue ();

    // public methods
    void Parse (char*);
    void ToHexString (char[]);
    void ToBinaryString (char[]);

    // private helper methods
private:
    static void ToUnsignedString (char[], int, int);

    // output
    friend ostream& operator<< (ostream&, const Integer&);
};

#endif

