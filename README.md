# fdf

## Cartesian coordinate into isometric projection

```
iso_x = (x - y) * cos(30°)
iso_y = (x + y) * sin(30°) - z
```
## Rotation

### Around x-axis

```
x'' = x
y'' = y * cos(b) - z * sin(b)
z'' = y * sin(b) + z * cos(b)
```
### Around y-axis

```
x'' = x * cos(a) + z * sin(a)
y'' = y
z'' = -x * sin(a) + z * cos(a)
```
### Around z-axis
```
x'' = x * cos(c) - y * sin(c)
y'' = x * sin(c) + y * cos(c)
z'' = z
```
