#pragma once

#define rdlib_version 1.0

#define __nodiscard [[nodiscard]]

#include <vector>
#include <string>
#include "Windows.h"

#define dbg_out(a, ...) OutputDebugStringA((std::format(a, __VA_ARGS__)).c_str())

constexpr const char SPACE_CH = ' ';
const std::string SPACE = " ";

const std::string EMPTY = "";

constexpr const char* ENV_NEWLINE = "\r\n";

inline std::vector<std::string> split(const std::string& s, const std::string& delimiter)
{
	size_t pos_start = 0, pos_end;
	const size_t delim_len = delimiter.length();
	std::vector<std::string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		std::string token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

inline void join(const std::vector<std::string>& v, const std::string c, std::string& s)
{
	s.clear();

	for (auto p = v.begin(); p != v.end(); ++p) {
		s += *p;
		if (p != v.end() - 1)
			s += c;
	}
}

template<typename T>
inline void qprint(const std::vector<T> t)
{
	std::string buf;
	join(t, ", ", buf);
	std::cout << buf;
}