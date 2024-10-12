#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::pair<int, int>> CATS(std::vector<std::vector<int>>& cats, std::vector<std::vector<int>>& people , std::vector<int>& catswithman , std::vector<int>& manwithcat , std::vector<int>& cat_index , int n) {
    while (std::count(catswithman.begin(), catswithman.end(), -1) != 0) {
        for (int i = 0; i < n; ++i) {
            if (catswithman[i] == -1) {
                int cat = i;
                int man = cats[cat][cat_index[cat]];

                if (manwithcat[man] == -1) {
                    catswithman[cat] = man;
                    manwithcat[man] = cat;
                } else {
                    int cat_preference;
                    int current_cat_preference;
                    int current_cat = manwithcat[man];
                    for (int j = 0; j < n; ++j) {
                        if (people[man][j] == cat) {
                            cat_preference = j;
                        }
                    }
                    for (int j = 0; j < n;++j) {
                        if (people[man][j] == current_cat) {
                            current_cat_preference = j;
                        }
                    }
                    if (cat_preference < current_cat_preference) {
                        catswithman[current_cat] = -1;
                        catswithman[cat] = man;
                        manwithcat[man] = cat;
                    } else {
                        cat_index[cat]++;
                    }
                }
            }
        }
    }
    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < n; ++i) {
        result.push_back({i, catswithman[i]});
    }
    sort(result.begin(), result.end());


    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;

    std::vector<int> catswithman(n, -1);
    std::vector<int> manwithcat(n, -1);
    std::vector<int> cat_index(n, 0);

    std::vector<std::vector<int>> cat(n, std::vector<int>(n));
    std::vector<std::vector<int>> people(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> cat[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> people[i][j];
        }
    }

    std::vector<std::pair<int , int>> result = CATS(cat, people , catswithman , manwithcat , cat_index , n);


    for (auto& pair : result) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}
