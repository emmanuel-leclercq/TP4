#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    map<string, unsigned> m;
    ifstream f("declaration.txt");
    string s;
    while (f >> s)
    {
        ++m[s];
    }

    //ordre lexicographique
//    sort(m.begin(), m.end(), [](pair<string, unsigned> p1, pair<string, unsigned> p2)
  //       { return p1.first < p2.first; });

    // remplissage d'un fichier avec les mots

    ofstream g("stats.dat");
    for (auto p : m)
    {
        g << p.first << " " << p.second << endl;
    }

    cout << "nombre de mots différents: " << m.size() << endl;

    cout << "nombre de mots de longeur 7 lettres ou plus: ";
    cout << count_if(m.begin(), m.end(), [](pair<string, unsigned> p)
                     { return p.first.size() >= 7; });
    cout << endl;

    cout << "mot le plus fréquent: " << max_element(m.begin(), m.end(), [](pair<string, unsigned> p1, pair<string, unsigned> p2)
                                                    { return p1.second < p2.second; })
                                            ->first;
    cout << endl;

    cout << "son nombre d'apparitions: " << max_element(m.begin(), m.end(), [](pair<string, unsigned> p1, pair<string, unsigned> p2)
                                                        { return p1.second < p2.second; })
                                                ->second;
    cout << endl;

    cout << "nombre total de lettres: " << accumulate(m.begin(), m.end(), 0, [](unsigned n, pair<string, unsigned> p)
                                                      { return n + p.first.size() * p.second; });
    cout << endl;

    cout << "mots de plus de plus de 12 lettres, apparaissant au moins 13 fois,";
    cout << " ne conntenant pas la lettre 'e' et ne se terminant pas par la lettre 's': " << endl;
    for_each(m.begin(), m.end(), [](pair<string, unsigned> p)
             {
                 if (p.first.size() > 12 && p.second >= 13 && p.first.find('e') == string::npos && p.first.back() != 's')
                 {
                     cout << p.first << endl;
                 } });
    return 0;
};
