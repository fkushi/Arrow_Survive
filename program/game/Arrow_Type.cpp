#include"Arrow_Type.h"
#include"IMG_load.h"
#include"GameManager.h"
#include "../support/Support.h"
#include"DxLib.h"

extern GameManager* gamemanager;
//extern IMG_load img;


Arrow_Type::Arrow_Type() {

	gamemanager->arrow_type.emplace_back(this);

}

void Arrow_Type::update(const float deltatime) {
	
	/*��̑����ύX*/
	//��shift�L�[+�����L�[
	if (gamemanager->down_sift && gamemanager->trigger_left) {
		arrow_type++;
		if (arrow_type >= arrow_type_max)arrow_type = arrow_type_min + 1;
	}
	//��shift�L�[+�E���L�[
	else if (gamemanager->down_sift && gamemanager->trigger_right) {
		arrow_type--;
		if (arrow_type <= arrow_type_min)arrow_type = arrow_type_max - 1;
	}
}
void Arrow_Type::render(const float deltatime) {
	
	if (arrow_type == 1)img_Arrow_Type = gamemanager->LoadGraphEx("graphics/Orb/�I�[�u_Arrow.png");
	if (arrow_type == 2)img_Arrow_Type = gamemanager->LoadGraphEx("graphics/Orb/�I�[�u_��.png");
	if (arrow_type == 3)img_Arrow_Type = gamemanager->LoadGraphEx("graphics/Orb/�I�[�u_��.png");

	if (gamemanager->GetPla_triger_push_sift())arrow_type_blend_add = 255;
	else {
		arrow_type_blend_add -= 3;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, arrow_type_blend_add);
	DrawRotaGraph((int)gamemanager->GetPosPlayer().x, (int)gamemanager->GetPosPlayer().y - 35, 0.5f, 0,
		img_Arrow_Type, true);
}