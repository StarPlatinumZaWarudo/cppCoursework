#include <vector>

#ifndef AVCW_VOTE_H
#define AVCW_VOTE_H

typedef unsigned int candidate;

class vote{
    std::vector<candidate> preference;

public:
    vote(const std::vector <candidate> &prefs);
    bool spent() const;
    candidate first_preference() const;
    void discard(candidate c);
    int returnSize() const;
    candidate returnCandidate(int i) const;

};

#endif //AVCW_VOTE_H