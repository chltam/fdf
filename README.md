# fdf

## Cartesian coordinate into isometric projection

```
iso_x = (x - y) * cos(30°)
iso_y = (x + y) * sin(30°) - z
```
## Horizontal Rotation:

```
x' = x * cos(a) - y * sin(a)
y' = x * sin(a) + y * cos(a)
```

## Vertical Rotation:

```
x'' = x * cos(b) + z * sin(b)
z'' = -x * sin(b) + z * cos(b)
```
