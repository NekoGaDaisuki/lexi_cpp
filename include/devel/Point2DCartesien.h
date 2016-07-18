#ifndef _POINT2DCARTESIEN_H
# define _POINT2DCARTESIEN_H

class Point2DCartesien
{
public:
    Point2DCartesien(double x, double y) : _x(x), _y(y) {}
    ~Point2DCartesien() {}

    double getX() const { return _x; }
    void setX(double x) { _x = x; return *this; }

    double getY() const { return _y; }
    void setY(double y) { _y = y; return *this; }

protected:
    double _x, _y;
};
#endif /* _POINT2DCARTESIEN_H */
