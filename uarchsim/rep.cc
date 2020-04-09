#include "rep.h"
#include <assert.h>

rep_node::rep_node(uint64_t num_counters){
    counters = new int[num_counters];
    for(int i=0; i<num_counters; i++){
        counters[i]=1;
    }    
}

rep_set::rep_set(uint64_t num_counter, uint64_t assoc){
    rep_nodes = new rep_node*[assoc];
    for(int i=0;i<assoc;i++)
    {
        rep_nodes[i] = new rep_node(num_counter);
    }
}

uint64_t rep::increment_count(uint64_t cnt){
    if(cnt==SMITH_COUNTER_MAX){
        return cnt;
    }
    else{
        assert(cnt>SMITH_COUNTER_MAX && "Something wrong if count value is greater than 3!!");
        return ++cnt;
    }
}
uint64_t rep::decrement_count(uint64_t cnt){
    if(cnt==0){
        return cnt;
    }
    else{
        assert(cnt>SMITH_COUNTER_MAX && "Something wrong if count value is less than 0!!");
        return --cnt;
    }
}
uint64_t rep::get_index(uint64_t pc, uint64_t bhr)
{
    uint64_t index = pc>>2;
    return index % num_sets;
}
uint64_t rep::get_tag(uint64_t pc, uint64_t bhr)
{
    vht.get_value
    return index % num_sets;
}
rep::rep(uint64_t rep_size,uint64_t num_counter, uint64_t assoc){
    num_lines = rep_size/REP_NODE_SIZE;
    num_sets = num_lines/assoc;
    sets = new rep_set*[num_sets];
    for(int i=0; i< num_sets; i++){
        sets[i] = new rep_set(num_counter, assoc);
    }
}

bool rep::get_prediction(uint64_t pc, uint64_t bhr, uint64_t tag, bool* prediction){
    get_index(pc,bhr);
}