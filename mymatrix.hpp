//---------------------------------------------------------------------------
#pragma once

#include <cstddef>
#include <tuple>
#include <map>
#include <utility>
//---------------------------------------------------------------------------

template<typename T, T d> class OwnIterator;
template<typename T, T d> class OwnContainer;

namespace internal {

template<typename T, T d>
struct TCell{
	public:
		TCell(int x, int y, OwnContainer<T,d>* m);
		TCell(const TCell& c);
		TCell<T,d>& operator=(const T& value);
		bool operator==(const T& value) const;
		T GetValue() const;
		operator T() const;
	private:
		int x;
		int y;
		OwnContainer<T,d>* m;
};

template<typename T, T d>
class TRow{
	public:
		TRow(int x, OwnContainer<T,d>* m);
		TCell<T,d> operator[](int y) const;
	private:
		int x;
		OwnContainer<T,d>* m;
};

} // namespace internal

template <typename T>
using TMap=std::map<std::pair<int,int>,T>;

template <typename T>
using TIterator=typename TMap<T>::iterator;

template<typename T, T d>
class OwnContainer
{
	friend class internal::TCell<T,d>;
public:

	typedef OwnIterator<T,d> iterator;

	OwnContainer();

	virtual ~OwnContainer();

	iterator begin();
	iterator end();

	size_t size() const;

	internal::TRow<T,d> operator[](int x) const;

private:

	T& search(int x,int y);
	void remove(int x,int y);

	TMap<T> _m;

};

template<typename T, T d>
class OwnIterator: public std::iterator<std::input_iterator_tag, T>
{
	friend class OwnContainer<T,d>;
	private:
		OwnIterator(TIterator<T> it);
	public:
		OwnIterator(const OwnIterator &it);
		bool operator!=(OwnIterator const& other) const;
		bool operator==(OwnIterator const& other) const;
		std::tuple<int,int,T> operator*() const;
		OwnIterator& operator++();
	private:
		TIterator<T> it;
};

template<typename T, T d>
using Matrix = OwnContainer<T,d>;

#include "mymatrix.inl"
