#pragma once
#include <Vector2.h>
class Enemy
{
public:

	Vector2 pos;
	int speed;
	float radious;
	static  int  isAlive;

	static  int enemy_number;

	Enemy() {
		enemy_number++;
		pos = { 200,400.0f - enemy_number * 100.0f };
		speed = 5;
		radious = 10;
		isAlive = true;
	};
	~Enemy() { enemy_number--; };
	void Init();
	void Update();
	void Draw();
};

