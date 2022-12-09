#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    float left, right;

    Line() : left(0), right(0) {}
    Line(float x_left, float x_right) : left(x_left), right(x_right) {}

    float length() {
        return abs(right - left);
    }

    friend ostream& operator<<(ostream &os, Line l) {
        return os << "(" << l.left << ", " << l.right << ")";
    }

    friend istream& operator>>(istream &is, Line l) {
        return is >> l.left >> l.right;
    }
};

void erase(vector<Line> &lines) {
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines.size(); j++) {
            if (lines[i].right >= lines[j].right && lines[i].left <= lines[j].left && i != j) {
                lines.erase(lines.begin() + j);
                j--;
            }   
        }
    }
}

int compare(const void* a, const void* b) {
    const Line* x = (Line*) a;
    const Line* y = (Line*) b;

    if (x->right == y->right) return 0;
    return x->right > y->right ? 1 : -1;
}

int main(int argc, char const *argv[]) {
    vector<Line> lines = {Line(-5, -2), Line(-3,  0), Line(-2, -1),
                          Line(1,  3),  Line(2,  4),  Line(4,  7)};

    // vector<Line> lines = {{-2, 0}, {-1.5, -0.5}, {-1, 0.5}, {0.5, 1.5}, {1, 3}, {1.5, 2}};

    erase(lines);
    qsort(&lines[0], lines.size(), sizeof(Line), compare);

    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }

    float len = lines[0].length();

    for (int i = 0; i < lines.size() - 1; i++) {
        if (lines[i].right <= lines[i+1].right && lines[i].right >= lines[i+1].left) {
            len += Line(lines[i].right, lines[i+1].right).length();
        } else {
            len += lines[i+1].length();
        }
    }

    cout << len << endl;
    
    return 0;
}
