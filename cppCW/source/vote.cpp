#include "vote.h"

vote::vote(const std::vector <candidate> &prefs) : preference(prefs) {

}

bool vote::spent() const {
    return preference.empty();
}
candidate vote::first_preference() const {
    if(!spent()) {
            return preference.at(0);
    }
    return 0;
}

void vote::discard(candidate c) {
    for (int i = 0; i < preference.size(); i++) {
        if (preference[i] == c) {
            preference.erase(preference.cbegin() +i);
        }
    }
}

int vote::returnSize() const {
    return preference.size();
}

candidate vote::returnCandidate(int i) const {
    return preference[i];
}