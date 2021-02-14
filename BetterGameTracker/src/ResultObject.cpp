#include "ResultObject.h"

ResultObject::ResultObject()
{
	m_losses = 0;
	m_streak = 0;
	m_wins = 0;
	m_last = ResultType::UNINITIALIZED;
}

void ResultObject::win()
{
	m_wins++;
	if (m_last == ResultType::WIN)
	{
		m_streak++;
	}
	else
	{
		m_streak = 0;
		m_last = ResultType::WIN;
	}
}

void ResultObject::lose()
{
	m_losses++;
	if (m_last == ResultType::LOSS)
	{
		m_streak++;
	}
	else
	{
		m_streak = 0;
		m_last = ResultType::LOSS;
	}
}

std::ostream ResultObject::save()
{
	return std::ostream();
}

bool ResultObject::load(std::istream)
{
	return false;
}

