#include"GameManager.h"
#include"SceneManager.h"
#include"Create_Stage.h"

SceneManager scene;
extern Create_Stage	c_st;

GameManager::GameManager() {
	pla = nullptr;
}
void GameManager::initialize() {
	
}

//----------------------------------------------------------------------------------------
/*関数*/
//----------------------------------------------------------------------------------------
void GameManager::Control_Keyboard() {
	down_sift = t2k::Input::isKeyDown(t2k::Input::KEYBORD_LSHIFT) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_RSHIFT);
	relese_sift = t2k::Input::isKeyReleaseTrigger(t2k::Input::KEYBORD_LSHIFT) || t2k::Input::isKeyReleaseTrigger(t2k::Input::KEYBORD_RSHIFT);
	down_up = t2k::Input::isKeyDown(t2k::Input::KEYBORD_UP) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_W);
	down_down = t2k::Input::isKeyDown(t2k::Input::KEYBORD_DOWN) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_S);
	down_right = t2k::Input::isKeyDown(t2k::Input::KEYBORD_RIGHT) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_D);
	down_left = t2k::Input::isKeyDown(t2k::Input::KEYBORD_LEFT) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_A);
	triger_enter = t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_NUMPADENTER);
	triger_sapce = t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE);
}

/*PLAYER*/
//PLAYER_POSITION
t2k::Vector3 GameManager::GetPosPlayer() {
	return pla->pos;
}
t2k::Vector3 GameManager::GetPos_ChangedPlayer(int pos_x, int pos_y) {
	pla->pos.x = (float)pos_x;
	pla->pos.y = (float)pos_y;
	return pla->pos;
}
//PLYERの向き、falseは右、tureは左
bool GameManager::GetPla_pla_dir() {
	return pla->pla_dir;
}
//shiftを押した時
bool GameManager::GetPla_triger_push_sift() {
	return pla->triger_push_sift;
}
//PLAYER_SIZE
int GameManager::GetPlaSize_W() {
	return pla->pla_w;
}
int GameManager::GetPlaSize_H() {
	return pla->pla_h;

}
//PLAYER_HP
int GameManager::GetPlaHp_now() {
	return pla->gezi_now_num;
}
//------------------------------------------------------
/*Arrow*/
t2k::Vector3 GameManager::GetArw_preve_Center() {
	for (auto ar_w : arw_win) {
		if (ar_w != nullptr) return ar_w->preve_Center;
	}
}
int GameManager::GetArwTyp_arrow_type() {
	for (auto ar_ty : arw_typ)return ar_ty->arrow_type;
	return true;
}
bool GameManager::GetArwWin_sequence_rotate() {
	for (auto aw_w : arw_win)return aw_w->sequence_rotate;
	return true;
}
void GameManager::createBullet_Player(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed) {
	new Bullet_Player(start, dir, radian, speed, pla->pla_dir);
}
void GameManager::createArrwo_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed) {
	new Arrow_Wing(start, dir, radian, speed, pla->pla_dir);
}
//------------------------------------------------------
/*ENEMY*/
//EnemyB
void GameManager::createEnemyB(t2k::Vector3 start, int speed) {
	new Enemy_B(start, speed);
}
//------------------------------------------------------
/*STAGE*/
//WALL
int GameManager::GetCreSt_stage_type() {
	return c_st.stage_type;
}
int GameManager::GetAtachWall() {
	for (auto wal : m_wal) return wal->atach_wal;
	return true;
}
//------------------------------------------------------
/*SCENE*/
//Timer
int GameManager::GetTime_M() {
	for (auto t : time)return t->m;
	return true;
}
int GameManager::GetTime_S() {
	for (auto t : time)return (int)t->s;
	return true;
}
//------------------------------------------------------
/*OnAtach_Arrow*/
int GameManager::GetOnAt_Arw_arrow_type() {
	for (auto at_arw : atach_arw)return at_arw->arrow_type;
}
//------------------------------------------------------
/*Vector*/
t2k::Vector3 GameManager::FixVector(float pos_x, float pos_y) {
	float sum = sqrt(pos_x * pos_x + pos_y * pos_y);
	float dx = sum/pos_x;
	float dy = sum/pos_y;
}

//----------------------------------------------------------------------------------------
/*update,render*/
//----------------------------------------------------------------------------------------
void GameManager::update(float deltatime) {
	for (auto ba : base)ba->update(deltatime);
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
#if 1
	/*STAGE*/
	for (auto m_b : m_stB)m_b->render(deltatime);
	for (auto m_a : m_stA)m_a->render(deltatime);
	/*WALL*/
	for (auto m_w : m_wal)m_w->render(deltatime);
	/*ENEMY*/
	for (auto p_b : pop_stB)p_b->render(deltatime);
	for (auto eb : enm_B)eb->render(deltatime);
	/*Timer*/
	for (auto t : time)t->render(deltatime);
	/*ARROW*/
	for (auto ar_ty : arw_typ)ar_ty->render(deltatime);
	for (auto bp : blt_pla)bp->render(deltatime);
	for (auto ar_wi : arw_win)ar_wi->render(deltatime);
	for (auto at_aw : atach_arw)at_aw->render(deltatime);
#endif
	/*PLAYER*/
	if(pla != nullptr)pla->render(deltatime);
}
//----------------------------------------------------------------------------------------
/*Delete_Check*/
//----------------------------------------------------------------------------------------
void GameManager::eraceCheck() {
	/*Stage*/
	{
		std::list<map_Wall*>::iterator it = m_wal.begin();
		while (it != m_wal.end()) {
			if (!(*it)->is_alive) {
				it = m_wal.erase(it);
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
		std::list<map_StageA*>::iterator it = m_stA.begin();
		while (it != m_stA.end()) {
			if (!(*it)->is_alive) {
				it = m_stA.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<map_StageB*>::iterator it = m_stB.begin();
		while (it != m_stB.end()) {
			if (!(*it)->is_alive) {
				it = m_stB.erase(it);
				continue;
			}
			it++;
		}
	}
	//------------------------------------------------------
	/*Arrow*/
	{
		std::list<Arrow_Type*>::iterator it = arw_typ.begin();
		while (it != arw_typ.end()) {
			if (!(*it)->is_alive) {
				it = arw_typ.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Bullet_Player*>::iterator it = blt_pla.begin();
		while (it != blt_pla.end()) {
			if (!(*it)->is_alive) {
				it = blt_pla.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Arrow_Wing*>::iterator it = arw_win.begin();
		while (it != arw_win.end()) {
			if (!(*it)->is_alive) {
				it = arw_win.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<OnAtach_Arrow*>::iterator it = atach_arw.begin();
		while (it != atach_arw.end()) {
			if (!(*it)->is_alive) {
				it = atach_arw.erase(it);
				continue;
			}
			it++;
		}
	}
	//------------------------------------------------------
	/*Enemy*/
	{
		std::list<Pop_EnemyB*>::iterator it = pop_stB.begin();
		while (it != pop_stB.end()) {
			if (!(*it)->is_alive) {
				it = pop_stB.erase(it);
				continue;
			}
			it++;
		}
	}
	{
		std::list<Enemy_B*>::iterator it = enm_B.begin();
		while (it != enm_B.end()) {
			if (!(*it)->is_alive) {
				it = enm_B.erase(it);
				continue;
			}
			it++;
		}
	}
}