#include "Log.h"

namespace util {

	Logger* Logger::s_instance = nullptr;

	Logger::Logger()
	{
	}

	Logger::~Logger()
	{
	}

	Logger* Logger::Instance()
	{
		if (s_instance == nullptr)
		{
			s_instance = new Logger();
		}

		return s_instance;
	}

	void Logger::Log(const std::string& str)
	{
		std::cout << str << '\n';
	}

}