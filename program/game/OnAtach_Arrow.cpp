#include"OnAtach_Arrow.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;

//--------------------------------------------------------------------------------------------------------------------------*
/*���̓����蔻��*/
//--------------------------------------------------------------------------------------------------------------------------*
OnAtach_Arrow::OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed, bool pla_dir,int type) {
	pos = start;
	preve_pos = start;
	atach_Arrow_dir = dir;
	atach_Arrow_speed = speed;
	preve_pla_dir = pla_dir;
	arrow_type = type;
	//---------------------------------------------------------
	/*�l�Q��*/
	preve_pla_dir = pla_dir;
	if(!preve_pla_dir)center_1 = { start.x + 85,start.y,0 };
	else center_1 = { start.x - 85,start.y ,0 };
	sequence_arw_win = false;
	//---------------------------------------------------------

	gamemanager->atach_arrow.emplace_back(this);
}

void OnAtach_Arrow::update_arrow(const float deltatime) {
	//--------------------------------------------------------------------------------------
	/*Arrow*/
	//--------------------------------------------------------------------------------------
	if (arrow_type == 1) {
		pos += atach_Arrow_dir * (float)atach_Arrow_speed;
		if (pos.x < 0 || pos.x > 1024 || pos.y < 0 || pos.y > 768) arrow_alive = false;
	}

	//--------------------------------------------------------------------------------------
	/*Arrow_Wing*/
	//--------------------------------------------------------------------------------------
	if (arrow_type == 2) {
		float add_x = cos(radius + 1.57f) * red_radius;
		float add_y = sin(radius + 1.57f) * red_radius;
		float add_center_x = cos(radius) * light_blue_radius;
		float add_center_y = sin(radius) * light_blue_radius;

		//�X������200�i�񂾂����Ɉڍs����FLAG����
		if ((!preve_pla_dir && preve_pos.x + 200 <= pos.x) || (preve_pla_dir && preve_pos.x - 200 >= pos.x)) {
			sequence_arw_win = true;
		}

		//�X�����ɐi�ޏ���
		if (!sequence_arw_win)pos.x += atach_Arrow_dir.x * atach_Arrow_speed;
		//����񂷂鏈��
		else {
			//��̎��񔼌a�g��
			light_blue_radius++;

			if (!preve_pla_dir) {
				center_pos.x = center_1.x + add_center_x;
				center_pos.y = center_1.y + add_center_y;
				pos.x = center_pos.x + add_x;
				pos.y = center_pos.y + add_y;
			}
			else {
				center_pos.x = center_1.x - add_center_x;
				center_pos.y = center_1.y - add_center_y;
				pos.x = center_pos.x - add_x;
				pos.y = center_pos.y - add_y;
			}

			radius += 0.05f;

		}

		//��ʊO�ɂł������
		if (pos.x < -150 || pos.x > 1124 || pos.y < -100 || pos.y > 1000) arrow_alive = false;

	}
}

void OnAtach_Arrow::render_arrow(const float deltatime) {

	if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_Q))img_alpha = 255;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, img_alpha);
	DrawCircle((int)pos.x, (int)pos.y, atach_Arrow_radius, GetColor(0, 0, 255), false);

}