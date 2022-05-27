#include"OnAtachEnter.h"
#include"GameManager.h"
#include "../support/Support.h"

extern GameManager* gamemanager;

OnAtachEnter::OnAtachEnter() {

}
//---------------------------------------------------------------------------------------------------------------
/*wall当たり判定*/
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Wall() {
	//grand = -1,right = 0,left = 1,up = 2,down = 3
	//couner_upR = 4,corner_upL = 5,corner_downR = 6,corner_downL = 7
	if (gamemanager->GetAtachWall() == -1) {
		pla_up = true;
		pla_down = true;
		pla_right = true;
		pla_left = true;
	}
	/*上*/
	if (gamemanager->GetAtachWall() != 2 && gamemanager->GetAtachWall() != 4 &&
		gamemanager->GetAtachWall() != 5) {
		pla_up = true;
	}
	else pla_up = false;
	/*下*/
	if (gamemanager->GetAtachWall() != 3 && gamemanager->GetAtachWall() != 6 &&
		gamemanager->GetAtachWall() != 7) {
		pla_down = true;
	}
	else pla_down = false;
	/*右*/
	if (gamemanager->GetAtachWall() != 0 && gamemanager->GetAtachWall() != 4 &&
		gamemanager->GetAtachWall() != 7) {
		pla_right = true;
	}
	else pla_right = false;
	/*左*/
	if (gamemanager->GetAtachWall() != 1 && gamemanager->GetAtachWall() != 5 &&
		gamemanager->GetAtachWall() != 6) {
		pla_left = true;
	}else pla_left = false;
}

//---------------------------------------------------------------------------------------------------------------
/*POP当たり判定*/
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Pop() {
	for (auto pb : gamemanager->pop_stB) {
		int pla_pop_check = t2k::isIntersectRectToCorrectPosition(gamemanager->pla->pos, gamemanager->pla->preve_pos,
			gamemanager->GetPlaSize_W(), gamemanager->GetPlaSize_H(), pb->pos, pb->size_w, pb->size_h);
	}
}

//---------------------------------------------------------------------------------------------------------------
/*ENEMY当たり判定*/
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Enemy() {
	for (auto eb : gamemanager->enm_B) {
		/*PlayerとEnemyB*/
		pla_enemyB_check = t2k::isIntersectRectToCorrectPosition(gamemanager->pla->pos, gamemanager->pla->preve_pos,
			gamemanager->GetPlaSize_W(), gamemanager->GetPlaSize_H(), eb->pos, eb->enm_B_SIZE, eb->enm_B_SIZE);
		//-------------------------------------------------------------------------------------------
		/*ArrowとEnemyB*/
		for (auto atar : gamemanager->atach_arw) {
			arw_enm_chenk = t2k::isIntersectSphere(eb->pos, (float)eb->enm_B_SIZE / 2, atar->pos, (float)atar->atach_Arrow_radius);
			//Arrow_判定
			if (arw_enm_chenk && gamemanager->GetOnAt_Arw_arrow_type() == 1) {
				eb->is_alive = false;
				atar->is_alive = false;
				//Arrow_描画
				for (auto arw : gamemanager->blt_pla) {
					int arw_check = t2k::isIntersectRectToCorrectPosition(eb->pos, eb->preve_pos, eb->enm_B_SIZE, eb->enm_B_SIZE,
						arw->pos, arw->blt_pla_w, arw->blt_pla_h);
					if (arw_check > 0 && arw_enm_chenk)arw->is_alive = false;
				}
			}
			else if (arw_enm_chenk && gamemanager->GetOnAt_Arw_arrow_type() == 2) {
				eb->is_alive = false;
				atar->is_alive = false;
				for (auto arw_w : gamemanager->arw_win)arw_w->is_alive = false;
			}
		}

		
	}
} 
//---------------------------------------------------------------------------------------------------------------
/*保留*/
//---------------------------------------------------------------------------------------------------------------
//ローカル座標による当たり判定
void OnAtachEnter::Atach_Pla_Block(t2k::Vector3 pla_pos, int pla_w, int pla_h,
	t2k::Vector3 box_pos, int box_w, int box_h) {
	if (pla_pos.x >= box_pos.x - (box_w >> 1) && pla_pos.x <= box_pos.x - (box_w >> 1) + 50 &&
		pla_pos.y <= box_pos.y + (box_h >> 1) && pla_pos.y >= box_pos.y - (box_h >> 1)) {
		for (auto w : gamemanager->m_wal) {
			w->atach_wal = w->atach_right;
		}
	}
}