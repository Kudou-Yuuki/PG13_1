#include "Player.h"

Player::Player() {
	pos = { 600,300 };
	speed = 5;
	radious = 30;

}
Player::~Player() {
	for (int i = 0; i < 20; i++)
	{
		bullet_[i].isShot = false;
	}
}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_D]) {
		pos.x += speed;
	}
	if (keys[DIK_A]) {
		pos.x -= speed;
	}
	if (keys[DIK_W]) {
		pos.y -= speed;
	}
	if (keys[DIK_S]) {
		pos.y += speed;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		for (int i = 0; i < 20; i++)
		{
			if (!bullet_[i].isShot) {

				bullet_[i].isShot = true;
				break;
			}

		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (bullet_[i].isShot) {
			bullet_[i].Update();
		}
		else {
			bullet_[i].pos = pos;
		}
	}

}
void Player::Draw() {
	for (int i = 0; i < 20; i++)
	{
		Novice::DrawEllipse(
			static_cast <int>(pos.x),
			static_cast <int>(pos.y),
			static_cast <int>(radious),
			static_cast <int>(radious),
			0.0f, WHITE, kFillModeSolid);
		bullet_[i].Draw();
	}
}
