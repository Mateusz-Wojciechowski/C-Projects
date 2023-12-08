#include "iostream"
#include "string"
#include "CNumber_const.h"
#include "CNumber.h"
#include "cmath"

using namespace std;
// mozliwe wycieki pamieci przy kopiowaniu obiektow
// okreslic dobrze znak dla dodawania o roznych znakach
// sprawdzic dzielenie przez zero
CNumber::CNumber(){
    pi_number = new int[i_default_len];
    i_length = i_default_len;
    int i_default_number_copy = i_default_number;
    b_is_negative = false;
    b_operation_valid = true;

    for(int i=i_default_len-1; i>=0; i--){
        pi_number[i] = i_default_number_copy % i_default_divider;
        i_default_number_copy /= i_default_divider;
    }
}

CNumber::CNumber(int i_number){
    if(i_number<0){
        b_is_negative = true;
    }
    else{
        b_is_negative = false;
    }

    i_length = iCalculateNumLen(i_number);
    pi_number = new int[i_length];
    b_operation_valid = true;
    int i_number_copy = abs(i_number);

    vAssignNewTable(i_number_copy);
}

CNumber::CNumber(const CNumber &pc_other){
    i_length = pc_other.i_length;
    pi_number = new int[i_length];
    b_is_negative = pc_other.b_is_negative;
    for(int i=0; i<i_length; i++){
        pi_number[i] = pc_other.pi_number[i];
    }
}

CNumber::~CNumber(){
    delete pi_number;
}

void CNumber::operator=(const int i_value){
    i_length = iCalculateNumLen(i_value);
    delete pi_number;

    pi_number = new int[i_length];
    if(i_value<0){
        b_is_negative = true;
    }
    else{
        b_is_negative = false;
    }

    int i_number_copy = abs(i_value);

    vAssignNewTable(i_number_copy);
}

void CNumber::operator=(const CNumber &pc_Other){
    delete pi_number;
    i_length = pc_Other.i_length;
    pi_number = new int[i_length];
    b_is_negative = pc_Other.b_is_negative;

    for(int i=0; i<i_length; i++){
        pi_number[i] = pc_Other.pi_number[i];
    }
}

CNumber CNumber::operator+(const CNumber &pc_other) const{
    CNumber c_result(0);
    delete c_result.pi_number;

    if(b_is_negative == pc_other.b_is_negative){
        int i_new_length = max(i_length, pc_other.i_length) + 1;
        c_result.pi_number = new int[i_new_length]();
        c_result.i_length = i_new_length;
        if(b_is_negative){
            c_result.b_is_negative = true;
        }

        int i_carry = 0;
        for(int i=0; i<i_new_length; i++){
            int i_digit_sum = i_carry;

            if(i<pc_other.i_length){
                i_digit_sum += pc_other.pi_number[pc_other.i_length - i - 1];
            }
            if(i<i_length){
                i_digit_sum += pi_number[i_length - i - 1];
            }

            c_result.pi_number[i_new_length - i - 1] = i_digit_sum % i_default_divider;
            i_carry = i_digit_sum/i_default_divider;
        }
    }

    else{
        int i_new_length = max(i_length, pc_other.i_length);
        c_result.i_length = i_new_length;
        c_result.pi_number = new int[i_new_length]();

        if(b_is_negative){
            CNumber c_this_positive = CNumber(*this);
            c_this_positive.b_is_negative = false;
            c_result = pc_other - c_this_positive;
        }

        else{
            CNumber c_other_positive = CNumber(pc_other);
            c_other_positive.b_is_negative = false;
            c_result = *this - c_other_positive;
        }
    }

    vRemoveLeadingZeros(c_result);

    return c_result;
}

