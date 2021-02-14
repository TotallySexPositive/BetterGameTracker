#pragma once
#include <string>
#include <istream>
#include <ostream>

enum class ResultType
{
	WIN,
	LOSS,
	UNINITIALIZED
};

class ResultObject
{
public:
	ResultObject();
	virtual ~ResultObject() = 0 {};
	virtual void win() = 0;
	virtual void lose() = 0;
	virtual std::ostream save() = 0; //get a stream representation to save to file
	virtual bool load(std::istream) = 0; //load the string representation from a stream
private:
	int m_wins;
	int m_losses;
	int m_streak;
	
	ResultType m_last;
};