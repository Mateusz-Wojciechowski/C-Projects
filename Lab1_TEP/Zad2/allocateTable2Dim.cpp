#include "iostream"
#include "string"
#include "allocateTable2Dim.h"

bool bAllocTable2Dim(int ***pi_table, int i_size_X, int i_size_Y){

    if(i_size_X<=0 || i_size_Y<=0){
        return false;
    }

    *pi_table = new int *[i_size_X];

    for(int i=0; i<i_size_X; i++){
        (*pi_table)[i] = new int[i_size_Y];
    }

    return true;
}