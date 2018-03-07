#ifndef GUARD_RAY_STRING
#define GUARD_RAY_STRING

// ray_string.h header file
#include<vector>
#include<string>

std::vector<std::string> split(const std::string& s);

std::string::size_type width(const std::vector<std::string>& v);


std::vector<std::string> frame(const std::vector<std::string>& v);

std::vector<std::string> vcat(const std::vector<std::string>& top, 
                              const std::vector<std::string>& bottom);

std::vector<std::string> hcat(const std::vector<std::string>& left,
                              const std::vector<std::string>& right);

#endif
