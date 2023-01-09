#include <fstream>
#include <vector>
using namespace std;

int start, p[10];
struct point {int x,y;} a[10];

int rotate(point a, point b, point c)
{ return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x); }

int f (const int *k, const int *j)
{ int r=rotate(a[start],a[*j],a[*k]);
  if  (r!=0) return r; else
  { int dk=abs(a[start].x-a[*k].x)+abs(a[start].y-a[*k].y);
    int dj=abs(a[start].x-a[*j].x)+abs(a[start].y-a[*j].y);
    return dj-dk;
  }
}

int main()
{ int j, n, n1;
  fi>>n;
  n1=n-1;
  for (j=0;  j<n;  j++)
  { fi>>a[j].x>>a[j].y;
    p[j]=j;
  }
  for (j=0;  j<n1;  j++)
  if ((a[p[j]].x <  a[p[n1]].x) ||
     ((a[p[j]].x == a[p[n1]].x) && (a[p[j]].y < a[p[n1]].y)))
  swap(p[n1], p[j]);
  start=p[n1];

  qsort(p, n1, sizeof (int), (int(*) (const void *, const void *)) f);

  vector <int> s ={p[n1],p[0]};

  bool line=true;
  for (j=2; j<n; j++)
  { line = (rotate(a[0],a[1],a[j])==0);
    if (!line) break;
  }

  if (!line) for (j=1; j<n1; j++)
  { while (rotate(a[s[s.size()-2]],a[s[s.size()-1]],a[p[j]])<0) s.pop_back();
    s.push_back(p[j]);
  }
  fo<<s[0];
  for (j=1; j<s.size(); j++) fo<<" "<<s[j];
  fo << endl;
  return 0;
}
