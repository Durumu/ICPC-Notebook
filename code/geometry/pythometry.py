from cmath import *

def dot(a, b):
    return (a.conjugate() * b).real

def cross(v, w):
    return v.real*w.imag - v.imag*w.real

# turn direction of angle centered at b
# left turn, >0. collinear, ==0
def ccw(a, b, c):
    return cross(b-a, c-a)

# in: set of points (complexes), len >= 3
# out: list of points in order
def graham_scan(point_set):
    if len(point_set) <= 3:
        return list(point_set)
    piv = min(point_set, key=lambda c: (c.imag, c.real))
    pts = sorted(point_set - {piv}, key=lambda p: -phase(p - piv))
    hull = [piv, pts[0]]
    for pt in pts[1:]:
        while len(hull) > 1 and ccw(hull[-2], hull[-1], pt) >= 0:
            hull.pop()
        hull.append(pt)
    return hull 

def perimeter(polygon):
    if len(polygon) == 1:
        return 0
    elif len(polygon) == 2:
        return abs(polygon[0]-polygon[1])
    return sum(abs(b-a) for a, b in zip(polygon, polygon[1:] + [polygon[0]]))

while 1:
    n = int(input())
    if not n:
        break
    pts = {complex(*map(int, input().split())) for _ in range(n)}
    tape = perimeter(graham_scan(pts))
    print('Tera que comprar uma fita de tamanho {:.2f}.'.format(tape))
