//±©Ò»³À 202130270029 
#include "character.h"
#include <cstddef>

people::people(int node, bool mask) {
	is_sick = symptom = vaccinated = isolated = ongoing = stay = 0;
	latency = anti_value = 1;
	active = 0.5;
	mask_on = mask;
	home_node = node;
	location = &build;
	destination = NULL;
}
const bool people::infected(bool PCR, bool nofake) const {
	if (is_sick && nofake)
		return is_sick;
	if (latency)
		if (is_sick && PCR)
			return hit(0.8); //20% fake-negative
	return is_sick && !latency;
}
const place* people::locate() const {
	return location;
}
const bool people::masked() const {
	return mask_on;
}
const int people::get_home() const {
	return home_node;
}
const int people::infect(double place) {
	if (hit(Rt * place * anti_value * (1 - 0.9 * mask_on) * (1 - 0.8 * vaccinated)))
		is_sick = true;
	return is_sick ? 1 : 0;
}
void people::isolate() {
	isolated = true;
	location->leaving(infected());
}
const bool people::move(int time) {
	if (isolated)
		return false;
	if (destination) {
		if (ongoing)
			--ongoing;
		else {
			location = destination;
			destination = NULL;
		}

	}
	else if (stay)
		--stay;
	else
		;// decide destination
	if (infected(true, true)) {
		if (latency) {
			if (!(--latency))
				location->infected();
		}
		else if (!symptom) {
			symptom = hit(0.5);
		}
		else if (speed) {

		}
		else if (report) {
			isolate();
			location->check();
		} //be reported to the authority
	}
	else {
		return infect(location->rate()) ? 1 : 0;
	}
	return 0;
}

student::student(int node, bool mask) :people(node, mask) {
	active = 0.4;
	anti_value = 0.7;
	latency = 3;
}