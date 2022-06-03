#include"map_Wall.h"
#include"Create_Stage.h"
#include"GameManager.h"
#include"IMG_load.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern IMG_load img;
extern Create_Stage	c_st;

/*ステージ周りにある川の当たり判定*/
map_Wall::map_Wall() {
	gamemanager->map_wall.emplace_back(this);
}

/*Wall当たり判定*/
void map_Wall::update(const float deltatime) {
	int pos_x = (int)gamemanager->GetPosPlayer().x;
	int pos_y = (int)gamemanager->GetPosPlayer().y;

	/*CORNERr*/
	if (pos_x < 64 && pos_y < 64 + 22)atach_wal = atach_corner_upL;
	else if (pos_x > 960 && pos_y < 64 + 22)atach_wal = atach_corner_upR;
	else if (pos_x < 64 && pos_y > 704 - 22)atach_wal = atach_corner_downR;
	else if (pos_x > 960 && pos_y > 704 - 22)atach_wal = atach_corner_downL;
	/*BRIDGE*/
	/*bridge_up*/
	else if (pos_x >= 512 - (bridge_w >> 1) && pos_x <= 512 + (bridge_w >> 1) &&
		pos_y <= 84 && c_st.pla_next_pop != 2)atach_wal = atach_grand;
	else if (pos_x >= 512 + (bridge_w >> 1) && pos_y <= 64)atach_wal = atach_right;
	else if (pos_x <= 512 - (bridge_w >> 1) && pos_y <= 64)atach_wal = atach_left;
	/*bridge_down*/
	else if (pos_x >= 512 - (bridge_w >> 1) && pos_x <= 512 + (bridge_w >> 1) &&
		pos_y >= 681 && c_st.pla_next_pop != 1)atach_wal = atach_wal = atach_grand;
	else if (pos_x >= 512 + (bridge_w >> 1) && pos_y >= 688)atach_wal = atach_right;
	else if (pos_x <= 512 - (bridge_w >> 1) && pos_y >= 688)atach_wal = atach_left;
	/*bridge_right*/
	else if (pos_y >= 384 - 42 && pos_y <= 384 + 38 - (pla_h >> 1) &&
		pos_x <= 62 && c_st.pla_next_pop != 4) atach_wal = atach_grand;
	else if (pos_y <= 384 + 38 - (pla_h >> 1) && pos_x < 62) atach_wal = atach_up;
	else if (pos_y >= 384 - 42 && pos_x < 62) atach_wal = atach_down;
	/*bridge_left*/
	else if (pos_y >= 384 - 42 && pos_y <= 384 + 38 - (pla_h >> 1) &&
		pos_x >= 960 && c_st.pla_next_pop != 3)atach_wal = atach_grand;
	else if (pos_y >= 384 - 42 && pos_x > 962)atach_wal = atach_down;
	else if (pos_y <= 384 + 38 - (pla_h >> 1) && pos_x > 962)atach_wal = atach_up;
	/*WALL*/
	else if (pos_x <= 64) atach_wal = atach_left;
	else if (pos_x >= 960)atach_wal = atach_right;
	else if (pos_y < 64 + 22)atach_wal = atach_up;
	else if (pos_y >= 682)atach_wal = atach_down;
	else atach_wal = atach_grand;
}

void map_Wall::render(const float deltatime) {
	img.img_wall();
	int pla_next = c_st.pla_next_pop;
	//SetDrawBright(255, 255, 255);
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0f, 0, img.img_wall_nomal, true);
	if(pla_next == 2)DrawRotaGraph(1024 >> 1, 32, 1.0f, 1.57f, img.img_wall_Bridge, true);
	if(pla_next == 1)DrawRotaGraph(1024 >> 1, 768 - 32, 1.0f, 1.57f, img.img_wall_Bridge, true);
	if(pla_next == 4)DrawRotaGraph(32, 768 >> 1, 1.0f, 0, img.img_wall_Bridge, true);
	if(pla_next == 3)DrawRotaGraph(1024 - 32, 768 >> 1, 1.0f, 0, img.img_wall_Bridge, true);
	
}