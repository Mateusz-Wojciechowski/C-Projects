#include <iostream>
#include <string>
#include "CTable.h"
#include "CTable_const.h"

using namespace std;

// non param constructor
CTable::CTable(){
    s_name = s_default_name;
    cout << s_non_param_comm << s_name << endl;
    i_table_len = i_table_default_len;
    pi_table = new int[i_table_len];

    for(int i=0; i<i_table_len; i++){
        pi_table[i] = 0;
    }
}

CTable::CTable(string sName, int iTableLen){
    s_name = sName;
    cout << s_param_comm << s_name << endl;
    i_table_len = iTableLen;
    pi_table = new int[i_table_len];

    for(int i=0; i<i_table_len; i++){
        pi_table[i] = 0;
    }
}

CTable::CTable(const CTable &pc_other){
    s_name = pc_other.s_name + s_copy_suffix;
    i_table_len = pc_other.i_table_len;
    pi_table = new int [i_table_len];

    for(int i=0; i<i_table_len; i++){
        pi_table[i] = pc_other.pi_table[i];
    }

    cout << s_copy_comm <<  s_name << endl;
}

CTable::CTable(bool){
    s_name = s_default_name;
    i_table_len = i_table_default_len_4;
    pi_table = new int[i_table_len];

    for(int i=0; i<i_table_len; i++){
        pi_table[i] = i+1;
    }
}

CTable::~CTable(){
    cout << s_delete_comm << s_name << endl;
    delete pi_table;
}

void CTable::vSetName(string s_new_name){
    s_name = s_new_name;
}

bool CTable::bSetNewSize(int i_new_table_len){
    if(i_new_table_len<0){
        return false;
    }

    int *pi_new_table = new int[i_new_table_len];


    for(int i=0; i< min(i_table_len, i_new_table_len); i++){
        pi_new_table[i] = pi_table[i];
    }

    for(int i=i_table_len; i<i_new_table_len; i++){
        pi_new_table[i] = 0;
    }

    delete pi_table;

    pi_table = pi_new_table;
    i_table_len = i_new_table_len;
    return true;
}

void CTable::vAdd1AndCopy(CTable **c_Res){
    *c_Res = new CTable(s_name, i_table_len+1);
    int *pi_new_table = new int[i_table_len+1];

    for(int i=0; i<i_table_len+1; i++){
        if(i==i_table_len){
            pi_new_table[i] = 1;
        }

        else{
            pi_new_table[i] = pi_table[i];
        }
    }

    delete (**c_Res).pi_table;
    (**c_Res).pi_table = pi_new_table;
}


CTable* CTable::pcClone(){
    return new CTable(*this);
}


string CTable::getSName(){
    return s_name;
}

int CTable::getITableLen(){
    return i_table_len;
}

int* CTable::getPiTable(){
    return pi_table;
}

void CTable::setTableLen(int i_new_table_len){
    i_table_len = i_new_table_len;
}

void CTable::setPiTable(int *pi_new_table) {
    pi_table = pi_new_table;
}

