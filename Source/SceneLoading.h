#pragma 

#include "Graphics/Sprite.h"
#include "Scene.h"
#include <thread>


// ローディングシーン
class SceneLoading : public Scene
{
public:
	SceneLoading(Scene* nextScene) : nextScene(nextScene) {}
	~SceneLoading() override {}

	// 初期化
	void Initialize() override;

	// 終了化
	void Finalize() override;

	// 更新処理
	void Update(float elapseTime) override;

	// 描画処理
	void Render() override;

private:
	// ローディングスレッド
	static void LoadingThread(SceneLoading* scene);

private:
	Sprite* sprite = nullptr;
	float angle = 0.0f;

	Scene* nextScene = nullptr;      // 次のシーン
	std::thread* thread = nullptr;   // 裏で動くスレッド

};
