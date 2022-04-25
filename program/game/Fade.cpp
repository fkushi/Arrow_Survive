#include"Fade.h"
#include"DxLib.h"
#include"Create_Stage.h"
#include"GameManager.h"

extern GameManager* gamemanager;
extern Create_Stage c_st;

/*フェードイン*/ 
bool Fade::FadeIn(int fade_speed, int r, int g, int b)
{
	SetDrawBright(bright, bright, bright);

	DrawFormatString(40, 40, GetColor(0, 0, 255), "%d", bright);

	if (bright > 255)
	{
		return true;
	}
	else
	{
		bright += fade_speed;
	}

	return false;
}
//--------------------------------------------------
/*フェードアウト*/
bool Fade::FadeOut(int fade_speed, int r, int g, int b)
{
	SetDrawBright(bright, bright, bright);
	DrawFormatString(40, 40, GetColor(0, 0, 255), "%d", bright);

	if (bright <= 0)
	{
		c_st.init_change = false;
		c_st.init_fade = false;
		c_st.Changed_Delete();
		return true;
	}
	else
	{
		bright -= fade_speed;
	}
	return false;
}