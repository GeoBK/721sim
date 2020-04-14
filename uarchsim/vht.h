#ifndef VHT_H
#define VHT_H
#include <cinttypes>
#include "bct.h"
#include "bdc.h"
class vht{
    bct* _bct;
    bdc* _bdc;
    public:
    vht(uint64_t bct_size, uint64_t bdc_size, uint64_t bdc_assoc,uint64_t rob_size);
    bool get_value(uint64_t pc, uint64_t bhr, uint64_t* value);
    bool increment_os_branch_count(uint64_t pc, uint64_t bhr);
    bool decrement_os_branch_count(uint64_t pc, uint64_t bhr);
    bool update_branch_difference(uint64_t pc, uint64_t bhr, int32_t diff);
    uint64_t rob_size;
    uint64_t get_rob_size();
};
#endif //VHT_H
