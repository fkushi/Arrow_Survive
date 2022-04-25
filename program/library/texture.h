#pragma once
#include <string>
#include "shared_factory.h"
#include "shared_flyweight_map.h"

namespace t2k{

	class Texture final : public SharedFactory<Texture>{
	private:
		int image_ = 0;
		int size_w_ = 0;
		int size_h_ = 0;
		std::string filename_;
		inline static SharedFlyWeightMap<std::string, Texture> textures_;

	public:
		typedef std::shared_ptr<Texture> SharedPtr;
		typedef std::weak_ptr<Texture> WeakPtr;
		Texture() {}
		~Texture(){}

		inline int getImage() { return image_; }
		inline int getWidth() { return size_w_; }
		inline int getHeight() { return size_h_; }

		//static Texture* create(const std::string& file_name);

		// �e�N�X�`������͈͂��w�肵�ĐV�����e�N�X�`���𐶐�����
		Texture::SharedPtr partiallyCreatedFromTexture( const int src_left_up_x, const int src_left_up_y, const int width, const int height );

		// �`��e�N�X�`���̐���
		static Texture::SharedPtr createRenderTexture( const int width, const int height );

		// ���\�[�X�t�@�C������e�N�X�`���𐶐�
		static Texture::SharedPtr createFromFile(const std::string& file_path);

		// �Q�Ƃ���Ȃ��Ȃ����e�N�X�`���̊J��( �V�[���̐؂�ւ����ȂǂŎg�p )
		inline static void releaseUnique() { textures_.eraseUnique(); }

		// SharedFlyWeightMap �p�̃��[�_�[
		// public �ɑ��݂��邪���[�U�[�͒��ڎg�p���Ȃ�( �{���Ȃ� inline�w�b�_�ȂǂŉB���Ώ� )
		static Texture::SharedPtr fromFlyWeightLoader(const std::string& key, const std::string& file_name);
	};

}
