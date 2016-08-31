#include "boundary.h"

Boundary::Boundary (int low, int high, BoundaryType bd) : lower_limit{low}, higher_limit{high}, boundary_type{bd} {}