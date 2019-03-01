#include<stdio.h>
#include<math.h>

struct Point2 { 
    double x, y; 

    Point2() { x = 0; y = 0; }

    Point2(double x_, double y_) {
        x = x_; y = y_;
    }

    Point2 operator + (const Point2& rhs) const {
        return Point2(x + rhs.x, y + rhs.y);
    }

    Point2 operator - (const Point2& rhs) const {
        return Point2(x - rhs.x, y - rhs.y);
    }

    Point2 operator / (const double rhs) const {
        return Point2(x / rhs, y / rhs);
    }
};

struct Matrix2 {
    double a00, a01, a10, a11;

    Matrix2(double a00_, double a10_, double a01_, double a11_) {
        a00 = a00_; a01 = a01_;
        a10 = a10_; a11 = a11_;
    }

    Point2 operator * (const Point2& rhs) const {
        return Point2(a00 * rhs.x + a01 * rhs.y, a10 * rhs.x + a11 * rhs.y);
    }
};

Matrix2 Rotation(double theta) {
    return Matrix2(cos(theta), sin(theta), -sin(theta), cos(theta));
}

Point2 operator * (const double lhs, const Point2& rhs) {
    return Point2(lhs * rhs.x, lhs * rhs.y);
}

void koch(int depth, Point2 from, Point2 to) {
    if (depth == 0) return;

    Point2 s, t, u;
    double theta = M_PI * 60.0 / 180.0;

    s = (2 * from + to) / 3.0;
    t = (from + 2 * to) / 3.0;
    u = Rotation(theta) * (t - s) + s;

    koch(depth - 1, from, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(depth - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(depth - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(depth - 1, t, to);
}

int main() {
    Point2 from = Point2(0, 0);
    Point2 to = Point2(100, 0);
    int depth;

    scanf("%d", &depth);
    printf("%.8f %.8f\n", from.x, from.y);
    koch(depth, from, to);
    printf("%.8f %.8f\n", to.x, to.y);

    return 0;
}
