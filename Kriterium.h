#pragma once

template <typename ObjectType, typename ResultType>
class Kriterium
{
public:
	virtual ResultType evaluate(ObjectType& object) {};
};