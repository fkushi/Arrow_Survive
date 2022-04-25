#include"Taitle.h"
#include"IMG_load.h"
#include"DxLib.h"
#include "../support/Support.h"

extern IMG_load img;

/*ステージ作成後タイトル作成予定*/
Taitle::Taitle() {

}
Taitle::~Taitle() {

}

void Taitle::update(float deltatime) {
	
}
void Taitle::render(float deltatime) {
	img.img_title();
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0f, 0, img.title, false);
}