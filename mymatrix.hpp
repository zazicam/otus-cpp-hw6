//---------------------------------------------------------------------------
#pragma once

#include <tuple>
#include <map>
#include <utility>
//---------------------------------------------------------------------------

template<typename T, T d> class OwnIterator;
template<typename T, T d> class OwnContainer;

template<typename T, T d>
struct TCell{
	public:
		TCell(OwnContainer<T,d>* m);
		TCell(const TCell& c);
		void SetXY(int x,int y);
		TCell<T,d>& operator=(const T& value);
		bool operator==(const T& value) const;
		T GetValue(void) const;
		operator T(void) const;
	private:
		int x;
		int y;
		OwnContainer<T,d>* m;

};

template<typename T, T d>
class TRow{
	public:
		TRow(OwnContainer<T,d>* m);
		void SetX(int x);
		TCell<T,d> operator[](int y) const;
	private:
		OwnContainer<T,d>* m;
		int x;
};

//bool operator<(const std::pair<int,int>& v1,const std::pair<int,int>& v2){
//	if (v1.first==v2.first) {
//		return v1.second<v2.second;
//	}
//	return v1.first<v2.first;
//}

template <typename T>
using TMap=std::map<std::pair<int,int>,T>;
template <typename T>
using TIterator=typename TMap<T>::iterator;

template<typename T, T d>
class OwnContainer
{
	friend class TCell<T,d>;
public:

	typedef OwnIterator<T,d> iterator;

	OwnContainer(void);

	virtual ~OwnContainer(void);

	iterator begin(void);
	iterator end(void);

	size_t size(void) const;

	TRow<T,d> operator[](int x) const;

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
		std::tuple<int,int,T> operator*(void) const;
		OwnIterator& operator++(void);
	private:
		TIterator<T> it;
};

template<typename T, T d>
using Matrix = OwnContainer<T,d>;
