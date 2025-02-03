#pragma once
#include <Vector2.h>
#include <Novice.h>
class Bullet
{
public:

	bool hit(Vector2 enemypos, float enemyradious);

	Bullet();
	~Bullet();
	void Update();
	void Draw();

	Vector2 pos;
	int speed;
	float radious;
	int isShot;

private:

};


