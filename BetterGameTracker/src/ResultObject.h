#pragma once
#include <string>
#include <istream>
#include <ostream>
#include "flatbuffer/ResultObject_generated.h"


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

	BGT::Types::Results* fb_result;
};