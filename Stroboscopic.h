#ifndef STROBOSCOPIC_H_INCLUDED
#define STROBOSCOPIC_H_INCLUDED

#include "SEGlobals.h"
#include "SEGame.h"
#include "SEGameObject.h"

class Stroboscopic : public SEGameObject
{
public :
	Stroboscopic(sf::Time decade_time, SEGameObject* parent);
	virtual ~Stroboscopic();
	void update(sf::Time deltaTime) override;

	Uint8 m_alpha;
	sf::Time m_decay_time;
};

#endif // STROBOSCOPIC_H_INCLUDED
