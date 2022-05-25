#include "NacitanieDat.h"
#include "VsetkyUzemneJednotky.h"
#include "structures/heap_monitor.h"

int main() {
	initHeapMonitor();
	VsetkyUzemneJednotky* jednotky = new VsetkyUzemneJednotky();
	delete jednotky;
	return 0;
}