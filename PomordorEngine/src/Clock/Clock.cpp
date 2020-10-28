#include "pegpch.h"

#include "Clock.h"

namespace Pome {

	void Clock::Start()
	{
		if (OnRunning || !Setted)
			return;

		OnRunning = true;
		Begin = std::chrono::system_clock::now();
	}

	void Clock::Start(uint32_t sec, uint32_t minute, uint32_t hour)
	{
		Set(sec, minute, hour);
		Start();
	}

	void Clock::Start(std::string time)
	{
		auto[sec, minute, hour] = ParsingStrTime(time);
		Start(sec, minute, hour);
	}

	void Clock::Set(uint32_t sec, uint32_t minute, uint32_t hour)
	{
		if (OnRunning || Setted)
			return;

		Setted = true;
		SettedSec = sec + minute * 60 + hour * 60 * 60;
	}

	void Clock::Stop()
	{
		if (!OnRunning)
			return;

		OnRunning = false;
		Setted = false;
		SettedSec = 0;
	}

	void Clock::Update()
	{
		Duration = std::chrono::system_clock::now() - Begin;
		if (Duration.count() > (double)SettedSec)
			Stop();
	}

	Clock::Time Clock::GetRemainTime()
	{
		uint32_t remain = SettedSec - (uint32_t)Duration.count();

		uint32_t sec = remain % 60;
		uint32_t minute = remain / 60;
		uint32_t hour = remain / 3600;

		return {sec, minute, hour};
	}

	std::string Clock::GetStrRemainTime()
	{
		std::string ret;
		auto[sec, minute, hour] = GetRemainTime();

		auto secStr = std::to_string(sec);
		auto minuteStr = std::to_string(minute);
		auto hourStr = std::to_string(hour);

		if (minute < 10)
		{
			ret += "0";
		}
		ret += minuteStr + " : ";
		if (sec < 10)
		{
			ret += "0";
		}
		ret += secStr;

		return ret;
	}

	Clock::Time Clock::GetPastTime()
	{
		uint32_t past = (uint32_t)Duration.count();

		uint32_t sec = past % 60;
		uint32_t minute = past / 60;
		uint32_t hour = past / 3600;

		return {sec, minute, hour};
	}

	float Clock::GetRemainRatio()
	{
		double remain = (double)SettedSec - Duration.count();

		return remain / (double)SettedSec;
	}

	float Clock::GetPastRatio()
	{
		uint32_t past = (uint32_t)Duration.count();

		return (float)past/SettedSec;
	}

	Clock::Time Clock::ParsingStrTime(const std::string& time)
	{
		std::string token;
		std::vector<std::string> tokens;
		std::istringstream iss(time);

		while (std::getline(iss, token, ':'))
		{
			tokens.push_back(token);
		}

		uint32_t ret[3]{ 0 };
		uint32_t cnt = 0;
		for (auto it = tokens.rbegin(); it != tokens.rend(); ++it)
		{
			ret[cnt] = std::atoi(it->c_str());
			cnt++;
		}

		return {ret[0], ret[1], ret[2]};
	}

}