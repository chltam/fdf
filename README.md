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
y'' = y * cos(a) - z * sin(a)
z'' = y * sin(a) + z * cos(a)
```
### Around y-axis

```
x'' = x * cos(b) + z * sin(b)
y'' = y
z'' = -x * sin(b) + z * cos(b)
```
### Around z-axis
```
x'' = x * cos(c) - y * sin(c)
y'' = x * sin(c) + y * cos(c)
z'' = z
```
