#include "vht.h"
bool vht::get_value(uint64_t pc, uint64_t bhr, uint64_t* value)
{
    int diff;
    bool hit = _bdc.get_difference(pc, bhr, &diff);
    uint64_t count = _bct.get_count(pc,bhr);
    *value = diff^count;
    return hit;

}
bool vht::increment_os_branch_count(uint64_t pc, uint64_t bhr)
{
    _bct.increment_bc(pc,bhr);
}
bool vht::decrement_os_branch_count(uint64_t pc, uint64_t bhr)
{
    _bct.decrement_bc(pc,bhr);
}
bool vht::update_branch_difference(uint64_t pc, uint64_t bhr, int64_t diff)
{
    _bdc.update_difference(pc,bhr,diff);
}