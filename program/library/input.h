#pragma once

namespace t2k {

    class Input final {
	public :
		Input(){}
		~Input(){}

		#define MOUSE_OUTPUT_LEFT	(0x08)
		#define MOUSE_OUTPUT_RIGHT	(0x10)
		#define MOUSE_OUTPUT_MIDDLE	(0x20)

		// �}�E�X�Ή��L�[ �ꗗ
		enum eMouse {
			MOUSE_PRESSED_LEFT = MOUSE_OUTPUT_LEFT,
			MOUSE_PRESSED_RIGHT = MOUSE_OUTPUT_RIGHT,
			MOUSE_PRESSED_MIDDLE = MOUSE_OUTPUT_MIDDLE,
			MOUSE_RELEASED_LEFT = MOUSE_OUTPUT_LEFT,
			MOUSE_RELEASED_RIGHT = MOUSE_OUTPUT_RIGHT,
			MOUSE_RELEASED_MIDDLE = MOUSE_OUTPUT_MIDDLE
		};

		// �L�[�{�[�h�Ή��L�[ �ꗗ
		enum eKeys {
			KEYBORD_BACK		// �o�b�N�X�y�[�X
			, KEYBORD_TAB		// �^�u
			, KEYBORD_RETURN	// �G���^�[
			, KEYBORD_LSHIFT	// ���V�t�g
			, KEYBORD_RSHIFT	// �E�V�t�g
			, KEYBORD_LCONTROL	// ���R���g���[��
			, KEYBORD_RCONTROL	// �E�R���g���[��
			, KEYBORD_ESCAPE	// �G�X�P�[�v
			, KEYBORD_SPACE	    // �X�y�[�X
			, KEYBORD_PGUP		// �o�������t�o
			, KEYBORD_PGDN		// �o�������c������
			, KEYBORD_END		// �G���h
			, KEYBORD_HOME		// �z�[��
			, KEYBORD_LEFT		// ��
			, KEYBORD_UP		// ��
			, KEYBORD_RIGHT	    // �E
			, KEYBORD_DOWN		// ��
			, KEYBORD_INSERT	// �C���T�[�g
			, KEYBORD_DELETE	// �f���[�g

			, KEYBORD_MINUS		    // �|
			, KEYBORD_YEN			// ��
			, KEYBORD_PREVTRACK	    // �O
			, KEYBORD_PERIOD		// �D
			, KEYBORD_SLASH		    // �^
			, KEYBORD_LALT			// ���`�k�s
			, KEYBORD_RALT			// �E�`�k�s
			, KEYBORD_SCROLL		// ScrollLock
			, KEYBORD_SEMICOLON	    // �G
			, KEYBORD_COLON		    // �F
			, KEYBORD_LBRACKET		// �m
			, KEYBORD_RBRACKET		// �n
			, KEYBORD_AT			// ��
			, KEYBORD_BACKSLASH	    // �_
			, KEYBORD_COMMA		    // �C
			, KEYBORD_CAPSLOCK		// CaspLock
			, KEYBORD_PAUSE		    // PauseBreak

			, KEYBORD_NUMPAD0	// �e���L�[�O
			, KEYBORD_NUMPAD1	// �e���L�[�P
			, KEYBORD_NUMPAD2	// �e���L�[�Q
			, KEYBORD_NUMPAD3	// �e���L�[�R
			, KEYBORD_NUMPAD4	// �e���L�[�S
			, KEYBORD_NUMPAD5	// �e���L�[�T
			, KEYBORD_NUMPAD6	// �e���L�[�U
			, KEYBORD_NUMPAD7	// �e���L�[�V
			, KEYBORD_NUMPAD8	// �e���L�[�W
			, KEYBORD_NUMPAD9	// �e���L�[�X
			, KEYBORD_MULTIPLY	// �e���L�[��
			, KEYBORD_ADD		// �e���L�[�{
			, KEYBORD_SUBTRACT	// �e���L�[�|
			, KEYBORD_DECIMAL	// �e���L�[�D
			, KEYBORD_DIVIDE	// �e���L�[�^
			, KEYBORD_NUMPADENTER	// �e���L�[�̃G���^�[

			, KEYBORD_F1	// �e�P
			, KEYBORD_F2	// �e�Q
			, KEYBORD_F3	// �e�R
			, KEYBORD_F4	// �e�S
			, KEYBORD_F5	// �e�T
			, KEYBORD_F6	// �e�U
			, KEYBORD_F7	// �e�V
			, KEYBORD_F8	// �e�W
			, KEYBORD_F9	// �e�X
			, KEYBORD_F10	// �e�P�O
			, KEYBORD_F11	// �e�P�P
			, KEYBORD_F12	// �e�P�Q

			, KEYBORD_A	// �`
			, KEYBORD_B	// �a
			, KEYBORD_C	// �b
			, KEYBORD_D	// �c
			, KEYBORD_E	// �d
			, KEYBORD_F	// �e
			, KEYBORD_G	// �f
			, KEYBORD_H	// �g
			, KEYBORD_I	// �h
			, KEYBORD_J	// �i
			, KEYBORD_K	// �j
			, KEYBORD_L	// �k
			, KEYBORD_M	// �l
			, KEYBORD_N	// �m
			, KEYBORD_O	// �n
			, KEYBORD_P	// �o
			, KEYBORD_Q	// �p
			, KEYBORD_R	// �q
			, KEYBORD_S	// �r
			, KEYBORD_T	// �s
			, KEYBORD_U	// �t
			, KEYBORD_V	// �u
			, KEYBORD_W	// �v
			, KEYBORD_X	// �w
			, KEYBORD_Y	// �x
			, KEYBORD_Z	// �y
			, KEYBORD_0	// �O
			, KEYBORD_1	// �P
			, KEYBORD_2	// �Q
			, KEYBORD_3	// �R
			, KEYBORD_4	// �S
			, KEYBORD_5	// �T
			, KEYBORD_6	// �U
			, KEYBORD_7	// �V
			, KEYBORD_8	// �W
			, KEYBORD_9	// �X
			, KEYBORD_MAX
		};


  	    // ������
	    static void initialize();

	    // �X�V
		static void update();

	    // ����
		static bool isKeyDown(eKeys key);

	    // ����( �g���K�[ )
		static bool isKeyDownTrigger(eKeys key);

	    // �����[�X�g���K�[
		static bool isKeyReleaseTrigger(eKeys key);

		// �}�E�X����
		static bool isMouseTrigger(eMouse _mouse);

	};

}

