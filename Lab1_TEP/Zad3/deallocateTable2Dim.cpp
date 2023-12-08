#include "deallocateTable2Dim.h"
#include "iostream"

bool bDeallocTable2Dim(int **pi_table, int i_size_X){
    if(pi_table==NULL || i_size_X<=0){
        return false;
    }

    for(int i=0; i<i_size_X; i++){
        delete (pi_table)[i];
    }

    delete pi_table;
    return true;
}