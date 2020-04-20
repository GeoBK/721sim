#include "bct.h"
#include <assert.h>
#include <stdio.h>
bct::bct(uint64_t bct_size){
    uint64_t entry_size = 0;
    for(uint64_t i = BCT_MAX_COUNT; i!=0; i=i>>1)
    {
        entry_size++;
    }
    num_entries = (bct_size*8)/entry_size;      //Multiply by 8 since size should be in bytes    
    counters = new int[num_entries];
}
uint64_t bct::get_index(uint64_t pc){
    uint64_t index = pc>>2;
    index = index % num_entries;
    return index;
}
bool bct::increment_bc(uint64_t pc, uint64_t bhr){
    uint64_t index = get_index(pc);
    counters[index] = (counters[index]+1)&BCT_MAX_COUNT;
    return true;
}

bool bct::decrement_bc(uint64_t pc, uint64_t bhr){
    uint64_t index = get_index(pc);    
    uint64_t test_var = counters[index];
    counters[index] = (counters[index]-1)&BCT_MAX_COUNT;
    if(test_var==0 && counters[index]!=BCT_MAX_COUNT)
    {
        assert("Decrement functionality not working properly. Overflow!!!");
    }
    return true;
}
uint64_t bct::get_count(uint64_t pc, uint64_t bhr)
{
    uint64_t index = get_index(pc);
    return counters[index];
}
