#include"IMG_load.h"
#include"GameManager.h"
#include"Create_Stage.h"
#include"DxLib.h"

extern Create_Stage c_st;
extern GameManager* gamemanager;

//-------------------------------------------------------------------------------------------------------------------------
/*���ׂĂ̕`��摜���܂Ƃ߂Ă���N���X*/
//-------------------------------------------------------------------------------------------------------------------------

/*PLAYER�C���[�W*/
void IMG_load::img_player() {
	if (!init_img_pla) {
		LoadDivGraph("graphics/Player/Player3_WALK.png", 3, 3, 1, anim_pla_W, anim_pla_H, anim_pla[0], true);
		init_img_pla = true;
	}
}