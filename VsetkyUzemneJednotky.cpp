#include "VsetkyUzemneJednotky.h"
#include "structures/heap_monitor.h"

VsetkyUzemneJednotky::VsetkyUzemneJednotky() :
	vsetkyUzemneJednotky_(new structures::SortedSequenceTable<std::string, UzemnaJednotka*>())
	//,vsetkyUzemneJednotkyNeutriedene_(new structures::UnsortedSequenceTable<std::string, UzemnaJednotka*>())
{
	nacitanieDat("data/kraje.csv");
	nacitanieDat("data/okresy.csv");
	nacitanieDat("data/obce.csv");
}

VsetkyUzemneJednotky::~VsetkyUzemneJednotky()
{
	for (auto jednotka : *vsetkyUzemneJednotky_) {
		delete jednotka->accessData();
	}

	//delete vsetkyUzemneJednotkyNeutriedene_;
	delete vsetkyUzemneJednotky_;
}

structures::SortedSequenceTable<std::string, UzemnaJednotka*>* VsetkyUzemneJednotky::getUtriedenaTabulka()
{
	return vsetkyUzemneJednotky_;
}

//structures::UnsortedSequenceTable<std::string, UzemnaJednotka*>* VsetkyUzemneJednotky::getNeutriedenaTabulka()
//{
//	return vsetkyUzemneJednotkyNeutriedene_;
//}

void VsetkyUzemneJednotky::nacitanieDat(string subor)
{
	string line, line2, code, officialTitle, mediumTitle, shortTitle, sortNumber, note;

	subor_.open(subor);

	if (subor_.is_open()) {
		getline(subor_, line);

		while (getline(subor_, line)) {
			stringstream lineStream(line);

			getline(lineStream, sortNumber, ';');
			
			getline(lineStream, code, ';');

			getline(lineStream, officialTitle, ';');

			getline(lineStream, mediumTitle, ';');

			getline(lineStream, shortTitle, ';');

			getline(lineStream, note, ';');

			if (officialTitle != "Zahranicie") {
				UzemnaJednotka* uzemna_jednotka = new UzemnaJednotka();
				uzemna_jednotka->setSortNumber(stoi(sortNumber));
				uzemna_jednotka->setCode(code);
				uzemna_jednotka->setOfficialTitle(officialTitle);
				uzemna_jednotka->setMediumTitle(mediumTitle);
				uzemna_jednotka->setShortTitle(shortTitle);
				uzemna_jednotka->setNote(note);

				if (code.length() == 1) {
					uzemna_jednotka->setTypUzemnejJednotky(KRAJ);
				}
				else if (code.length() == 6) {
					uzemna_jednotka->setTypUzemnejJednotky(OKRES);
				}
				else if (code.length() == 12) {
					uzemna_jednotka->setTypUzemnejJednotky(OBEC);
				}

				if (uzemna_jednotka->getTypUzemnejJednotky() == OBEC) {
					uzemna_jednotka->setVyssiaUzemnaJednotka(vsetkyUzemneJednotky_->find(code.substr(0, 6)));
				}
				else if (uzemna_jednotka->getTypUzemnejJednotky() == OKRES) {
					uzemna_jednotka->setVyssiaUzemnaJednotka(vsetkyUzemneJednotky_->find(code.substr(0, 5)));
				}
				else {
					uzemna_jednotka->setVyssiaUzemnaJednotka(nullptr);
				}

				if (uzemna_jednotka->getStringTypUzemnejJednotky() != "KRAJ")
					uzemna_jednotka->setPocetObyvatelov(uzemna_jednotka->vypocitajPocetObyvatelov(code));

				if (uzemna_jednotka->getTypUzemnejJednotky() == KRAJ) {
					vsetkyUzemneJednotky_->insert(note.substr(5, 5), uzemna_jednotka);
					//vsetkyUzemneJednotkyNeutriedene_->insert(note.substr(5,5), uzemna_jednotka);
					uzemna_jednotka->setPocetObyvatelov(uzemna_jednotka->vypocitajPocetObyvatelov(note.substr(5, 5)));
				}
				else {
					vsetkyUzemneJednotky_->insert(code, uzemna_jednotka);
					//vsetkyUzemneJednotkyNeutriedene_->insert(code, uzemna_jednotka);
				}

				if (uzemna_jednotka->getTypUzemnejJednotky() == OBEC) {
					cout << uzemna_jednotka->getCode() << "  " << uzemna_jednotka->getStringTypUzemnejJednotky() << "  " << uzemna_jednotka->getOfficialTitle() << "  " << uzemna_jednotka->getVyssiaUzemnaJednotka().getOfficialTitle() << "  " << "Pocet obyvatelov: " << uzemna_jednotka->getPocetObyvatelov() << "  " << "Zakladne vzdelanie " << uzemna_jednotka->getVzdelanieTabulka().at(1) << endl;
				}
				else if (uzemna_jednotka->getTypUzemnejJednotky() == KRAJ) {
					cout << uzemna_jednotka->getCode() << "  " << uzemna_jednotka->getStringTypUzemnejJednotky() << "  " << uzemna_jednotka->getOfficialTitle() << "  " << uzemna_jednotka->getPocetObyvatelov() << "  " << endl;
				}
				else if (uzemna_jednotka->getTypUzemnejJednotky() == OKRES) {
					cout << uzemna_jednotka->getCode() << "  " << uzemna_jednotka->getStringTypUzemnejJednotky() << "  " << uzemna_jednotka->getOfficialTitle() << "  " << uzemna_jednotka->getVyssiaUzemnaJednotka().getOfficialTitle() << "  " << uzemna_jednotka->getPocetObyvatelov() << "  " << vsetkyUzemneJednotky_->size() << endl;
				}
			}
		}
		cout << vsetkyUzemneJednotky_->size() << endl;
		subor_.close();
	}
}
