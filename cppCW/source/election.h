#include "vote.h"

class election{
    std::vector<vote> votes;

public:
    void add_vote(const vote &v);
    int vote_count() const;
    void eliminate (candidate c);
    std::vector<std::pair<candidate, int>> ranked_candidates() const;
    std::vector<vote> getVotes();

};

election read_votes(std::istream &in);

#ifndef AVCW_ELECTION_H
#define AVCW_ELECTION_H
#endif //AVCW_ELECTION_H