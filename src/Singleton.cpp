
#include "Singleton.hpp"

Singleton* Singleton::pinstance_{nullptr};
std::mutex Singleton::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Singleton *Singleton::GetInstance(void)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Singleton();
    }
    return pinstance_;
}

void	Singleton::change_angle_mod(void)
{
	_is_radian = !_is_radian;
}

bool	Singleton::is_radian() const
{
	return (_is_radian);
}