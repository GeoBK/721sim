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
    uint64_t index = (pc^bhr)>>2;       // PC[7:0] xor {GBH[2:5],0000 - Not adding the final zeroes for GBH XOR
    return index % num_sets;
}
uint64_t rep::get_tag(uint64_t pc, uint64_t bhr, uint64_t value)
{
    //Tag = {000, PC[14:8]}   ^   {GBH[6:9],000000}   ^   {BDT, BCT}
    uint64_t shifted_pc = pc/num_sets;
    uint64_t mask = 0xffffffffffffff00;
    uint64_t padded_gbh = bhr&mask;
    return shifted_pc^padded_gbh^value;
}

uint64_t rep::parse_prediction(uint64_t smith_counter){
    return (smith_counter>>1)&1;
}

rep::rep(uint64_t rep_size,uint64_t num_counter, uint64_t assoc){
    num_lines = rep_size/REP_NODE_SIZE;
    num_sets = num_lines/assoc;
    associativity = assoc;
    //TODO do a sanity check to make sure the value in num_counter is a power of 2
    sets = new rep_set*[num_sets];
    for(int i=0; i< num_sets; i++){
        sets[i] = new rep_set(num_counter, assoc);
    }
}

bool rep::get_prediction(uint64_t pc, uint64_t bhr, uint64_t value, bool* prediction){
    int64_t index = get_index(pc,bhr);
    int64_t tag = get_tag(pc,bhr,value);
    rep_set* target_set = sets[index];
    bool is_found = false;
    for(int i=0; i< associativity; i++){
        if(target_set->rep_nodes[i]->is_valid && target_set->rep_nodes[i]->tag==tag){
            uint64_t selector = bhr & (num_counters-1);
            *prediction = (bool)parse_prediction(target_set->rep_nodes[i]->counters[selector]);
            is_found = true;
        }
    }
    return is_found;
}

bool rep::prediction_feedback(bool actual_outcome, uint64_t pc, uint64_t bhr, uint64_t value, bool bp_prediction, bool rep_prediction)
{
    int64_t index = get_index(pc,bhr);
    int64_t tag = get_tag(pc,bhr,value);
    rep_set* target_set = sets[index];
    bool is_found = false;
    for(int i=0; i< associativity; i++){
        if(target_set->rep_nodes[i]->is_valid && target_set->rep_nodes[i]->tag==tag){
            uint64_t selector = bhr & (num_counters-1);
            if(actual_outcome==rep_prediction && actual_outcome!=bp_prediction){
                if(target_set->rep_nodes[i]->replacement_counter<REPLACEMENT_MAX_COUNT){
                    target_set->rep_nodes[i]->replacement_counter+=2;
                    if(target_set->rep_nodes[i]->replacement_counter>=REPLACEMENT_MAX_COUNT)
                    {
                        target_set->rep_nodes[i]->replacement_counter=REPLACEMENT_MAX_COUNT;
                        for(int j=0;j<associativity;j++){
                            if(j!=i){
                                target_set->rep_nodes[i]->replacement_counter>>=1;
                            }
                        }
                    }
                }                
            }
            if(rep_prediction==bp_prediction)
            {
                if(target_set->rep_nodes[i]->replacement_counter>0)                
                {
                    target_set->rep_nodes[i]->replacement_counter-=2;
                    if(target_set->rep_nodes[i]->replacement_counter<=0)
                    {
                        target_set->rep_nodes[i]->replacement_counter=0;
                    }
                }                
            }
            if(actual_outcome){
                target_set->rep_nodes[i]->counters[selector] = increment_count(target_set->rep_nodes[i]->counters[selector]);
            }else{
                target_set->rep_nodes[i]->counters[selector] = decrement_count(target_set->rep_nodes[i]->counters[selector]);
            }
            is_found = true;
        }
    }
    assert(is_found && "If the feedback isnt't able to find the record then there is a problem with my understanding of the working of REP replacement");
    if(!is_found){
        uint64_t target_way = 0;
        uint64_t curr_min_rcount = REPLACEMENT_MAX_COUNT +1;
        bool is_found = false;
        for(int i=0; i< associativity; i++){
            if(!target_set->rep_nodes[i]->is_valid)
            {
                target_way=i;
                break;            
            }
            if(target_set->rep_nodes[i]->is_valid && target_set->rep_nodes[i]->replacement_counter<curr_min_rcount){
                target_way = i;            
            }
        }
        uint64_t selector = bhr & (num_counters-1);
        target_set->rep_nodes[target_way]->counters[selector] = (uint64_t)actual_outcome+(uint64_t)1;
        target_set->rep_nodes[target_way]->is_valid = true;
        target_set->rep_nodes[target_way]->tag = tag;
        target_set->rep_nodes[target_way]->replacement_counter = 0;
    }
    return true;
}
