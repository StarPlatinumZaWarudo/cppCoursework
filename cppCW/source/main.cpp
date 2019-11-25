#include <iostream>
#include <fstream>
#include "vote.h"
#include "election.h"
#include <vector>

int main() {
    bool winner = false;
    int round = 1;
    election e;
    std::fstream in("votes.txt");
    if(in.is_open()) {
    e = read_votes(in);

    }
    while(!winner) {
        std::cout << "Round " << round << ": " << e.vote_count() << " votes" << std::endl;
        std::cout << "First preference: \n";
        std::vector<std::pair<candidate, int>> rankedCandidates = e.ranked_candidates();
        for(int i = 0; i < rankedCandidates.size(); i++){
            std::cout << "Candidate " << rankedCandidates[i].first << " : " << rankedCandidates[i].second << "\n";
        }
        if(rankedCandidates[0].second > e.vote_count() /2){
            winner = true;
            std::cout << "Candidate " << rankedCandidates[0].first << " is elected" << std::endl;
        }
        else{
            std::cout <<"Candidates " << rankedCandidates[rankedCandidates.size() -1].first <<" has been eliminated";
            e.eliminate(rankedCandidates[rankedCandidates.size() -1].first);
        }
        round++;
        std::cout << "\n";
    }
    return 0;
}