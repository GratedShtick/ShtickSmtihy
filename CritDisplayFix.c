#include "C_Code.h"
void ComputeBattleUnitEffectiveCritRate(struct BattleUnit* attacker, struct BattleUnit* defender) {
    int item, i;
    attacker->battleEffectiveCritRate = attacker->battleCritRate - defender->battleDodgeRate;
    if (GetItemIndex(attacker->weapon) == ITEM_MONSTER_STONE) {
        attacker->battleEffectiveCritRate = 0;
	}
    if (attacker->battleEffectiveCritRate < 0) {
        attacker->battleEffectiveCritRate = 0;
	}
	if (attacker->battleEffectiveCritRate > 100) {
		attacker->battleEffectiveCritRate = 100;
	}
    for (i = 0; (i < UNIT_ITEM_COUNT) && (item = defender->unit.items[i]); ++i) {
        if (GetItemAttributes(item) & IA_NEGATE_CRIT) {
            attacker->battleEffectiveCritRate = 0;
            break;
        }
    }
}
