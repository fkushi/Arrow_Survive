#pragma once
class Create_Stage {
private:

public:
	Create_Stage();

	/*現在のステージ種類*/
	int stage_type = 0;

	/*playerが渡った橋がどの橋かの判定*/
	int pla_next_pop = 0;

	//enum class CHOOSEWAY:uint32_t {
	enum class CHOOSEWAY : int {
		FAST,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		MAX
	};
	
	/*フェードイン、フェードアウトをするflag*/
	bool init_fade = false;

	/*playerが移動したらステージ変更するflag*/
	//falseになったらステージ変更
	bool init_change = true;
	
	void Changed_Delete();
	void create_Stage();
};