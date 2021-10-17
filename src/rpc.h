#pragma once

#include <string>
#include <json.hpp>

using json = nlohmann::json;

enum HTTPMethod {
	POST,
	PUT,
	PATCH,
	DELETE
};

class RPC {

	public:
		std::string name;
		HTTPMethod method;

	public:
		RPC(std::string name, HTTPMethod method) :
			name(name), method(method) {}

	public:
		json execute(json arguments);

};
