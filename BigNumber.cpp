#include "BigNumber.h"

BigNumber::BigNumber(string n){
    setNumber(n);
}

BigNumber::BigNumber(const long &a) {
    string n = to_string(a);
    setNumber(n);
}

BigNumber::BigNumber(const char *n) {
    setNumber(n);
}

BigNumber::BigNumber(const BigNumber &b){
    this->setSize(b.getSize());
    this->setSign(b.getSign());
    this->setNumber(b.getNumber());
}

void BigNumber::setNumber(string n){
    setSize(n.length());
    if(n[0] == '-')
    {
        bigNumber = n;
        setSign(0);
    }
    else
    {
        setSign(1);
        bigNumber = n;
        if(!(bigNumber[0] == '+')) {
            bigNumber.insert(bigNumber.begin(), '+');
            size++;
        }
    }
}

string BigNumber::getNumber() const{
    return bigNumber;
}

string BigNumber::getNumberWithoutSign() const{
    string s = bigNumber;
    s.erase(0, 1);
    return s;
}

void BigNumber::setSign(bool s) {
    sign = s;
}

bool BigNumber::getSign() const{
    return sign;
}

void BigNumber::setSize(int n) {
    size = n;
}

int BigNumber::getSize() const {
    return size;
}

BigNumber &BigNumber::incerement(BigNumber &b)
{
    int i = 1;
    while (i != getSize()) {
        if (b.bigNumber[i] != '9') {
            b.bigNumber[i]++;
            break;
        } else {
            b.bigNumber[i] = '0';
            i++;
        }
    }
    if (i == getSize())
        b.getNumber() = b.getNumber() + "1";
    return *this;
}

BigNumber &BigNumber::decrement(BigNumber &b)
{
    int i = 1;
    while (i != getSize()) {
        if (b.bigNumber[i] != '0') {
            b.bigNumber[i]--;
            break;
        } else {
            b.bigNumber[i] = '9';
            i++;
        }
    }
    if (i == size - 1)
        b.bigNumber.erase(size - 1);
    return *this;
}

BigNumber &BigNumber::simulation(const BigNumber &a) {
    this->bigNumber.append(a.getSize() - this->getSize(), '0');
    this->setSize(a.getSize());
    return *this;
}

void BigNumber::deleteLeftZeroes() {
    int i = getSize() - 1;
    while (bigNumber[i] == '0' || bigNumber[i] == '+' || bigNumber[i] == '-') {
        bigNumber.erase(i);
        --i;
    }
    if(bigNumber == "")
        bigNumber = "0";
}

void BigNumber::changeSign(bool a) {
    if(a == false)
        bigNumber[0] = '-';
    else
        bigNumber[0] = '+';
}

void BigNumber::findSign(const BigNumber &a)  {
    if((this->getSign() == false && a.getSign() == true) || (this->getSign() == true && a.getSign() == false)){
        this->setSign(false);
        this->changeSign(false);
    }
    else if(this->getSign() == false && a.getSign() == false) {
        this->setSign(true);
        this->changeSign(true);
    }
}

BigNumber &BigNumber::operator=(const BigNumber &b){
    this->setSize(b.getSize());
    this->setSign(b.getSign());
    this->setNumber(b.getNumber());
}

BigNumber &BigNumber::operator=(const long a){
    string s = to_string(a);
    setNumber(s);
}

bool BigNumber::operator==(const BigNumber &a) const {
    return this->getNumber() == a.getNumber();
}

bool BigNumber::operator==(const long a) const{
    BigNumber b(to_string(a));
    return *this == b;
}

bool BigNumber::operator!=(const BigNumber &a) const {
    return !(a == *this);
}

bool BigNumber::operator!=(const long a) const {
    BigNumber b(to_string(a));
    return *this != b;
}

bool BigNumber::operator<(const BigNumber &a) const {
    if(this->getSign() != a.getSign()){
        if(this->getSign() == false)
            return true;
        else
            return false;
    }
    int n = this->getSize();
    if(this->getSign() != a.getSign())
        return this->getSize() < a.getSize();
    while(n >= 1) {
        if (this->bigNumber[n] != a.bigNumber[n])
            return this->bigNumber[n] < a.bigNumber[n];
        n--;
    }
    return false;
}

bool BigNumber::operator<(const long a) const {
    BigNumber b(to_string(a));
    return *this < b;
}

bool BigNumber::operator<=(const BigNumber &a) const {
    return !(*this > a);
}

bool BigNumber::operator<=(const long a) const {
    BigNumber b(to_string(a));
    return *this <= b;
}

bool BigNumber::operator>(const BigNumber &a) const {
    return a < *this;
}

bool BigNumber::operator>(const long a) const {
    BigNumber b(to_string(a));
    return *this > b;
}

bool BigNumber::operator>=(const BigNumber &a) const {
    return !(*this < a);
}

bool BigNumber::operator>=(const long a) const {
    BigNumber b(to_string(a));
    return *this >= b;
}

int BigNumber::operator[](const int n) const {
    if(getSize() <= n || n < 0)
        throw out_of_range("ERORR!");
    else
        return bigNumber[n] - '0'; // convert char to int
}

BigNumber &BigNumber::operator++(){
    if(!(this->getSign()))
        decrement(*this);
    else
        return incerement(*this);
}

BigNumber BigNumber::operator++(int a){
    if(!(this->getSign()))
        return decrement(*this);
    else
        return incerement(*this);
}

