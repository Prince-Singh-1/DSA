class Bank {
public:
    vector<long long> bal;

    Bank(vector<long long>& balance) {
        bal = balance;
    }

    bool transfer(int i, int j, long long money) {
        if (i < 1 || i > bal.size() || j < 1 || j > bal.size())
            return false;

        i--;
        j--;

        if (bal[i] >= money) {
            bal[i] -= money;
            bal[j] += money;
            return true;
        }

        return false;
    }

    bool deposit(int i, long long money) {
        if (i < 1 || i > bal.size())
            return false;

        i--;
        bal[i] += money;
        return true;
    }

    bool withdraw(int i, long long money) {
        if (i < 1 || i > bal.size())
            return false;

        i--;

        if (bal[i] >= money) {
            bal[i] -= money;
            return true;
        }

        return false;
    }
};