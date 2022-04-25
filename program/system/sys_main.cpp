#include <chrono>
#include "DxLib.h"
#include "../library/input.h"
#include "../support/FrameRateController.h"
#include "../game/game_main.h"

static std::chrono::system_clock::time_point clock_start, clock_end ; 

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode( true ) ;

	// �E�B���h�E�T�C�Y�ݒ�
	SetGraphMode( 1024, 768, 32 ) ;

	// �t���[�����[�g�ݒ�
	FpsSetting( 60, 800 ) ;

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )		
	{
		// �G���[���N�����璼���ɏI��
		return -1 ;				
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// �v���J�n����
	clock_start = std::chrono::system_clock::now();

	// �L�[���͐���̏�����
	t2k::Input::initialize();


	// ���b�Z�[�W���[�v
	while( 1 )
	{
		// �t���[���Ԃ̌o�ߎ���
		// �}�C�N���b�Ōv�����ĕb�ɕϊ�
		clock_end = std::chrono::system_clock::now();
		double microseconds = static_cast<double>( std::chrono::duration_cast<std::chrono::microseconds>(clock_end - clock_start).count() );
		float deltatime = static_cast<float>( microseconds / 1000.0 / 1000.0 );
		clock_start = clock_end;

		if( ProcessMessage() == -1 ){
			break ;
		}

		// ��ʂ��N���A
		ClearDrawScreen() ;

		// �L�[��Ԃ̍X�V
		t2k::Input::update();

		// �Q�[�����C�����[�`��
		gameMain(deltatime);

		// �t���[�����[�g�R���g���[��
		FpsControll() ;

		// �o�b�N�o�b�t�@���t���b�v
		ScreenFlip() ;
		//SetWaitVSyncFlag(FALSE);

	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;			

	// �\�t�g�̏I��
	return 0 ;				 
}
