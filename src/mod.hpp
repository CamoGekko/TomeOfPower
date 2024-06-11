#include <modding/functionptr.hpp>

void custom_outputStats(){

}

int initialize(){ // Example

    outputStatsPtr = &custom_outputStats;

    return 0;
} 