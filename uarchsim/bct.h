#include <cinttypes>
#define BCT_MAX_COUNT 0xff       //Keeping a 4 bit counter for now
class bct{
    int* counters;
    uint64_t get_index(uint64_t pc);
    int num_entries = 0;
    public:
    bct(uint64_t size);
    uint64_t get_count(uint64_t pc, uint64_t bhr);
    bool increment_bc(uint64_t pc, uint64_t bhr);
    bool decrement_bc(uint64_t pc, uint64_t bhr);
};