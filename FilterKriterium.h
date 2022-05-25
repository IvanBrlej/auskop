#pragma once
#include "VseobecnyFilter.h"
#include "KriteriumUJNazov.h"

template <typename ObjectType, typename ValueType>
class FilterKriterium : public VseobecnyFilter<ObjectType>
{
private:
	Kriterium<ObjectType, ValueType>* kriterium_;
protected:
	virtual bool presielFilter(ValueType value) = 0;
public:
	bool presiel(const ObjectType& object)override
	{
		return presielFilter(kriterium_->evaluate(object));
	};
};