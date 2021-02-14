#include "ResultObject.h"
#include <ostream>
ResultObject::ResultObject()
{
}

void ResultObject::win()
{
}

void ResultObject::lose()
{
}

std::ostream ResultObject::save()
{
	std::ostream x();
	return x;
}

bool ResultObject::load(std::istream)
{
	return false;
}

