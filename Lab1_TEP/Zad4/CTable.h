
#ifndef LAB1_TEP_CTABLE_H
#define LAB1_TEP_CTABLE_H
#include <iostream>
#include <string>
using namespace std;

class CTable{
public:
    CTable();
    CTable(string sName, int iTableLen);
    CTable(const CTable &pc_other);
    CTable(bool b_has_4_elem);
    ~CTable();

    void vSetName(string s_new_name);
    bool bSetNewSize(int i_new_table_len);
    CTable *pcClone();
    string getSName();
    int getITableLen();
    int* getPiTable();
    void setTableLen(int i_new_table_len);
    void setPiTable(int * pi_new_table);
    void vAdd1AndCopy(CTable **c_Res);

private:
    string s_name;
    int i_table_len;
    int *pi_table;
};

#endif //LAB1_TEP_CTABLE_H;








