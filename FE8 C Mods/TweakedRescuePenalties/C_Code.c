#include "C_Code.h"
inline int GetUnitSkill(struct Unit* unit) {
    u16 item = GetUnitEquippedWeapon(unit);
    if(unit->state & US_RESCUING && GetUnitAid(unit) / UNIT_CON(GetUnit(unit->rescue)) >= 2)
        return unit->skl / 2 + (unit->skl / 4) + GetItemSklBonus(item);
    if (unit->state & US_RESCUING)
        return unit->skl / 2 + GetItemSklBonus(item);
    return unit->skl + GetItemSklBonus(item);
}
inline int GetUnitSpeed(struct Unit* unit) {
    u16 item = GetUnitEquippedWeapon(unit);
    if(unit->state & US_RESCUING && GetUnitAid(unit) / UNIT_CON(GetUnit(unit->rescue)) >= 2)
        return unit->spd / 2 + (unit->spd / 4) + GetItemSklBonus(item);
    if (unit->state & US_RESCUING)
        return unit->spd / 2 + GetItemSpdBonus(item);
    return unit->spd + GetItemSpdBonus(item);
}
