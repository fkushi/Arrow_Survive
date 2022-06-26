#include"Fade_Manager.h"
#include"DxLib.h"

bool Fade_Manager::FadeIn(int fade_speed) {

	SetDrawBright(bright, bright, bright);

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

bool Fade_Manager::FadeOut(int fade_speed) {

	SetDrawBright(bright, bright, bright);

	if (bright <= 0)
	{
		/*c_st.init_change = false;
		c_st.init_fade = false;
		c_st.Changed_Delete();*/
		return true;
	}
	else
	{
		bright -= fade_speed;
	}
	return false;

}

void Fade_Manager::Fade() {
	if (!init_fade)FadeIn(5);
	else FadeOut(5);
}