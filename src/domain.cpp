#include "domain.h"

Domain::Domain (Boundary x, Boundary y, Boundary z) : x_direction{x}, y_direction{y}, z_direction{z} {}

void Domain::apply_boundary_condition (std::vector<Atom> &atoms, double dt) {
  for (auto &atom : atoms) {
    // apply boundary condition in y direction
    switch (y_direction.type()) {
      case BoundaryType::PERIODIC:
	if (atom.pos().y() > y_direction.high()) atom.pos().y() -= (y_direction.high() - y_direction.low());
	else if (atom.pos().y() < y_direction.low()) atom.pos().y() += (y_direction.high() - y_direction.low());
	break;
      case BoundaryType::SLIP:
	break;
      case BoundaryType::NO_SLIP:
	if (atom.pos().y() > y_direction.high() || atom.pos().y() < y_direction.low()) {
	  atom.vel() = -atom.vel();
	  atom.pos() += atom.vel()*dt;
	}
	break;
      case BoundaryType::THERMAL:
	break;
    }
    // apply boundary condition in x direction
    switch (x_direction.type()) {
      case BoundaryType::PERIODIC:
	if (atom.pos().x() > x_direction.high()) atom.pos().x() -= (x_direction.high() - x_direction.low());
	else if (atom.pos().x() < x_direction.low()) atom.pos().x() += (x_direction.high() - x_direction.low());
	break;
      case BoundaryType::SLIP:
	break;
      case BoundaryType::NO_SLIP:
	if (atom.pos().x() > x_direction.high() || atom.pos().x() < x_direction.low()) {
	  atom.vel() = -atom.vel();
	  atom.pos() += atom.vel()*dt;
	}
	break;
      case BoundaryType::THERMAL:
	break;
    }
    // apply boundary condition in z direction
    switch (z_direction.type()) {
      case BoundaryType::PERIODIC:
	if (atom.pos().z() > z_direction.high()) atom.pos().z() -= (z_direction.high() - z_direction.low());
	else if (atom.pos().z() < z_direction.low()) atom.pos().z() += (z_direction.high() - z_direction.low());
	break;
      case BoundaryType::SLIP:
	break;
      case BoundaryType::NO_SLIP:
	if (atom.pos().z() > z_direction.high() || atom.pos().z() < z_direction.low()) {
	  atom.vel() = -atom.vel();
	  atom.pos() += atom.vel()*dt;
	}
	break;
      case BoundaryType::THERMAL:
	break;
    }
  }
}