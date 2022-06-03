#include"Arrow_Type.h"
#include"IMG_load.h"
#include"GameManager.h"
#include "../support/Support.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern IMG_load img;


Arrow_Type::Arrow_Type() {
	gamemanager->arrow_type.emplace_back(this);
}

void Arrow_Type::update(const float deltatime) {
	bool down_sift = t2k::Input::isKeyDown(t2k::Input::KEYBORD_LSHIFT) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_RSHIFT);
	bool trigger_left = t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT);
	//両shiftキー+左矢印キー
	if (down_sift && trigger_left) {
		arrow_type++;
		if (arrow_type >= arrow_type_max)arrow_type = arrow_type_min + 1;
		img.init_img_arw_type = false;
	}
	//両shiftキー+右矢印キー
	else if ((t2k::Input::isKeyDown(t2k::Input::KEYBORD_LSHIFT) ||
		t2k::Input::isKeyDown(t2k::Input::KEYBORD_RSHIFT)) &&
		t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT)) {
		arrow_type--;
		if (arrow_type <= arrow_type_min)arrow_type = arrow_type_max - 1;
		img.init_img_arw_type = false;
	}
}
void Arrow_Type::render(const float deltatime) {
	/*画像load*/
	img.img_arw_type();
	
	if (gamemanager->GetPla_triger_push_sift())arrow_type_blend_add = 255;
	else {
		arrow_type_blend_add -= 3;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, arrow_type_blend_add);
	DrawRotaGraph((int)gamemanager->GetPosPlayer().x, (int)gamemanager->GetPosPlayer().y - 35, 0.5f, 0,
		img.img_arrow_type, true);
}