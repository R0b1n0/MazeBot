#pragma once
#include <vector>
#include <functional>
#include <utility>

template <class T> class DelegateWrapper
{
private:
	std::vector<T> methods;

public:
	//Args est un template parameter pack (Args c'est juste un nom typique pour ce genre de variables)
	//L'op�rateur (...) d�clare Args comme template parameter pack 
	template<typename... Args> 
	void Invoke(Args&&... args)
	{
		for (auto& method : methods)
		{
			method(std::forward<Args>(args)...);
		}
	}

	DelegateWrapper<T>& operator += (T method)
	{
		methods.push_back(method);
		return *this;
	}

	//TODO Ajouter une m�thode pour unsub, les statics �a mord
};
