#pragma once;
#include "../../Unuk/Player.h"
#include "../System/Timer.h"
#include "ParticleEmitter.h"

class Spells {
public:
	Spells(void);
	~Spells(void);

	enum {
		FIREBALL,
		ICE
	};

	void CastSpell(Player* player);

private:
	Timer* _timeBetweenCast;

};
