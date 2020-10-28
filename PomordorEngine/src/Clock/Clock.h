#pragma once

#include <tuple>
#include <stdint.h>
#include <string>
#include <chrono>

namespace Pome {

	class Clock
	{
		//Time is sec, minute, hour;
		using Time = std::tuple<uint32_t, uint32_t, uint32_t>;

	public:
		Clock() = default;

	public:
		void Set(uint32_t sec, uint32_t minute, uint32_t hour);
		void Start();
		void Start(uint32_t sec, uint32_t minute, uint32_t hour);
		void Start(std::string time);

		void Stop();

		void Update();

		inline bool isRunning() const { return OnRunning; }

		//Return tuple is in order sec, minute, hour
		Time GetRemainTime();
		std::string GetStrRemainTime();

		Time GetPastTime();
		float GetRemainRatio();
		float GetPastRatio();

	private:
		Time ParsingStrTime(const std::string& time);

	private:
		bool OnRunning = false;
		bool Setted = false;
		uint32_t SettedSec; //sec

		std::chrono::system_clock::time_point Begin;
		std::chrono::duration<double> Duration;
	};

}