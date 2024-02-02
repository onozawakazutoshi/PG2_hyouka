#define _USE_MATH_DEFINES
#include <Novice.h>
#include <math.h>
#include"Player.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "Enemy.h"


const char kWindowTitle[] = "学籍番号";

bool CircleCircle(float x1, float y1, float x2, float y2, float radius1, float radius2) {

	//Novice::ScreenPrintf(0, 0, "%f", sqrtf(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))));
	//Novice::ScreenPrintf(0, 20, "%f", radius1 + radius2);
	if (sqrtf(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))) <= radius1+ radius2) {
		return true;
	}
	else {
		return false;
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	Player* player = new Player(640, 360, 4, 12,true);

	Enemy* enemy[2];

	for (int i = 0;i < 2;i++) {
		if (i < 1)
			enemy[i] = new  EnemyA(100, 300, 4, 0,15,true);
		else
			enemy[i] = new EnemyB(300, 200, 6, 0,12,true);
	}
	int scene = 0;
	int dicount[2] = { 0 };
	int titleGH = Novice::LoadTexture("./title.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		switch (scene)
		{
		case 0:
			Novice::ScreenPrintf(600, 360, "start\nSPASE");
			Novice::DrawSprite(340, 210, titleGH, 1.0f, 1.0f,0.0f, 0xFFFFFFFF);
			for (int i = 0;i < 2;i++) {
				if (i < 1)
					enemy[i] = new  EnemyA(100, 300, 4, 0,15,true);
				else
					enemy[i] = new EnemyB(300, 200, 6, 0,12,true);
			}
			player = new Player(640, 360, 4, 12,true);

			if (keys[DIK_SPACE]) {
				scene = 1;
			}
			break;
		case 1:
		
		///
		/// ↓更新処理ここから
		///
		/// 
		if (player->Getlive()) {
			player->Update(keys);
		}
		for (int i = 0;i < 2;i++) {
			enemy[i]->Update();
		}
		for (int i = 0;i <2;i++) {
			if (enemy[i]->live_) {
				if (CircleCircle(player->GetPosX(), player->GetPosY(), enemy[i]->GetPosX(), enemy[i]->GetPosY(), player->Getradius(), enemy[i]->Getradius())) {
					player->Live();
				}
			}
		}
		for (int i = 0;i < 2;i++) {
			if (CircleCircle(player->Bullet->Getx(), player->Bullet->Gety(), enemy[i]->GetPosX(), enemy[i]->GetPosY(), player->Bullet->Getradius(), enemy[i]->Getradius())) {
				enemy[i]->Live();
			}
		}
		//Novice::ScreenPrintf(0, 40, "%f,%f", player->Bullet->Getx(), player->Bullet->Gety());
		//Novice::ScreenPrintf(0, 60, "%f,%f", player->Bullet->Getradius(), enemy[0]->Getradius());

		if (!player->Getlive()) {
			scene = 2;
		}
	
		if (!enemy[0]->live_) {
			dicount[0]++;
			if (dicount[0] > 300) {
				enemy[0]->live_ = true;
				dicount[0] = 0;
			}
		}
		if (!enemy[1]->live_) {
			dicount[1]++;
			if (dicount[1] > 300) {
				enemy[1]->live_ = true;
				dicount[1] = 0;
			}
		}

		if (!enemy[0]->live_ && !enemy[1]->live_) {
			scene = 3;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		if (player->Getlive()) {
			player->Draw();
		}
		for (int i = 0;i < 2;i++) {
			if (enemy[i]->live_) {
				enemy[i]->Draw();
			}
		}

		
		///
		/// ↑描画処理ここまで
		///
		
		break;
		case 2:
			Novice::ScreenPrintf(600, 360, "restart");

			for (int i = 0;i < 2;i++) {
				if (i < 1)
					enemy[i] = new  EnemyA(100, 300, 4, 0,15, true);
				else
					enemy[i] = new EnemyB(300, 200, 6, 0,12, true);
			}
			player = new Player(640, 360, 4, 12, true);

			if (keys[DIK_SPACE]) {
				scene = 1;
			}
			break;

		case 3:
			Novice::ScreenPrintf(600, 360, "GAME CLEAR\nrestart");

			for (int i = 0;i < 2;i++) {
				if (i < 1)
					enemy[i] = new  EnemyA(100, 300, 4, 0, 15, true);
				else
					enemy[i] = new EnemyB(300, 200, 6, 0, 12, true);
			}
			player = new Player(640, 360, 4, 12, true);

			if (keys[DIK_SPACE]) {
				scene = 1;
			}
			break;

		default:
			break;
		}

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
