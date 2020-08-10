#include "factorial.h" //includes own header file to help catch errors  
 int fact(int num) { // make sure in and out is +
    int result; //can iniut result in loop doesnt have to be num
     if(num <0)
            return -1;
    for(result = 1; num > 1; num--) {
        result *= num;
    } 
    return result;
}
