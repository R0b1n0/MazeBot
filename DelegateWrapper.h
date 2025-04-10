#pragma once
#include <vector>
#include <functional>
#include <utility>

//TODO move into a new file 
template <class T> class DelegateWrapper
{
private:
	std::vector<T> methods;

public:
	template<typename... Args>
	void Invoke(Args&&... args)
	{
		for (auto& method : methods)
		{
			method(std::forward<Args>(args)...);
		}
	}

	DelegateWrapper<T> operator += (T)
	{
		
	}
};
