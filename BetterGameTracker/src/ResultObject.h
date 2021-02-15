#pragma once
#include <string>
#include <istream>
#include <ostream>
#include <map>

#include "flatbuffer/ResultObject_generated.h"


class ResultObject
{
public:
	ResultObject();
	ResultObject(int, int, int, std::string, BGT::Types::Result, float, float);
	~ResultObject() {};
	virtual void win();
	virtual void lose();
	virtual bool save(std::ostream*); //save the flatbuffer to a ostream
	static std::map<std::string, std::shared_ptr<ResultObject>> load(std::istream*); //load the flatbuffers from a istream

public:
	int wins;
	int losses;
	int streak;
	float mmr;
	float last_mmr;
	BGT::Types::Result previous;
	std::string mode;
};