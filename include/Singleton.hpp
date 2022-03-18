#pragma once

#include "Map_variable.hpp"
#include <mutex>

/**
 * The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class Singleton
{
	private:
		static Singleton *pinstance_;
		static std::mutex mutex_;

	private:
		Singleton(void) {}
		~Singleton() {}

		//var
		bool exit = false;
		Map_variable	my_map;
		bool		_is_radian = false;

	public:
		Singleton(Singleton &other) = delete;
		void operator=(const Singleton &) = delete;

		static Singleton *GetInstance(void);

		bool	get_exit(void) const {return exit;}
		void		set_exit(bool val) {exit = val;}
		void		change_angle_mod(void);
		bool		is_radian(void) const;
		Map_variable &get_map_variable() {return my_map;}
};
