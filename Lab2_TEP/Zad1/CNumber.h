
#ifndef LAB2_TEP_CNUMBER_H
#define LAB2_TEP_CNUMBER_H
#include "string"

using namespace std;

class CNumber{
public:
    CNumber();
    CNumber(int i_number);
    CNumber(const CNumber &pc_other);
    ~CNumber();
    void operator=(const int i_value);
    void operator=(const CNumber &pc_other);
    CNumber operator+(const CNumber &pc_other) const;
    CNumber operator-(const CNumber &pc_other) const;
    CNumber operator*(const CNumber &pc_other) const;
    CNumber operator/(const CNumber &pc_other) const;
    CNumber division(const CNumber &pc_other) const;
    CNumber cMod(CNumber &pc_other, CNumber ** pc_div);
    bool operator<=(const CNumber &pc_other) const;
    bool operator<(const CNumber &pc_other) const;
    bool isZero();
    void vRemoveLeadingZeros(CNumber &c_result) const;
    void reverseArray(int* pi_number, int i_len) const;
    int iCalculateNumLen(int i_number);
    void vAssignNewTable(int i_value);
    string sToStr();
    int getLength();
    int *getPiNumber();
private:
    int i_length;
    int *pi_number;
    bool b_is_negative;
    bool b_operation_valid;
};
#endif //LAB2_TEP_CNUMBER_H
