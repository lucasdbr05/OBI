#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
const double  PI = 3.141592653589793;
int n,m, o;
const int MAX = 1e9+7;
struct Point {
	int x, y; 
	bool operator < (Point o){ 
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
	void operator+=(const Point& o) { x += o.x, y += o.y; } 
	void operator-=(const Point& o) { x -= o.x, y -= o.y; } 
	
};

vector<Point> pts;

// double angle(Point p){
//     double ret = atan2(p.y, p.x);
//     while(ret < 0)
//         ret += 2*PI;
//     return ret;
// }

// bool radialComp( Point &a,Point& b){
// 	Point v, u; 
//         v.x = a.x - cen.x;
// 		u.x = b.x - cen.x;
//         v.y = a.y - cen.y,
// 		u.y = b.y - cen.y;
// 	return angle(v) < angle(u);
// }




int check(Point& p, Point& s, Point& t){
    ii n = {p.x-s.x,p.y-s.y};
    ii m = {p.x-t.x,p.y-t.y};
    int ans = (n.first*m.second)-(n.second*m.first);
    
    return ans; 
}

int signal(Point& p, Point& s, Point& t){
    int i= check(p,s,t);
    if (i>0) return 1;
    else if(i<0) return -1;
    else return 0;
}


bool touch(Point& p, Point& s, Point& t){
    return (p.x<=max(t.x, s.x))&&(p.x>=min(t.x,s.x))&&(p.y<=max(t.y, s.y))&&(p.y>=min(t.y,s.y));
}

vector<Point> convex_hull(){
    vector<Point> lw, up;
    for (auto p: pts){
        while (lw.size()>1 and signal(p, lw[lw.size()-2], lw.back())>0){
            lw.pop_back();
        }
        lw.push_back(p); 
    }
    reverse(pts.begin(), pts.end());
    for (auto p: pts){
        while (up.size()>1 and signal(p, up[up.size()-2], up.back())>0){
            up.pop_back();
        }
        up.push_back(p); 
    }
    vector<Point> hull;
    for (int i=0; i<lw.size()-1; i++) hull.push_back(lw[i]);
    for (int i=0; i<up.size()-1; i++) hull.push_back(up[i]);
    return hull;
}
int32_t main(){
    cin >> n;
    
    for (int i=0; i<n; i++){
        Point p; cin >> p.x >> p.y;
        pts.push_back(p);
    }


    sort(pts.begin(), pts.end());
    vector<Point> hull = convex_hull();


    cout << hull.size()<< endl;
    for(auto pt:hull){
        
        cout << pt.x << " "<< pt.y << endl;
    }
    

}