#pragma once

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;


class TimerControler
{
public:
	void Tick();
	inline float GetDeltaTime() { return m_DeltaTime; }
	inline static TimerControler* GetInstance() { return s_Instance = (s_Instance != nullptr)? s_Instance : new TimerControler();}


private:
	TimerControler() {};
	static TimerControler* s_Instance;
	float m_DeltaTime = 0;
	float m_LastTime = 0;;
};

