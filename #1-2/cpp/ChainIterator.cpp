#include "ChainIterator.h"

ChainIterator& ChainIterator::operator++() {
	current = current->next;
	return *this;
}
ChainIterator ChainIterator::operator++(int) {
	ChainIterator old = *this;
	current = current->next;
	return old;
}
bool ChainIterator::operator!=(const ChainIterator right) const {
	return current != right.current;
}
bool ChainIterator::operator==(const ChainIterator right) const {
	return current == right.current;
}