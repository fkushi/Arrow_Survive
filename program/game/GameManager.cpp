#include"GameManager.h"
#include"SceneManager.h"
#include"Create_Stage.h"
#include"IMG_load.h"
#include"DxLib.h"

SceneManager scene;
IMG_load img;
extern Create_Stage	c_st;

GameManager::GameManager() {
	player = nullptr;
}

void GameManager::initialize() {

}

//-------------------------------------------------------------------------------------------------------------
/*関数*/
//-------------------------------------------------------------------------------------------------------------

//------------------------------------------------------
/*画像ハンドルの読み込み*/
//------------------------------------------------------
int GameManager::LoadGraphEx(std::string ghPass)
{
	//ghPassの場所にある画像がmapに登録されているか確認
	auto itr = loadGh.find(ghPass);
	//mapの最後まで検索しなくても一致した場合->すでに読み込んでいる
	if (itr != loadGh.end()) {
		return loadGh[ghPass];
	}
	//読み込んでいなかったら登録して画像ハンドルを返す
	else {
		int gh = LoadGraph(ghPass.c_str());
		//mapにパスと画像ハンドルを登録
		loadGh.insert(std::make_pair(ghPass, gh));
		//画像ハンドルを返す
		return gh;
	}

	return 0;
}

//------------------------------------------------------
/*KEYBOARD*/
//------------------------------------------------------
void GameManager::Control_Keyboard() {
	down_shift = t2k::Input::isKeyDown(t2k::Input::KEYBORD_LSHIFT) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_RSHIFT);
	relese_shift = t2k::Input::isKeyReleaseTrigger(t2k::Input::KEYBORD_LSHIFT) || t2k::Input::isKeyReleaseTrigger(t2k::Input::KEYBORD_RSHIFT);
	down_up = t2k::Input::isKeyDown(t2k::Input::KEYBORD_UP) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_W);
	down_down = t2k::Input::isKeyDown(t2k::Input::KEYBORD_DOWN) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_S);
	down_right = t2k::Input::isKeyDown(t2k::Input::KEYBORD_RIGHT) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_D);
	down_left = t2k::Input::isKeyDown(t2k::Input::KEYBORD_LEFT) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_A);
	trigger_enter = t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_NUMPADENTER);
	trigger_sapce = t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE);
	trigger_left = t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT) || t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_A);
	trigger_right = t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT) || t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_D);
}

//------------------------------------------------------
/*PLAYER*/
//------------------------------------------------------
//PLAYERの描画座標を取得する関数
t2k::Vector3 GameManager::GetPosPlayer() {
	return player->pos;
}
t2k::Vector3 GameManager::GetPos_ChangedPlayer(int pos_x, int pos_y) {
	player->pos.x = static_cast<float>(pos_x);
	player->pos.y = static_cast<float>(pos_y);
	return player->pos;
}
//PLYERの向き、falseは右、tureは左
bool GameManager::GetPla_pla_dir() {
	return player->pla_dir;
}
//shiftを押した時
bool GameManager::GetPla_triger_push_sift() {
	return player->triger_push_sift;
}
//PLAYER_SIZE
int GameManager::GetPlaSize_W() {
	return player->pla_w;
}
int GameManager::GetPlaSize_H() {
	return player->pla_h;

}
//PLAYER_HP
int GameManager::GetPlaHp_now() {
	return player->gezi_now_num;
}

//------------------------------------------------------
/*Arrow*/
//------------------------------------------------------
t2k::Vector3 GameManager::GetArw_preve_Center() {
	for (auto ar_w : arrow_wing) {
		if (ar_w != nullptr) return ar_w->preve_Center;
	}
}
int GameManager::GetArwTyp_arrow_type() {
	for (auto ar_ty : arrow_type)return ar_ty->arrow_type;
	return true;
}
bool GameManager::GetArwWin_sequence_rotate() {
	for (auto aw_w : arrow_wing)return aw_w->sequence_rotate;
	return true;
}

//------------------------------
//Arrowの生成
//------------------------------
void GameManager::createBullet_Player(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed) {
	new Bullet_Player(start, dir, radian, speed, player->pla_dir);
}

//------------------------------
//Arrow_wingの生成
//------------------------------
void GameManager::createArrwo_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed) {
	new Arrow_Wing(start, dir, radian, speed, player->pla_dir);
}

//------------------------------------------------------
/*ENEMY*/
//EnemyBのインスタンスを新規生成
//------------------------------------------------------
void GameManager::createEnemyB(t2k::Vector3 start, int speed) {
	new Enemy_B(start, speed);
}

//------------------------------------------------------
/*STAGE*/
//------------------------------------------------------

//------------------------------
//Stage_Typeの取得関数
//------------------------------
int GameManager::GetCreSt_stage_type() {
	return c_st.stage_type;
}

//------------------------------
//WALLの当たり判定取得
//------------------------------
int GameManager::GetAtachWall() {
	for (auto wal : map_wall) return wal->atach_wal;
	return true;
}

//------------------------------------------------------
/*SCENE*/
//Timerクラスの取得関数
//------------------------------------------------------

