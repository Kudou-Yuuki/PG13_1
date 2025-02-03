#pragma once

#include "Bullet.h"

class Player
{
public:


	Vector2 pos;
	int speed;
	float radious;

	Bullet bullet_[20];

	Player();
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
private:

};
