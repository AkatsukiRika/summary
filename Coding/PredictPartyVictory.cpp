#include <string>
#include <queue>
using namespace std;

class PredictPartyVictory {
public:
    struct Senator {
        int position;
        char party;
    };

    string predictPartyVictory(string senate) {
        if (senate.length() == 1) {
            if (senate[0] == 'R') {
                return "Radiant";
            } else {
                return "Dire";
            }
        }

        queue<Senator> senatorQueue;
        int countTotalR = 0;
        int countTotalD = 0;
        for (int i = 0; i < senate.length(); i++) {
            Senator tmp;
            tmp.position = i;
            tmp.party = senate[i];
            senatorQueue.push(tmp);
            if (senate[i] == 'R') {
                countTotalR++;
            } else {
                countTotalD++;
            }
        }

        int countBannedR = 0;
        int countBannedD = 0;
        int pendingBanR = 0;
        int pendingBanD = 0;
        
        while (countBannedR < countTotalR && countBannedD < countTotalD) {
            auto popFront = senatorQueue.front();
            senatorQueue.pop();
            if (popFront.party == 'R' && pendingBanR > 0) {
                pendingBanR--;
                countBannedR++;
                continue;
            } else if (popFront.party == 'D' && pendingBanD > 0) {
                pendingBanD--;
                countBannedD++;
                continue;
            }

            if (popFront.party == 'R') {
                pendingBanD++;
            } else {
                pendingBanR++;
            }
            senatorQueue.push(popFront);
        }

        if (countBannedR < countTotalR) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};

int main() {
    auto solution = std::unique_ptr<PredictPartyVictory>();
    auto result = solution->predictPartyVictory("RDD");
    printf("result=%s\n", result.c_str());
    return 0;
}