/** Includes **/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <vector>
#include <queue>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <set>
#include <random>
#include <map>

using namespace std;

/** Shortcuts **/
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define Pb pop_back
#define Pf pop_front
#define mp make_pair
#define INF (int32)1e9

//typedef long int int32;
//typedef unsigned long int uint32;
//typedef long long int int64;
//typedef unsigned long long int uint64;

typedef long long LL;
typedef long double LD;

/** Globals **/
class libinform {
public:
    int N, T, M, id_source;
};

int myrandom(int i) { return std::rand() % i; }

map<int, int> cost;
map<int, int> countBooks;

bool comp(const pair<libinform, set<int>>& a, const pair<libinform, set<int>> &b) {
    long long int s1 = 0;
    long long int s2 = 0;
    int uniqueness1 = 0;
    int uniqueness2 = 0;
    for (int x : a.se) {
        s1 += cost[-x];
        uniqueness1 += countBooks[-x];
    }

    for (int x : b.se) {
        s2 += cost[-x];
        uniqueness2 += countBooks[-x];
    }

//    return s1 * a.first.N * uniqueness2 * b.first.T > s2 * b.first.N * uniqueness1 * a.first.T;
    return a.first.T < b.first.T;
}

void solve() {
    int B;
    cin >> B;
    int L;
    cin >> L;
    int D;
    cin >> D;

//    cerr << B << " " << L << " " << D << endl;

//    cerr << "Finished reading 1" << " " << B << endl;
//
    vector<pair<int, int>> S(B);
    for (int i = 0; i < B; ++i) {
        cin >> S[i].fi;
        S[i].se = i;
        cost[S[i].se + 1] = S[i].fi;
    }
    std::sort(S.begin(), S.end());

//    cerr << "Finished reading 2" << endl;

    typedef pair<pair<int, int>, int> libinfo;

    vector<pair<libinform, set<int>>> lib(L);
    for (int j = 0; j < L; ++j) {
        int N, T, M;
        cin >> N >> T >> M;
        lib[j].fi.N = N;
        lib[j].fi.T = T;
        lib[j].fi.M = M;
        lib[j].fi.id_source = j;

        for (int i = 0; i < N; ++i) {
            int cur;
            cin >> cur;
            ++countBooks[cur];
            lib[j].se.insert(-cur);
        }
    }

//    cerr << /**/"Finished reading" << endl;

    sort(lib.begin(), lib.end(), comp);

//    cerr << "Finished sorting" << endl;

//    int givenBooks = 0;
//    vector<int> order(L);
//    for (int i = 0; i < L; ++i) {
//        order[i] = i;
//    }

//    cerr << "Finished ordering" << endl;


    int timeSum = 0;
    int i = 0;

    vector<pair<int, set<int>>> result;
    map<int, int> usedBook;
    while (i < L && timeSum + lib[i].first.T < D) {
        int daysEnd = timeSum + lib[i].first.T;
        int id = -1;
        for (int days = timeSum; days < D; ++days) {
            if (days > daysEnd) {
                id = days;
                break;
            }
        }
        timeSum += lib[i].first.T;

//    cerr << "Finished counting days" << endl;

        int answer = 0;
        set<int> scanBooks;
        map<int, bool> used;
        for (int j = id; j < D; ++j) {
            auto it = lib[i].se.begin();
//        int j = 0;
//        while (j < min(lib[order[0]].fi.M) {
//            if (!used[])
//        }
            for (int k = 0; k < min(lib[i].fi.M, (int) lib[i].se.size()); ++k) {
//            cerr << -(*it) << endl;
                if (!usedBook[-(*it)]) {
                    answer += cost[-(*it)];
                    scanBooks.insert(-(*it));
                }
                lib[i].se.erase(it);
                ++it;
            }
        }
        result.pb({lib[i].fi.id_source, scanBooks});
        ++i;
    }

//    cerr << "Finished counting answer" << endl;

//    cout << " baldfnqlksjdhf" << endl;
//    cerr << "Here" << endl;
    cout << (int) result.size() << endl;
    for (auto &p : result) {
        cout << p.first << " " << p.second.size() << endl;
        for (auto &el : p.second) {
            cout << el << " ";
        }
        cout << endl;
    }
//    /*
//     * OUT
//     * A (0 ≤ A ≤ L) – the number of libraries to sign up (you don't need to sign up all libraries
//     * the 1rst line containing:
//     * Y–the ID of the library,
//     * K (1 ≤ K ≤ NY) – the number of books to be scanned from library Y.
//     * the second line containing the IDs of the books to scan from that library:
//     * k0, ... , kK-1, (0 ≤ ki ≤ B–1) in the order that they are scanned, without duplicates.
//     */
//
//    cerr << "Finished" << endl;
}

//#define __debug_mode
int main() {
    auto start = std::chrono::steady_clock::now();
    std::ios_base::sync_with_stdio(false);

    vector<pair<const char *, const char *>> input =
            {mp("a.txt", "a.out"),
             mp("b.txt", "b.out"),
             mp("c.txt", "c.out"),
             mp("d.txt", "d.out"),
             mp("e.txt", "e.out"),
             mp("f.txt", "f.out")};

//#ifdef __debug_mode
//    freopen("a_example.txt", "r", stdin);
//    freopen("a_example.out", "w", stdout);
//    int num_of_tests = 0;
//    cin >> num_of_tests;
//    for (int i = 0; i < num_of_tests; ++i)
//        solve();
//#else
    freopen("a.txt", "r", stdin);
    freopen("a.out", "w", stdout);
    solve();
//#endif

//    for (const auto &en : input) {
//        freopen(en.fi, "r", stdin);
//        freopen(en.se, "w", stdout);
//        cerr << "Done " << en.fi << endl;
//        solve();
//    }

    auto finish = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    cerr << "Elapsed: " << elapsed_ms.count() << " ms\n";
    return 0;
}

