#include "election.h"
#include "vote.h"
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>

void election::add_vote(const vote &v){
    votes.push_back(v);
}

int election::vote_count() const {
    return votes.size();
}

std::vector<vote> election::getVotes() {
    return votes;
}

void election::eliminate (candidate c) {
    for (vote &v : votes) {
        v.discard(c);
    }
    votes.erase(remove_if(votes.begin(), votes.end(), [](vote &v) { return v.spent(); }), votes.end());
}

bool compare(std::pair<candidate, int> p1, std::pair<candidate, int> p2){
    return p1.second > p2.second;
}

std::vector<std::pair<candidate, int>> election::ranked_candidates() const{
    std::vector<std::pair<candidate, int>> ranked_candidates;
    std::map<candidate, int> map;

    int i = 0;
    for(const vote &vote: votes){
        ++map[votes[i].first_preference()];
        ++i;
    }
    for (const auto &m : map) {
        ranked_candidates.push_back({m.first, m.second});
    }
    std::sort(ranked_candidates.begin(),ranked_candidates.end(), compare);
    return ranked_candidates;
}

election read_votes (std::istream &in){
    election e;
    std::string line;
    candidate  temp;

    while (getline(in, line)) {
        std::vector<candidate> prefs;
        std::stringstream s(line);
        while (s >> temp) {
            prefs.push_back(temp);
        }
        vote vote(prefs);
        e.add_vote(vote);
    }
    return e;
}
