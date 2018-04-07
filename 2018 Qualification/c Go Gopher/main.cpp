#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;  // since cin and cout are both in namespace std
    
int main() {
  int num_test_cases;
  cin >> num_test_cases;

  for (int i = 0; i < num_test_cases; ++i) 
  {
    int A;
    cin >> A;

    vector<int> rs, cs;
    int colForLastRow;

    if (A == 20)
    {
        // trying to make 3x7 board, last block only need to check 1 column
        rs = vector<int>{2};
        cs = vector<int>{2, 5, 6};
        colForLastRow = 1; // +1 --> +1 for column 7
    }
    else if (A == 200)
    {
        // trying to make 12x17 board, last block only need to check 2 column
        rs = vector<int>{2, 5, 8, 11};
        cs = vector<int>{2, 5, 8, 11, 14, 16};
        colForLastRow = 0; // 0 --> +1 for column 16, 17
    }
    else
    {
        printf("Not expecting A of %d\n", A);
        continue;
    }

    int rowIn, colIn;

    // loop each center of a 3x3 block, make sure each block is completed before continue
    for (int ir : rs)
        for (int ic : cs)
        {
            // all 9 neighbor cells to be digged
            set<pair<int, int>> tasks;
            int strInd = (ic == cs.back()) ? colForLastRow : -1; // last column, less tasks

            // row -1 --> +1. And col -1 --> +1 if not right most block
            for (int i = -1; i <= 1; ++i)
                for (int j = strInd; j <= 1; ++j)
                    tasks.insert({ir+i, ic+j});

            while(!tasks.empty())
            {
                cout << ir << " " << ic << endl;
                cin >> rowIn >> colIn;
                if (rowIn == -1 && colIn == -1) break;
                if (rowIn == 0 && colIn == 0) break;
                tasks.erase({rowIn, colIn});
            }
        }

  }
  return 0;
}
