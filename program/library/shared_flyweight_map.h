#pragma once
#include <unordered_map>
#include <memory>
#include <stdexcept>

namespace t2k {

	//------------------------------------------------------------------------------------------------------------
	//
	// �t���C�E�F�C�g�ȃ}�b�v 
	// tips... ���̃}�b�v�ɓo�^�ł���̂� std::shared_ptr �̂�
	//         �o�^���� Class �� std::shared_ptr<Class> ��߂�l�Ƃ���
	//         fromFlyWeightLoader ���������邱�Ƃ� load �����s�����
	//         �t���C�E�F�C�g�� load �ɂȂ�܂�
	//         fromFlyWeightLoader �̓t���C�E�F�C�g���ӎ����Ȃ����[�h���\�b�h���������Ă������� 
	//

	template< class Key, class Class >
	class SharedFlyWeightMap {
	private:
		std::unordered_map< Key, std::shared_ptr<Class> > management_map_;
	public:

		//-------------------------------------------------------------------------------
		// ���݂̗L��
		inline bool isExist(const Key& key) {
			return (management_map_.end() != management_map_.find(key));
		}

		//-------------------------------------------------------------------------------
		// �o�^
		inline void regist(const Key & key, std::shared_ptr<Class> data) {
			management_map_.try_emplace(key, data);
		}

		//-------------------------------------------------------------------------------
		// �J��
		inline void erase(const Key & key) {
			std::unordered_map<std::string, std::shared_ptr<Class>>::iterator it = management_map_.find(key);
			if (management_map_.end() == it) return;
			management_map_.erase(it);
		}

		//-------------------------------------------------------------------------------
		// �S�J��
		inline void clear() { management_map_.clear(); }

		//-------------------------------------------------------------------------------
		// ���̃}�b�v�݂̂��Q�Ƃ��Ă���f�[�^���J��
		inline void eraseUnique() {
			std::unordered_map<std::string, std::shared_ptr<Class>>::iterator it = management_map_.begin();
			while (it != management_map_.end()) {
				if (1 < it->second.use_count()) {
					it++;
					continue;
				}
				it = management_map_.erase( it );
			}
		}

		//-------------------------------------------------------------------------------
		// �擾
		inline std::shared_ptr<Class> get(const Key & key) {
			std::shared_ptr<Class> ptr;
			try {
				ptr = management_map_.at(key);
			}
			catch (std::out_of_range&) {
				warningMassage(("missing map : " + key).c_str());
			}
			return ptr;
		}


		//-------------------------------------------------------------------------------
		// ���[�h�Ɠo�^
		template< class Desc >
		std::shared_ptr<Class> load(const Key & key, const Desc & desc) {
			std::shared_ptr<Class> ptr;
			if (isExist(key)) {
				ptr = get(key);
				return ptr;
			}
			ptr = Class::fromFlyWeightLoader(key, desc);
			regist(key, ptr);
			return ptr;
		}

	};

}
