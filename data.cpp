#include <iostream>
#include <random>
#include <ctime>

using namespace std;

const double MAX = 10000.0;
const double MIN = -100000.0;

int main() {
    mt19937 rng(time(0)); 
    uniform_int_distribution<int> type_dist(1, 52);
    int test_type = type_dist(rng);
    cout << test_type << endl;
    return 0;
}