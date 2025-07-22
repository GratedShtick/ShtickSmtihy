#include "C_Code.h"
void MakePoisonDamageTargetList(int faction) {
    int i;
    InitTargets(0, 0);
    for (i = faction + 1; i < faction + 0x40; i++) {
        struct Unit* unit = GetUnit(i);
        if (!UNIT_IS_VALID(unit)) {
            continue;
        }
        if (unit->state & (US_DEAD | US_NOT_DEPLOYED | US_RESCUED | US_BIT16)) {
            continue;
        }
        if (unit->statusIndex != UNIT_STATUS_POISON) {
            continue;
        }
        AddTarget(unit->xPos, unit->yPos, unit->index, (GetUnitMaxHp(unit)/5));
    }
    return;
}
void ComputeBattleUnitStatusBonuses(struct BattleUnit* bu) {
    switch (bu->unit.statusIndex) {
    case UNIT_STATUS_ATTACK:
        bu->battleAttack += 10;
        break;
    case UNIT_STATUS_DEFENSE:
        bu->battleDefense += 10;
        break;
    case UNIT_STATUS_CRIT:
        bu->battleCritRate += 10;
        break;
    case UNIT_STATUS_AVOID:
        bu->battleAvoidRate += 10;
        break;
	case UNIT_STATUS_POISON:
		bu->battleAttack -=3;
		if(bu->battleAttack < 0) {
			bu->battleAttack = 0;
		}	
		bu->battleDefense -=3;
		if(bu->battleDefense < 0) {
			bu->battleDefense = 0;
		}
		bu->battleSpeed -=3;
		if(bu->battleSpeed < 0) {
			bu->battleSpeed = 0;
		}
		bu->battleHitRate -=10;
		if(bu->battleHitRate < 0) {
			bu->battleHitRate = 0;
		}
		bu->battleAvoidRate -=10;
		if(bu->battleAvoidRate < 0) {
			bu->battleAvoidRate = 0;
		}
		bu->battleCritRate -=10;
		if(bu->battleCritRate < 0) {
			bu->battleCritRate = 0;
		}
		bu->battleDodgeRate -=10;
		if(bu->battleDodgeRate < 0) {
			bu->battleDodgeRate = 0;
		}		
		break;
    } 
}