BigNumber &BigNumber::operator--(){
    if(!(this->getSign()))
        return incerement(*this);
    else
        return decrement(*this);
}

BigNumber BigNumber::operator--(int a){
    if(!(this->getSign()))
        return incerement(*this);
    else
        return decrement(*this);
}

BigNumber &BigNumber::operator+=(const BigNumber &a) {
    if(this->getSign() != a.getSign()){
        if(this->getSign() == false){
            this->setSign(true);
            return (*this -= a);
        }
        else{
            this->setSign(false);
            return (*this -= a);
        }
    }
    int sum = 0;
    BigNumber b = a;
    if(b.getSize() > this->getSize())
        *this = this->simulation(b);
    if(b.getSize() < this->getSize())
        b = b.simulation(*this);
    for (int i = 1; i < this->getSize(); ++i) {
        sum += (this->bigNumber[i] - '0' + b.bigNumber[i] - '0');
        this->bigNumber[i] = (sum % 10) + '0';
        sum /= 10;
    }
    if(sum != 0) {
        string str = to_string(sum);
        this->bigNumber.append(str);
    }
    return *this;
}

BigNumber &BigNumber::operator+=(const long a){
    throw invalid_argument("Can not do this!");
}

BigNumber BigNumber::operator+(const BigNumber &b) {
    BigNumber temp;
    temp = *this;
    temp += b;
    return temp;
}

BigNumber BigNumber::operator+(const long a) {
    BigNumber helepr = a, temp;
    temp = *this + helepr;
    return temp;
}

BigNumber &BigNumber::operator-=(const BigNumber &b) {
    BigNumber a = b;
    if(this->getSign() != a.getSign()){
        if(this->getSign() == false){
            a.setSign(false);
            return (*this += a);
        }
        else{
            a.setSign(true);
            return (*this += a);
        }
    }
    int n = this->getSize();
    int t = 0, s;
    if (a.getSize() < this->getSize())
        a.simulation(*this);
    for (int i = 1; i < n; i++) {
        if (i < n)
            s = this->bigNumber[i] - a.bigNumber[i] + t;
        else
            s = this->bigNumber[i] + t;
        if (s < 0)
            s += 10, t = -1;
        else
            t = 0;
        this->bigNumber[i] = s + '0';
    }
    while (n > 1 && a.bigNumber[n - 1] == 0) {
        this->bigNumber.pop_back(),
                n--;
    }
    this->deleteLeftZeroes();
    return *this;
}

BigNumber &BigNumber::operator-=(const long a) {
    throw invalid_argument("Can not do this!");
}

BigNumber BigNumber::operator-(const BigNumber &a) {
    BigNumber temp;
    temp = *this;
    temp -= a;
    return temp;
}

BigNumber BigNumber::operator-(const long a) {
    BigNumber helepr = a, temp;
    temp = *this - helepr;
    return temp;
}

BigNumber &BigNumber::operator*=(const BigNumber &a) {
    if(a.getSize() <= 1 || this->getSize() <= 1)
        this->bigNumber = "0";
    int n = this->getSize(), m = a.getSize();
    vector<int> v(n + m, 0);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++){
            v[i + j - 1] += ((this->bigNumber[i] - '0' ) * (a.bigNumber[j] - '0'));
        }
    n += m;
    this->bigNumber.resize(v.size());
    for (int s, i = 1, t = 0; i < n; i++){
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        this->bigNumber[i] = v[i] + '0' ;
    }
    for (int i = n - 1; i >= 1 && !v[i]; i--)
        this->bigNumber.pop_back();
    this->findSign(a);
    return *this;
}

BigNumber &BigNumber::operator*=(const long a) {
    throw invalid_argument("Can not do this!");
}

BigNumber BigNumber::operator*(const BigNumber &a) {
    BigNumber temp;
    temp = *this;
    temp += a;
    return temp;
}

BigNumber BigNumber::operator*(const long a) {
    BigNumber helepr = a, temp;
    temp = *this * helepr;
    return temp;
}

BigNumber &BigNumber::operator%=(const BigNumber &a) {
    BigNumber first(this->getNumberWithoutSign());
    BigNumber second(a.getNumberWithoutSign());
    if(first == second)
        *this = 0;
    if(first > second)
        while(this->getNumberWithoutSign() < a.getNumberWithoutSign())
            *this -= second;
    return *this;
}

BigNumber &BigNumber::operator%=(const long a) {
    throw invalid_argument("Can not do this!");
}

BigNumber BigNumber::operator%(const BigNumber &a) {
    BigNumber temp;
    temp = *this;
    temp %= a;
    return temp;
}

BigNumber BigNumber::operator%(const long a) {
    BigNumber helepr = a, temp;
    temp = *this % helepr;
    return temp;
}

void BigNumber::printDremeter() const {
    cout << this->bigNumber[0];
    int i = 1;
    while (i < getSize()){
        cout << this->bigNumber[i];
        if(i % 3 == 0 && i != size - 1)
            cout << ",";
        i++;
    }
    cout << endl;
}

ostream &operator<<(ostream &out_put, const BigNumber &b){
    out_put << b.getNumber();
    return out_put;
}

istream &operator>>(istream &in_put, BigNumber &b){
    string s;
    in_put >> s;
    b.setSize(s.size());
    b.setNumber(s);
    return in_put;
}

BigNumber::~BigNumber(){}