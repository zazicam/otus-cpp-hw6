#include "mymatrix.hpp"

// TCell

template<typename T, T d>
TCell<T,d>::TCell(OwnContainer<T,d>* m) : x(-1), y(-1), m(m) {
}

template<typename T, T d>
TCell<T,d>::TCell(const TCell& c){
	this->m=c.m;
	this->x=c.x;
	this->y=c.y;
}

template<typename T, T d>
void TCell<T,d>::SetXY(int x,int y){
	this->x=x;
	this->y=y;
}

template<typename T, T d>
TCell<T,d>& TCell<T,d>::operator=(const T& value){
	T& v=m->search(x,y);
	v=value;
	if (v==d) {
		m->remove(x,y);
	}
	return *this;
}

template<typename T, T d>
bool TCell<T,d>::operator==(const T& value) const{
	T v=m->search(x,y);
	if (v==d) {
		m->remove(x,y);
	}
	return v==value;
}

template<typename T, T d>
T TCell<T,d>::GetValue() const{
	T v=m->search(x,y);
	if (v==d) {
		m->remove(x,y);
	}
	return v;
}
template<typename T, T d>
TCell<T,d>::operator T() const{
	return GetValue();
}
//------------------------------------------------------------------------------

//TRow

template<typename T, T d>
TRow<T,d>::TRow(OwnContainer<T,d>* m) : x(0), m(m) {
}

template<typename T, T d>
void TRow<T,d>::SetX(int x){
	this->x=x;
}

template<typename T, T d>
TCell<T,d> TRow<T,d>::operator[](int y) const{
	TCell<T,d> c(m);
	c.SetXY(x,y);
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
TRow<T,d> OwnContainer<T,d>::operator[](int x) const{
	TRow<T,d> row((OwnContainer<T,d>*)this);
	row.SetX(x);
	return row;
}

template<typename T, T d>
size_t OwnContainer<T,d>::size() const{
	return _m.size()+1;
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

