#pragma once
#include <functional>

namespace t2k {

	//------------------------------------------------------------------------------------------------------------
	//
	// ���Ԍo�߂ł̃��\�b�h�Ăяo��
	// 
	//

	template <class T>
	class TimerCallback final {
	private:
		T object_;
		std::function<void(T, const float)> function_;
		float sum_time_ = 0;
		float regulation_time_seconds_ = 0;
		TimerCallback() {}
	public:

		//===================================================================================
		// �R���X�g���N�^
		// arg1... ��܃N���X�� this �|�C���^���w��
		// arg2... �R�[���o�b�N�ŌĂяo��������܃N���X�̃����o���\�b�h�܂��̓����_���w��
		// arg3... �R�[���o�b�N�Ăяo���̋K�莞��( �b���w�� 1.0f ��1�b )
		// arg4... ����̃R�[���o�b�N�̂ݑ��Ăяo��������� true ���w��  �ȗ���
		//===================================================================================
		TimerCallback( const T obj, const std::function<void(T, const float)> func, const float regulation_time, const bool is_callback_start = false )
			: regulation_time_seconds_(regulation_time)
			, object_(obj)
			, function_(func)
			, sum_time_((is_callback_start) ? regulation_time : 0)
		{}
		~TimerCallback(){}

		//===================================================================================
		// �K�莞�Ԍo�߂ŃR�[���o�b�N���Ăяo���A�b�v�f�[�g( ���t���[���Ăяo����OK )
		// arg1... �t���[���Ԃ̌o�ߎ���( �~���b�w�� )
		// ret.... �R�[���o�b�N���Ăяo������ true ���A��
		//===================================================================================
		inline bool update( const float deltatime ) {
			sum_time_ += deltatime;
			if ( sum_time_ < regulation_time_seconds_ ) return false;
			function_(object_, deltatime);
			sum_time_ = 0;
			return true;
		}
	};

}

