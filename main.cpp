#include <Novice.h>
#include "Player.h"
#include <Enemy.h>

const char kWindowTitle[] = "LC1A_04_クドウユウキ_pg13-1";

int Enemy::enemy_number;
int Enemy::isAlive;


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Player* player = new Player;

	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;


	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys, preKeys);
		for (int i = 0; i < 20; i++) {
			if (player->bullet_[i].hit(enemy1->pos, enemy1->radious)) {

				Enemy::isAlive = false;
			}
			if (player->bullet_[i].hit(enemy2->pos, enemy2->radious)) {

				Enemy::isAlive = false;
			}
		}

		enemy1->Update();
		enemy2->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		enemy1->Draw();
		enemy2->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了

		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
