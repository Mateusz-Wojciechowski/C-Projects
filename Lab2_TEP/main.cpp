#include <iostream>
#include "Zad1/CNumber.h"
using namespace std;

int main() {
//    // Zad 1
//    cout << "Zad 1" << endl;
//    CNumber c_num;
//    cout << c_num.getLength() << endl;
//
//    for(int i=0; i<c_num.getLength(); i++){
//        cout << c_num.getPiNumber()[i];
//    }

    // Zad 2
    // jesli uzyjemy kodu w ten sposob bedziemy probowac dealokacji fragmentu pamieci ktory zostal juz zdealokowany
    // wystapi Process finished with exit code -1073740940 (0xC0000374) ktory oznacza STATUS_HEAP_CORRUPTION
//    c_num_0 = 368;
//    c_num_1 = 1567;
//    c_num_0 = c_num_1;

    // Zad 3 - usuniecie destruktora nie otrzymamy bledu, program zakonczy sie z kodem 0,
    // nie bedziemy mieli proby zdealokowania niezaalokowanej pamieci, bedzie jednak wyciek pamieci

    // Zad 4 aby uniknac wyciekow pamieci dealokujemy stara tablice pi_numer
    // dodatkowo zamiast przypisywac wskaznik na ten sam element na strecie robimy kopie

    CNumber c_num_0, c_num_1, c_mod, *pc_div;
    c_num_0 = 21;
    c_num_1 = 4;

    c_mod = c_num_0.cMod(c_num_1, &pc_div);

    cout << "Modulo: " << c_mod.sToStr() << endl;
    cout << "Wynik dzielenia: " << pc_div->sToStr() << endl;
    delete pc_div;
}