#include "C_Code.h"
void StartArenaDialogue(int, ProcPtr);
void ArenaUi_ResultsDialogue(ProcPtr proc) {
    u32 partyGold = GetPartyGoldAmount();
    switch (ArenaGetResult()) {
        case 1: ///If player unit wins
            if (gActiveUnit->curHP >= (GetUnitMaxHp(gActiveUnit) / 2)) {
				SetTalkNumber(ArenaGetMatchupGoldValue() * 4);
				StartArenaDialogue(0x100, proc);
				SetPartyGoldAmount(partyGold = partyGold + (ArenaGetMatchupGoldValue() * 4));
			} else {
				SetTalkNumber(ArenaGetMatchupGoldValue() * 2);
				StartArenaDialogue(0x8D6, proc);
				SetPartyGoldAmount(partyGold = partyGold + (ArenaGetMatchupGoldValue() * 2));
			}
            break;
        case 2: ///If player unit loses
            StartArenaDialogue(0x8D7, proc);
            break;
        case 3: ///If player unit draws like if weapons break
            StartArenaDialogue(0x8D9, proc);
            SetPartyGoldAmount(partyGold = partyGold + ArenaGetMatchupGoldValue());
            break;
        case 4: ///If player bows out
            StartArenaDialogue(0x8D8, proc);
            break;
    }
    return;
}
