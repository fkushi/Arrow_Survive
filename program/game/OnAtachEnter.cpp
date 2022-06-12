#include"OnAtachEnter.h"
#include"SONG_load.h"
#include"GameManager.h"
#include "../support/Support.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern SONG_load		song;

OnAtachEnter::OnAtachEnter() {

}
//---------------------------------------------------------------------------------------------------------------
/*wall�����蔻��*/
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Wall() {
	/*�ǂɓ�����������flag����*/
	//grand = -1,right = 0,left = 1,up = 2,down = 3
	//couner_upR = 4,corner_upL = 5,corner_downR = 6,corner_downL = 7
	if (gamemanager->GetAtachWall() == -1) {
		pla_up = true;
		pla_down = true;
		pla_right = true;
		pla_left = true;
	}
	/*��*/
	if (gamemanager->GetAtachWall() != 2 && gamemanager->GetAtachWall() != 4 &&
		gamemanager->GetAtachWall() != 5) {
		pla_up = true;
	}
	else pla_up = false;
	/*��*/
	if (gamemanager->GetAtachWall() != 3 && gamemanager->GetAtachWall() != 6 &&
		gamemanager->GetAtachWall() != 7) {
		pla_down = true;
	}
	else pla_down = false;
	/*�E*/
	if (gamemanager->GetAtachWall() != 0 && gamemanager->GetAtachWall() != 4 &&
		gamemanager->GetAtachWall() != 7) {
		pla_right = true;
	}
	else pla_right = false;
	/*��*/
	if (gamemanager->GetAtachWall() != 1 && gamemanager->GetAtachWall() != 5 &&
		gamemanager->GetAtachWall() != 6) {
		pla_left = true;
	}else pla_left = false;
}

//---------------------------------------------------------------------------------------------------------------
/*POP�����蔻��*/
//�G�̐����ꏊ��PLAYERE�̓����蔻��
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Pop() {
	for (auto pb : gamemanager->pop_enemyB) {
		int pla_pop_check = t2k::isIntersectRectToCorrectPosition(gamemanager->player->pos, gamemanager->player->preve_pos,
			gamemanager->GetPlaSize_W(), gamemanager->GetPlaSize_H(), pb->pos, pb->size_w, pb->size_h);
	}
}

//---------------------------------------------------------------------------------------------------------------
/*ENEMY�����蔻��*/
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Enemy() {
	for (auto eb : gamemanager->enemy_B) {
		/*Player��EnemyB�̔���*/
		
		int pla_enmB_atach = t2k::isIntersectRectToCorrectPosition(gamemanager->player->pos, gamemanager->player->preve_pos,
			gamemanager->GetPlaSize_W() - 10, gamemanager->GetPlaSize_W() - 10, eb->pos, eb->enm_B_SIZE, eb->enm_B_SIZE);
		

		pla_enemyB_check = t2k::isIntersectSphere(gamemanager->player->pos, gamemanager->player->pla_w>>1, 
			eb->pos, static_cast<float>(eb->enm_B_SIZE));
		
		//-------------------------------------------------------------------------------------------
		/*Arrow��EnemyB*/
		//-------------------------------------------------------------------------------------------
		for (auto atar : gamemanager->atach_arrow) {
			/*Arrow�̔��蕔���̔���*/
			arw_enm_chenk = t2k::isIntersectSphere(eb->pos, static_cast<float>(eb->enm_B_SIZE / 2),
				atar->pos, static_cast<float>(atar->atach_Arrow_radius));
			
			//------------------------------------------------------------------------------------------
			/*Arrow*/
			//------------------------------------------------------------------------------------------
			if (arw_enm_chenk && gamemanager->GetOnAt_Arw_arrow_type() == 1) {
				//�q�b�g��������SE
				PlaySoundMem(song.se_atach, DX_PLAYTYPE_BACK, true);

				//*�q�b�g������`�������
				eb->is_alive = false;
				atar->arrow_alive = false;

				//Arrow�`�敔���̔���
				for (auto arw : gamemanager->bullet_player) {
					int arw_check = t2k::isIntersectRectToCorrectPosition(eb->pos, eb->preve_pos, eb->enm_B_SIZE, eb->enm_B_SIZE,
						arw->pos, arw->blt_pla_w, arw->blt_pla_h);
					if (arw_check > 0 )arw->arrow_alive = false;
				}
			}
			//------------------------------------------------------------------------------------------
			/*Arrow_Wing*/
			//------------------------------------------------------------------------------------------
			else if (arw_enm_chenk && gamemanager->GetOnAt_Arw_arrow_type() == 2) {
				//��̓����蔻�肪�q�b�g������`�������
				eb->is_alive = false;
				atar->arrow_alive = false;

				//Arrow_Wing�`�敔���̔���
				for (auto arw_w : gamemanager->arrow_wing) {
					int arw_w_check = t2k::isIntersectRectToCorrectPosition(eb->pos, eb->preve_pos, eb->enm_B_SIZE, eb->enm_B_SIZE,
						arw_w->pos, arw_w->blt_pla_w, arw_w->blt_pla_h);
					if (arw_w_check > 0)arw_w->arrow_alive = false;
				}
			}
		}

		
	}
} 