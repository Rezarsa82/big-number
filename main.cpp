#include <iostream>
#include "BigNumber.h"

using namespace std;

int main() {
    cout << "*************************************Check constructors and (<<, >>) operators*************************************" << endl << endl;

    BigNumber bigNumber1("-1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
    cout << bigNumber1 << endl;

    BigNumber bigNumber2 = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    cout << bigNumber2 << endl;

    BigNumber bigNumber3 = +45455445453;
    cout << bigNumber3 << endl << endl;

    BigNumber bigNumbercopy(bigNumber1);
    cout << bigNumbercopy << endl; // check copy constructor and << operator

    BigNumber bigNumberConLong = -1234567890;
    cout << bigNumberConLong << endl; // check conversion constructor for long

    BigNumber bigNumberConChar = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    cout << bigNumberConChar << endl << endl; // check conversion constructor for char

    BigNumber bigNumbercin;
    cin >> bigNumbercin;
    cout << bigNumbercin << endl;

    cout << "********************************************Check assignments operators********************************************" << endl << endl;

    BigNumber bigNumberAssign = bigNumber1;
    cout << bigNumberAssign << endl;

    long int a = -324238578;
    bigNumberAssign = a;
    cout << bigNumberAssign << endl;

    cout << "*****************************************Check pos/pre ++ and -- operators*****************************************" << endl << endl;

    BigNumber bigNumberTest1("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    ++bigNumberTest1;
    cout << bigNumberTest1 << endl;

    BigNumber bigNumberTemp1 = ++bigNumberTest1;
    cout << bigNumberTemp1 << endl;

    bigNumberTest1++;
    cout << bigNumberTest1 << endl << endl;

    BigNumber bigNumberTest2("-00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
    ++bigNumberTest2;
    cout << bigNumberTest2 << endl;

    BigNumber bigNumberTemp2 = ++bigNumberTest2;
    cout << bigNumberTemp2 << endl;

    bigNumberTest2++;
    cout << bigNumberTest2 << endl << endl;

    BigNumber bigNumberTest3("-00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
    --bigNumberTest3;
    cout << bigNumberTest3 << endl;

    BigNumber bigNumberTemp3 = --bigNumberTest3;
    cout << bigNumberTemp3 << endl;

    bigNumberTemp3--;
    cout << bigNumberTemp3 << endl << endl;

    BigNumber bigNumberTest4("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
    --bigNumberTest4;
    cout << bigNumberTest4 << endl;

    BigNumber bigNumberTemp4 = --bigNumberTest4;
    cout << bigNumberTemp4 << endl;

    bigNumberTest4--;
    cout << bigNumberTest4 << endl << endl;

    cout << "*********************************************Check comparing operators*********************************************" << endl << endl;

    BigNumber bigNumberCompare1("-1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
    BigNumber bigNumberCompare2("-1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
    BigNumber bigNumberCompare3("1415926565535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");

    if(bigNumberCompare1 == bigNumberCompare2)
        cout << "== operator works correctly!" << endl;

    if(bigNumberCompare1 != bigNumberCompare3)
        cout << "!= operator works correctly!" << endl;

    if(bigNumberCompare1 < bigNumberCompare3)
        cout << "< operator work correctly!" << endl;

    if(bigNumberCompare3 > bigNumberCompare2)
        cout << "> operator work correctly!" << endl << endl;

    cout << "*********************************************Check print and subscript*********************************************" << endl << endl;
    bigNumber1.printDremeter();

    cout << bigNumber1[2] << endl;

    cout << "********************************************Check calculation operators********************************************" << endl << endl;

    long c = -466485115;
    BigNumber bigNumberPlus1("-9");
    BigNumber bigNumberPlus2("1");
    bigNumberPlus1 += bigNumberPlus2;
    cout << bigNumberPlus1 << endl;

    BigNumber bigNumberPlus3 = bigNumberPlus1 + bigNumberPlus2;
    cout << bigNumberPlus3 <<  endl;
    cout << bigNumberPlus1 + c << endl;

    BigNumber bigNumberMinus1("9");
    BigNumber bigNumberMinus2("-1");
    bigNumberMinus1 -= bigNumberMinus2;
    cout << bigNumberMinus1 << endl;

    BigNumber bigNumberMinus3 = (bigNumberMinus1 - bigNumberMinus2);
    cout << bigNumberMinus3 << endl;
    cout << bigNumberMinus1 - c << endl;

    BigNumber bigNumberMult1("+63211111111111184111111111111");
    BigNumber bigNumberMult2("15645486468642545454");
    bigNumberMult1 *= bigNumberMult2;
    cout << bigNumberMult1 << endl;

    BigNumber bigNumberMult3 = bigNumberMult1 * bigNumberMult2;
    cout << bigNumberMult3 << endl;
    cout << bigNumberMult1 * c << endl;

    return 0;
}
