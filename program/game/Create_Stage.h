#pragma once
class Create_Stage {
private:
	//int stage_type = 0;
	/*void Changed_Delete();*/
public:
	Create_Stage();

	int stage_type = 0;
	int pla_next_pop = fast;
	enum {
		fast,up,down,left,right
	};

	bool init_fade = false;
	bool init_change = true;
	
	void Changed_Delete();
	void create_Stage();
};