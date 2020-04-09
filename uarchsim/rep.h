#include <cinttypes>
#define REPLACEMENT_MAX_COUNT 0x3f
#define SMITH_COUNTER_MAX 0x3
#define REP_NODE_SIZE 3
class rep_node{
    uint64_t replacement_counter=0;       //should be a 6 bit counter to enable the replacement strategy
    uint64_t tag =0;                       //10 bit tag - we will probably make it bigger
    int * counters;
    public:
    rep_node(uint64_t num_counters);
};
class rep_set{
    rep_node** rep_nodes;
    public:
    rep_set(uint64_t num_counter, uint64_t assoc);
};
class rep{
    uint64_t num_counters;
    rep_set** sets;
    uint64_t num_lines;
    uint64_t num_sets;
    uint64_t increment_count(uint64_t cnt);
    uint64_t decrement_count(uint64_t cnt);
    uint64_t get_index(uint64_t pc, uint64_t bhr);
    public:
    rep(uint64_t rep_size,uint64_t num_counter, uint64_t assoc);
    bool get_prediction(uint64_t pc, uint64_t bhr, uint64_t tag, bool* prediction);
    bool prediction_feedback(bool is_misprediction, uint64_t pc, uint64_t bhr);

};