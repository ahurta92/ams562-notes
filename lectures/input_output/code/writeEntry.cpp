#include "examples.h"

ostream &operator<<(ostream &os, const Entry &e) {
	return os << "{\"" << e.name << "\"," << e.number << "}";
}