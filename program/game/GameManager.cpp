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

//------------------------------------------------------
/*PLAYER*/
//------------------------------------------------------
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
//PLAYER_BULLET
void GameManager::createBullet_Player(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed) {
	new Bullet_Player(start, dir, radian, speed, pla->pla_dir);
}

//------------------------------------------------------
/*ENEMY*/
//------------------------------------------------------
//EnemyB
void GameManager::createEnemyB(t2k::Vector3 start, int speed) {
	new Enemy_B(start, speed);
}

//------------------------------------------------------
/*STAGE*/
//------------------------------------------------------
//WALL
int GameManager::GetAtachWall() {
	for (auto wal : m_wal) return wal->atach_wal;
	return true;
}
/*BASE*/
int GameManager::GetBase_Changetype(int back_type) {
	for (auto ba : base) ba->stage_type = back_type;
	return true;
}
int GameManager::GetBase_Backtype() {
	for (auto ba : base) return ba->stage_type;
	return true;
}

//------------------------------------------------------
/*SCENE*/
//------------------------------------------------------
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
/*Vector*/
//------------------------------------------------------
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
	for (auto bp : blt_pla)bp->render(deltatime);
	for (auto at_aw : atach_arw)at_aw->render(deltatime);
#endif
	/*PLAYER*/
	if(pla != nullptr)pla->render(deltatime);
}
//----------------------------------------------------------------------------------------
/*Delete_Check*/
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
	//-----------------------------------------------------------------------------------------------
	/*Arrow*/
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
		std::list<OnAtach_Arrow*>::iterator it = atach_arw.begin();
		while (it != atach_arw.end()) {
			if (!(*it)->is_alive) {
				it = atach_arw.erase(it);
				continue;
			}
			it++;
		}
	}
	//-----------------------------------------------------------------------------------------------
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