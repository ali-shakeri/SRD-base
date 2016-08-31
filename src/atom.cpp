#include "atom.h"

Atom::Atom (AtomType a) : position{}, velocity{}, atom_type{a} {}
Atom::Atom (Point pos, Point vel, AtomType a) : position{pos}, velocity{vel}, atom_type{a} {}
