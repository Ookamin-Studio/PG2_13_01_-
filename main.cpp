#include <Novice.h>
#include"Enemy.h"
#include"player.h"

bool Enemy::allAlive=true;

//当たり判定用関数
bool CheckDistance(Vector2 c1, int r1, Vector2 c2, int r2) {
	int dx = c2.x - c1.x;
	int dy = c2.y - c1.y;
	int radiusSum = r1 + r2;

	int distanceSquared=dx * dx + dy * dy;
	int radiusSumSq = radiusSum * radiusSum;
	if (radiusSumSq < distanceSquared) {
		return false;
	}
	else {
		return true;
	}
}

const char kWindowTitle[] = "GC1A_03_ジョ_シュウゴウ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//宣言
	Enemy* enemyA = new Enemy({ 100, 100 }, 5, 0);
	Enemy* enemyB = new Enemy({ 300, 300 }, -5, 0);
	Player* player = new Player();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

#pragma region 更新
		enemyA->Update();
		enemyB->Update();
		player->Update(keys, preKeys);
		//当たり判定
		if (CheckDistance(enemyA->pos_, enemyA->radius_, player->bullet_->pos_, player->bullet_->radius_)||
			CheckDistance(enemyB->pos_, enemyB->radius_, player->bullet_->pos_, player->bullet_->radius_)) {
			enemyA->allAlive=false;
		}
		//リスポーン
		if (Novice::CheckHitKey(DIK_R)) {
			enemyA->allAlive = true;
		}
#pragma endregion


#pragma region 描画
		enemyA->Draw();
		enemyB->Draw();
		player->Draw();
		Novice::ScreenPrintf(10, 10, "Enemy A isAlive: %d", enemyA->allAlive);
		Novice::ScreenPrintf(10, 30, "Enemy B isAlive: %d", enemyB->allAlive);
#pragma endregion

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	delete enemyA;
	delete enemyB;
	delete player;
	Novice::Finalize();
	return 0;
}
