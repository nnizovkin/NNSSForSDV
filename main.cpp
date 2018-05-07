/*  Framework for nearest neighbour search for sequence of points in some trajectory.
    Copyright (C) 2018  Nizovkin Nikolay.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <iostream>
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct Coordinate {
    Coordinate(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int x;
    int y;
};

class GridPiece {
private:
    HashSetWithOpenAddressing <Coordinate> piece;
    int scale;

public:
    Coordinate search(Coordinate c) {
        c = roundOf(c);
        return piece.contains(c) ? c : NOT_FOUND_COORD;
    }

private:
    Coordinate roundOf(Coordinate c) { ... }
};

class GridStorage {
    //some data structure for save GridPiece with cache for vector<GridPiece> for given part of spatial
public:
    std::vector <GridPiece> loadGridPieces(Coordinate c) { ... }
};

class Searcher {
private:
    GridStorage storage;

public:
    std::pair<Coordinate, int> search(Coordinate c, int gridLevel) {
        std::vector <GridPiece> gridPieces = storage.loadGridPieces(c);
        Coordinate res = gridPieces[gridLevel].search(c);
        //check search anything
        if (res != NOT_FOUND_COORD) {
            if (gridLevel == 0) {
                return std::pair(res, 0);
            }
            //don't do binary search because point for search is near each other and change of level should happens rare
            for (int i = gridLevel - 1; i >= 0; i--) {
                Coordinate temp = gridPieces[gridLevel].search(c);
                if (temp == NOT_FOUND_COORD) {
                    return std::pair(res, i + 1);
                }
                res = temp;
            }
            return std::pair(res, 0);

        }
        //don't do binary search because point for search is near each other and change of level shouldn't happens often
        for (int i = gridLevel + 1; i < gridPieces.size(); i++) {
            res = gridPieces[gridLevel].search(c);
            if (res != NOT_FOUND_COORD) {
                return std::pair(res, i);
            }
        }

        //strange situation
        throw Exception();
    }
};


