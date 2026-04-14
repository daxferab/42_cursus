#include <iostream>
#include "include/Array.hpp"
#include <cstdlib>

#define MAX_VAL 20
int main(int, char**)
{
    // ------------- Empty array construction --------------- //
    Array<int>  emptyArray;

    std::cout << "--------- EMPTY ARRAY ---------" << std::endl;
    for (size_t i = 0; i < emptyArray.size(); i++)
        std::cout << emptyArray[i] << std::endl << std::endl;

    // ------------- n = 5 array construction --------------- //

    Array<int>  fiveArray(5);

    std::cout << "-------- 5-SIZED ARRAY --------" << std::endl;
    for (size_t i = 0; i < fiveArray.size(); i++)
        std::cout << fiveArray[i] << " ";
    std::cout << std::endl;
    std::cout << "-> Filling... ->" << std::endl;
    for (size_t i = 0; i < fiveArray.size(); i++)
    {
        fiveArray[i] = i;
        std::cout << fiveArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // --------- Copy and assignement of the 5 array -------- //

    Array<int>  copyFiveArray(fiveArray);
    Array<int>  assignFiveArray(fiveArray);
    std::cout << "Deep copy (copy):" << std::endl;
    for (size_t i = 0; i < copyFiveArray.size(); i++)
        std::cout << copyFiveArray[i] << " ";
    std::cout << std::endl;
    std::cout << "Deep copy (assignment):" << std::endl;
    for (size_t i = 0; i < assignFiveArray.size(); i++)
        std::cout << assignFiveArray[i] << " ";
    std::cout << std::endl << std::endl;

    // --------- Modify copy and assignment arrays ---------- //
    std::cout << "Checking independency:" << std::endl;

    for (size_t i = 0; i < copyFiveArray.size(); i++)
        copyFiveArray[i] *= 10;
    for (size_t i = 0; i < assignFiveArray.size(); i++)
        assignFiveArray[i] *= 5;

    std::cout << "Modified copy array (* 10):" << std::endl;
    for (size_t i = 0; i < copyFiveArray.size(); i++)
        std::cout << copyFiveArray[i] << " ";
    std::cout << std::endl;
    std::cout << "Modified assignement array (* 5):" << std::endl;
    for (size_t i = 0; i < assignFiveArray.size(); i++)
        std::cout << assignFiveArray[i] << " ";
    std::cout << std::endl;

    std::cout << "5-sized array (unmodified):" << std::endl;
    for (size_t i = 0; i < fiveArray.size(); i++)
        std::cout << fiveArray[i] << " ";
    std::cout << std::endl;

    return 0;
}
