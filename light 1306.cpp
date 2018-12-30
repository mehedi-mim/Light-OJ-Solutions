#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}
void shift_solution (ll & x, ll & y, ll a, ll b, ll cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions (ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    ll x, y, g;
    if (! find_any_solution (a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a>0 ? +1 : -1;
    ll sign_b = b>0 ? +1 : -1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution (x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution (x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y > maxy)
        shift_solution (x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap (lx2, rx2);
    ll lx = max (lx1, lx2);
    ll rx = min (rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
int main()
{
    //freopen("0utput.txt","w",stdout);
    ll T;
    scanf("%lld",&T);
    ll cs = 0;
    while(T--)
    {
        ll ans = 0;
        ll a,b,c,x1,x2,y1,y2;
        scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&x1,&x2,&y1,&y2);
        c = (0-c);
        if(!a && !b)
        {
            if(!c)
            {
                ll  keep1,keep2;
                keep1 = abs(x1-x2) + 1;
                keep2 = abs(y1 - y2) + 1;
                ans = keep1*keep2;
            }
            else
            {
                ans = 0;
            }
        }
        else if(!a)
        {
            if(c%b == 0)
            {
                if(c/b >= y1 && c/b <= y2)
                    ans = abs(x2-x1)+1;
                else
                    ans = 0;
            }
            else
                ans = 0;
        }
        else if(!b)
        {
            if(c%a == 0)
            {
                if(c/a >= x1 && c/a <= x2)
                    ans = abs(y2-y1)+1;
                else
                    ans = 0;
            }
            else
                ans = 0;
        }
        else
            ans = find_all_solutions(a,b,c,x1,x2,y1,y2);

        printf("Case %lld: %lld\n",++cs,ans);
    }
    return 0;
}
