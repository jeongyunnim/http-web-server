#pragma once

#include "AMethod.hpp"
#include "UserData.hpp"

class MethodGet : public AMethod
{
public:
	// temp
	MethodGet(int fd);
	~MethodGet(void);

	int GenerateResponse(std::string mUri, LocationBlock& mSetting, std::map<int, std::string>& mHeaders);
	int AutoIndexResponse(std::string& mUri);

private:
	const MethodGet& operator=(const MethodGet& rhs);
	MethodGet(const MethodGet& rhs);
	MethodGet(void);
};