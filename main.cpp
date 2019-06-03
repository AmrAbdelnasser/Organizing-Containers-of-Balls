#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container)
{
  int n = container.size();
  vector<int> cap_each_cont;
  vector<int> num_balls_each_type;
  for (int i = 0; i < n; ++i) {
    int cap_cont = 0;
    int ball_type = 0;
    for (int j = 0; j < n; ++j) {
      cap_cont += container[i][j];
      ball_type += container[j][i];
    }
    cap_each_cont.push_back(cap_cont);
    num_balls_each_type.push_back(ball_type);
  }
  sort(cap_each_cont.begin(), cap_each_cont.end());
  sort(num_balls_each_type.begin(), num_balls_each_type.end());
  if (cap_each_cont == num_balls_each_type)
    return "Possible";
  else
    return "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
