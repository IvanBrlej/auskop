#include "UzemnaJednotka.h"
#include "structures/heap_monitor.h"

UzemnaJednotka::UzemnaJednotka()
{
}

UzemnaJednotka::~UzemnaJednotka()
{
	delete vzdelanieTabulka_;
}

void UzemnaJednotka::setSortNumber(int sortNumber)
{
	sortNumber_ = sortNumber;
}

void UzemnaJednotka::setCode(std::string code)
{
	code_ = code;
}

void UzemnaJednotka::setOfficialTitle(std::string officialTitle)
{
	officialTitle_ = officialTitle;
}

void UzemnaJednotka::setMediumTitle(std::string mediumTitle)
{
	mediumTitle_ = mediumTitle;
}

void UzemnaJednotka::setShortTitle(std::string shortTitle)
{
	shortTitle_ = shortTitle;
}

void UzemnaJednotka::setNote(std::string note)
{
	note_ = note;
}

void UzemnaJednotka::setTypUzemnejJednotky(TypUzemnejJednotky typJednotky)
{
	typJednotky_ = typJednotky;
}

void UzemnaJednotka::setPocetObyvatelov(int obyvatelia)
{
	pocetObyvatelov_ = obyvatelia;
}

UzemnaJednotka& UzemnaJednotka::getVyssiaUzemnaJednotka()
{
	return *vyssiaUzemnaJednotka_;
}

structures::Array<int>& UzemnaJednotka::getVzdelanieTabulka()
{
	return *vzdelanieTabulka_;
}

int UzemnaJednotka::getSortNumber()
{
	return sortNumber_;
}

std::string UzemnaJednotka::getCode()
{
	return code_;
}

std::string UzemnaJednotka::getOfficialTitle()
{
	return officialTitle_;
}

std::string UzemnaJednotka::getMediumTitle()
{
	return mediumTitle_;
}

std::string UzemnaJednotka::getShortTitle()
{
	return shortTitle_;
}

std::string UzemnaJednotka::getNote()
{
	return note_;
}

TypUzemnejJednotky UzemnaJednotka::getTypUzemnejJednotky()
{
	return typJednotky_;
}

std::string UzemnaJednotka::getStringTypUzemnejJednotky()
{
	 if (typJednotky_ == OBEC) {
		 return "OBEC";
	 }
	 else if (typJednotky_ == OKRES) {
		 return "OKRES";	
	 }
	 else if (typJednotky_ == KRAJ) {
		 return "KRAJ";
	 }
	 else {
		 return " ";
	 }
}

int UzemnaJednotka::vypocitajPocetObyvatelov(std::string obec)
{
	std::string line, code, uzemnaJednotka, bezUkoncenia, zakladne, stredne, uplnestredne, odborne, vysokoskolske, bezVzdelania, nezistene;

	int bezUkonceniaInt = 0;
	int	zakladneInt = 0;
	int stredneInt = 0;
	int uplnestredneInt = 0;
	int odborneInt = 0;
	int vysokoskolskeInt = 0;
	int bezVzdelaniaInt = 0;
	int nezisteneInt = 0;

	ifstream subor_;

	int obyvatelia = 0;

	subor_.open("data/vzdelanie.csv");

	if (subor_.is_open()) {
		getline(subor_, line);

		while (getline(subor_, line)) {
			stringstream lineStream(line);

			getline(lineStream, code, ';');
			if (code.find(obec) != std::string::npos) {
			
				getline(lineStream, uzemnaJednotka, ';');
				
				getline(lineStream, bezUkoncenia, ';');
				obyvatelia += stoi(bezUkoncenia);

				getline(lineStream, zakladne, ';');
				obyvatelia += stoi(zakladne);

				getline(lineStream, stredne, ';');
				obyvatelia += stoi(stredne);

				getline(lineStream, uplnestredne, ';');
				obyvatelia += stoi(uplnestredne);
				
				getline(lineStream, odborne, ';');
				obyvatelia += stoi(odborne);
				
				getline(lineStream, vysokoskolske, ';');
				obyvatelia += stoi(vysokoskolske);

				getline(lineStream, bezVzdelania, ';');
				obyvatelia += stoi(bezVzdelania);

				getline(lineStream, nezistene, ';');
				obyvatelia += stoi(nezistene);

				bezUkonceniaInt += stoi(bezUkoncenia);
				zakladneInt += stoi(zakladne);
				stredneInt += stoi(stredne);
				uplnestredneInt += stoi(uplnestredne);
				odborneInt += stoi(odborne);
				vysokoskolskeInt += stoi(vysokoskolske);
				bezVzdelaniaInt += stoi(bezVzdelania);
				nezisteneInt += stoi(nezistene);
			}
		}

		vzdelanieTabulka_->at(0) = bezUkonceniaInt;
		vzdelanieTabulka_->at(1) = zakladneInt;
		vzdelanieTabulka_->at(2) = stredneInt;
		vzdelanieTabulka_->at(3) = uplnestredneInt;
		vzdelanieTabulka_->at(4) = odborneInt;
		vzdelanieTabulka_->at(5) = vysokoskolskeInt;
		vzdelanieTabulka_->at(6) = bezVzdelaniaInt;
		vzdelanieTabulka_->at(7) = nezisteneInt;

		subor_.close();
		return obyvatelia;
	}
	//subor_.close();
}

int UzemnaJednotka::getPocetObyvatelov()
{
	return pocetObyvatelov_;
}

int UzemnaJednotka::getVzdelaniePodiel()
{
	return vzdelaniePodiel_;
}

int UzemnaJednotka::getVzdelaniePocet()
{
	return vzdelaniePocet_;
}

void UzemnaJednotka::setVyssiaUzemnaJednotka(UzemnaJednotka* vyssia)
{
	vyssiaUzemnaJednotka_ = vyssia;
}


