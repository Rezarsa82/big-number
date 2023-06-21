#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <iostream>
#include <string.h>
#include <stdexcept>
#include <vector>

using namespace std;

class BigNumber{
    friend ostream &operator<<(ostream&, const BigNumber&);
    friend istream &operator>>(istream&, BigNumber&);
public:
    explicit BigNumber(string = ""); // constructor
    BigNumber(const BigNumber&); // copy constructor
    BigNumber(const long&); // conversion constructor for long
    BigNumber(const char*); // conversion constructor for string

    void setNumber(string); // setter for bigNumber
    string getNumber() const; // getter for bigNumber
    string getNumberWithoutSign() const;
    void setSign(bool); // sette for sign
    bool getSign() const; // getter for sign
    void setSize(int); // setter for size
    int getSize() const; // getter for size

    BigNumber &incerement(BigNumber&); // helper function
    BigNumber &decrement(BigNumber&); // helper function
    BigNumber &simulation(const BigNumber&); // helper function
    void deleteLeftZeroes(); // helper function
    void changeSign(bool); // helper function
    void findSign(const BigNumber&) ; // helper function

    BigNumber &operator=(const BigNumber&); // assignment operator for BigNumber & BigNumber
    BigNumber &operator=(const long); // assignment operator for BigNumber & long

    bool operator==(const BigNumber&) const; // == operator(1)
    bool operator==(const long) const; // == operator(2)
    bool operator!=(const BigNumber&) const; // != operator(1)
    bool operator!=(const long) const; // != operator(2)

    bool operator<(const BigNumber&) const; // < operator(1)
    bool operator<(const long) const; // < operator(2)
    bool operator<=(const BigNumber&) const; // <= operator(1)
    bool operator<=(const long) const; // <= operator(2)
    bool operator>(const BigNumber&) const; // > operator(1)
    bool operator>(const long) const; // > operator(2)
    bool operator>=(const BigNumber&) const; // >= operator(1)
    bool operator>=(const long) const; // >= operator(2)

    int operator[](const int) const; // subscript operator

    BigNumber &operator++(); // prefix ++
    BigNumber operator++(int); // postfix ++
    BigNumber &operator--(); // prefix --
    BigNumber operator--(int); // postfix --

    BigNumber &operator+=(const BigNumber&); // += operator(1)
    BigNumber &operator+=(const long); // += operator(2)
    BigNumber operator+(const BigNumber&); // + operator(1)
    BigNumber operator+(const long); // + operator(2)

    BigNumber &operator-=(const BigNumber&); // -= operator(1)
    BigNumber &operator-=(const long); // -= operator(2)
    BigNumber operator-(const BigNumber&); // - operator(1)
    BigNumber operator-(const long); // - operator(2)

    BigNumber &operator*=(const BigNumber&); // *= operator(1)
    BigNumber &operator*=(const long); // *= operator(2)
    BigNumber operator*(const BigNumber&); // * operator(1)
    BigNumber operator*(const long); // * operator(2)

    BigNumber &operator%=(const BigNumber&); // %= operator(1)
    BigNumber &operator%=(const long ); // %= operator(2)
    BigNumber operator%(const BigNumber&); // % operator(1)
    BigNumber operator%(const long); // % operator(2)

    void printDremeter() const; // determined print function

    ~BigNumber(); // destructor

private:
    string bigNumber;
    size_t size;
    bool sign; // True for positive numbers and False for nefative numbers
};


#endif //BIGNUMBER_H
