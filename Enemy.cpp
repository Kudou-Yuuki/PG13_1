#include "Enemy.h"
#include <Novice.h>

void Enemy::Update() {
	if (isAlive) {
		pos.x -= speed;
	}
	if (radious >= pos.x || pos.x + radious >= 1280) {
		speed *= -1;
	}

}

void Enemy::Draw() {
	if (isAlive) {
		Novice::DrawEllipse(
			static_cast <int>(pos.x),
			static_cast <int>(pos.y),
			static_cast <int>(radious),
			static_cast <int>(radious),
			0.0f, RED, kFillModeSolid);
	}
}
