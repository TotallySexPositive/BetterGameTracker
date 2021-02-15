#include "ResultObject.h"
#include <vector>
#include <fstream>

using namespace BGT::Types;

ResultObject::ResultObject() : ResultObject(0, 0, 0, "bullshit", Result::Result_UNINITIALIZED, 0.0, 0.0)
{

}

ResultObject::ResultObject(int wins = 0, int losses = 0, int streak = 0, std::string mode = "bullshit", Result previous = Result::Result_UNINITIALIZED, float mmr = 0.0, float last_mmr = 0.0) 
	: wins(wins), losses(losses), streak(streak), mode(mode), previous(previous), mmr(mmr), last_mmr(last_mmr)
{
}

void ResultObject::win()
{
	wins++;
	if (previous == Result::Result_WIN)
	{
		streak++;
	}
	else
	{
		previous = Result::Result_WIN;
		streak = 0;
	}
}

void ResultObject::lose()
{
	losses++;
	if (previous == Result::Result_LOSS)
	{
		streak++;
	}
	else
	{
		previous = Result::Result_LOSS;
		streak = 0;
	}
}

bool ResultObject::save(std::ostream* o)
{
	flatbuffers::FlatBufferBuilder builder(1024);
	auto fb_result = CreateResults(builder, wins, losses, streak, mmr, last_mmr, previous, builder.CreateString(mode));
	builder.FinishSizePrefixed(fb_result);
	
	char *buf = (char *)builder.GetBufferPointer();
	auto size = builder.GetSize();
	std::string s;
	s.assign(buf, buf + size);
	*o << s;
	return true;
}

std::map<std::string, std::shared_ptr<ResultObject>> ResultObject::load(std::istream* i)
{
	std::map<std::string, std::shared_ptr<ResultObject>> m;
	std::vector<char> file_buffer = std::vector<char>(std::istreambuf_iterator<char>(*i), std::istreambuf_iterator<char>());
	uint8_t pos = 0;
	const uint8_t SIZE_OFFSET = 4;
	char* buf = file_buffer.data();
	while (pos < file_buffer.size())
	{
		auto r = GetSizePrefixedResults(buf);
		auto offset = flatbuffers::GetPrefixedSize((uint8_t*)buf) + SIZE_OFFSET; //
		m[r->mode()->c_str()] = std::make_shared<ResultObject>(r->wins(), r->losses(), r->streak(), r->mode()->c_str(), r->previous(), r->mmr(), r->last_mmr());
		buf += offset;
		pos += offset;
	}
	
	return m;
}

