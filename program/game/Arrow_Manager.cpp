#include"Arrow_Manager.h"
#include"SONG_load.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern SONG_load		song;

//--------------------------------------------------------------------------------------------------------------------------*
/*ArrowManager*/
//Arrow‚Æ‚Â‚¢‚½cpp‚Ü‚½‚ÍBullet_Player.cpp‚ð‚Ü‚Æ‚ß‚éƒNƒ‰ƒX
//--------------------------------------------------------------------------------------------------------------------------*

Arrow_Manager::Arrow_Manager() {

	new Arrow_Type();

	gamemanager->arrow_manager.emplace_back(this);
}

void Arrow_Manager::update(const float deltatime) {

	for (auto aw_ba : gamemanager->arrow_base)aw_ba->update_arrow(deltatime);

	//-----------------------------------------------------------
	/*DELETE*/
	//-----------------------------------------------------------
	gamemanager->eraceCheck_Base();
	gamemanager->eraceCheck();
}
void Arrow_Manager::render(const float deltatime) {

	for (auto aw_ba : gamemanager->arrow_base)aw_ba->render_arrow(deltatime);

}

void Arrow_Manager::Create_Arrow(t2k::Vector3 start, bool player_dir) {
	//-----------------------------------------------------------
	/*Player‚ªspace‚ð‰Ÿ‚µ‚½‚Æ‚«A‚»‚ÌŽž‚Ì–î‚Ì‘®«‚ð”­ŽË‚·‚é*/
	//-----------------------------------------------------------

	int speed = 8;
	int radian = 0;

	if (gamemanager->GetArwTyp_arrow_type() == 1) {
		PlaySoundMem(song.se_shot, DX_PLAYTYPE_BACK, true);
		if (!player_dir) {
			new Bullet_Player(start, t2k::Vector3(1,0,0), radian, speed, player_dir);
		}
		else {
			new Bullet_Player(start, t2k::Vector3(-1, 0, 0), radian, speed, player_dir);
		}
	}
	else if (gamemanager->GetArwTyp_arrow_type() == 2) {
		PlaySoundMem(song.se_shot, DX_PLAYTYPE_BACK, true);
		if (!player_dir) {
			new Arrow_Wing(start, t2k::Vector3(1, 0, 0), radian, speed, player_dir);
		}
		else {
			new Arrow_Wing(start, t2k::Vector3(-1, 0, 0), radian, speed, player_dir);
		}
	}
}