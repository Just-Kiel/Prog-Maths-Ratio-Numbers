#include "../include/side_functions.hpp"

int gcd(int a, int b) // The function runs recursive in nature to return GCD  
{  
    if (b == 0) // if b becomes 0 return a   
        return a;  
    return gcd(b, a % b); // divide to a by b to make smaller number   
       
}  