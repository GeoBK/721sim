#include <cinttypes>
class bdc_node{
    
    public:
    uint64_t    tag=0;
    int32_t     diff=0;
    bool        is_valid= false;
    uint64_t    timestamp;
};
class set{
    public:
    bdc_node* diffs;
    set(uint64_t assoc);
};
class bdc{    
    set**    sets;
    uint64_t num_sets;
    uint64_t num_entries;  
    uint64_t associativity;  
    uint64_t get_index(uint64_t pc, uint64_t bhr);
    uint64_t get_tag(uint64_t pc, uint64_t bhr);
    public:
    bdc(uint64_t bdc_size, uint64_t assoc);
    bool get_difference(uint64_t pc, uint64_t bhr, int32_t* diff);
    bool update_difference(uint64_t pc, uint64_t bhr, int32_t diff);
};