
#include "Zad4/CTable.h"
#include "Zad1/allocateFillTable.h"
#include "Zad2/allocateTable2Dim.h"
#include "Zad3/deallocateTable2Dim.h"
#include <iostream>

void vModTab(CTable *pc_tab, int new_size){
    pc_tab->bSetNewSize(new_size);
}

void vModTab(CTable c_tab, int new_size){
    c_tab.bSetNewSize(new_size);
}

int main() {
//    //Zad 1
//    vAllocTableFill34(10);
//    cout << endl;
//
//    //Zad 2
//    int ** pi_2Dim_table;
//    if(bAllocTable2Dim(&pi_2Dim_table, 10, 5)){
//        cout << "Alloc successful" << endl;
//    }
//
//    //Zad 3
//    if(bDeallocTable2Dim(pi_2Dim_table, 10)){
//        cout << "Dealloc successful" << endl;
//    }
//
//    //Zad 4
//    CTable c_table_param("Michal", 12);
//
//    cout << "Tab length after initialization: " << c_table_param.getITableLen() << endl;
//    cout << endl;
//
//    vModTab(c_table_param, 5); // copying constructor will get called
//    cout << "Tab length after non pointer mod: " << c_table_param.getITableLen() << endl;
//    cout << endl;
//
//    vModTab(&c_table_param, 5);
//    cout << "Tab length after pointer mod: " << c_table_param.getITableLen() << endl;
//
//    CTable *c_table_dynamic = new CTable("Jakub", 15);
//    cout << c_table_dynamic->getSName() << endl;
//    delete c_table_dynamic;
//
//    CTable c_table_static_array[3];
//    CTable *c_table_dynamic_array = new CTable[3];
//    delete [] c_table_dynamic_array;


    CTable c_table_orig(true);
    cout << "c_table_orig table length and table:" << endl;
    cout << c_table_orig.getITableLen() << endl;
    for(int i=0; i<c_table_orig.getITableLen(); i++){
        cout << c_table_orig.getPiTable()[i] << " ";
    }
    cout << endl;

    CTable *pc_copy;
    c_table_orig.vAdd1AndCopy(&pc_copy);

    cout << "pc_copy table after vAdd1AndCopy and length" << endl;
    cout << pc_copy->getITableLen() << endl;
    for(int i=0; i<pc_copy->getITableLen(); i++){
        cout << pc_copy->getPiTable()[i] << " ";
    }
    cout << endl;

    cout << "c_table_orig table length and table after vAdd1AndCopy:" << endl;
    cout << c_table_orig.getITableLen() << endl;
    for(int i=0; i<c_table_orig.getITableLen(); i++){
        cout << c_table_orig.getPiTable()[i] << " ";
    }
    cout << endl;

    delete pc_copy;
}
