#pragma once
#include <iostream>
#include <string>

namespace util {

	class Logger
	{
	public:
		Logger();
		~Logger();

		static Logger* Instance();

		void Log(const std::string& str);

	private:
		static Logger* s_instance;

	};

}