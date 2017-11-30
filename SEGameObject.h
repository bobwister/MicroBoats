#ifndef SEGAMEOBJECT_H_INCLUDED
#define SEGAMEOBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"
#include "AnimatedSprite.hpp"
#include "TextUtils.h"
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "SEGlobals.h"
#include "SFText.h"
#include "Enums.h"
#include "SEPatterns.h"
#include "SEGlobals.h"

using namespace std;
using namespace sf;

class Equipment;
class Weapon;
class Loot;

class SEGameObject : public AnimatedSprite
{
public:
	SEGameObject(sf::Vector2f position, sf::Vector2f speed, std::string textureName, sf::Vector2f size, sf::Vector2f origin, int frameNumber = 1, int animationNumber = 1);
	SEGameObject(sf::Vector2f position, sf::Vector2f speed, std::string textureName, sf::Vector2f size);
	SEGameObject(sf::Vector2f position, sf::Vector2f speed, sf::Texture *texture);
	SEGameObject();

	~SEGameObject();

	virtual void update(sf::Time deltaTime);
	virtual void updateAnimation(sf::Time deltaTime);
	void setAnimationLine(int animation, bool keep_frame_index = false);

	bool m_visible;
	bool m_isOnScene;
	bool m_GarbageMe;
	bool m_DontGarbageMe;
	GameObjectType m_collider_type;
	LayerType m_layer;
	sf::Vector2f m_size;
	std::string m_display_name;

	string getName();
	SEGameObject* Clone();
	void setGhost(bool ghost);
	
	float m_diag;
	bool m_ghost;
	float m_rotation_speed;
	int m_animationNumber;
	int m_frameNumber;
	int m_currentAnimationIndex;
	std::string m_textureName;
	sf::Vector2f m_speed;

	//Utilitary methods
	float GetAbsoluteSpeed();
	static float GetAbsoluteSpeed(sf::Vector2f speed_);
	float GetAbsoluteSpeedSquared();
	static float GetAbsoluteSpeedSquared(sf::Vector2f speed_);
	static sf::Vector2f GetSpeedVectorFromAbsoluteSpeedAndAngle(float absolute_speed, float curAngle);
	void SetSpeedVectorFromAbsoluteSpeedAndAngle(float absolute_speed, float curAngle);

	static bool NormalizeSpeed(sf::Vector2f* vector, float max_value);
	static void ScaleSpeed(sf::Vector2f* vector, float target_value);
	static void AddSpeed(sf::Vector2f* vector, float added_value);
	static float GetAngleRadForSpeed(sf::Vector2f curSpeed);
	static float GetDistanceBetweenObjects(SEGameObject* object1, SEGameObject* object2);
	static float GetDistanceBetweenPositions(sf::Vector2f position1, sf::Vector2f position2);
	static float GetAngleRadBetweenObjects(SEGameObject* ref_object, SEGameObject* object2);
	static float GetAngleRadBetweenPositions(sf::Vector2f ref_position, sf::Vector2f position2);
	static bool IntersectSegments(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y, float *i_x = NULL, float *i_y = NULL);
	static float DistancePointToSement(float p0_x, float p0_y, float p_1x, float p_1y, float p_2x, float p_2y, float *i_x = NULL, float *i_y = NULL);

	static int GetPixelDistanceFromEdge(int pixel_index, int width, int height);
	static void GlowEffect(int blur_radius, sf::Uint8* pixels, int width, int height, int stroke_size = 0);
	static int GaussianBlurDistribution(int x);

	//GAME SPECIFICS - NOT CORE TO THE ENGINE
	int m_money;
	int m_armor;
	int m_armor_max;
	int m_shield;
	int m_shield_max;
	int m_damage;
	int m_shield_regen;
	float m_shield_recovery_time;
	bool m_disable_fire;
	sf::Vector2f m_speed;
	PatternBobby m_Pattern;
	float m_diag;
	bool m_transparent;
	bool m_ghost;
	bool m_wake_up;
	float m_rotation_speed;
	int m_animationNumber;
	int m_frameNumber;
	int m_currentAnimationIndex;
	sf::Time m_collision_timer;
	InteractionType m_isCollidingWithInteractiveObject;
	InteractionType m_previouslyCollidingWithInteractiveObject;
	void addMoney(int loot_value);
	void setMoney(int loot_value);
	virtual void GetDamageFrom(SEGameObject& object);
	virtual void GetDamage(int damage);
	virtual void GetGrazing(sf::Time deltaTime, float hyperspeedMultiplier);
	GameObjectType m_collider_type;
	LayerType m_layer;
	sf::Vector2f m_size;
	bool m_visible;
	bool m_GarbageMe;
	bool m_DontGarbageMe;
	std::string m_textureName;
	bool m_immune;

	virtual void Death();

protected:
	sf::Vector2f m_initial_position;
	Animation m_defaultAnimation;
	Animation* m_currentAnimation;

	virtual void Init(sf::Vector2f position, sf::Vector2f speed, sf::Texture *texture);
	virtual void Init(sf::Vector2f position, sf::Vector2f speed, sf::Texture *texture, int frameNumber, int animationNumber = 1);
	virtual void Init(sf::Vector2f position, sf::Vector2f speed, std::string textureName, sf::Vector2f size, int frameNumber = 1, int animationNumber = 1);
	virtual void Init(sf::Vector2f position, sf::Vector2f speed, std::string textureName, sf::Vector2f size, int frameNumber, int animationNumber, sf::Uint8* pixels);
	
};

#endif // SEGAMEOBJECT_H_INCLUDED