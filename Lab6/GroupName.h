#pragma once

template <typename T>
class GroupName
{
private:
	T name;
public:
	GroupName(T name) {
		this->name = name;
	};
	T getName() {
		return this->name;
	};
	void setName(T name) {
		this->name = name;
	};
};

