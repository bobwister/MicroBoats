#ifndef SFTEXTPOP_H_INCLUDED
#define SFTEXTPOP_H_INCLUDED

#include "SEGameObject.h"

using namespace sf;

class SFTextPop : public SFText
{
public:
	SFTextPop() {};
	SFTextPop(SFText* text, float distance_not_faded, float distance_faded, float total_pop_time, SEGameObject* target, float offset_positionY);
	~SFTextPop() {};
	void update(Time deltaTime) override;

	float m_distance_not_faded;
	float m_distance_faded;
	float m_total_pop_time;
	sf::Clock m_timer_clock;
	Uint8 m_alpha;
	SEGameObject* m_target;
	float m_offset_positionY;
};

#endif // SFTEXTPOP_H_INCLUDED
