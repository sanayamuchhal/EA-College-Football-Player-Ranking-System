#ifndef NATIONAL_PLAYER_RANKING_SYSTEM_H
#define NATIONAL_PLAYER_RANKING_SYSTEM_H

#include <string>
#include <vector>

using namespace std;

// Forward Declarations
class Player;
class PlayerStats;
class RankingEntry;
class RivalTracker;

/* ===========================
   PlayerStats Class
   =========================== */
class PlayerStats {
private:
    int yards;
    int touchdowns;
    int interceptions;
    float efficiencyRating;

public:
    PlayerStats();

    void computeEfficiency();
    void resetWeeklyStats();

    // Getters
    int getYards() const;
    int getTouchdowns() const;
    int getInterceptions() const;
    float getEfficiencyRating() const;

    // Setters
    void setYards(int y);
    void setTouchdowns(int t);
    void setInterceptions(int i);
};


/* ===========================
   Player Class
   =========================== */
class Player {
private:
    string playerID;
    string name;
    string position;
    float rankingPoints;

    PlayerStats stats;

public:
    Player(string id, string n, string pos);

    void updateStats(int yards, int touchdowns, int interceptions);
    void calculateRankingPoints();

    // Getters
    string getPlayerID() const;
    string getName() const;
    string getPosition() const;
    float getRankingPoints() const;
    PlayerStats& getStats();

    // Setter
    void setRankingPoints(float points);
};


/* ===========================
   RankingEntry Class
   =========================== */
class RankingEntry {
private:
    int rankPosition;
    int weeklyChange;
    Player* player;

public:
    RankingEntry(Player* p, int rank);

    void updateRank(int newRank);

    // Getters
    int getRankPosition() const;
    int getWeeklyChange() const;
    Player* getPlayer() const;
};


/* ===========================
   RivalTracker Class
   =========================== */
class RivalTracker {
private:
    Player* mainPlayer;
    Player* rivalPlayer;
    float dominanceScore;

public:
    RivalTracker(Player* main, Player* rival);

    void compareWeeklyPerformance();
    void updateDominance();

    // Getters
    float getDominanceScore() const;
    Player* getMainPlayer() const;
    Player* getRivalPlayer() const;
};


/* ===========================
   RankingSystem Class
   =========================== */
class RankingSystem {
private:
    vector<Player*> playerList;
    vector<RankingEntry> weeklyRankings;

public:
    RankingSystem();

    void addPlayer(Player* player);
    void calculateAllRankingPoints();
    void sortPlayersByPosition();
    void updateWeeklyRankings();

    // Getters
    vector<RankingEntry> getWeeklyRankings() const;
};

#endif
