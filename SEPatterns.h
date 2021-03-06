#ifndef SEPATTERNS_H_INCLUDED
#define SEPATTERNS_H_INCLUDED

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <string>
#include "TextUtils.h"
#include "Logger.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

enum PatternType 
{
	NoMovePattern,
	Line_,
	Rectangle_,
	Circle_,
	Oscillator,
	NBVAL_PatternType
};

enum BobbyPatternData
{
	BOBBY_PATTERN_TYPE,//0
	BOBBY_PATTERN_SPEED,//1
	BOBBY_PATTERN_ARG1,//2
	BOBBY_PATTERN_ARG2,//3
	BOBBY_PATTERN_ARG3,//4
};

class PatternBobby
{

public:
	PatternBobby();
	void SetPattern(PatternType pt, float patternSpeed, vector<float> args);
	void StartPattern();
	sf::Vector2f GetOffset(float seconds, bool absolute_coordinate = false);
	static PatternBobby* PatternLoader(vector<string> line_data, int index);

	PatternType m_currentPattern;
	vector<float> m_patternParams;
	float m_patternSpeed;
	float m_patternSpeedInRadian;

private:
	sf::Vector2f ToCartesianCoords(sf::Vector2f polarCoords);
	void ToCartesianCoords(sf::Vector2f* polarCoords);
	void CheckArgSize(size_t expected);

	sf::Vector2i m_direction;
	sf::Vector2f m_curSandboxPosition_cartesian;
	sf::Vector2f m_curSandboxPosition_polar;

	float m_distance_left;
	float m_currTheta;
};


#endif // SEPATTERNS_H_INCLUDED