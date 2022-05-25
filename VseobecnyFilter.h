#pragma once

template <typename ObjectType>
class VseobecnyFilter
{
public:
	virtual bool presiel(const ObjectType& object) = 0;
};