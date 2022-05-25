#pragma once
#include "FilterKriterium.h"
#include "Filte_fi.h"
#include "KriteriumUJPrislusnost.h"
#include <string>

class FilterUJPrislusnost : public Filter_fi<UzemnaJednotka,std::string>
 {

 public:
	 //FilterUJPrislusnost(std::string nazov) : Filter_fi(new KriteriumUJPrislusnost(), nazov) {};
};