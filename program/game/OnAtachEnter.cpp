#include"OnAtachEnter.h"
#include"Anim_Player.h"
#include"SONG_load.h"
#include"GameManager.h"
#include "../support/Support.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern SONG_load		song;
extern Anim_Player* anim_player;

OnAtachEnter::OnAtachEnter() {

}

//---------------------------------------------------------------------------------------------------------------
/*wall“–‚½‚è”»’è*/
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Wall() {
	/*•Ç‚É“–‚½‚Á‚½Žž‚Ìflagˆ—*/
	//grand = -1,right = 0,left = 1,up = 2,down = 3
	//couner_upR = 4,corner_upL = 5,corner_downR = 6,corner_downL = 7
	if (gamemanager->GetAtachWall() == -1) {
		pla_up = true;
		pla_down = true;
		pla_right = true;
		pla_left = true;
	}
	/*ã*/
	if (gamemanager->GetAtachWall() != 2 && gamemanager->GetAtachWall() != 4 &&
		gamemanager->GetAtachWall() != 5) {
		pla_up = true;
	}
	else pla_up = false;
	/*‰º*/
	if (gamemanager->GetAtachWall() != 3 && gamemanager->GetAtachWall() != 6 &&
		gamemanager->GetAtachWall() != 7) {
		pla_down = true;
	}
	else pla_down = false;
	/*‰E*/
	if (gamemanager->GetAtachWall() != 0 && gamemanager->GetAtachWall() != 4 &&
		gamemanager->GetAtachWall() != 7) {
		pla_right = true;
	}
	else pla_right = false;
	/*¶*/
	if (gamemanager->GetAtachWall() != 1 && gamemanager->GetAtachWall() != 5 &&
		gamemanager->GetAtachWall() != 6) {
		pla_left = true;
	}else pla_left = false;
}

//---------------------------------------------------------------------------------------------------------------
/*POP“–‚½‚è”»’è*/
//“G‚Ì¶¬êŠ‚ÆPLAYERE‚Ì“–‚½‚è”»’è
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Pop() {
	for (auto pb : gamemanager->pop_enemyB) {
		int pla_pop_check = t2k::isIntersectRectToCorrectPosition(gamemanager->player->pos, gamemanager->player->preve_pos,
			gamemanager->GetPlaSize_W(), gamemanager->GetPlaSize_H(), pb->pos, pb->size_w, pb->size_h);
	}
}

//---------------------------------------------------------------------------------------------------------------
/*ENEMY“–‚½‚è”»’è*/
//---------------------------------------------------------------------------------------------------------------
void OnAtachEnter::Atach_Pla_Enemy() {
	for (auto eb : gamemanager->enemy_B) {
		
		//-------------------------------------------------------------------------------------------
		/*Player‚ÆEnemyB‚Ì“–‚½‚è”»’è*/
		//-------------------------------------------------------------------------------------------
		if (!anim_player->init_animation_player_dead) {
			player_enemyB_atach = t2k::isIntersectRectToCorrectPosition(gamemanager->player->pos, gamemanager->player->preve_pos,
				gamemanager->GetPlaSize_W() - 10, gamemanager->GetPlaSize_W() - 10, eb->pos, eb->enm_B_SIZE, eb->enm_B_SIZE);
		}
		//HIT”»’è
		pla_enemyB_check = t2k::isIntersectSphere(gamemanager->player->pos, static_cast<float>(gamemanager->player->pla_w>>1) + 10,
			eb->pos, static_cast<float>(eb->enm_B_SIZE  >> 1));
		
		//-------------------------------------------------------------------------------------------
		/*Arrow‚ÆEnemyB‚ÌHIT”»’è*/
		//-------------------------------------------------------------------------------------------
		for (auto atar : gamemanager->atach_arrow) {
			
			/*–î‚¶‚è‚Ì”»’è•”•ª‚Ì”»’è*/
			arw_enm_check = t2k::isIntersectSphere(eb->pos, static_cast<float>(eb->enm_B_SIZE / 2),
				atar->pos, static_cast<float>(atar->atach_Arrow_radius));

			//------------------------------------------------------------------------------------------
			/*Arrow*/
			//------------------------------------------------------------------------------------------

			if (arw_enm_check) {
				//ƒqƒbƒg‚µ‚½Žž‚ÌSE
				PlaySoundMem(song.se_atach, DX_PLAYTYPE_BACK, true);

				//-------------------------------------------
				/*–î‚Ì“–‚½‚è”»’è‚ªƒqƒbƒg‚µ‚½‚çÁ‚·*/
				//-------------------------------------------
				//EnemyB
				eb->is_alive = false;

				//Arrow_Wing‚Ì“–‚½‚è”»’è
				atar->arrow_alive = false;

				//Arrow•`‰æ•”•ª
				for (auto arw : gamemanager->bullet_player) {
					
					//–î‚¶‚è‚ª“–‚½‚è‚©‚Â–î‚Ì•`‰æ‚ª“–‚½‚Á‚½ê‡A•`‰æ‚ðÁ‚·
					bool img_arw_enm = t2k::isIntersectSphere(eb->pos, static_cast<float>(eb->enm_B_SIZE / 2), 
						arw->pos, static_cast<float>(arw->blt_pla_w >> 1));
					
					if(img_arw_enm)arw->arrow_alive = false;
				}

				//Arrow_Wing•`‰æ•”•ª
				for (auto arw_w : gamemanager->arrow_wing) {
					
					//–î‚¶‚è‚ª“–‚½‚è‚©‚Â–î‚Ì•`‰æ‚ª“–‚½‚Á‚½ê‡A•`‰æ‚ðÁ‚·
					bool img_win_enm = t2k::isIntersectSphere(eb->pos, static_cast<float>(eb->enm_B_SIZE / 2),
						arw_w->pos, static_cast<float>(arw_w->blt_pla_w >> 1));
					
					if(img_win_enm)arw_w->arrow_alive = false;

				}
			}
		}

		
	}
} 