//------------------------------
//分カウントの取得関数
//------------------------------
int GameManager::GetTime_M() {
	for (auto t : time)return t->m;
	return true;
}

//------------------------------
//秒カウントの取得関数
//------------------------------
int GameManager::GetTime_S() {
	for (auto t : time)return (int)t->s;
	return true;
}

//------------------------------------------------------
/*OnAtach_Arrow*/
//------------------------------------------------------
int GameManager::GetOnAt_Arw_arrow_type() {
	for (auto at_arw : atach_arrow)return at_arw->arrow_type;
	return 0;
}

//-------------------------------------------------------------------------------------------------------------
/*update,render*/
//-------------------------------------------------------------------------------------------------------------
void GameManager::update(float deltatime) {
	for (auto ba : base)ba->update(deltatime);

	atach.Atach_Pla_Enemy();

	/*シーン*/
	scene.sequence_.update(deltatime);
	/*キーボード*/
	Control_Keyboard();

	std::list<Base*>::iterator it = base.begin();
	while (it != base.end()) {
		if (!(*it)->is_alive) {
			delete(*it);
			it = base.erase(it);
			continue;
		}
		it++;
	}
}
void GameManager::render(float deltatime) {
	/*STAGE*/
	for (auto m_b : map_stageB)m_b->render(deltatime);
	for (auto m_a : map_stageA)m_a->render(deltatime);
	/*WALL*/
	for (auto m_w : map_wall)m_w->render(deltatime);
	/*ENEMY*/
	for (auto p_b : pop_enemyB)p_b->render(deltatime);
	for (auto eb : enemy_B)eb->render(deltatime);
	/*Timer*/
	for (auto t : time)t->render(deltatime);
	/*ARROW*/
	for (auto arw_m : arrow_manager)arw_m->render(deltatime);
	//for (auto ar_ty : arrow_type)ar_ty->render(deltatime);
	for (auto bp : bullet_player)bp->render(deltatime);
	//for (auto ar_wi : arrow_wing)ar_wi->render_arrow(deltatime);
	for (auto at_aw : atach_arrow)at_aw->render(deltatime);
	/*PLAYER*/
	if (player != nullptr)player->render(deltatime);
}

//-------------------------------------------------------------------------------------------------------------
/*Delete_Check*/
//eraceCheck_Base():基底クラスのDELETE、eraceCheck():リスト内のDELETE
//-------------------------------------------------------------------------------------------------------------

void GameManager::eraceCheck_Base() {
	{
		std::list<Base*>::iterator it = base.begin();
		while (it != base.end()) {
			if (!(*it)->is_alive) {
				delete(*it);
				it = base.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Arrow_Base*>::iterator it = arrow_base.begin();
		while (it != arrow_base.end()) {
			if (!(*it)->arrow_alive) {
				delete(*it);
				it = arrow_base.erase(it);
				continue;
			}
			it++;
		}
	}
}

void GameManager::eraceCheck() {
	/*Stage*/
	{
		std::list<map_Wall*>::iterator it = map_wall.begin();
		while (it != map_wall.end()) {
			if (!(*it)->is_alive) {
				it = map_wall.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Timer*>::iterator it = time.begin();
		while (it != time.end()) {
			if (!(*it)->is_alive) {
				it = time.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<map_StageA*>::iterator it = map_stageA.begin();
		while (it != map_stageA.end()) {
			if (!(*it)->is_alive) {
				it = map_stageA.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<map_StageB*>::iterator it = map_stageB.begin();
		while (it != map_stageB.end()) {
			if (!(*it)->is_alive) {
				it = map_stageB.erase(it);
				continue;
			}
			it++;
		}
	}

	//------------------------------------------------------
	/*Arrow*/
	//------------------------------------------------------
	{
		std::list<Arrow_Type*>::iterator it = arrow_type.begin();
		while (it != arrow_type.end()) {
			if (!(*it)->arrow_alive) {
				it = arrow_type.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Bullet_Player*>::iterator it = bullet_player.begin();
		while (it != bullet_player.end()) {
			if (!(*it)->is_alive) {
				it = bullet_player.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Arrow_Wing*>::iterator it = arrow_wing.begin();
		while (it != arrow_wing.end()) {
			if (!(*it)->arrow_alive) {
				it = arrow_wing.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<OnAtach_Arrow*>::iterator it = atach_arrow.begin();
		while (it != atach_arrow.end()) {
			if (!(*it)->is_alive) {
				it = atach_arrow.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Arrow_Manager*>::iterator it = arrow_manager.begin();
		while (it != arrow_manager.end()) {
			if (!(*it)->is_alive) {
				it = arrow_manager.erase(it);
				continue;
			}
			it++;
		}
	}

	//------------------------------------------------------
	/*Enemy*/
	//------------------------------------------------------
	{
		std::list<Pop_EnemyB*>::iterator it = pop_enemyB.begin();
		while (it != pop_enemyB.end()) {
			if (!(*it)->is_alive) {
				it = pop_enemyB.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Enemy_B*>::iterator it = enemy_B.begin();
		while (it != enemy_B.end()) {
			if (!(*it)->is_alive) {
				it = enemy_B.erase(it);
				continue;
			}
			it++;
		}
	}
}