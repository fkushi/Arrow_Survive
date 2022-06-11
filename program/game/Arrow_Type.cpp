#include"Arrow_Type.h"
#include"GameManager.h"
#include "../support/Support.h"
#include"DxLib.h"

extern GameManager* gamemanager;


Arrow_Type::Arrow_Type() {

	gamemanager->arrow_type.emplace_back(this);

}

void Arrow_Type::update_arrow(const float deltatime) {
	
	auto choose_type_max = static_cast<uint32_t>(ARROW_TYPE::MAX);
	auto choose_type_min = static_cast<uint32_t>(ARROW_TYPE::MIN);
	auto choose_type_arrow = static_cast<uint32_t>(ARROW_TYPE::ARROW);
	auto choose_type_wing = static_cast<uint32_t>(ARROW_TYPE::WING);
	auto choose_type_fire = static_cast<uint32_t>(ARROW_TYPE::FIRE);

	//------------------------------------------------------------------
	/*矢の属性変更*/
	//両shiftキー+左矢印キーを押すと属性を変える
	//------------------------------------------------------------------
	if (gamemanager->down_shift && gamemanager->trigger_left) {
		arrow_type++;
		if (arrow_type == choose_type_max)arrow_type = choose_type_arrow;
	}

	//------------------------------------------------------------------
	//両shiftキー+右矢印キーを押すと属性を変える
	//------------------------------------------------------------------
	else if (gamemanager->down_shift && gamemanager->trigger_right) {
		arrow_type--;
		if (arrow_type == choose_type_min)arrow_type = choose_type_fire;
	}

	//------------------------------------------------------------------
	/*描画したものを徐々に透過する*/
	//shiftキーを押すと再描画する
	//------------------------------------------------------------------
	if (gamemanager->GetPla_triger_push_sift())arrow_type_blend_add = 255;
	else {
		arrow_type_blend_add -= 3;
	}

}
void Arrow_Type::render_arrow(const float deltatime) {
	
	auto choose_type_arrow = static_cast<uint32_t>(ARROW_TYPE::ARROW);
	auto choose_type_wing = static_cast<uint32_t>(ARROW_TYPE::WING);
	auto choose_type_fire = static_cast<uint32_t>(ARROW_TYPE::FIRE);

	if (arrow_type == choose_type_arrow)img_Arrow_Type = gamemanager->LoadGraphEx("graphics/Orb/オーブ_Arrow.png");
	if (arrow_type == choose_type_wing)img_Arrow_Type = gamemanager->LoadGraphEx("graphics/Orb/オーブ_風.png");
	if (arrow_type == choose_type_fire)img_Arrow_Type = gamemanager->LoadGraphEx("graphics/Orb/オーブ_炎.png");

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, arrow_type_blend_add);
	DrawRotaGraph(static_cast<int>(gamemanager->GetPosPlayer().x), static_cast<int>(gamemanager->GetPosPlayer().y) - 35, 0.5f, 0,
		img_Arrow_Type, true);
}