CNumber CNumber::operator-(const CNumber &pc_other) const{
    CNumber c_result(0);
    delete c_result.pi_number;

    if(b_is_negative!=pc_other.b_is_negative){
        int i_new_length = max(i_length, pc_other.i_length)+1;
        c_result.i_length = i_new_length;
        c_result.pi_number = new int[i_new_length]();

        if(b_is_negative){
            CNumber c_this_positive = CNumber(*this);
            c_this_positive.b_is_negative = false;
            c_result = c_this_positive + pc_other;
            c_result.b_is_negative = true;
        }

        else{
            CNumber c_other_positive = CNumber(pc_other);
            c_other_positive.b_is_negative = false;
            c_result = *this + c_other_positive;
            c_result.b_is_negative = false;
        }
    }

    else{
        int i_new_length = max(i_length, pc_other.i_length);
        c_result.i_length = i_new_length;
        c_result.pi_number = new int[i_new_length]();

        CNumber c_num_1 = *this;
        CNumber c_num_2 = pc_other;

        if(!(*this<pc_other) && !(pc_other<*this)){
            return c_result;
        }

        if(b_is_negative){
            if(pc_other<*this){
                c_num_1 = pc_other;
                c_num_2 = *this;
                c_result.b_is_negative = false;
            }

            else{
                c_num_1 = *this;
                c_num_2 = pc_other;
                c_result.b_is_negative = true;
            }
        }

        else if(!b_is_negative){
            if(pc_other<*this){
                c_result.b_is_negative = false;
            }

            else{
                c_result.b_is_negative = true;
                c_num_1 = pc_other;
                c_num_2 = *this;
            }
        }

        int i_borrow = 0;
        for(int i=0; i<i_new_length; i++){
            int i_digit_sub = i_borrow;

            if(i<c_num_1.i_length){
                i_digit_sub += c_num_1.pi_number[c_num_1.i_length - i - 1];
            }

            if(i<c_num_2.i_length){
                i_digit_sub -= c_num_2.pi_number[c_num_2.i_length - i - 1];
            }

            if(i_digit_sub<0){
                i_digit_sub += i_default_divider;
                i_borrow = -1;
            }

            else{
                i_borrow = 0;
            }
            c_result.pi_number[i_new_length - i - 1] = i_digit_sub;
        }
    }
    vRemoveLeadingZeros(c_result);

    return c_result;
}

CNumber CNumber::operator*(const CNumber &pc_other) const {
    int i_new_length = i_length + pc_other.i_length;
    CNumber c_result;
    delete c_result.pi_number;
    c_result.pi_number = new int[i_new_length]();
    c_result.i_length = i_new_length;
    c_result.b_is_negative = (b_is_negative != pc_other.b_is_negative);

    for (int i = 0; i < i_length; ++i) {
        int i_carry = 0;
        for (int j = 0; j < pc_other.i_length || i_carry != 0; ++j) {
            int i_product = c_result.pi_number[i_new_length - i - j - 1] + pi_number[i_length - 1 - i] * (j < pc_other.i_length ? pc_other.pi_number[pc_other.i_length - 1 - j] : 0) + i_carry;
            c_result.pi_number[i_new_length - i - j - 1] = i_product % i_default_divider;
            i_carry = i_product / i_default_divider;
        }
    }

    vRemoveLeadingZeros(c_result);

    return c_result;
}

CNumber CNumber::operator/(const CNumber &pc_other) const {
    if(pc_other.i_length==1 && pc_other.pi_number[0]==0){
        CNumber c_invalid_result(0);
        c_invalid_result.b_operation_valid = false;
        return c_invalid_result;
    }

    CNumber c_result(0);
    delete c_result.pi_number;
    c_result.i_length = max(i_length - pc_other.i_length, 0) + pc_other.i_length;
    c_result.pi_number = new int[c_result.i_length]();

    CNumber divisor = CNumber(*this);
    CNumber divider = CNumber(pc_other);
    divider.b_is_negative = false;
    divisor.b_is_negative = false;

    CNumber c_extra(0);


    for(int i = 0; i<c_result.i_length; i++){
        c_extra = c_extra * i_default_divider;
        c_extra = c_extra + divisor.pi_number[i];

        int counter = 0;
        while(divider<=c_extra){
            c_extra = c_extra - divider;
            counter++;
        }

        c_result.pi_number[i] = counter;
    }

    if(b_is_negative==pc_other.b_is_negative){
        c_result.b_is_negative = false;
    }

    else{
        c_result.b_is_negative = true;
    }

    vRemoveLeadingZeros(c_result);

    return c_result;
}

bool CNumber::operator<=(const CNumber &pc_other) const {
    if(b_is_negative != pc_other.b_is_negative){
        return b_is_negative;
    }

    bool b_both_negative = b_is_negative && pc_other.b_is_negative;

    if(i_length != pc_other.i_length){
        if(i_length > pc_other.i_length){
            return b_both_negative;
        }

        else{
            return !b_both_negative;
        }
    }

    for(int i=0; i<i_length; i++){
        if(pi_number[i]>pc_other.pi_number[i]) {
            return b_both_negative;
        }

        else if(pi_number[i]<pc_other.pi_number[i]){
            return !b_both_negative;
        }
    }

    return true;
}


