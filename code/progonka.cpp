#include <iostream>
#include <vector>

std::vector<float> progonka(std::vector<float> c, std::vector<float> b, std::vector<float> a, std::vector<float> d) {
	std::vector<float> p;
	std::vector<float> q;
	p.push_back(-c[0]/b[0]);
	q.push_back(d[0]/b[0]);
        for(size_t i = 1; i != c.size(); ++i) {
		float current_p = p[i - 1];
		float current_q = q[i - 1];	
		float newP = -c[i] / (a[i - 1] * current_p + b[i]);
	        float newQ = (d[i] - a[i-1] * current_q) / (a[i-1] * current_p + b[i]);
		p.push_back(newP);
		q.push_back(newQ);
	}
	float endUnknown = (d.back() - a.back() * q.back()) / (p.back() * a.back() + b.back());
	std::vector<float> solve(b.size());
	solve[solve.size() - 1] = endUnknown;
	for(size_t j = p.size() - 1; j != 0; --j) {
		float newUnknown = solve[j + 1] * p[j] + q[j];
		solve[j] = newUnknown;
	}
	solve[0] = -((c[0] / b[0]) * solve[1]) + d[0] / b[0];
	return solve;
}

int main() {

	std::vector<float> a {45, 2};
	std::vector<float> b {1, 2, 3};
	std::vector<float> c {11, 3};
	std::vector<float> d {12, 35, 56};
	std::vector<float> solve = progonka(c, b, a, d);
	for(size_t i = 0; i != solve.size(); ++i){
	   std::cout << solve[i] << "\n";
	}

}
