#include "mymatrix.hpp"

// internal::TCell

template<typename T, T d>
internal::TCell<T,d>::TCell(int x, int y, OwnContainer<T,d>* m) : x(x), y(y), m(m) {
}

template<typename T, T d>
internal::TCell<T,d>::TCell(const TCell& c){
	this->m=c.m;
	this->x=c.x;
	this->y=c.y;
}

template<typename T, T d>
internal::TCell<T,d>& internal::TCell<T,d>::operator=(const T& value){
	T& v=m->search(x,y);
	v=value;
	if (v==d) {
		m->remove(x,y);
	}
	return *this;
}

template<typename T, T d>
bool internal::TCell<T,d>::operator==(const T& value) const{
	T v=m->search(x,y);
	if (v==d) {
		m->remove(x,y);
	}
	return v==value;
}

template<typename T, T d>
T internal::TCell<T,d>::GetValue() const{
	T v=m->search(x,y);
	if (v==d) {
		m->remove(x,y);
	}
	return v;
}
template<typename T, T d>
internal::TCell<T,d>::operator T() const{
	return GetValue();
}
//------------------------------------------------------------------------------

//internal::TRow

template<typename T, T d>
internal::TRow<T,d>::TRow(int x, OwnContainer<T,d>* m) : x(x), m(m) {
}

template<typename T, T d>
internal::TCell<T,d> internal::TRow<T,d>::operator[](int y) const{
	internal::TCell<T,d> c(x,y, m);
	return c;
}
//------------------------------------------------------------------------------

//OwnContainer

template<typename T, T d>
OwnContainer<T,d>::OwnContainer(){
}

template<typename T, T d>
OwnContainer<T,d>::~OwnContainer() {
}

template<typename T, T d>
::internal::TRow<T,d> OwnContainer<T,d>::operator[](int x) const{
	::internal::TRow<T,d> row(x, (OwnContainer<T,d>*)this);
	return row;
}

template<typename T, T d>
size_t OwnContainer<T,d>::size() const{
	return _m.size();
}

template<typename T, T d>
OwnIterator<T,d> OwnContainer<T,d>::begin(){
	return iterator(_m.begin());
}

template<typename T, T d>
OwnIterator<T,d> OwnContainer<T,d>::end(){
	return iterator(_m.end());
}

template<typename T, T d>
T& OwnContainer<T,d>::search(int x,int y){
	std::pair<int,int> p;
	p.first=x;
	p.second=y;
	if (_m.count(p)==0) {
		_m[p]=d;
	}
	return _m[p];
}

template<typename T, T d>
void OwnContainer<T,d>::remove(int x,int y){
	std::pair<int,int> p{x,y};
	if (_m.count(p)) {
		_m.erase(p);
	}
}

//------------------------------------------------------------------------------

//OwnIterator

template<typename T, T d>
OwnIterator<T,d>::OwnIterator(TIterator<T> it) : it(it) {
}

template<typename T, T d>
OwnIterator<T,d>::OwnIterator(const OwnIterator &it){
	this->it=it.it;
}

template<typename T, T d>
bool OwnIterator<T,d>::operator!=(OwnIterator const& other) const{
	return this->it!=other.it;
}

template<typename T, T d>
bool OwnIterator<T,d>::operator==(OwnIterator const& other) const{
	return this->it==other.it;
}

template<typename T, T d>
std::tuple<int,int,T> OwnIterator<T,d>::operator*() const{
	int x=it->first.first;
	int y=it->first.second;
	int v=it->second;
	return std::make_tuple(x,y,v);
}

template<typename T, T d>
OwnIterator<T,d>& OwnIterator<T,d>::operator++(){
	it++;
	return *this;
}
//------------------------------------------------------------------------------

