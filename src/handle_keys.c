#include "keys.h"

static const keys_t keys_g[NB_KEYS] =
{
	{ sfKeyNum1, 0x1 },
	{ sfKeyNum2, 0x2 },
	{ sfKeyNum3, 0x3 },
	{ sfKeyNum4, 0xC },
	{ sfKeyA, 0x4 },
	{ sfKeyZ, 0x5 },
	{ sfKeyE, 0x6 },
	{ sfKeyR, 0xD },
	{ sfKeyQ, 0x7 },
	{ sfKeyS, 0x8 },
	{ sfKeyD, 0x9 },
	{ sfKeyF, 0xE },
	{ sfKeyW, 0xA },
	{ sfKeyX, 0x0 },
	{ sfKeyC, 0xB },
	{ sfKeyV, 0xF }
};

bool handle_keys(cpu_t *cpu, const sfKeyCode *keyCode, bool value)
{
	for (uint8_t i = 0; i < NB_KEYS ; ++i) {
		if (keys_g[i].keyCode == *keyCode) {
			cpu->keys[keys_g[i].pos] = value;
			return true;
		}
	}
	return false;
}
