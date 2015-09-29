#include "poly.hpp"

#include <sstream>
#include <cmath>



int Poly::operator[](int exp) const {
    auto it = m_values.find(exp);
    if(it == m_values.end()) {
        return 0;
    }

    return it->second;
}

int& Poly::operator[](int exp) {
    return m_values[exp];
}


Poly& Poly::operator+=(Poly const& b) {

    for(auto& it: b) {
        this->m_values[it.first] = this->m_values[it.first] + it.second;
    }
   
    return *this;
}

Poly& Poly::operator-=(Poly const& b) {
    for(auto& it: b) {
        this->m_values[it.first] = this->m_values[it.first] - it.second;
    }
   
    return *this;
}

std::istream& operator>>(std::istream& is, Poly& p) {
    std::string token;
    if (!(is >> token)) return is; // Couldn't extract the token?
    std::istringstream iss(token);
    Poly tmp; // A temporary in order to avoid modifying p if an error occurs
    bool fail = false;
    for (int m, exp; iss >> m; tmp[exp] += m) {
        if (iss.get() == 'x' && iss >> exp) continue; // All OK, add to tmp
        fail = true;
        break;
    }
    if (!iss.eof()) fail = true; // Fail if iss >> m failed due to garbage rather than EOF
    if (fail) is.clear((is.rdstate() & ~std::ios::goodbit) | std::ios::failbit); // Set iostate fail
    else p = tmp; // All OK, output the result
    return is;
}

std::ostream& operator<<(std::ostream& os, Poly const& p) {
    //For example, 4x²+2x+7 would be written 4x2+2x1+7x0
    for(auto& it: p) {
        int sign = std::signbit(it.first);
        if(it.first == p.begin()->first) {
            os << ((sign) ? "-": "") << it.second << "x" << it.first;
        } else {
            os << ((sign) ? "-": "+") << it.second << "x" << it.first;
        }
    }
    return os;
}

Poly operator+(Poly const& a, Poly const& b) {
    Poly newPoly;
    for(auto& it: b) {
        newPoly[it.first] = a[it.first] + it.second;
    }
    return newPoly;
}

Poly operator-(Poly const& a, Poly const& b) {
    Poly newPoly = a + -b;
    return newPoly;
}

Poly operator-(Poly const& p) {
    Poly newPoly;
    for(auto& it: p) {
        newPoly[it.first] = -it.second;
    }
    
    return newPoly;
}

bool operator<(Poly const& a, Poly const& b) {
    auto a_it = a.begin();
    auto b_it = b.begin();
    return a_it->first < b_it->first;
}

bool operator==(Poly const& a, Poly const& b){
    auto a_it = a.begin();
    auto b_it = b.begin();
    return a_it->first == b_it->first;
}
bool operator>(Poly const& a, Poly const& b){
    return b < a;
}
bool operator!=(Poly const& a, Poly const& b){
    return !(a == b);
}
