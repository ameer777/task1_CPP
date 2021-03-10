# include <iostream>
# include <string>
#include "snowman.hpp"
using namespace std;

namespace ariel{
    std::string snowman(int arr){
        int arrayCopy = arr;
        int i = 0;
        while(arrayCopy != 0){
            int m = arrayCopy%10;
            i++;
            if(i > 8){
                throw out_of_range{"the length of the number should be 8!"};
            }
            if (m < 1){
                throw out_of_range{"the nbumer must be more than 0"};
            }
            if(m > 4){
                throw out_of_range{"the nbumer must be less than 4"};
            }
        arrayCopy = arrayCopy / 10;
    }
    if(i < 8){
        throw out_of_range{"the length of the number should be 8!"};
    }
        return "_===_\n(.,.)\n( : )\n( : )";
        
    
}
}