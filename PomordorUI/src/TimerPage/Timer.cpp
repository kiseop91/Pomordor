#include "pompch.h"

#include "Timer.h"
#include "TimerPage.h"

#include "ui_TimerPage.h"
#include "TrayIcon.h"

Timer::Timer(TimerPage* myPage)
	: m_MyPage(myPage)
	, m_CurState(TimerState::None)
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
	m_CurState = TimerState::Porm;

	setTimerStateUi();
	updateSetCount();
	m_EngineClock.Start(m_MyPage->ui->TimerButton->text().toStdString());
}

void Timer::Stop()
{
	m_CurState = TimerState::None;
	
	setTimerStateUi();
	fillProgress(0.999f);
	m_EngineClock.Stop();
}

void Timer::setTimerStateUi()
{
	switch (m_CurState)
	{
	case TimerState::Break:
		m_MyPage->ui->TimerStateLabel->setText("Break");
		m_MyPage->ui->TimerStateLabel->setStyleSheet(SSTimerState_Break);
		m_MyPage->ui->TimerButton->setStyleSheet(SSTimerButton_Break);
		m_MyPage->ui->Progress_Back->setStyleSheet(SSProgress_Break_bg);
		break;
	case TimerState::Porm:
		m_MyPage->ui->TimerStateLabel->setText("Running");
		m_MyPage->ui->TimerStateLabel->setStyleSheet(SSTimerState_Porm);
		m_MyPage->ui->TimerButton->setStyleSheet(SSTimerButton_Porm);
		m_MyPage->ui->Progress_Back->setStyleSheet(SSProgress_Porm_bg);
		break;
	case TimerState::None:
		m_MyPage->ui->TimerStateLabel->setText("Pomordor");
		m_MyPage->ui->TimerStateLabel->setStyleSheet(SSTimerState_Porm);
		m_MyPage->ui->TimerButton->setStyleSheet(SSTimerButton_Porm);
		m_MyPage->ui->Progress_Back->setStyleSheet(SSProgress_Porm_bg);
		break;
	}
}

void Timer::updateSetCount()
{
	uint32_t setCount = m_SetTotal - (m_ScheduleQueue.size() + 1) / 2 + 1;
	if (m_CurState == TimerState::None)
		setCount = 0;
	QString setStr = "Set Count : " + QString::number(setCount) + " / " + QString::number(m_SetTotal);
	m_MyPage->ui->SetCountLabel->setText(setStr);
}

void Timer::fillProgress(float percentage)
{
	switch (m_CurState)
	{
	case TimerState::Porm: SSProgress = SSProgress_Porm; break;
	case TimerState::Break: SSProgress = SSProgress_Break; break;
	case TimerState::None: SSProgress = SSProgress_Porm; break;
	}

	SSProgress.replace(QString("{GradPoint_1}"), QString::number(percentage));
	SSProgress.replace(QString("{GradPoint_2}"), QString::number(percentage + 0.0001f));
	m_MyPage->ui->Progress_Front->setStyleSheet(SSProgress);
}

void Timer::Update()
{
	m_EngineClock.Update();

	float percentage = m_EngineClock.GetRemainRatio();
	m_MyPage->ui->TimerButton->setText(QString::fromStdString(m_EngineClock.GetStrRemainTime()));
	fillProgress(percentage);

	if (!m_EngineClock.isRunning())
	{
		//First : ToastMessage
		if (m_ScheduleQueue.begin()->first == TimerState::Porm)
		{
			m_MyPage->ToastMessage("Just one Pormodor done!", "Take a break", 3000);
		}
		else
		{
			if (m_ScheduleQueue.size() == 1)
			{
				m_MyPage->ToastMessage("The break Time done!", "Your Pomordor schedule is done!", 3000);
			}
			else
			{
				m_MyPage->ToastMessage("The break Time done!", "Next Pormordor time start now!", 3000);
			}
		}
		m_ScheduleQueue.pop_front();
		updateSetCount();

		//Second : Check schedule and exec
		if (m_ScheduleQueue.empty())
		{
			m_MyPage->timerFinish();
		}
		else
		{
			m_CurState = m_ScheduleQueue.begin()->first;
			setTimerStateUi();
			m_EngineClock.Start(0, m_ScheduleQueue.begin()->second, 0);
		}
	}
}
