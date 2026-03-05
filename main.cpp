#include <iostream>
#include "player_ranking_system.h"

using namespace std;

int main() {

    // Create ranking system
    RankingSystem system;

    // Create players
    Player* p1 = new Player("QB01", "Caleb Williams", "QB");
    Player* p2 = new Player("QB02", "Drake Maye", "QB");
    Player* p3 = new Player("QB03", "Michael Penix", "QB");

    // Add players to ranking system
    system.addPlayer(p1);
    system.addPlayer(p2);
    system.addPlayer(p3);

    // Update stats
    p1->updateStats(350, 3, 1);
    p2->updateStats(320, 2, 0);
    p3->updateStats(290, 2, 2);

    // Calculate rankings
    system.calculateAllRankingPoints();
    system.updateWeeklyRankings();

    // Display rankings
    vector<RankingEntry> rankings = system.getWeeklyRankings();

    cout << "===== NATIONAL PLAYER POWER RANKINGS =====" << endl;

    for (auto &entry : rankings) {
        Player* player = entry.getPlayer();
        cout << "#" << entry.getRankPosition()
             << " " << player->getName()
             << " (" << player->getPosition() << ")"
             << " Points: " << player->getRankingPoints()
             << endl;
    }

    return 0;
}
