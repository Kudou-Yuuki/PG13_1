#include "Bullet.h"
#include <corecrt_math.h>

bool Bullet::hit(Vector2 enemypos, float enemyradious) {
	bool result{};

	if (radious + (enemyradious) >=
		sqrtf(powf(pos.x - enemypos.x, 2) + powf(pos.y - enemypos.y, 2))) {
		isShot = false;
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

Bullet::Bullet() {
	pos = {};
	speed = 5;
	radious = 10;
	isShot = true;

}
Bullet::~Bullet() {}

void Bullet::Update() {
	if (isShot) {
		pos.y -= 5;
	}
	if (pos.y <= 0) {
		isShot = false;
	}
}

void Bullet::Draw() {
	if (isShot) {
		Novice::DrawEllipse(
			static_cast <int>(pos.x),
			static_cast <int>(pos.y),
			static_cast <int>(radious),
			static_cast <int>(radious),
			0.0f, RED, kFillModeSolid);
	}
}
