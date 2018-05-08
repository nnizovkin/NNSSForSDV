# NNSSForSDV
Framework for nearest neighbour search for sequence of points in some trajectory.
Useful in different auto pilot systems.

We create a set of grids with one point of reference and scales by successive powers of two.
The grid is stored in a hash table with open addressing. The grid point is the intersection point of the grid lines.
For example, for a grid of scale 1 and a reference point of 0 0,
the grid points are for example (0 0) (0 1) (0 2) (1 1) (1 2), etc.

When adding a new point to the grid, we look for the nearest point on the
grid to the given one and add it to the hash table. Add a point to the grid of each scale.

To scale the application: grids can be cut and stored in parts and, if necessary, loaded.

When looking for the nearest neighbor of point A, if point A does not fall into a piece of sliced ​grids we overload the sliced grids.
When searching for the nearest neighbor of point A, we are looking for a grid with a minimum scale, in which for the
point on the grid closest to A the nearest point was added. In other words, we round of the point A to point on the grid
and then we look is such round of point in the hash table.

Фреймворк для поиска ближайшего соседа для точек движущихся по какой-то траектории.
 Применимо в различных системах автопилотирования.

Создаём набор сеток с одной точкой отсчёта и масштабами последовательными степенями двойки.
Сетка хранится в хеш таблице с открытой адресацией. Точка сетки - точка пересечения линий сетки.
Например у сетки масштаба 1 и точкой отсчёта 0 0 точками сетки будут например (0 0) (0 1) (0 2) (1 1) (1 2) и т.д.

При добавлении новой точки к сетке мы ищем ближайшую точку на сетке к данной и добавляем её в хеш таблицу.
 Добавляем точку к сетке каждого масштаба.

Для масштабирования приложения: сетки можно нарезать и хранить частями и при необходимости подгружать.

При поиске ближайшего соседа точки A, если точка A не попадает в кусок нарезанных сеток перегружаем сетки.
При поиске ближайшего соседа точки A, мы ищем сетку с минимальным масштабом, в которой для точки на сетке ближайшей к
A добавлялась ближайшая точка. Иными словами мы округляем точку A до таких координат, чтобы она была точкой на сетке и
после этого смотрим есть ли такая точка в хеш таблице.