bool CNumber::operator<(const CNumber &pc_other) const{
    if(b_is_negative != pc_other.b_is_negative){
        return b_is_negative;
    }

    bool b_both_negative = b_is_negative && pc_other.b_is_negative;

    if(i_length != pc_other.i_length){
        if(i_length > pc_other.i_length){
            return b_both_negative;
        }

        else{
            return !b_both_negative;
        }
    }

    for(int i=0; i<i_length; i++){
        if(pi_number[i]>pc_other.pi_number[i]) {
            return b_both_negative;
        }

        else if(pi_number[i]<pc_other.pi_number[i]){
            return !b_both_negative;
        }
    }
    return false;
}

bool CNumber::isZero(){
    for(int i=0; i<i_length; i++){
        if(pi_number[i]!=0){
            return false;
        }
    }
    return true;
}

CNumber CNumber::cMod(CNumber &pc_other, CNumber **pc_div) {
    if(pc_other.i_length==1 && pc_other.pi_number[0]==0){
        CNumber c_invalid_result(0);
        c_invalid_result.b_operation_valid = false;
        return c_invalid_result;
    }


    CNumber c_result(0);
    delete c_result.pi_number;
    c_result.i_length = max(i_length - pc_other.i_length, 0) + pc_other.i_length;
    c_result.pi_number = new int[c_result.i_length]();

    CNumber divisor = CNumber(*this);
    CNumber divider = CNumber(pc_other);
    divider.b_is_negative = false;
    divisor.b_is_negative = false;

    CNumber c_extra(0);

    for(int i = 0; i<c_result.i_length; i++){
        c_extra = c_extra * i_default_divider;
        c_extra = c_extra + divisor.pi_number[i];

        int counter = 0;
        while(divider<=c_extra){
            c_extra = c_extra - divider;
            counter++;
        }

        c_result.pi_number[i] = counter;
    }

    if(b_is_negative==pc_other.b_is_negative){
        c_result.b_is_negative = false;
    }

    else{
        c_result.b_is_negative = true;
    }

    *pc_div = new CNumber();

    **pc_div = c_result;

    CNumber c_mul(0);
    c_mul = c_result * pc_other;

    CNumber c_mod(0);
    c_mod = *this - c_mul;

    vRemoveLeadingZeros(c_mod);
    vRemoveLeadingZeros(**pc_div);

    return c_mod;
}

void CNumber::vRemoveLeadingZeros(CNumber &c_result) const {
    while (c_result.i_length > 1 && c_result.pi_number[0] == 0) {
        for (int i = 0; i < c_result.i_length - 1; i++) {
            c_result.pi_number[i] = c_result.pi_number[i + 1];
        }
        c_result.i_length--;
    }
}

int CNumber::iCalculateNumLen(int i_number){
    int i_number_copy = i_number;
    int i_number_len = 0;

    if(i_number_copy==0){
        return 1;
    }

    while(i_number_copy!=0){
        i_number_copy /= i_default_divider;
        i_number_len++;
    }

    return i_number_len;
}

void CNumber::vAssignNewTable(int i_value){
    for(int i=i_length-1; i>=0; i--){
        pi_number[i] = i_value % i_default_divider;
        i_value /= i_default_divider;
    }
}

string CNumber::sToStr(){
    string s_num_as_text;

    if(b_operation_valid){
        for(int i=0; i<i_length; i++){
            char c_digit = '0' + pi_number[i];
            s_num_as_text += string(1, c_digit);
        }

        if(b_is_negative){
            s_num_as_text = '-' + s_num_as_text;
        }
    }

    else{
        s_num_as_text = s_invalid_op_comm;
    }

    return s_num_as_text;
}

void CNumber::reverseArray(int* pi_number, int i_len) const {
    int temp;
    for (int i = 0; i < i_len / 2; ++i) {
        temp = pi_number[i];
        pi_number[i] = pi_number[i_len - 1 - i];
        pi_number[i_len - 1 - i] = temp;
    }
}

int CNumber::getLength(){
    return i_length;
}

int *CNumber::getPiNumber(){
    return pi_number;
}

