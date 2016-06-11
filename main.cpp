#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

struct part {
    double prize;
    double weight;
    double coef;
};


int main() {
    long long ctr, sumweight, n, limit;
    double result;
    ctr = sumweight = 0;
    result = 0;
    std::vector<part> mercury;
    std::cin >> n >> limit;
    mercury.resize(n);
    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x;
        mercury[i].prize = x;
        std::cin >> y;
        mercury[i].weight = y;
        if (x == 0) {
            mercury[i].coef = 0;
        } else {
            mercury[i].coef = x / y;
        }
    }
    std::sort(mercury.begin(), mercury.end(), [] (const part& first, const part& second) {
        return first.coef > second.coef;
    });
    while (sumweight < limit || ctr < mercury.size()) {
        if (mercury[ctr].coef > 0) {
            if ((mercury[ctr].weight) <= limit - sumweight) {
                result += mercury[ctr].prize;
                sumweight += mercury[ctr].weight;
                ++ctr;
            } else {
                result += (limit - sumweight) * mercury[ctr].coef;
                sumweight += limit - sumweight;
                ++ctr;
            }
        } else {
            break;
        }
    }
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << result << "\n";
}
