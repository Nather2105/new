#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

// ��������� �����, ��������� ��� ���������� ����� �� ����������
// �� ����� ����� ��������������� � ������� ��������� qsort()
Point p0;

// �������� ������� ��� ������ ���� � �����
Point nextToTop(stack<Point>& S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// �������� ������� ��� ����� ������ ���� �����
void swap(Point& p1, Point& p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// �������� ������� ��� ���������� �������� ������
// �� p1 � p2
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y);
}
// ������ �������� �������������� �������� (p, q, r).
// ������� ������� ������� ��������
// 0 --> p, q � r ��������
// 1 --> �� ������������ �������
// 2 --> ����� ����������� ������
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // ���������
    return (val > 0) ? 1 : 2; // ����������� ��� ����� ����������� ������
}

// �������, ��� ��������������� �������� �������� qsort() ��� ���������� ������
// ����� ������� ����� �����
int compare(const void* vp1, const void* vp2)
{
    Point* p1 = (Point*)vp1;
    Point* p2 = (Point*)vp2;

    // ������ ��������
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

// ����� ������ �������� ������ � n �����.
void convexHull(Point points[], int n)
{
    // ������ �������� �����
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // ������� ������ ����� ������� ��� ������� ���
        // �������� ���� � ��� ��躿
        if ((y < ymin) || (ymin == y &&
            points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // �������� ������ ����� ����� �� ������� ����
    swap(points[0], points[min]);

    // ���������� n-1 ���� ������� ������� ������.
    // ����� p1 ����� ����� p2 � ������������� ��������, ���� p2
    // �� ������ �������� ��� (����� ����������� ������
    // ��������), �� p1
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // ���� �� ��� ����� ����� ��������� ��������� ��� �� p0,
    // ��������� ���, ��� ����, �� ����������� ��������� �� p0
    // �����'������, �� � ������������� ��������� ����� ������� ����
    // �������� ��������� ����� � ����, ���� ����� ��
    // ���� ����� �� ��������� ���.
    int m = 1; // ����������� ������ �������� ������
    for (int i = 1; i < n; i++)
    {
        // ����������� �������� i, ���� ���� i �� i+1 �������
        // ������� p0
        while (i < n - 1 && orientation(p0, points[i],
            points[i + 1]) == 0)
            i++;


        points[m] = points[i];
        m++;  // ������� ����� �������� ������
    }

    // ���� ������������� ����� ����� ������ ����� 3 �����,
    // ������ �������� ���������
    if (m < 3) return;

    // ������� ������� ���� � ������ ����� ��� �����
    // �� �����.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // �������� ����� n-3 �����
    for (int i = 3; i < m; i++)
    {
        // ����������� �������� �������, ���� ��� �����������
        // ����� next-to-top, top, �� points[i] �������
        //�� ���� �������
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    vector <Point> path;
    double suma = 0;
    // ����� ���� �� ������ �����, ������� ���� �����
    cout << "�����, �� ��������� ������ ��������: " << endl;
    while (!S.empty())
    {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        path.push_back(p);
        S.pop();
    }
    // ����������� ������� �������.
    for (int i = 0; i < path.size() - 1; i++) {
        double p = sqrt(pow(path[i + 1].x - path[i].x, 2) + pow(path[i + 1].y - path[i].y, 2));
        suma += p;
    }
    suma += sqrt(pow(path[0].x - path[path.size() - 1].x, 2) + pow(path[0].y - path[path.size() - 1].y, 2));
    cout << "������� �������: " << suma << endl;
}

int main()
{
    setlocale(LC_ALL, "UKR");
    cout << "����i�� �i���i��� �����: ";
    int n; cin >> n;
    cout << "����i�� �����." << endl;
    Point* points = new Point[n];
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
    }
    convexHull(points, n);
    return 0;
}
