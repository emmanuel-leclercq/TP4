#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <deque>
#include <list>

using namespace std;

int main()
{
     unsigned N = 40000000;
     vector<double> c1(N);
     vector<double> c2(N);
     mt19937 G(time(nullptr));
     exponential_distribution<double> E(1.0);

     // étape 1: remplissage
     auto start = chrono::high_resolution_clock::now();
     for_each(c1.begin(), c1.end(), [&](double &x)
              { x = E(G); });
     auto end = chrono::high_resolution_clock::now();
     cout << "étape 1: remplissage " << endl;
     cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl
          << endl;

     // étape 2: compte les valeurs >10
     start = chrono::high_resolution_clock::now();
     unsigned n = count_if(c1.begin(), c1.end(), [](double x)
                           { return x > 10; });
     end = chrono::high_resolution_clock::now();
     cout << "étape 2: compte les valeurs >10 " << endl;
     cout << n << " " << endl;
     cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
     cout << endl;

     // étape 3: mise au carré des 15 premiers
     start = chrono::high_resolution_clock::now();
     transform(c1.begin(), c1.begin() + 15, c1.begin(), [](double x)
               { return x * x; });
     end = chrono::high_resolution_clock::now();
     cout << "étape 3: mise au carré des 15 premiers " << endl;
     cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
     cout << endl;

     // étape 4: copie vers le 2e vect
     start = chrono::high_resolution_clock::now();
     copy(c1.begin(), c1.end(), c2.begin());
     end = chrono::high_resolution_clock::now();
     cout << "étape 4: copie vers le 2e vect " << endl;
     cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
     cout << endl;

     // étape 5: tri de la 1e moitié
     start = chrono::high_resolution_clock::now();
     sort(c1.begin(), c1.begin() + N / 2);
     end = chrono::high_resolution_clock::now();
     cout << "étape 5: tri de la 1e moitié " << endl;
     cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
     cout << endl;

     // étape 6: swap
     start = chrono::high_resolution_clock::now();
     swap(c1, c2);
     end = chrono::high_resolution_clock::now();
     cout << "étape 6: swap " << endl;
     cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
     cout << endl;

     return 0;
}