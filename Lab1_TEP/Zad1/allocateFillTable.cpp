#include "iostream"
#include "allocateFillTable_const.h"
#include "allocateFillTable.h"
using namespace std;

void vAllocTableFill34(int i_table_size){
    if(i_table_size>0){
        int *i_table;
        i_table = new int[i_table_size];

        for(int i=0; i<i_table_size; i++){
            i_table[i] = i_table_value;
        }

        for(int i=0; i<i_table_size; i++){
            cout << i_table[i] << s_comma_space;
        }

        delete i_table;
    }

    else{
        cout << s_wrong_size_comm << endl;
    }
}
