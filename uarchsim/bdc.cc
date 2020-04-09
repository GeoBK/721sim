#include "bdc.h"
set::set(uint64_t assoc){
    diffs = new bdc_node[assoc];
}
bdc::bdc(uint64_t size, uint64_t assoc){
    //Size does not include the tag store, each difference consumes 4 bytes
    associativity = assoc;
    num_entries = size/4;
    num_sets = size/(4*assoc);
    sets = new set*[num_sets];
    for(int i=0;i<num_sets;i++)
    {
        sets[i]=new set(assoc);
    }
}
uint64_t bdc::get_index(uint64_t pc, uint64_t bhr){
    uint64_t index = pc>>2;
    return index % num_sets;
}
uint64_t bdc::get_tag(uint64_t pc, uint64_t bhr){
    uint64_t tag = pc>>2;
    return tag/num_sets;
}
bool bdc::get_difference(uint64_t pc, uint64_t bhr, int32_t* diff)
{    
    bool is_found = false;
    set* target_set = sets[get_index(pc,bhr)];
    for(int i =0;i<associativity;i++){
        if(target_set->diffs[i].is_valid && target_set->diffs[i].tag==get_tag(pc,bhr))
        {
            is_found=true;
            target_set->diffs[i].timestamp= update_count++;
            *diff=target_set->diffs[i].diff;
        }
    }
    return is_found;
}
bool bdc::update_difference(uint64_t pc, uint64_t bhr, int32_t diff){
    update_count++;
    bool is_found = false;
    set* target_set = sets[get_index(pc,bhr)];
    uint64_t target_tag = get_tag(pc,bhr);
    for(int i =0;i<associativity;i++){        
        if(target_set->diffs[i].is_valid && target_set->diffs[i].tag==target_tag)
        {
            is_found=true;
            target_set->diffs[i].diff=diff;
            target_set->diffs[i].timestamp = update_count++;
        }
    }
    uint64_t min_time=0;
    int target_way = 0;
    if(!is_found){
        for(int i=0;i<associativity;i++){
            if(!target_set->diffs[i].is_valid){
                target_way = i;
                break;
            }
            if(target_set->diffs[i].is_valid && target_set->diffs[i].timestamp>min_time)
            {
                target_way = i;                
            }
        }
        target_set->diffs[target_way].is_valid=true;
        target_set->diffs[target_way].diff=diff;
        target_set->diffs[target_way].tag=target_tag;
        target_set->diffs[target_way].timestamp = update_count++;
    }
}